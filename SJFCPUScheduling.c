#include <stdio.h>
int main()
{
    int bt[] = {6, 2, 8, 3}, wt[] = {0, 0, 0, 0}, tat[4], n = 4, i, j, temp;
    for (i = 0; i < n; i++) // Sort burst times
        for (j = i + 1; j < n; j++)
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
    for (i = 0; i < n; i++)
        printf("BT: %d WT: %d TAT: %d\n", bt[i], wt[i], tat[i]);
}