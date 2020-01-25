//  Alexander Kim
//  Lab 0: Unix Utilities (wzip.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    if(argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    if(argc >= 2) {
        while(argc > 1) {
            const char *fileName = argv[argc - 1];

            FILE *fp1 = fopen(fileName, "r");

            if(fp1 == NULL) {
                printf("wzip: cannot open file\n");
                exit(1);
            }

            char c = fgetc(fp1);
            
            while(c != EOF) {
                int isRecurring = 0;
                int count = 1;
            
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

            fclose(fp1);

            argc--;
        }
        
        exit(0);
    }
    
}
