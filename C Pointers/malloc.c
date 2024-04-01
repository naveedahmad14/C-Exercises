#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    int *arr; 
    int size = argc - 1;

    arr = malloc(size * sizeof(int));
    if(arr == NULL) return -1;

    for(int i=1; i<argc; i++) { //start at 1 to ensure we have correct length
        arr[i-1] = atoi(argv[i]); 
    }

    qsort(arr, size, sizeof(int), compare);

    for (int i = 0; i < size; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}