#include <stdio.h>

int n = 0;
int x[31];
FILE *fi = NULL, *fo = NULL;

void printResult() // Xuất cấu hình hiện tại ra file
{
    for (int i = 1; i <= n; i++)
    {
        fprintf(fo, "%d", x[i]);
    }
    fprintf(fo, "\n");
}

void Try(int i) // Thử cách chọn cho x[i]
{
    for (int j = 0; j <= 1; j++) // Xét lần lượt các giá trị có thể gán cho x[i]
    {
        x[i] = j;   // Thử đặt x[i]
        if (i == n) // Nếu i = n (đã tìm được phần tử cuối cùng của cấu hình) thì in kết quả
        {
            printResult();
        }
        else // Nếu i chưa phải phần tử cuối cùng, thì tìm tiếp x[i+1]
        {
            Try(i + 1);
        }
    }
}

int main()
{
    fi = fopen("BSTR.INP", "r");
    if (fi != NULL)
    {
        fscanf(fi, "%d", &n);
        fclose(fi);
        if (n > 0 && n <= 30)
        {
            fo = fopen("BSTR.OUT", "w");
            Try(1); // Thử cách chọn cho x[1]
            fclose(fo);
        }
    }
    return 0;
}