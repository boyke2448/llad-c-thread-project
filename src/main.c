#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 10

sem_t semaphore;


void *publisher(void *arg) {
    sem_post(&semaphore);
    printf("Published.\n");
    return NULL;
}

void *subscriber(void *arg){
    sem_wait(&semaphore);
    printf("Subscriber read.\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    
    pthread_t pub, sub;
    sem_init(&semaphore,0,0);

    pthread_create(&pub, NULL, publisher, NULL);
    pthread_create(&sub, NULL, subscriber, NULL);
    pthread_join(pub, NULL);
    pthread_join(sub, NULL);
    sem_destroy(&semaphore);

    return 0;
}