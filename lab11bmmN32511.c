#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

char wordToSearch[100];

int containsWord(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 0;
    }

    int foundWord = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, word) != NULL) {
            foundWord = 1;
            break;
        }
    }

    fclose(file);
    return foundWord;
}

int printFile(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    (void)sb;
    (void)ftwbuf;

    if (typeflag == FTW_F && containsWord(fpath, wordToSearch)) {
        printf("%s\n", fpath);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        fprintf(stdout, "Usage: %s [directory path] [word to search]\n", argv[0]);
        fprintf(stdout, "Options:\n -h  Show help\n -v  Show version\n");
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-v") == 0) {
        fprintf(stdout, "Бехит Мохаммед Махмуд | группа N32511 | version 1.0\n");
        return 0;
    }

    if (argc < 3) {
        fprintf(stderr, "Error: missing arguments.\nUsage: %s [directory path] [word to search]\n", argv[0]);
        return 1;
    }

    const char *basePath = argv[1];
    strncpy(wordToSearch, argv[2], sizeof(wordToSearch) - 1);
    wordToSearch[sizeof(wordToSearch) - 1] = '\0';

    int flags = FTW_PHYS;
    int nopenfd = 20;

    if (nftw(basePath, printFile, nopenfd, flags) == -1) {
        perror("nftw");
        return 1;
    }

    return 0;
}
