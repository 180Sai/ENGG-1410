#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decihex.h"
#define LINE_MAX 125

char *changExt(const char fileName[], char ext[]) {
    char tmp[256];
    strcpy(tmp, fileName);
    char *loc = strrchr(tmp, '.');
    if (loc)
        *(loc + 1) = '\0';
    char *end = malloc(256 * sizeof(char));
    sprintf(end, "%s%s", tmp, ext);
    return end;
}

int main(int argc, const char *argv[]) {
    int isEncrypt = 1;
    char *fileName; // max file name length

    FILE *Read;
    FILE *Write;

    if (argc > 2) {
        Read = fopen(argv[2], "r");
        if (!strcmp(argv[1], "-E")) {
            fileName = changExt(argv[2], "crp");
        } else {
            isEncrypt = 0;
            fileName = changExt(argv[2], "txt");
        }
    } else {
        Read = fopen(argv[1], "r");
        fileName = changExt(argv[1], "txt");
    }
    Write = fopen(fileName, "w+");
    free(fileName);

    char fileText[LINE_MAX];
    while (fgets(fileText, sizeof(fileText), Read) != NULL) {
        if (isEncrypt) {
            for (long long unsigned int i = 0; i < sizeof(fileText); i++) {
                if (fileText[i] == '\0')
                    break;
                else if (fileText[i] == '\n')
                    fprintf(Write, "\n");
                else if (fileText[i] == '\t')
                    fprintf(Write, "TT");
                else if (fileText[i] - 16 < 32) {
                    char h[hlen(fileText[i] - 16 - 32 + 144)];
                    h[0] = fileText[i] - 16 - 32 + 144;
                    h[1] = '\0';
                    decihex(fileText[i] - 16 - 32 + 144, h);
                    fprintf(Write, "%s", h);
                } else {
                    char h[hlen(fileText[i] - 16)];
                    h[0] = fileText[i] - 16;
                    h[1] = '\0';
                    decihex(fileText[i] - 16, h);
                    fprintf(Write, "%s", h);
                }
            }
        } else {
            for (long long unsigned int i = 0; i < sizeof(fileText); i += 2) {
                if (fileText[i] == '\n') {
                    fprintf(Write, "\n");
                    break;
                } else if (fileText[i] == 'T' && fileText[i + 1] == 'T')
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