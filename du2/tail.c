#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//definitions of error messages
#define argsErr "too many arguments"
#define filesNumErr "too many files (one file supported only)"
#define linesNumErr "parsing number of lines failed"
#define mallocErr "memory allocation failed"
#define fileErr "file reading failed (file probably doesn't exist)"
#define lineErr "a line was truncated to the max length of 511 chars"

#define BUFFER_SIZE 512
#define DEFAULT_LINES 10

//prints error message given in error
void printError(const char* error){
    fprintf(stderr, "ERROR: %s\n", error);
    fprintf(stderr, "USAGE: ./tail [-n NUMBER] [FILE]\n");
}

//frees the dynamically allocated buffer
void freeBuffer(char **buffer, const int size){
    for(int i = 0; i < size; i++){
        free(buffer[i]);
    }
    free(buffer);
}

//checks and parses input arguments, returns 0 on error or number of lines to print,
//negative number to print from that line
long parseArgs(int argc, char *argv[]){
    if(argc > 4){
        printError(argsErr);
        return 0;
    }

    long linesToPrint = DEFAULT_LINES;

    if(argc > 1 && !strcmp(argv[1], "-n")){
        char *endPtr;
        linesToPrint = strtol(argv[2], &endPtr, 10);
        if(linesToPrint < 1 || strcmp(endPtr, "")){
            printError(linesNumErr);
            return 0;
        }

        if(argv[2][0] == '+')
            linesToPrint = -linesToPrint;
    } 
    else if(argc > 2){
        printError(filesNumErr);
        return 0;
    }

    return linesToPrint;
}

//allocate buffer for size lines, with each line being BUFFER_SIZE long
char **allocBuffer(const int size){
    char **buffer = malloc(size * sizeof(char*));
    if(buffer == NULL){
        printError(mallocErr);
        return NULL;
    }
    for(int i = 0; i < size; i++){
        buffer[i] = malloc(BUFFER_SIZE);
        if(buffer[i] == NULL){  //free everything and exit on malloc error
            freeBuffer(buffer, i);
            printError(mallocErr);
            return NULL;
        }
    }

    return buffer;
}

int main(int argc, char *argv[]){
    long linesToPrint;
    if((linesToPrint = parseArgs(argc, argv)) == 0){
        return 1;
    }

    //alloc memory for buffer, if set to print from given line, buffer for one line is enough
    char **buffer;
    if((buffer = allocBuffer(linesToPrint > 0 ? linesToPrint : 1)) == NULL)
        return 1;
    
    bool fromStart = false;
    if(linesToPrint < 0){
        linesToPrint = -linesToPrint;
        fromStart = true;
    }

    //open file
    int filePos = argc == 3 ? 0 : argc - 1;
    FILE *f;
    if(filePos > 0){
        f = fopen(argv[filePos], "r"); //if file is set, open it
        if(f == NULL){
            freeBuffer(buffer, linesToPrint);
            printError(fileErr);
            return 1;
        }
    }
    else f = stdin; //else read from stdin

    //loop through lines, saving them in buffer
    int bufPos = 0, line = 0;
    bool full = false, errPrinted = false;
    char *newLine;
    while((newLine = fgets(buffer[bufPos], BUFFER_SIZE, f))){
        buffer[bufPos] = newLine;
        if(strlen(buffer[bufPos]) == BUFFER_SIZE - 1){
            if(buffer[bufPos][BUFFER_SIZE - 2] != '\n'){ //finish reading line if it's too long
                int nextChar;
                while((nextChar = getc(f)) != '\n' && nextChar != EOF) printf("%c", nextChar);
                if(!errPrinted){
                    printf("Line %d was truncated to the max length of 511 chars (this error will show only once)\n", line);
                    errPrinted = true;
                }
            }
        }

        //print ant continue if set to print from given line
        if(fromStart){
            if(line >= linesToPrint - 1){
                printf("%s", buffer[bufPos]);
            }
            line++;
            continue;
        }

        bufPos++;
        if(bufPos == linesToPrint){ //reset buffer line position if got to end
            bufPos = 0;
            full = true;
        }
        line++;
    }

    //print buffer
    if(!fromStart){
        int printIndex = full ? bufPos : 0;
        do{
            printf("%s", buffer[printIndex]);
            printIndex = (printIndex + 1) % linesToPrint;
        } while(printIndex != bufPos);
    }
    
    //free everything and close file if one was opened
    freeBuffer(buffer, fromStart ? 1 : linesToPrint);
    if(f != stdin)
        fclose(f);
    return 0;
}