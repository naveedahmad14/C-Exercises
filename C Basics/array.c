#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv) { // 'char ** argv' means 'char argv[][]'
    int arr[argc-1]; //index starts at 0 so length - 1
    
    for(int i=1; i<argc; i++) { //start at 1 to ensure we have correct length
        arr[i-1] = atoi(argv[i]); 
        /*         
        how this works since i get confused:
        ./arg 5 3 6 6 
        arr[0] = arg[1]
        ... 
        array[3] = arg[4]

        more complex approach to start loop at 0:
        for(int i=0; i<argc-1; i++) {
            arr[i] = atoi(argv[i+1]); 
        */
    }

    int length = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, length, sizeof(int), compare);

    for (int i = 0; i < length; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}