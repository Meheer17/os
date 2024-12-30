#include <stdio.h>
#define MF 3
void pf(int f[])
{
    for (int i = 0; i < MF; i++)
        printf(f[i] == -1 ? "- " : " %d ", f[i]);
    printf("\n");
}
int main()
{
    int f[MF] = {-1, -1, -1}, pF = 0;
    int r[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(r) / sizeof(r[0]);
    printf("Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", r[i]);
    printf("\n\nPage Replacement Order:\n");
    for (int i = 0; i < n; i++)
    {
        int p = r[i], fnd = 0;
        for (int j = 0; j < MF; j++)
            if (f[j] == p)
            {
                fnd = 1;
                break;
            }
        if (!fnd)
        {
            printf("Page %d-> ", p);
            int op = -1, maxDist = 0;
            for (int j = 0; j < MF; j++)
            {
                int dist = 0;
                for (int k = i + 1; k < n; k++)
                    if (r[k] == f[j])
                        break;
                    else
                        dist++;
                if (dist > maxDist)
                {
                    maxDist = dist;
                    op = j;
                }
            }
            f[op] = p;
            pf(f);
            pF++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pF);
    return 0;
}