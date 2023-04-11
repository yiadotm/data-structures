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

int main(int argc, char **argv) {
    int opt = 0;
    FILE *infile = stdin;
    FILE *outfile = stdout;


    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'i':
            if (optarg) {
                if ((infile = fopen(optarg, "r")) == NULL) {
                    fprintf(stderr, "Error opening %s\n", optarg);

                    exit(1);
                }
            }
            break;

        case 'o':
            if (optarg) {
                outfile = fopen(optarg, "w");
            }
            break;

        }
    }

    //https://www.geeksforgeeks.org/c-program-count-number-lines-file/
    int lines = 0;
    char c;
    for (c = getc(infile); c != EOF; c = getc(infile)) {
        if (c == '\n') {
            lines++;
        }
    }

    fclose(infile);
}
