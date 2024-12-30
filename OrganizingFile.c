#include <stdio.h>
#include <dirent.h>
int main()
{
    DIR *dir = opendir(".");
    if (!dir)
    {
        printf("Failed to open directory\n");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)))
        printf("%s\n", entry->d_name);
    closedir(dir);
    return 0;
}