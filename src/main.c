#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "threadpool.h"


int main(int argc, char *argv[]) {

    threadpool_t pool;
    threadpool_init(&pool);
    int* one = malloc(sizeof(int));
    int* two = malloc(sizeof(int));
    *one = 1;
    *two = 2;
    threadpool_add_task(&pool, example_task, one);
    threadpool_add_task(&pool, example_task, two);

    sleep(5);

    threadpool_destroy(&pool);
    return 0;
}