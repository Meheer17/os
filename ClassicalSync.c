#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 10, x = 0;
int main()
{
    int n;
    while (1)
    {
        printf("\n1. Produce\n2. Consume\n3. Exit\nChoice: ");
        scanf("%d", &n);
        if (n == 1 && empty > 0)
            printf("Produced item %d\n", ++x), full++, empty--;
        else if (n == 2 && full > 0)
            printf("Consumed item %d\n", x--), full--, empty++;
        else if (n == 3)
            break;
        else
            printf("Buffer %s!\n", empty ? "is full" : "is empty");
    }
    return 0;
}