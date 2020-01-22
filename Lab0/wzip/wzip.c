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
        FILE *fp1 = fopen(argv[1], "r");
        
        if(fp1 == NULL) {
            printf("wzip: cannot open file\n");
            perror("Error");
            exit(1);
        }
        
        FILE *fp2 = fopen(argv[2], "w");
        
        if(fp2 == NULL) {
            printf("wzip: cannot open file\n");
            perror("Error");
            exit(1);
        }
        
        char c = fgetc(fp1);
        while(c != EOF) {
            
            
        }
        
        fclose(fp1);
        fclose(fp2);
        
        exit(0);
    }
    
    
    
}
