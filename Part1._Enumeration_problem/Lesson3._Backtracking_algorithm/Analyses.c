#include <stdio.h>

int x[31], t[31], n;
FILE *fi, *fo;

void printResult(int k)
{
    fprintf(fo, "%d = ", n);
    for (int i = 1; i < k; i++)
    {
        fprintf(fo, "%d+", x[i]);
    }
    fprintf(fo, "%d\n", x[k]);
}

void Try(int i)
{
    for (int j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++)
    {
        x[i] = j;
        t[i] = t[i - 1] + j;
        Try(i + 1);
    }
    x[i] = n - t[i - 1];
    printResult(i);
}

int main()
{
    x[0] = 1, t[0] = 0;
    fi = fopen("ANALYSE.INP", "r");
    if (fi != NULL)
    {
        fscanf(fi, "%d", &n);
        if (n > 0 && n <= 30)
        {
            fo = fopen("ANALYSE.OUT", "w");
            Try(1);
            fclose(fo);
        }
        fclose(fi);
    }
    return 0;
}