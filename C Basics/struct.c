#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
} timestamp;

typedef struct timestamp time;

timestamp add_timestamps(timestamp t1, timestamp t2) {
    timestamp sum = {t1.hour + t2.hour, t1.minute + t2.minute, t1.second + t2.second};
    return sum;
}

int main(int argc, char **argv) {
    if (argc != 7) {
        printf("Usage: <hour1> <minute1> <second1> <hour2> <minute2> <second2>\n");
        return 1;
    }
    timestamp t1= {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
    timestamp t2= {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
    timestamp sum = add_timestamps(t1, t2);
    printf("%d %d %d\n", sum.hour, sum.minute, sum.second);
    return 0;
}