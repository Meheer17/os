#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
int main()
{
    int shmid;
    char message[] = "Hello, Shared Memory!";
    char shm[100];
    shmid = shmget(IPC_PRIVATE, 100, 0666 | IPC_CREAT);
    if (shmid == -1)
        return 1;
    shmat(shmid, shm, 0);
    for (int i = 0; message[i] != '\0'; i++)
    {
        shm[i] = message[i];
    }
    printf("Message read from shared memory: %s\n", shm);
    shmdt(shm);
    return 0;
}