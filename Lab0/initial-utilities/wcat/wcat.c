//  Alexander Kim
//  Lab 0: Unix Utilities (wcat.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    //If no arguments in command line after wcat is called
    if(argc == 1) {
        return 0;
    } else if (argc >= 2) {
        //Iterate through each file given to wcat
        for(int i = 0; i < argc - 1; i++) {
            FILE *fp = fopen(argv[i + 1], "r");
            
            //Buffer to store result
            char buffer[10];
            
            //Print error message if file cannot be opened, or read file into buffer and print out what's in the buffer
            if(fp == NULL) {
                printf("wcat: cannot open file\n");
                exit(1);
            } else {
                while(fgets(buffer, 10, fp) != NULL) {
                    printf("%s", buffer);
                }
            }
            
            //Close file
            fclose(fp);
        }
        
        exit(0);
    }
}
