#include <stdio.h>
int main()
{
    int bt[] = {6, 2, 8, 3}, wt[4] = {0}, tat[4], rem_bt[4], n = 4, t = 2, time = 0, i;
    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    for (i = 0; i < n; i++)
    {
        if (rem_bt[i] > t)
        {
            rem_bt[i] -= t;
            time += t;
        }
        else
        {
            time += rem_bt[i];
            wt[i] = time - bt[i];
            rem_bt[i] = 0;
        }
    }
    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
    for (i = 0; i < n; i++)
        printf("P%d BT:%d WT:%d TAT:%d\n", i + 1, bt[i], wt[i], tat[i]);
    return 0;
}