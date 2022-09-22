#include <stdio.h>

int n = 0, k = 0;
int x[31];
FILE *fi = NULL, *fo = NULL;

void printResult()
{
    fprintf(fo, "{");
    for (int i = 1; i < k; i++)
    {
        fprintf(fo, "%d, ", x[i]);
    }
    fprintf(fo, "%d}\n", x[k]);
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            printResult();
        }
        else
        {
            Try(i + 1);
        }
    }
}

int main()
{
    fi = fopen("SUBSET.INP", "r");
    if (fi != NULL)
    {
        fscanf(fi, "%d %d", &n, &k);
        fclose(fi);
        if (k > 0 && k <= n && n <= 30)
        {
            fo = fopen("SUBSET.OUT", "w");
            x[0] = 0;
            Try(1);
            fclose(fo);
        }
    }
    return 0;
}