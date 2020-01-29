//  Alexander Kim
//  Lab 0: Unix Utilities (wunzip.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    //Print error message if no files are passed to wunzip
    if(argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    //If one or more files are passed to wunzip
    if(argc >= 2) {
        //For each file passed to wunzip
        for(int i = 1; i < argc; i++) {
            const char *fileName = argv[i];
            
            //Open file to read and print error message if file can't be printed
            FILE *fp1 = fopen(fileName, "rb");

            if(fp1 == NULL) {
                printf("wunzip: cannot open file\n");
                exit(1);
            }
            
            int count = 0;
            size_t bytesRead = 0;

            //Read integer for each iteration, then read character and print the character count number of times
            while((bytesRead = fread(&count, sizeof(int), 1, fp1)) > 0)  {
                char c = fgetc(fp1);
                
                for(int i = 0; i < count; i++) {
                    printf("%c", c);
                }
            }

            //Close the file
            fclose(fp1);
        }
        
        exit(0);
    }
    
}
