#include <stdio.h>
int main()
{
    FILE *file = fopen("C:/Users/itssk/OneDrive/Desktop/os/example.txt", "w");
    if (!file)
    {
        printf("Error creating file.\n");
        return 1;
    }
    fprintf(file, "This is an example file content.");
    printf("File created successfully.\n");
}