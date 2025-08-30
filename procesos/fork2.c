#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    fork();
    fork();

    printf("pid-%d\n", getpid());

    sleep(5);

    return 0;
}