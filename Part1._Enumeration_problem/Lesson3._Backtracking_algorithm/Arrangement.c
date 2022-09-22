#include <stdio.h>
#include <stdbool.h>

int n = 0, k = 0;
int x[21];
bool c[21];
FILE *fi = NULL, *fo = NULL;

void printResult() // Xuất cấu hình hiện tại
{
    for (int i = 1; i <= k; i++)
    {
        fprintf(fo, "%d ", x[i]);
    }
    fprintf(fo, "\n");
}

void Try(int i) // Thử các cách chọn cho x[i]
{
    for (int j = 1; j <= n; j++)
    {
        if (c[j]) // Chỉ xét những giá trị j còn tự do
        {
            x[i] = j;
            if (i == k) // Nếu chọn đến được x[k] thì chỉ cần in kết quả
            {
                printResult();
            }
            else
            {
                c[j] = false; // Đánh dấu j đã được chọn
                Try(i + 1);   // Xét những giá trị j còn tự do để gán cho x[i+1]
                c[j] = true;  // Bỏ đánh dấu: j lại là tự do, bởi sắp tới sẽ thử một cách chọn khác của x[i]
            }
        }
    }
}

int main()
{
    fi = fopen("ARRANGES.INP", "r");
    if (fi != NULL)
    {
        fscanf(fi, "%d %d", &n, &k);
        fclose(fi);
        if (k > 0 && k <= n && n <= 20)
        {
            fo = fopen("ARRANGES.OUT", "w");
            for (int i = 1; i <= n; i++)
            {
                c[i] = true; // Đánh dấu tất cả các số đều chưa được chọn
            }
            Try(1); // Thử các cách chọn cho x[1]
            fclose(fo);
        }
    }
    return 0;
}