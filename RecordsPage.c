#include <stdio.h>
#define MAX 5
int main()
{
    int records[MAX], n, i;
    printf("Enter number of records: ");
    scanf("%d", &n);
    printf("Enter records:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &records[i]);
    printf("Records in the file:\n");
    for (i = 0; i < n; i++)
        printf("%d ", records[i]);
    printf("\nEnter record number to access: ");
    int recordNum;
    scanf("%d", &recordNum);
    if (recordNum <= n)
    {
        printf("Accessing record: %d\n", records[recordNum - 1]);
    }
    else
    {
        printf("Invalid record number\n");
    }
    return 0;
}