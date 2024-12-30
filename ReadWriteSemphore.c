#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t m, wb;
int d = 0, rc = 0;
void *reader(void *a)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&m);
        rc++;
        if (rc == 1)
            sem_wait(&wb);
        sem_post(&m);
        printf("R: %d\n", d);
        sem_wait(&m);
        rc--;
        if (rc == 0)
            sem_post(&wb);
        sem_post(&m);
    }
    return NULL;
}
void *writer(void *a)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&wb);
        d++;
        printf("W: %d\n", d);
        sem_post(&wb);
    }
    return NULL;
}
int main()
{
    pthread_t r, w;
    sem_init(&m, 0, 1);
    sem_init(&wb, 0, 1);
    pthread_create(&r, NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);
    pthread_join(r, NULL);
    pthread_join(w, NULL);
    sem_destroy(&m);
    sem_destroy(&wb);
    return 0;
}