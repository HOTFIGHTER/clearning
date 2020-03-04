//
// Created by xmly on 2019/12/8.
//

#include <printf.h>
#include <zconf.h>
#include <signal.h>
#include <sys/wait.h>

static void sig_int(int);

int main() {
    pid_t pid;
    int status;
    /**打印进程号*/
    printf("hello world from process ID %d\n", getpid());
    printf("uid =%d,gid=%d\n", getuid(), getgid());
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        printf("signal error");
    }
    if ((pid = fork()) < 0) {
        printf("fork error");
    }
    if (waitpid(pid, &status, 0) < 0) {
        printf("waidpid error");
    }
    _exit(0);
}


void sig_int(int signo) {
    printf("interrupt\n");
}