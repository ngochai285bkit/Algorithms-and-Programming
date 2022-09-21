# BÀI 2. PHƯƠNG PHÁP SINH

Phương pháp sinh có thể áp dụng để giải bài toán liệt kê tổ hợp đặt ra nếu như hai điều kiện sau thoả mãn:

- Có thể xác định được một thứ tự trên tập các cấu hình tổ hợp cần liệt kê. Từ đó có thể biết đượccấu hình đầu tiên và cấu hình cuối cùng trong thứ tự đó.
- Xây dựng được thuật toán từ một cấu hình chưa phải cấu hình cuối, sinh ra được cấu hình kế tiếp nó.

Phương pháp sinh có thể mô tả như sau:

```text
〈Xây dựng cấu hình đầu tiên〉;
 repeat
    〈Đưa ra cấu hình đang có〉;
    〈Từ cấu hình đang có sinh ra cấu hình kế tiếp nếu còn〉;
 until〈hết cấu hình〉;
```

## Thứ tự từ điển

Trên các kiểu dữ liệu đơn giản chuẩn, người ta thường nói tới khái niệm thứ tự. Ví dụ trên kiểu số thì có quan hệ: 1 < 2; 2 < 3; 3 < 10; …, trên kiểu ký tự Char thì cũng có quan hệ 'A' < 'B'; 'C' < 'c'…

Xét quan hệ thứ tự toàn phần "nhỏ hơn hoặc bằng" ký hiệu "≤" trên một tập hợp S, là quan hệ hai ngôi thoả mãn bốn tính chất:

Với ∀a, b, c ∈ S

- Tính phổ biến: Hoặc là a ≤ b, hoặc b ≤ a;
- Tính phản xạ: a ≤ a
- Tính phản đối xứng: Nếu a ≤ b và b ≤ a thì bắt buộc a = b.
- Tính bắc cầu: Nếu có a ≤ b và b ≤ c thì a ≤ c.

Trong trường hợp a ≤ b và a ≠ b, ta dùng ký hiệu "<" cho gọn, (ta ngầm hiểu các ký hiệu như ≥, >, khỏi phải định nghĩa)

Ví dụ như quan hệ "≤" trên các số nguyên cũng như trên các kiểu vô hướng, liệt kê là quan hệ thứ tự toàn phần.

Trên các dãy hữu hạn, người ta cũng xác định một quan hệ thứ tự:

Xét a[1..n] và b[1..n] là hai dãy độ dài n, trên các phần tử của a và b đã có quan hệ thứ tự "≤". Khi đó a ≤ b nếu như

Hoặc a[i] = b[i] với ∀i: 1 ≤ i ≤ n.
Hoặc tồn tại một số nguyên dương k: 1 ≤ k < n để:
a[1] = b[1]
a[2] = b[2]
...
a[k-1] = b[k-1]
a[k] = b[k]
a[k+1] < b[k+1]

Trong trường hợp này, ta có thể viết a < b.
Thứ tự đó gọi là **thứ tự từ điển** trên các dãy độ dài n.

Khi độ dài hai dãy a và b không bằng nhau, người ta cũng xác định được thứ tự từ điển. Bằng cách thêm vào cuối dãy a hoặc dãy b những phần tử đặc biệt gọi là phần tử ∅ để độ dài của a và b bằng nhau, và coi những phần tử ∅ này nhỏ hơn tất cả các phần tử khác, ta lại đưa về xác định thứ tự từ điển của hai dãy cùng độ dài. Ví dụ:

〈1, 2, 3, 4〉 < 〈5, 6〉

〈a, b, c〉 < 〈a, b, c, d〉

'calculator' < 'computer'

## 2.1. SINH CÁC DÃY NHỊ PHÂN ĐỘ DÀI N

Một dãy nhị phân độ dài n là một dãy x[1..n] trong đó x[i] ∈ {0, 1} (∀i : 1 ≤ i ≤ n).

Dễ thấy: một dãy nhị phân x độ dài n là biểu diễn nhị phân của một giá trị nguyên p(x) nào đó nằm trong đoạn [0, $2^n-1$]. Số các dãy nhị phân độ dài n = số các số tự nhiên ∈ [0, $2^n-1$] = $2^n$.

Ta sẽ lập chương trình liệt kê các dãy nhị phân theo thứ tự từ điển có nghĩa là sẽ liệt kê lần lượt các dãy nhị phân biểu diễn các số nguyên theo thứ tự 0, 1, …, $2^n -1$.

Ví dụ: Khi n = 3, các dãy nhị phân độ dài 3 được liệt kê như sau:

|   |   |   |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| **p(x)** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| **x** | 000 | 001 | 010 | 011 | 100 | 101 | 110 | 111 |

Như vậy dãy đầu tiên sẽ là 00…0 và dãy cuối cùng sẽ là 11…1. Nhận xét rằng nếu dãy x = x[1..n] là dãy đang có và không phải dãy cuối cùng cần liệt kê thì dãy kế tiếp sẽ nhận được bằng cách cộng thêm 1 ( theo cơ số 2 có nhớ) vào dãy hiện tại.

Ví dụ khi n = 8:

| Dãy đang có | Sau khi cộng 1 |
|:-----------:|:--------------:|
| 10010000 | 10010001 |
| 10010111 | 10011000 |

Như vậy kỹ thuật sinh cấu hình kế tiếp từ cấu hình hiện tại có thể mô tả như sau:

> Xét từ cuối dãy về đầu (xét từ hàng đơn vị lên), tìm số 0 gặp đầu tiên
>
> - Nếu thấy thì thay số 0 đó bằng số 1 và đặt tất cả các phần tử phía sau vị trí đó bằng 0.
> - Nếu không thấy thì thì toàn dãy là số 1, đây là cấu hình cuối cùng

Dữ liệu vào (**Input**): nhập từ file văn bản BSTR.INP chứa số nguyên dương n ≤ 30

Kết quả ra (**Output**): ghi ra file văn bản BSTR.OUT các dãy nhị phân độ dài n.

| BSTR.INP | BSTR.OUT |
|:--------:|:--------:|
| 3 | 000 |
|   | 001 |
|   | 010 |
|   | 011 |
|   | 100 |
|   | 101 |
|   | 110 |
|   | 111 |

***Code Pascal***

```pascal
program Binary_Strings;
const
    InputFile = 'BSTR.INP';
    OutputFile = 'BSTR.OUT';
    max = 30;
var
    x: array[1..max] of Integer;
    n, i: Integer;
    f: Text;
begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n);
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
    FillChar(x, SizeOf(x), 0); {Cấu hình ban đầu x=00..0}
    repeat {Thuật toán sinh}
        for i := 1 to n do Write(f, x[i]); {In ra cấu hình hiện tại}
        WriteLn(f);
        i := n; {x[i] là phần tử cuối dãy, lùi dần i cho tới khi gặp số 0 hoặc khi i = 0 thì dừng}
        while (i > 0) and (x[i] = 1) do Dec(i);
        if i > 0 then {Chưa gặp phải cấu hình 11…1}
        begin
            x[i] := 1; {Thay x[i] bằng số 1}
            FillChar(x[i + 1], (n - i) * SizeOf(x[1]), 0); {Đặt x[i+1] = x[i+2] = … = x[n] := 0}
        end;
    until i = 0; {Đã hết cấu hình}
    Close(f);
end.
```

***Code C***

```c
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
```
