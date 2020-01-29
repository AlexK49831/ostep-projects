//  Alexander Kim
//  Lab 0: Unix Utilities (wzip.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    //Print error message if no files are passed to wzip
    if(argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    //If one or more files are passed to wzip
    if(argc >= 2) {
        //For each file passed to wzip
        for(int i = 1; i < argc; i++) {
            const char *fileName = argv[i];
            
            //Open file to read, and print error message if file can't be opened
            FILE *fp1 = fopen(fileName, "r");

            if(fp1 == NULL) {
                printf("wzip: cannot open file\n");
                exit(1);
            }

            //Get the first character in the file
            char c = fgetc(fp1);
            
            //Keep reading while file still has stuff to read
            while(c != EOF) {
                int isRecurring = 0;
                int count = 1;
            
                //Check and keep count of how many consecutive characters there are in file and write count and character to new file when consecutive characters stop
                do {
                    char currentChar = fgetc(fp1);

                    if(currentChar == c) {
                        isRecurring = 1;
                        count++;
                    } else {
                        isRecurring = 0;
                        
                        fwrite(&count, sizeof(int), 1, stdout);
                        fwrite(&c, sizeof(char), 1, stdout);

                        c = currentChar;
                        
                        count = 1;
                        
                        break;
                    }
                } while (isRecurring);
            }
            
            //Close file
            fclose(fp1);
        }
        
        exit(0);
    }
    
}
