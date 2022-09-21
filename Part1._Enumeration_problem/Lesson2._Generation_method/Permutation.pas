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