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