#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd;
    char buf[100];
    if ((fd = creat("sample.txt", S_IRWXU)) == -1)
    {
        perror("create");
        exit(1);
    }
    close(fd);
    if ((fd = open("sample.txt", O_WRONLY | O_APPEND)) == -1)
    {
        perror("open");
        exit(1);
    }
    write(fd, "Hello, World!\n", 14);
    close(fd);
    if ((fd = open("sample.txt", O_RDONLY)) == -1)
    {
        perror("open");
        exit(1);
    }
    int bytesRead = read(fd, buf, sizeof(buf));
    close(fd);
    write(STDOUT_FILENO, buf, bytesRead);
    remove("sample.txt");
    return 0;
}