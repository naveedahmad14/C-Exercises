#include <stdio.h>
#include <stdlib.h>

void even_or_odd(int num){
    if (num % 2 == 0) {
        printf("%d is even\n", num);
    } 
    else{
        printf("%d is odd\n", num);
    }
}

int print_help_and_exit(char **argv) {
    printf("Cannot enter more than 10 numbers");
    exit(-1);
}

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    int arr[argc-1]; //index starts at 0 so length - 1

    if (argc > 11) {
        print_help_and_exit(argv);
    };

    for(int i=1; i<argc; i++) { //start at 1 to ensure we have correct length
        arr[i-1] = atoi(argv[i]); 
    }

    for (int i = 0; i < argc - 1; i++) { 
        even_or_odd(arr[i]);
    }
    return 0;
}