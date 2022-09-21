#include <stdio.h>

int main()
{
    FILE *fi = NULL, *fo = NULL;
    int i = 0;

    fi = fopen("SUBSET.INP", "r");
    if (fi != NULL)
    {
        int n = 0, k = 0;
        fscanf(fi, "%d %d", &n, &k);
        fclose(fi);
        if (1 <= k && k <= n && n <= 30)
        {
            fo = fopen("SUBSET.OUT", "w");
            int x[n + 1];

            // Khởi tạo cấu hình ban đầu
            for (i = 1; i <= k; i++)
            {
                x[i] = i;
            }

            do
            {
                // Xuất cấu hình hiện tại ra file
                fprintf(fo, "{");
                for (i = 1; i < k; i++)
                {
                    fprintf(fo, "%d, ", x[i]);
                }
                fprintf(fo, "%d}\n", x[k]);

                // Sinh cấu hình kế tiếp
                i = k;
                while (i > 0 && x[i] == n - k + i)
                {
                    i--;
                }
                if (i > 0) // Khi chưa gặp cấu hình cuối cùng
                {
                    x[i] = x[i] + 1;
                    for (int j = i + 1; j <= k; j++)
                    {
                        x[j] = x[j - 1] + 1;
                    }
                }
            } while (i != 0); // Đã gặp cấu hình cuối cùng
            fclose(fo);
        }
    }
    return 0;
}