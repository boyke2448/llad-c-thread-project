#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARR_SIZE 10
pthread_key_t key;

void* array_destructor(void *args) {
    int *arr = (int *)args;
    free(arr);
    printf("Array freed.\n");
    return NULL;
}

void* thread_function(void *args) {
    char *txt = (char *)args;
    printf("%s.\n", txt);
    int* arr = (int *)malloc(10 * sizeof(int));
    pthread_setspecific(key, arr);

    for(int i = 0; i < ARR_SIZE; i++) {
        arr[i] = i;
    }

    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d.\n", arr[i]);
    }

    return NULL;

}

int main() {
    pthread_t t1, t2;
    pthread_key_create(&key, (void *)array_destructor);

    pthread_create(&t1, NULL, thread_function, "t1" );
    pthread_create(&t2, NULL, thread_function, "t2" );

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_key_delete(key);

    return 0;
}