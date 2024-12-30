#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main()
{
    if (chmod("file.txt", 0666) == 0)
        printf("Permissions changed.\n");
    else
        perror("chmod");
    return 0;
}