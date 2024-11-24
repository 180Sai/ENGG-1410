#include <stdio.h>
#include <string.h>

// appended function for hexadecimal-decimal conversion
#include "decihex.h"

// macros for debug (no arguments to pass to main)
#define IS_ENCRYPT 1
#define FILE_NAME "secret.txt"

#define IS_DEBUG_TEXT 0

// macros for reader's convenience
#define HEX_OFFSET 16
#define HEX_OV 32
#define HEX_OV_OFFSET (16 + 32 - 144)
#define LINE_MAX 125

int main() {
    FILE *file_handle = fopen(FILE_NAME, "r");
    char fileText[LINE_MAX];

    while (fgets(fileText, sizeof(fileText), file_handle) != NULL) {
        if (IS_ENCRYPT) {
            printf("%s", fileText);
            for (long long unsigned int i = 0; i < sizeof(fileText); i++) {
                if (fileText[i] == '\0') break;
                
                if (fileText[i] <= 0)
                    continue;
                else if (fileText[i] == '\n')
                    printf("\n");
                else if (fileText[i] == '\t')
                    printf("TT");
                else if (fileText[i] - HEX_OFFSET < HEX_OV) {
                    char h[hlen(fileText[i] - HEX_OV_OFFSET)];
                    h[0] = fileText[i] - HEX_OV_OFFSET;
                    h[1] = '\0';
                    decihex(fileText[i] - HEX_OV_OFFSET, h);

#if !IS_DEBUG_TEXT
                    printf("%s", h);
#endif
#if IS_DEBUG_TEXT
                    printf("original: %c, ascii: %d, ascii encrypt: %d, hex: %s\n", fileText[i], fileText[i], fileText[i] - HEX_OV_OFFSET, h);
#endif

                } else {
                    char h[hlen(fileText[i] - HEX_OFFSET)];
                    h[0] = fileText[i] - HEX_OFFSET;
                    h[1] = '\0';
                    decihex(fileText[i] - HEX_OFFSET, h);

#if !IS_DEBUG_TEXT
                    printf("%s", h);
#endif
#if IS_DEBUG_TEXT
                    printf("original: %c, ascii: %d, ascii encrypt: %d, hex: %s\n", fileText[i], fileText[i], fileText[i] - HEX_OFFSET, h);
#endif
                }
            }
        } else {
            // code not implemented yet
        }
    }

    fclose(file_handle);

    return 0;
}