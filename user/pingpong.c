#include "kernel/types.h"
#include "user/user.h"
#include "kernel/syscall.h"

int main(int argc, char *argv[])
{
    char buf[512];
    int p[2];
    pipe(p);
    int pid;
    pid = fork();
    if (pid > 0) {
        write(p[1], "ping", strlen("ping"));
        pid = wait(&pid);
        read(p[0], buf, strlen("pong"));

        printf("%d: received %s\n", getpid(), buf);
    } else if (pid == 0) {
        read(p[0], buf, strlen("ping"));

        printf("%d: received %s\n", getpid(), buf);

        write(p[1], "pong", strlen("pong"));

        exit(0);
    } else {
        printf("fork error\n");
    }
    exit(0);
}