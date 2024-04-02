#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // needed for sleep and usleep
#include <sys/time.h> // needed for gettimeofday

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);
    struct timeval tv, start, stop, elapsed;

    gettimeofday(&tv, NULL);

    gettimeofday(&start, NULL);
    sleep(num);
    gettimeofday(&stop, NULL);

    timersub(&stop, &start, &elapsed);

    printf("sleep duration: %lu.%06d seconds\n", elapsed.tv_sec, elapsed.tv_usec);
    return 0;
}