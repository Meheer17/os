#include <stdio.h>
#define MAX 100
int main()
{
    int f[MAX], p[MAX], n_f, n_p, cnt = 0, faults = 0, front = 0;
    printf("Enter number of frames: ");
    scanf("%d", &n_f);
    printf("Enter number of pages: ");
    scanf("%d", &n_p);
    printf("Enter reference string: ");
    for (int i = 0; i < n_p; ++i)
        scanf("%d", &p[i]);
    for (int i = 0; i < n_f; ++i)
        f[i] = -1;
    for (int i = 0; i < n_p; ++i)
    {
        int flag = 0;
        for (int j = 0; j < n_f; ++j)
            if (f[j] == p[i])
                flag = 1;
        if (!flag)
        {
            f[front] = p[i];
            front = (front + 1) % n_f;
            faults++;
        }
        for (int j = 0; j < n_f; ++j)
            printf("%d\t", f[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}