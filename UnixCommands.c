#include <stdio.h>
#include <string.h>
int main()
{
    char fn[10], pat[10], temp[200];
    FILE *fp;
    printf("\nEnter file name: ");
    scanf("%s", fn);
    printf("Enter the pattern: ");
    scanf("%s", pat);
    fp = fopen(fn, "r");
    while (fgets(temp, sizeof(temp), fp))
    {
        if (strstr(temp, pat))
            printf("%s", temp);
    }
    fclose(fp);
    return 0;
}