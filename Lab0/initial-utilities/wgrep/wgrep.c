//  Alexander Kim
//  Lab 0: Unix Utilities (wgrep.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    //Get the search term from command line argument and store in term
    char term[100];
    strcpy(term, argv[1]);
    
    //Return no matching words if the empty string is passed as an argument
    if(strcmp(term, "") == 0) {
        printf("No instances of the term in the file(s).\n");
        exit(1);
    }
    
    //If no files are passed to wgrep
    if(argc == 1) {
        printf("wgrep: searchterm [file...]\n");
        exit(1);
    } else if (argc == 2) {
        size_t nameMaxSize = 100;
        char *fileName = malloc(nameMaxSize * sizeof(char));
        char *ptr = NULL;
        
        //Get the file name from stdin
        fgets(fileName, nameMaxSize, stdin);
        
        //Check for newline and remove it
        if ((ptr = strchr(fileName, '\n')) != NULL) {
            *ptr = '\0';
        }
        
        //Open file to read
        FILE *fp = fopen(fileName, "r");
        
        //If file can't be opened, print error message
        if(fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        
        char *buffer = (char *) malloc(nameMaxSize * sizeof(char));
        
        //Print error message if unable to allocate memory for buffer
        if(buffer == NULL) {
            printf("Unable to allocate memory for buffer.");
            exit(1);
        }

        //Get each line in file, compare it to term, and print buffer if there is a match
        while(getline(&buffer, &nameMaxSize, fp) != EOF) {
            if(strstr(buffer, term) != NULL) {
                printf("%s", buffer);
            }
        }

        //Free buffer memory and close file
        free(buffer);
        fclose(fp);
    
    } else if (argc > 2) {
        //For each file passed to wgrep
        for(int i = 2; i < argc; i++) {
            //Open file to read
            FILE *fp = fopen(argv[i], "r");
            
            //Print error message if unable to open file
            if(fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            
            char *buffer = NULL;
            size_t buffsize = 100;

            buffer = (char *) malloc(buffsize * sizeof(char));

            //Print error message if unable to allocate memory for buffer
            if(buffer == NULL) {
                printf("Unable to allocate memory for buffer.");
                exit(1);
            }

            //Get each line in file, compare it to term, and print buffer if there is a match
            while(getline(&buffer, &buffsize, fp) != EOF) {
                if(strstr(buffer, term) != NULL) {
                    printf("%s", buffer);
                }
            }

            //Free buffer memory and close file
            free(buffer);
            fclose(fp);
        }
    }
    
    exit(0);
}
