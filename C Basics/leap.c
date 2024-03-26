#include <stdio.h>
#include <stdlib.h>

int print_help_and_exit(char **argv) {
    printf("Usage: %s <int 1>\n", argv[0]);
    exit(-1);
}

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    int year = atoi(argv[1]);
    
    if(argc != 2)
        print_help_and_exit(argv);
    
    if (year % 4 != 0){
        printf("%d is a common year\n", year);
    }
    else if (year % 100 != 0) {
        printf("%d is a common year\n", year);
    }
    else if (year % 400 != 0) {
        printf("%d is a common year\n", year);
    }
    else{
        printf("%d is a common year\n", year);
    }

    return 0;
}