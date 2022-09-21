#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    FILE *fi = NULL, *fo = NULL;
    int n = 0, k = 0, i = 0, start = 0, end = 0;

    fi = fopen("PERMUTE.INP", "r");
    if (fi != NULL)
    {
        fscanf(fi, "%d", &n);
        fclose(fi);
        if (n > 0 && n <= 12)
        {
            fo = fopen("PERMUTE.OUT", "w");

            // Khởi tạo cấu hình đầu tiên
            int x[n + 1];
            for (i = 1; i <= n; i++)
            {
                x[i] = i;
            }

            do
            {
                // Xuất cấu hình hiện tại ra file
                for (i = 1; i <= n; i++)
                {
                    fprintf(fo, "%d ", x[i]);
                }
                fprintf(fo, "\n");

                // Sinh cấu hình kế tiếp
                i = n - 1;
                while (i > 0 && x[i] > x[i + 1])
                {
                    i--;
                }
                if (i > 0) // Nếu chưa gặp cấu hình cuối cùng
                {
                    k = n;
                    while (x[k] < x[i])
                    {
                        k--;
                    }
                    swap(&x[i], &x[k]);
                    start = i + 1;
                    end = n;
                    while (start < end)
                    {
                        swap(&x[start], &x[end]);
                        start++;
                        end--;
                    }
                }

            } while (i != 0); // Đã gặp cấu hình cuối

            fclose(fo);
        }
    }
    return 0;
}