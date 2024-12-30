#include <stdio.h>
int main()
{
    FILE *file = fopen("example.txt", "w+");
    if (file == NULL)
        return 1;
    fprintf(file, "Hello, World,\nThis is C file management example.\n");
    rewind(file);
    char buffer[100];
    while (fgets(buffer, 100, file))
        printf("%s", buffer);
    fclose(file);
    return 0;
}