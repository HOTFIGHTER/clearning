//
// Created by xmly on 2019/12/8.
//
#include <dirent.h>
#include <sys/types.h>
#include <cstdio>
#include <zconf.h>

#define BUFFSIZE  8192

void readIO();

int main(int argc, char *argv[]) {
    DIR *dp;
    dirent *dirp;
    if ((dp = opendir(argv[1])) == NULL) {
        stderr;
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    readIO();
}


void readIO() {
    int n;
    char buf[BUFFSIZE];
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            stderr;
        }
    }
    if (n < 0) {
        stderr;
    }
    _exit(0);
}
