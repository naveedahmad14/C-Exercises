#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc == 2) {
        int a = atoi(argv[1]);

        printf("Variable contains %d and is located @%p\n", a, &a);
    }
    return 0;
}