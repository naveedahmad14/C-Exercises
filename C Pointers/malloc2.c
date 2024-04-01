#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    int x = atoi(argv[1]); 
    int y = atoi(argv[2]); 
    int **array;
    array = malloc(x * sizeof(int *));
    if(array == NULL) return -1;
    for(int i=0; i<x; i++) {
        array[i] = malloc(y * sizeof(int));
        if(array[i] == NULL) return -1;
    }
    for (int i = 0; i < x; i++) {
        if (i > 0) printf("\n");
        for (int j = 0; j < y; j++) {
            array[i][j] = i * y + j;
            printf("%d ", array[i][j]);
        }
    }
    printf("\n");

    for(int i=0; i<x; i++)
        free(array[i]);
    free(array);
}