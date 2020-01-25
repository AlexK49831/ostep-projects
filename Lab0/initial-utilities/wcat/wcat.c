//  Alexander Kim
//  Lab 0: Unix Utilities (wcat.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if(argc == 1) {
        return 0;
    } else if (argc >= 2) {
        for(int i = 0; i < argc - 1; i++) {
            FILE *fp = fopen(argv[i + 1], "r");
            
            char buffer[10];
            
            if(fp == NULL) {
                printf("wcat: cannot open file\n");
                exit(1);
            } else {
                while(fgets(buffer, 10, fp) != NULL) {
                    printf("%s", buffer);
                }
            }
            
            fclose(fp);
        }
        
        exit(0);
    }
}
