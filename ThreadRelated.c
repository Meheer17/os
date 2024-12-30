#include <pthread.h>
#include <stdio.h>
void *func(void *arg)
{
    printf("Inside the thread\n");
    pthread_exit(NULL);
}
int main()
{
    pthread_t ptid;
    pthread_create(&ptid, NULL, func, NULL);
    printf("This line may be printed before thread terminates\n");
    pthread_join(ptid, NULL);
    printf("This line will be printed after thread ends\n");
    return 0;
}