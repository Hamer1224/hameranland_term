#include <stdio.h>
#include "header.h"

void print_string(char* string) {
    if (string) {
        printf("%s", string);
    } else {
        printf("Cant fing any string!");   
    }
}
