#ifndef THREADPOOL_H
#define THREADPOOL_H

#define THREADS 8
#define QUEUE_SIZE 100

#include <pthread.h>

typedef struct {
    void (*fn)(void *args);
    void* args;
} task_t;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t notify;
    pthread_t threads[QUEUE_SIZE];
    task_t tasks[THREADS];
    int queued;
    int queue_front;
    int queue_back;
    int stop;
} threadpool_t;

void threadpool_init(threadpool_t *pool);
void threadpool_destroy(threadpool_t* pool);
void threadpool_add_task(threadpool_t* pool, void (*function)(void*), void* arg);
void example_task(void* arg);


#endif // THREADPOOL_H