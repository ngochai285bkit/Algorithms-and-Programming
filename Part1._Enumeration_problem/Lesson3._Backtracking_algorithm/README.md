# BÀI 3. THUẬT TOÁN QUAY LUI

Thuật toán quay lui dùng để giải bài toán liệt kê các cấu hình. Mỗi cấu hình được xây dựng bằng cách xây dựng từng phần tử, mỗi phần tử được chọn bằng cách thử tất cả các khả năng. Giả sử cấu hình cần liệt kê có dạng x[1..n], khi đó thuật toán quay lui thực hiện qua các bước:

1) Xét tất cả các giá trị x[1] có thể nhận, thử cho x[1] nhận lần lượt các giá trị đó. Với mỗi giá trị thử gán cho x[1] ta sẽ:
2) Xét tất cả các giá trị x[2] có thể nhận, lại thử cho x[2] nhận lần lượt các giá trị đó. Với mỗi giá trị thử gán cho x[2] lại xét tiếp các khả năng chọn x[3] … cứ tiếp tục như vậy đến bước:
…
n) Xét tất cả các giá trị x[n] có thể nhận, thử cho x[n] nhận lần lượt các giá trị đó, thông báo cấu hình tìm được 〈x[1], x[2], …, x[n]〉.

Trên phương diện quy nạp, có thể nói rằng thuật toán quay lui liệt kê các cấu hình n phần tử dạng x[1..n] bằng cách thử cho x[1] nhận lần lượt các giá trị có thể. Với mỗi giá trị thử gán cho x[1] bài toán trở thành liệt kê tiếp cấu hình n - 1 phần tử x[2..n].

Mô hình của thuật toán quay lui có thể mô tả như sau:

```pascal
{Thủ tục này thử cho x[i] nhận lần lượt các giá trị mà nó có thể nhận}
procedure Try(i: Integer);
begin
    for 〈mọi giá trị V có thể gán cho x[i]〉 do
        begin
            〈Thử cho x[i] := V〉;
            if 〈x[i] là phần tử cuối cùng trong cấu hình〉 then
                〈Thông báo cấu hình tìm được〉
            else
                begin
                    〈Ghi nhận việc cho x[i] nhận giá trị V (nếu cần)〉;
                    Try(i + 1); {Gọi đệ quy để chọn tiếp x[i+1]}
                    〈Nếu cần, bỏ ghi nhận việc thử x[i] := V để thử giá trị khác〉;
                end;
        end;
end;
```

Thuật toán quay lui sẽ bắt đầu bằng lời gọi Try(1)

## 3.1. LIỆT KÊ CÁC DÃY NHỊ PHÂN ĐỘ DÀI N

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

Biểu diễn dãy nhị phân độ dài N dưới dạng x[1..n]. Ta sẽ liệt kê các dãy này bằng cách thử dùng các giá trị {0, 1} gán cho x[i]. Với mỗi giá trị thử gán cho x[i] lại thử các giá trị có thể gán cho x[i+1].Chương trình liệt kê bằng thuật toán quay lui có thể viết:

***Code Pascal***

```pascal
program BinaryStrings;
const
    InputFile = 'BSTR.INP';
    OutputFile = 'BSTR.OUT';
    max = 30;
var
    x: array[1..max] of Integer;
    n: Integer;
    f: Text;

procedure PrintResult; {In cấu hình tìm được, do thủ tục tìm đệ quy Try gọi khi tìm ra một cấu hình}
var
    i: Integer;
begin
    for i := 1 to n do Write(f, x[i]);
    WriteLn(f);
end;

procedure Try(i: Integer); {Thử các cách chọn x[i]}
var
    j: Integer;
begin
    for j := 0 to 1 do {Xét các giá trị có thể gán cho x[i], với mỗi giá trị đó}
        begin
            x[i] := j; {Thử đặt x[i]}
            if i = n then PrintResult {Nếu i = n thì in kết quả}
            else Try(i + 1); {Nếu i chưa phải là phần tử cuối thì tìm tiếp x[i+1]}
        end;
end;

begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n); {Nhập dữ liệu}
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
    Try(1); {Thử các cách chọn giá trị x[1]}
    Close(f);
end.
```

***Code C***

```c
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
```

***Ví dụ: Khi n = 3, cây tìm kiếm quay lui như sau:***

![Cây tìm kiếm quay lui](/Part1._Enumeration_problem/Lesson3._Backtracking_algorithm/H1.png)

---

## 3.2. LIỆT KÊ CÁC TẬP CON K PHẦN TỬ

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

Để liệt kê các tập con k phần tử của tập S = {1, 2, …, n} ta có thể đưa về liệt kê các cấu hình x[1..n], ở đây các x[i] ∈ S và x[1] < x[2] < … < x[k]. Ta có nhận xét:

> x[k] ≤ n
>
> x[k-1] ≤ x[k] - 1 ≤ n - 1
>
> …
>
> x[i] ≤ n - k + i
>
> …
>
> x[1] ≤ n - k + 1.

Từ đó suy ra x[i-1] + 1 ≤ x[i] ≤ n - k + i (1 ≤ i ≤ k) ở đây ta giả thiết có thêm một số x[0] = 0 khi xét i = 1.
Như vậy ta sẽ xét tất cả các cách chọn x[1] từ 1 (=x[0] + 1) đến n - k + 1, với mỗi giá trị đó, xét tiếp tất cả các cách chọn x[2] từ x[1] +1 đến n - k + 2, … cứ như vậy khi chọn được đến x[k] thì ta có một cấu hình cần liệt kê. Chương trình liệt kê bằng thuật toán quay lui như sau:

***Code Pascal***

```pascal
program Combination;
const
    InputFile = 'SUBSET.INP';
    OutputFile = 'SUBSET.OUT';
    max = 30;
var
    x: array[0..max] of Integer;
    n, k: Integer;
    f: Text;

procedure PrintResult; (*In ra tập con {x[1], x[2], …, x[k]}*)
var
    i: Integer;
begin
    Write(f, '{');
    for i := 1 to k - 1 do Write(f, x[i], ', ');
    WriteLn(f, x[k], '}');
end;

procedure Try(i: Integer); {Thử các cách chọn giá trị cho x[i]}
var
    j: Integer;
begin
    for j := x[i - 1] + 1 to n - k + i do
        begin
            x[i] := j;
            if i = k then PrintResult
            else Try(i + 1);
        end;
end;

begin
    Assign(f, InputFile); Reset(F);
    ReadLn(f, n, k);
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
    x[0] := 0;
    Try(1);
    Close(f);
end.
```

***Code C***

```c
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
```

Nếu để ý chương trình trên và chương trình liệt kê dãy nhị phân độ dài n, ta thấy về cơ bản chúng chỉ khác nhau ở thủ tục Try(i) - chọn thử các giá trị cho x[i], ở chương trình liệt kê dãy nhị phân ta thử chọn các giá trị 0 hoặc 1 còn ở chương trình liệt kê các tập con k phần tử ta thử chọn x[i] là một trong các giá trị nguyên từ x[i-1] + 1 đến n - k + i. Qua đó ta có thể thấy tính phổ dụng của thuật toán quay lui: mô hình cài đặt có thể thích hợp cho nhiều bài toán, khác với phương pháp sinh tuần tự, với mỗi bài toán lại phải có một thuật toán sinh kế tiếp riêng làm cho việc cài đặt mỗi bài một khác, bên cạnh đó, không phải thuật toán sinh kế tiếp nào cũng dễ cài đặt.

## 3.3. LIỆT KÊ CÁC CHỈNH HỢP KHÔNG LẶP CHẬP K

Để liệt kê các chỉnh hợp không lặp chập k của tập S = {1, 2, …, n} ta có thể đưa về liệt kê các cấu hình x[1..k] ở đây các x[i] ∈ S và khác nhau đôi một. Như vậy thủ tục Try(i) - xét tất cả các khả năng chọn x[i] - sẽ thử hết các giá trị từ 1 đến n, mà các giá trị này chưa bị các phần tử đứng trước chọn. Muốn xem các giá trị nào chưa được chọn ta sử dụng kỹ thuật dùng mảng đánh dấu:

- Khởi tạo một mảng c[1..n] mang kiểu logic boolean. Ở đây c[i] cho biết giá trị i có còn tự do hay đã bị chọn rồi. Ban đầu khởi tạo tất cả các phần tử mảng c là TRUE có nghĩa là các phần tử từ 1 đến n đều tự do.
- Tại bước chọn các giá trị có thể của x[i] ta chỉ xét những giá trị j có c[j] = TRUE có nghĩa là chỉ chọn những giá trị tự do.
- Trước khi gọi đệ quy tìm x[i+1]: ta đặt giá trị j vừa gán cho x[i] là đã bị chọn có nghĩa là đặt c[j] := FALSE để các thủ tục Try(i + 1), Try(i + 2)… gọi sau này không chọn phải giá trị j đó nữa
- Sau khi gọi đệ quy tìm x[i+1]: có nghĩa là sắp tới ta sẽ thử gán một giá trị khác cho x[i] thì ta sẽ đặt giá trị j vừa thử đó thành tự do (c[j] := TRUE), bởi khi xi đã nhận một giá trị khác rồi thì các phần tử đứng sau: x[i+1], x[i+2] … hoàn toàn có thể nhận lại giá trị j đó. Điều này hoàn toàn hợp lý trong phép xây dựng chỉnh hợp không lặp: x[1] có n cách chọn, x[2] có n - 1 cách chọn, …Lưu ý rằng khi thủ tục Try(i) có i = k thì ta không cần phải đánh dấu gì cả vì tiếp theo chỉ có in kết quả chứ không cần phải chọn thêm phần tử nào nữa.

***Input:*** file văn bản ARRANGE.INP chứa hai số nguyên dương n, k (1 ≤ k ≤ n ≤ 20) cách nhau ít nhất một dấu cách

***Output:*** file văn bản ARRANGE.OUT ghi các chỉnh hợp không lặp chập k của tập {1, 2, …, n}

| ARRANGE.INP | ARRANGE.OUT |
|:-----------:|:-----------:|
|     3 2     |     1 2     |
|             |     1 3     |
|             |     2 1     |
|             |     2 3     |
|             |     3 1     |
|             |     3 2     |

***Code Pascal***

```pascal
program Arrangement;
const
    InputFile = 'ARRANGES.INP';
    OutputFile = 'ARRANGES.OUT';
    max = 20;
var
    x: array[1..max] of Integer;
    c: array[1..max] of Boolean;
    n, k: Integer;
    f: Text;

procedure PrintResult; {Thủ tục in cấu hình tìm được}
var
    i: Integer;
begin
    for i := 1 to k do Write(f, x[i], ' ');
    WriteLn(f);
end;

procedure Try(i: Integer); {Thử các cách chọn x[i]}
var
    j: Integer;
begin
    for j := 1 to n do
    if c[j] then {Chỉ xét những giá trị j còn tự do}
        begin
            x[i] := j;
            if i = k then PrintResult {Nếu đã chọn được đến xk thì chỉ việc in kết quả}
            else
                begin
                    c[j] := False; {Đánh dấu: j đã bị chọn}
                    Try(i + 1); {Thủ tục này chỉ xét những giá trị còn tự do gán cho x[i+1]}
                    c[j] := True; {Bỏ đánh dấu: j lại là tự do, bởi sắp tới sẽ thử một cách chọn khác của x[i]}
                end;
        end;
end;

begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n, k);
    Assign(f, OutputFile); Rewrite(f);
    FillChar(c, SizeOf(c), True); {Tất cả các số đều chưa bị chọn}
    Try(1); {Thử các cách chọn giá trị của x[1]}
    Close(f);
end.
```

***Code C***

```c
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
```
