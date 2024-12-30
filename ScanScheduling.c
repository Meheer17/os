#include <stdio.h>
#include <stdlib.h>
int main()
{
    int req[] = {10, 20, 30, 40, 50, 90, 15}, head = 50, i, Time = 0;
    int max = 90;
    int min = 0;
    for (i = 0; i < 7; i++)
    {
        Time += abs(head - req[i]);
        head = req[i];
    }
    Time += abs(head - max);
    head = max;
    Time += abs(head - min);
    head = min;
    for (i = 0; i < 7; i++)
    {
        Time += abs(head - req[i]);
        head = req[i];
    }
    printf("Total Seek Time: %d\n", Time);
    return 0;
}