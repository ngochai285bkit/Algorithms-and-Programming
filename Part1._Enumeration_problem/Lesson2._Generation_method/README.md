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

- Xét từ cuối dãy về đầu (xét từ hàng đơn vị lên), tìm số 0 gặp đầu tiên
- Nếu thấy thì thay số 0 đó bằng số 1 và đặt tất cả các phần tử phía sau vị trí đó bằng 0.
- Nếu không thấy thì thì toàn dãy là số 1, đây là cấu hình cuối cùng

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

## 2.2. LIỆT KÊ CÁC TẬP CON K PHẦN TỬ

Ta sẽ lập chương trình liệt kê các tập con k phần tử của tập {1, 2, …, n} theo thứ tự từ điền.

Ví dụ: với n = 5, k = 3, ta phải liệt kê đủ 10 tập con:

> 1.{1, 2, 3} , 2.{1, 2, 4} , 3.{1, 2, 5} , 4.{1, 3, 4} , 5.{1, 3, 5}
>
> 6.{1, 4, 5} , 7.{2, 3, 4} , 8.{2, 3, 5} , 9.{2, 4, 5} , 10.{3, 4, 5}

Như vậy tập con đầu tiên (cấu hình khởi tạo) là {1, 2, …, k}. Cấu hình kết thúc là {n - k + 1, n - k + 2, …, n}.

Nhận xét: Ta sẽ in ra tập con bằng cách in ra lần lượt các phần tử của nó theo thứ tự tăng dần. Biểu diễn mỗi tập con là một dãy x[1..k] trong đó x[1] < x[2] < … < x[k]. Ta nhận thấy giới hạn trên (giá trị lớn nhất có thể nhận) của x[k] là n, của x[k-1] là n - 1, của x[k-2] là n - 2…

Tổng quát: giới hạn trên của x[i] = n - k + i;

Còn tất nhiên, giới hạn dưới của x[i] (giá trị nhỏ nhất x[i] có thể nhận) là x[i-1] + 1.

Như vậy nếu ta đang có một dãy x đại diện cho một tập con, nếu x là cấu hình kết thúc có nghĩa là tất cả các phần tử trong x đều đã đạt tới giới hạn trên thì quá trình sinh kết thúc, nếu không thì ta phải sinh ra một dãy x mới tăng dần thoả mãn vừa đủ lớn hơn dãy cũ theo nghĩa không có một tập con k phần tử nào chen giữa chúng khi sắp thứ tự từ điển.

Ví dụ: n = 9, k = 6. Cấu hình đang có x = 〈1, 2, 6, 7, 8, 9〉. Các phần tử x[3] đến x[6] đã đạt tới giới hạn trên nên để sinh cấu hình mới ta không thể sinh bằng cách tăng một phần tử trong số các x[6], x[5], x[4], x[3] lên được, ta phải tăng x[2] = 2 lên thành x[2] = 3. Được cấu hình mới là x = 〈1, 3, 6, 7, 8, 9〉. Cấu hình này đã thoả mãn lớn hơn cấu hình trước nhưng chưa thoả mãn tính chất vừa đủ lớn, muốn vậy ta lại thay x[3], x[4], x[5], x[6] bằng các giới hạn dưới của nó. Tức là:

> x[3] := x[2] + 1 = 4
>
> x[4] := x[3] + 1 = 5
>
> x[5] := x[4] + 1 = 6
>
> x[6] := x[5] + 1 = 7

Ta được cấu hình mới x = 〈1, 3, 4, 5, 6, 7〉 là cấu hình kế tiếp. Nếu muốn tìm tiếp, ta lại nhận thấy rằng x[6] = 7 chưa đạt giới hạn trên, như vậy chỉ cần tăng x[6] lên 1 là được x = 〈1, 3, 4, 5, 6, 8〉.

Vậy kỹ thuật sinh tập con kế tiếp từ tập đã có x có thể xây dựng như sau:

- Tìm từ cuối dãy lên đầu cho tới khi gặp một phần tử x[i] chưa đạt giới hạn trên n - k + i.
- Nếu tìm thấy:
  - Tăng x[i] đó lên 1.
  - Đặt tất cả các phần tử phía sau x[i] bằng giới hạn dưới.

- Nếu không tìm thấy tức là mọi phần tử đã đạt giới hạn trên, đây là cấu hình cuối cùng

**Input:** file văn bản SUBSET.INP chứa hai số nguyên dương n, k (1 ≤ k ≤ n ≤ 30) cách nhau ít nhất một dấu cách

**Output:** file văn bản SUBSET.OUT các tập con k phần tử của tập {1, 2, …, n}

| SUBSET.INP | SUBSET.OUT |
|:----------:|:----------:|
|    5 3     |  {1, 2, 3} |
|            |  {1, 2, 4} |
|            |  {1, 2, 5} |
|            |  {1, 3, 4} |
|            |  {1, 3, 5} |
|            |  {1, 4, 5} |
|            |  {2, 3, 4} |
|            |  {2, 3, 5} |
|            |  {2, 4, 5} |
|            |  {3, 4, 5} |

***Code Pascal***

```pascal
program Combination;
const
    InputFile = 'SUBSET.INP';
    OutputFile = 'SUBSET.OUT';
    max = 30;
var
    x: array[1..max] of Integer;
    n, k, i, j: Integer;
    f: Text;
begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n, k);
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
    for i := 1 to k do x[i] := i; {x := 12…k (Cấu hình khởi tạo)}
    repeat
        {In ra cấu hình hiện tại}
        Write(f, '{');
        for i := 1 to k - 1 do Write(f, x[i], ', ');
        WriteLn(f, x[k], '}');
        {Sinh tiếp}
        i := k; {Xét từ cuối dãy lên tìm x[i] chưa đạt giới hạn trên n - k + i}
        while (i > 0) and (x[i] = n - k + i) do Dec(i);
        if i > 0 then {Nếu chưa lùi đến 0 có nghĩa là chưa phải cấu hình kết thúc}
            begin
                Inc(x[i]); {Tăng x[i] lên 1, Đặt các phần tử đứng sau x[i] bằng giới hạn dưới của nó}
                for j := i + 1 to k do x[j] := x[j - 1] + 1;
            end;
    until i = 0; {Lùi đến tận 0 có nghĩa là tất cả các phần tử đã đạt giới hạn trên - hết cấu hình}
    Close(f);
end.
```

***Code C***

```c
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
```

## 2.3. LIỆT KÊ CÁC HOÁN VỊ

Ta sẽ lập chương trình liệt kê các hoán vị của {1, 2, …, n} theo thứ tự từ điển.

Ví dụ với n = 4, ta phải liệt kê đủ 24 hoán vị:
> 1.1234, 2.1243, 3.1324, 4.1342, 5.1423, 6.1432,
>
> 7.2134, 8.2143, 9.2314, 10.2341, 11.2413, 12.2431,
>
> 13.3124, 14.3142, 15.3214, 16.3241, 17.3412, 18.3421,
>
> 19.4123, 20.4132, 21.4213, 22.4231, 23.4312, 24.4321.

Như vậy hoán vị đầu tiên sẽ là 〈1, 2, …, n〉. Hoán vị cuối cùng là 〈n, n-1, …, 1〉. Hoán vị sẽ sinh ra phải lớn hơn hoán vị hiện tại, hơn thế nữa phải là hoán vị vừa đủ lớn hơn hoán vị hiện tại theo nghĩa không thể có một hoán vị nào khác chen giữa chúng khi sắp thứ tự.

Giả sử hoán vị hiện tại là x = 〈3, 2, 6, 5, 4, 1〉, xét 4 phần tử cuối cùng, ta thấy chúng được xếp giảm dần, điều đó có nghĩa là cho dù ta có hoán vị 4 phần tử này thế nào, ta cũng được một hoán vị bé hơn hoán vị hiện tại. Như vậy ta phải xét đến x[2] = 2, thay nó bằng một giá trị khác. Ta sẽ thay bằng giá trị nào?, không thể là 1 bởi nếu vậy sẽ được hoán vị nhỏ hơn, không thể là 3 vì đã có x[1] = 3 rồi (phần tử sau không được chọn vào những giá trị mà phần tử trước đã chọn). Còn lại các giá trị 4, 5, 6. Vì cần một hoán vị vừa đủ lớn hơn hiện tại nên ta chọn x[2] = 4. Còn các giá trị (x[3], x[4], x[5], x[6]) sẽ lấy trong tập {2, 6, 5, 1}. Cũng vì tính vừa đủ lớn nên ta sẽ tìm biểu diễn nhỏ nhất của 4 số này gán cho x[3], x[4], x[5], x[6] tức là 〈1, 2, 5, 6〉. Vậy hoán vị mới sẽ là 〈3, 4, 1, 2, 5, 6〉.

Ta có nhận xét gì qua ví dụ này: Đoạn cuối của hoán vị hiện tại được xếp giảm dần, số x[5] = 4 là số nhỏ nhất trong đoạn cuối giảm dần thoả mãn điều kiện lớn hơn x[2] = 2. Nếu đổi chỗ x[5] cho x[2] thì ta sẽ được x[2] = 4 và đoạn cuối vẫn được sắp xếp giảm dần. Khi đó muốn biểu diễn nhỏ nhất cho các giá trị trong đoạn cuối thì ta chỉ cần đảo ngược đoạn cuối.

Trong trường hợp hoán vị hiện tại là 〈2, 1, 3, 4〉 thì hoán vị kế tiếp sẽ là 〈2, 1, 4, 3〉. Ta cũng có thể coi hoán vị 〈2, 1, 3, 4〉 có đoạn cuối giảm dần, đoạn cuối này chỉ gồm 1 phần tử (4). Vậy kỹ thuật sinh hoán vị kế tiếp từ hoán vị hiện tại có thể xây dựng như sau:

- Xác định đoạn cuối giảm dần dài nhất, tìm chỉ số i của phần tử x[i] đứng liền trước đoạn cuối đó. Điều này đồng nghĩa với việc tìm từ vị trí sát cuối dãy lên đầu, gặp chỉ số i đầu tiên thỏa mãn x[i] < x[i+1].
- Nếu tìm thấy chỉ số i như trên:
  - Trong đoạn cuối giảm dần, tìm phần tử x[k] nhỏ nhất thoả mãn điều kiện x[k] > x[i]. Do đoạn cuối giảm dần, điều này thực hiện bằng cách tìm từ cuối dãy lên đầu gặp chỉ số k đầu tiên thoả mãn x[k] > x[i] (có thể dùng tìm kiếm nhị phân).
  - Đảo giá trị x[k] và x[i]
  - Lật ngược thứ tự đoạn cuối giảm dần (từ x[i+1] đến x[k]) trở thành tăng dần.
- Nếu không tìm thấy tức là toàn dãy đã sắp giảm dần, đây là cấu hình cuối cùng

**Input:** file văn bản PERMUTE.INP chứa số nguyên dương n ≤ 12

**Output:** file văn bản PERMUTE.OUT các hoán vị của dãy (1, 2, …, n)

| PERMUTE.INP | PERMUTE.OUT |
|:-----------:|:-----------:|
|      3      |    1 2 3    |
|             |    1 3 2    |
|             |    2 1 3    |
|             |    2 3 1    |
|             |    3 1 2    |
|             |    3 2 1    |

***Code Pascal***

```pascal
program Permutation;
const
    InputFile = 'PERMUTE.INP';
    OutputFile = 'PERMUTE.OUT';
    max = 12;
var
    n, i, k, a, b: Integer;
    x: array[1..max] of Integer;
    f: Text;
procedure Swap(var X, Y: Integer); {Thủ tục đảo giá trị hai tham biến X, Y}
var
    Temp: Integer;
begin
    Temp := X; X := Y; Y := Temp;
end;

begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n);
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
    for i := 1 to n do x[i] := i; {Khởi tạo cấu hình đầu: x[1] := 1; x[2] := 2; …, x[n] := n}
    repeat
        for i := 1 to n do Write(f, x[i], ' '); {In ra cấu hình hoán vị hiện tại}
        WriteLn(f);
        i := n - 1;
        while (i > 0) and (x[i] > x[i + 1]) do Dec(i);
        if i > 0 then {Chưa gặp phải hoán vị cuối (n, n-1, …, 1)}
            begin
                k := n; {x[k] là phần tử cuối dãy}
                while x[k] < x[i] do Dec(k); {Lùi dần k để tìm gặp x[k] đầu tiên lớn hơn x[i]}
                Swap(x[k], x[i]); {Đổi chỗ x[k] và x[i]}
                a := i + 1; b := n; {Lật ngược đoạn cuối giảm dần, a: đầu đoạn, b: cuối đoạn}
                while a < b do
                    begin
                        Swap(x[a], x[b]); {Đảo giá trị x[a] và x[b]}
                        Inc(a); {Tiến a và lùi b, tiếp tục cho tới khi a, b chạm nhau}
                        Dec(b);
                    end;
            end;
    until i = 0; {Toàn dãy là dãy giảm dần - không sinh tiếp được - hết cấu hình}
    Close(f);
end.
```

***Code C***

```c
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
```

---
