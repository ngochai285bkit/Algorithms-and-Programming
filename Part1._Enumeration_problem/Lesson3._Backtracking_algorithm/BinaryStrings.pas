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