#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Usage: file\n");
        return 1;
    }

    //remember filename
    char *infile = argv[1];

    //open file for writing into (creates new file if none, adds to end of file if it exists)
    FILE *inptr = fopen(infile, "a+");

    //memory to write into
    char *paragraph = malloc(sizeof(char) * 512);

    //make sure paragraph was successfully created
    if(paragraph == NULL) {
        fprintf(stderr, "Memory allocation failed");
        return 2;
    }

    fprintf(stdout, "Enter text: ");

    //allows user to enter text until they use ctrl-D
    while(fgets(paragraph, 512, stdin)) {

        if(feof(stdin)) {
            break;
        }

        fwrite(paragraph, 512, 1, inptr);
        for(int i = 0; i < 512; i++) {
            paragraph[i] = '\0';
        }
    }

    //frees allocated memory
    free(paragraph);

    //success
    return 0;
}
