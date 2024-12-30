#include <stdio.h>
int block[10] = {100, 500, 200, 300, 600, 350, 50, 800, 150, 450};
int process[5] = {212, 417, 112, 426, 500};
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (block[j] >= process[i])
            {
                block[j] -= process[i];
                printf("Process %d fits in Block %d\n", i + 1, j + 1);
                break;
            }
        }
    }
    return 0;
}