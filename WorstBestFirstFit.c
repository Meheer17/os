#include <stdio.h>
int main()
{
    int b[] = {10, 20, 30, 40}, p[] = {1, 2, 3, 4}, i, j;
    for (i = 0; i < 4; i++)
    {
        int w = -1;
        for (j = 0; j < 4; j++)
            if (b[j] >= p[i] && (w == -1 || b[j] > b[w]))
                w = j;
        if (w != -1)
        {
            b[w] = 0;
            printf("p%d->b%d\n", i + 1, w + 1);
        }
        else
            printf("p%d->not allowed", i + 1);
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int b[] = {10, 20, 30, 40}, p[] = {1, 2, 3, 4}, i, j;
    for (i = 0; i < 4; i++)
    {
        int w = -1;
        for (j = 0; j < 4; j++)
            if (b[j] >= p[i] && (w == -1 || b[j] < b[w]))
                w = j;
        if (w != -1)
        {
            b[w] = 0;
            printf("p%d->b%d\n", i + 1, w + 1);
        }
        else
            printf("p%d->not allowed", i + 1);
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int b[] = {10, 20, 30, 40}, p[] = {1, 2, 3, 4}, i, j;
    for (i = 0; i < 4; i++)
    {
        int w = -1;
        for (j = 0; j < 4; j++)
            if (b[j] >= p[i])
            {
                w = j;
                break;
            }
        if (w != -1)
        {
            b[w] = 0;
            printf("p%d->b%d\n", i + 1, w + 1);
        }
        else
            printf("p%d->not allowed", i + 1);
    }
    return 0;
}