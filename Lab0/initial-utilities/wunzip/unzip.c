//  Alexander Kim
//  Lab 0: Unix Utilities (wunzip.c)
//  CIS 3207-003
//  John Fiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(int argc, const char * argv[]) {
//    
//    if(argc == 1) {
//        printf("wzip: file1 [file2 ...]\n");
//        exit(1);
//    }
//    
//    if(argc >= 2) {
//        while(argc > 1) {
//            const char *fileName = argv[argc - 1];
//
//            FILE *fp1 = fopen(fileName, "r");
//
//            if(fp1 == NULL) {
//                printf("wzip: cannot open file\n");
//                exit(1);
//            }
//            
//            int count = 0;
//            size_t bytesRead = 0;
//            
//            while(bytesRead = fread(&count, sizeof(int), 1, stdin) > 0)  {
//                char c = fread(&c, sizeof(char), 1, stdin);
//            }
//
//            fclose(fp1);
//
//            argc--;
//        }
//        
//        exit(0);
//    }
//    
//}
