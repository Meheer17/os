#include <stdio.h>
int main()
{
    FILE *s = fopen("src.txt", "r"), *d = fopen("dst.txt", "w");
    char c;
    while ((c = fgetc(s)) != EOF)
        fputc(c, d);
    fclose(s), fclose(d);
    
}