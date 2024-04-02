#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1000

void replaceWord(char *str, const char *oldWord, const char *newWord) {
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int oldWordLen = strlen(oldWord);

    while ((pos = strstr(str, oldWord)) != NULL) {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + oldWordLen);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <word_to_replace>\n", argv[0]);
        return 1;
    }

    char *f = argv[1];
    char *w = argv[2];

    int fd1 = open(f, O_RDONLY);
    if (fd1 == -1) {
        printf("Error opening input file\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytesRead = read(fd1, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        printf("Error reading input file\n");
        close(fd1);
        return 1;
    }

    close(fd1);
    replaceWord(buffer, w, "");
    
    // Construct the output file name with "-processed" appended
    char new_f[strlen(f) + strlen("-processed") + 1]; // +1 for null terminator
    sprintf(new_f, "%s-processed", f);

    int fd2 = open(new_f, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd2 == -1) {
        printf("Error opening output file\n");
        return 1;
    }

    int bytesWritten = write(fd2, buffer, strlen(buffer));
    if (bytesWritten == -1) {
        printf("Error writing to output file\n");
        close(fd2);
        return 1;
    }

    close(fd2);
    return 0;
}