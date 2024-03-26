#include <stdio.h>
int main() {
    int so_int = sizeof(int);
    int so_double = sizeof(double);
    int so_ulonglongint = sizeof(unsigned long long int);
    int so_all = so_double * so_int * so_ulonglongint;
    printf("Size of int: %d bytes \n", so_int);
    printf("Size of double: %d bytes \n", so_double);
    printf("Size of unsigned long long int: %d bytes \n", so_ulonglongint);
    printf("Size of all 3 multipled: %d bytes \n", so_all);
}