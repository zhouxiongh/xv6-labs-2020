#include "kernel/types.h"
#include "user/user.h"
#include "kernel/syscall.h"

int main(int argc, char *argv[])
{
    if(argc < 2){
        fprintf(2, "Usage: echo []...\n");
        exit(1);
    }
    int time;
    time = atoi(argv[1]);
    sleep(time);
    exit(0);
}