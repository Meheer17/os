#include <stdio.h>
#include <stdlib.h>
typedef struct Block
{
    int data;
    struct Block *next;
} Block;
int main()
{
    int n, data;
    Block *head = NULL, *temp, *tail;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for block %d: ", i + 1);
        scanf("%d", &data);
        temp = (Block *)malloc(sizeof(Block));
        temp->data = data;
        temp->next = NULL;
        if (!head)
            head = temp;
        else
            tail->next = temp;
        tail = temp;
    }
    printf("File Blocks (Linked List):\n");
    for (temp = head; temp; temp = temp->next)
        printf("Block Data: %d\n", temp->data);
    return 0;
}