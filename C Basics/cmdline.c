#include <stdio.h>
#include <stdlib.h>

int print_help_and_exit(char **argv) {
    printf("Usage: %s <double 1> <double 2> <double 3>\n", argv[0]);
    exit(-1);
}

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    double product;

    if(argc != 4)
        print_help_and_exit(argv);
    
    product = atof(argv[1]) * atof(argv[2]) * atof(argv[3]);

    printf("%f\n", product);

    return 0;
}