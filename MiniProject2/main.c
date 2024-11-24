#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decihex.h"

#define IS_DEBUG_TEXT 0

// macros for reader's convenience
#define HEX_OFFSET 16
#define HEX_OV 32
#define HEX_OV_OFFSET (16 + 32 - 144)
#define LINE_MAX 125

char *changExt(const char fileName[], char ext[]) {
    char *tmp = malloc(256 * sizeof(char));
    strcpy(tmp, fileName);
    char *loc = strrchr(tmp, '.');
    if (loc)
        *(loc + 1) = '\0';
    sprintf(tmp, "%s%s", tmp, ext);
    return tmp;
}

int main(int argc, const char *argv[]) {
    int file_index = 1;
    int isEncrypt = 1;
    char *fileName; // max file name length

    FILE *Read;
    FILE *Write;

    if (argc > 2) {
        Read = fopen(argv[2], "r");
        if (!strcmp(argv[1], "-E")) {
            printf("t1");
            fileName = changExt(argv[2], "crp");
        } else {
            isEncrypt = 0;
            fileName = changExt(argv[2], "txt");
        }
    } else {
        printf("t3");
        Read = fopen(argv[1], "r");
        fileName = changExt(argv[1], "txt");
    }
    Write = fopen(fileName, "w+");

    char fileText[LINE_MAX];
    while (fgets(fileText, sizeof(fileText), Read) != NULL) {
        if (isEncrypt) {
            for (int i = 0; i < sizeof(fileText); i++) {
                if (fileText[i] == '\0')
                    break;
                else if (fileText[i] == '\n')
                    fprintf(Write, "\n");
                else if (fileText[i] == '\t')
                    fprintf(Write, "TT");
                else if (fileText[i] - HEX_OFFSET < HEX_OV) {
                    char h[hlen(fileText[i] - HEX_OV_OFFSET)];
                    h[0] = fileText[i] - HEX_OV_OFFSET;
                    h[1] = '\0';
                    decihex(fileText[i] - HEX_OV_OFFSET, h);
                    fprintf(Write, "%s", h);
                } else {
                    char h[hlen(fileText[i] - HEX_OFFSET)];
                    h[0] = fileText[i] - HEX_OFFSET;
                    h[1] = '\0';
                    decihex(fileText[i] - HEX_OFFSET, h);
                    fprintf(Write, "%s", h);
                }
            }
        } else {
            for (int i = 0; i < sizeof(fileText); i += 2) {
                if (fileText[i] == '\0')
                    break;
                else if (fileText[i] == '\n')
                    fprintf(Write, "\n");
                else if (fileText[i] == 'T' && fileText[i + 1] == 'T')
                    fprintf(Write, "\t");
                else {
                    int dec;
                    int decr;
                    char hex[] = {fileText[i], fileText[i + 1], '\0'};
                    hexdeci(hex, &dec, 2);
                    decr = dec + 16;
                    if (dec > 127)
                        decr += 32 - 144;
                    fprintf(Write, "%c", decr);
                }
            }
        }
    }

    fclose(Write);
    fclose(Read);
    return 0;
}