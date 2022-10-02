program Analyses;

const
    InputFile = 'ANALYSE.INP';
    OutputFile = 'ANALYSE.OUT';
    max = 30;

var
    n: Integer;
    x: array[0..max] of Integer;
    t: array[0..max] of Integer;
    f: Text;

procedure Init; {Khởi tạo}
begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n);
    Close(f);
    x[0] := 1;
    t[0] := 0;
end;

procedure PrintResult(k: Integer);
var
    i: Integer;
begin
    Write(f, n, ' = ');
    for i := 1 to k - 1 do Write(f, x[i], '+');
    WriteLn(f, x[k]);
end;

procedure Try(i: Integer);
var
    j: Integer;
begin
    for j := x[i - 1] to (n - T[i - 1]) div 2 do {Trường hợp còn chọn tiếp x[i+1]}
        begin
            x[i] := j;
            t[i] := t[i - 1] + j;
            Try(i + 1);
        end;
    x[i] := n - T[i - 1]; {Nếu x[i] là phần tử cuối thì nó bắt buộc phải là … và in kết quả}
    PrintResult(i);
end;

begin
    Init;
    Assign(f, OutputFile); Rewrite(f);
    Try(1);
    Close(f);
end.