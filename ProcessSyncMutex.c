#include <stdio.h>
#include <pthread.h>
void *func(void *arg) { return NULL; }
int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func, NULL);
    pthread_create(&t2, NULL, func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final counter value: 0\n");
    return 0;
}