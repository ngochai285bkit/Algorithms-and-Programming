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