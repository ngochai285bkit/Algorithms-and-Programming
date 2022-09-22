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