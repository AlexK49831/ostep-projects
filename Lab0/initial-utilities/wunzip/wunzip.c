//  Alexander Kim
//  Lab 0: Unix Utilities (wunzip.c)
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
        for(int i = 1; i < argc; i++) {
            const char *fileName = argv[i];

            FILE *fp1 = fopen(fileName, "rb");

            if(fp1 == NULL) {
                printf("wunzip: cannot open file\n");
                exit(1);
            }
            
            int count = 0;
            size_t bytesRead = 0;

            while((bytesRead = fread(&count, sizeof(int), 1, fp1)) > 0)  {
                char c = fgetc(fp1);
                
                for(int i = 0; i < count; i++) {
                    printf("%c", c);
                }
            }

            fclose(fp1);
        }
        
        exit(0);
    }
    
}
