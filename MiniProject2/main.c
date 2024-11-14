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
            for(int i = 0; i < sizeof(fileText); i++)
            {
                if (fileText[i] == '\n')
                    printf("\n------------");
                else if (fileText[i] == '\t')
                    printf("TT");
                else if (fileText[i]-16 < 32)
                {
                    char h[digiDecihex(fileText[i]-16-32+144)];
                    h[0] = fileText[i]-16-32+144;
                    h[1] = '\0';
                    decihex(fileText[i]-16-32+144, h);
                    printf("%s, %c, %d\n", h, fileText[i]-16-32+144, (fileText[i]-16-32+144));
                }
                else{
                    char h[digiDecihex(fileText[i]-16)];
                    h[0] = fileText[i]-16;
                    h[1] = '\0';
                    decihex(digiDecihex(fileText[i]-16), h);
                    printf("%s, %c, %didk\n", h, fileText[i]-16, (fileText[i]-16-32+144));
                }
            }
        }
        else{

        }
    }

    fclose(file_handle);
    printf("%d, %c", 'A'-16, 'A'-16);
}