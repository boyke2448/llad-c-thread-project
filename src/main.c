#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 10

int counter = 0;
pthread_mutex_t lock;

void *thread_function(void *args) {
    
    pthread_mutex_lock(&lock);
    
    for(int i=0; i < 100000; i++) {
        counter++;
    }
    
    pthread_mutex_unlock(&lock);
    
    printf("Counter is %d\n", counter);
}

int main(int argc, char *argv[]) {
    
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_init(&lock, NULL);
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        if(pthread_create(&threads[i], NULL, thread_function, NULL)) {

            printf("Thread %d created.\n", i);
            
        }
    }

    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}