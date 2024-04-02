#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 
    char string1[128];
    char string2[128];

    printf("input string1:\n");
    fgets(string1, 128, stdin);

    printf("input string2:\n");
    fgets(string2, 128, stdin);

    if (strcmp(string1, string2) == 0) {
        printf("strings are similar\n");
    }
    else{
        printf("strings are different\n");
    }
}