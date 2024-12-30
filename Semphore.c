#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define BUF_SIZE 10
int buf[BUF_SIZE], in = 0, out = 0;
sem_t empty, full, mutex;
void *prod(void *arg)
{
    for (int i = 0; i < 20; i++)
    {
        int item = rand() % 100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buf[in] = item;
        in = (in + 1) % BUF_SIZE;
        printf("Produced: %d\n", item);
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void *cons(void *arg)
{
    for (int i = 0; i < 20; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buf[out];
        out = (out + 1) % BUF_SIZE;
        printf("Consumed: %d\n", item);
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}
int main()
{
    pthread_t p, c;
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}