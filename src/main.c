#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Hello from the thread!\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    int q = 0;
    int *p = &q;
    *p += 10;
    printf("Value: %d\n", *p);
    return 0;
}