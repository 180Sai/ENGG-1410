#include <stdio.h>
#include <string.h>

#include "decihex.h"

int main(int argc, const char* argv[])
{
    int file_index = 1;
    int isEncrypt = 1;

    if(argc > 2){
        if(strcmp(argv[1], "-E") != 0){
            isEncrypt = 0;
            }
        file_index = 2;
    }

    FILE* file_handle;
    file_handle = fopen(argv[file_index], "r");

    char fileText[100];

    while (fgets(fileText, sizeof(fileText), file_handle) != NULL) {
        if (isEncrypt){
            printf("%s", fileText);
            for(int i = 0; i < sizeof(fileText); i++)
            {
                if (fileText[i] <= 0)
                    continue;
                else if (fileText[i] == '\n')
                    printf("\n");
                else if (fileText[i] == '\t')
                    printf("TT");
                else if (fileText[i]-16 < 32)
                {
                    char h[hlen(fileText[i]-16-32+144)];
                    h[0] = fileText[i]-16-32+144;
                    h[1] = '\0';
                    decihex(fileText[i]-16-32+144, h);
                    // printf("%s", h);
                    printf("original: %c, ascii: %d, ascii encrypt: %d, hex: %s\n", fileText[i], fileText[i], fileText[i]-16-32+144, h);
                }
                else{
                    char h[hlen(fileText[i]-16)];
                    h[0] = fileText[i]-16;
                    h[1] = '\0';
                    decihex(fileText[i]-16, h);
                    // printf("%s", h);
                    printf("original: %c, ascii: %d, ascii encrypt: %d, hex: %s\n", fileText[i], fileText[i], fileText[i]-16, h);
                }
            }
        }
        else{

        }
    }

    fclose(file_handle);
}