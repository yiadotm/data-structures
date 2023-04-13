#include <getopt.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "List.h"

#define OPTIONS "i:o:"

int main(int argc, char *argv[]) {
    //int opt = 0;
    FILE *infile = stdin;
    FILE *outfile = stdout;

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }
   // open files for reading and writing 
   infile = fopen(argv[1], "r");
      if( infile==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   outfile = fopen(argv[2], "w");
   if( outfile==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }       
    // while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
    //     switch (opt) {
    //     case 'i':
    //         if (optarg) {
    //             if ((infile = fopen(optarg, "r")) == NULL) {
    //                 fprintf(stderr, "Error opening %s\n", optarg);

    //                 exit(1);
    //             }
    //         }
    //         break;

    //     case 'o':
    //         if (optarg) {
    //             outfile = fopen(optarg, "w");
    //         }
    //         break;

    //     }
    // }

    //https://www.geeksforgeeks.org/c-program-count-number-lines-file/

    int lines = 0;
    char **arr = (char**)calloc(10, sizeof(char*));
    char c[300];


    // for (c = gets(infile); c != EOF; c = gets(infile)) {
    //     arr[lines] = c;
    //     if (c == '\n') {
    //         lines++;
    //     }
    // }
    // while (fgets(c, 255, infile) != NULL) {
    //     arr[lines] = *c;
    //     lines++;
    // }
    //printf("pog\n");
    while (fgets(c, 300, infile) != NULL) {
        lines++;
        //fscanf(infile, "%s", &arr[lines]);
        if (lines == 10) {
            arr = (char**)realloc(arr, (lines *2)* sizeof(char*));
        }
        arr[lines-1] = (char *)malloc((strlen(c)) * sizeof(char));
        //printf("%s", c);
        //stackoverflow
        size_t len = strlen(c);
        if (len > 0 && c[len-1] == '\n') {
            c[--len] = '\0';
        }
        strcpy(arr[lines-1], c);

    }

    // printf("\n");
    // for (int i = 0; i < lines; i++) {
    //     printf("arr[%d] = %s \n", i, arr[i]);
    // }
    //printf("%d\n", lines);
    List L = newList();
    moveFront(L);
    append(L, 0);
    //printList(stdout, L);
    for(int i = 1; i < lines; i++) {
        moveFront(L);

        for (int j = 0; j < length(L); j++) {
            
            //printf("length: %d, i: %d, j: %d, cur: %s, cursor: %s, index: %d\n\n", length(L), i, j, arr[i], arr[index(L)], index(L));

            if (strcmp(arr[i], arr[get(L)]) < 0) {
                insertBefore(L, i);
                //printf("insert\n");
                //printList(stdout, L);
                break;
            } 

            if (j == length(L) - 1) {
                append(L, i);
                //printf("append\n");
                //printList(stdout, L);
                break;
            }
            moveNext(L);
            //printf("next\n");
        

            //printList(stdout, L);
        }

    }
    printList(stdout, L);
    free(arr);
    freeList(&L);
    fclose(infile);
    fclose(outfile);
}
