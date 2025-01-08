#include <stdio.h>
#include <pthread.h>
#define N 5
pthread_mutex_t cks[N];

int main()
{
    pthread_t t[N];
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&cks[i], NULL);
    for (int i = 0; i < N; i++)
    {
        printf("Philosopher %d is thinking.\n", i);
        pthread_mutex_lock(&cks[i]);
        pthread_mutex_lock(&cks[(i + 1) % N]);
        printf("Philosopher %d is eating.\n", i);
        pthread_mutex_unlock(&cks[i]);
        pthread_mutex_unlock(&cks[(i + 1) % N]);
    }
    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&cks[i]);
    return 0;
}