#include <stdio.h>

int main(int argc, char **argv) {
    char *string = "hello, world!\n";

    int i = 0;
    while(*(string) != '\0')
        printf("%c", *(string+1));

    return 0;
}