#include <stdio.h>
#define MAX 5
int main()
{
    int *indexBlock[MAX], fileBlocks[MAX], n, i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block addresses:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &fileBlocks[i]);
    for (i = 0; i < n; i++)
        indexBlock[i] = &fileBlocks[i];
    printf("Index Block Points to:\n");
    for (i = 0; i < n; i++)
        printf("Block %d-> Address %d\n", i + 1, *indexBlock[i]);
    return 0;
}