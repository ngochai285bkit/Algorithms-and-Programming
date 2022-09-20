#include <stdio.h>

int main()
{
    FILE *fi = fopen("BSTR.INP", "r");
    if (fi != NULL)
    {
        int n = 0;
        fscanf(fi, "%d", &n);
        fclose(fi);
        if (n > 0 && n <= 30)
        {
            FILE *fo = fopen("BSTR.OUT", "w");
            int i = 0;
            int bit[n + 1];

            // Khởi tạo cấu hình đầu tiên
            for (i = 1; i <= n; i++)
            {
                bit[i] = 0;
            }

            do
            {
                // Xuất cấu hình hiện tại ra file
                for (i = 1; i <= n; i++)
                {
                    fprintf(fo, "%d", bit[i]);
                }
                fprintf(fo, "\n");

                // Sinh cấu hình kế tiếp
                i = n;
                while (i > 0 && bit[i] == 1)
                {
                    i--;
                }
                if (i > 0)
                {
                    bit[i] = 1;
                    for (int j = i + 1; j <= n; j++)
                    {
                        bit[j] = 0;
                    }
                }

            } while (i != 0); // Gặp cấu hình cuối cùng

            fclose(fo);
        }
    }
    return 0;
}