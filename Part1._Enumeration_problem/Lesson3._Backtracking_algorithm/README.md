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
