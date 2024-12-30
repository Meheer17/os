#include <stdio.h>
int main()
{
    int n = 3, bt[] = {5, 8, 12}, wt[3] = {0}, tat[3], i;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
    printf("P\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}