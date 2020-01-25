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
    
    if(strcmp(term, "") == 0) {
        printf("No instances of the term in the file(s).\n");
        exit(1);
    }
    
    if(argc == 1) {
        printf("wgrep: searchterm [file...]\n");
        exit(1);
    } else if (argc == 2) {
        size_t nameMaxSize = 100;
        char *fileName = malloc(nameMaxSize * sizeof(char));
        char *ptr = NULL;
        
        fgets(fileName, nameMaxSize, stdin);
        
        if ((ptr = strchr(fileName, '\n')) != NULL) {
            *ptr = '\0';
        }
        
        FILE *fp = fopen(fileName, "r");
        
        if(fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        
        char *buffer = (char *) malloc(nameMaxSize * sizeof(char));

        if(buffer == NULL) {
            printf("Unable to allocate memory for buffer.");
            exit(1);
        }

        while(getline(&buffer, &nameMaxSize, fp) != EOF) {
            if(strstr(buffer, term) != NULL) {
                printf("%s", buffer);
            }
        }

        free(buffer);
        fclose(fp);
    
    } else if (argc > 2) {
        for(int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            
            if(fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            
            char *buffer = NULL;
            size_t buffsize = 100;

            buffer = (char *) malloc(buffsize * sizeof(char));

            if(buffer == NULL) {
                printf("Unable to allocate memory for buffer.");
                exit(1);
            }

            while(getline(&buffer, &buffsize, fp) != EOF) {
                if(strstr(buffer, term) != NULL) {
                    printf("%s", buffer);
                }
            }

            free(buffer);
            fclose(fp);
        }
    }
    
    exit(0);
}
