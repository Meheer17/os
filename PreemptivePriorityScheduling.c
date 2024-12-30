#include <stdio.h>
int main()
{
    int bt[] = {6, 2, 8, 3}, pr[] = {1, 4, 2, 3}, wt[4] = {0}, tat[4], n = 4, i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
    for (i = 0; i < n; i++)
        printf("P%d Pr:%d BT:%d WT:%d TAT:%d\n", i + 1, pr[i], bt[i], wt[i], tat[i]);
}