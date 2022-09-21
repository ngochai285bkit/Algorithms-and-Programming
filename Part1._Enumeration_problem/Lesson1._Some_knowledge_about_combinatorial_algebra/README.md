# BÀI 1. NHẮC LẠI MỘT SỐ KIẾN THỨC ĐẠI SỐ TỔ HỢP

Cho S là một tập hữu hạn gồm n phần tử và k là một số tự nhiên.
Gọi X là tập các số nguyên dương từ 1 đến k: X = {1, 2, …, k}

## 1.1. CHỈNH HỢP LẶP

Mỗi ánh xạ f: X → S. Cho tương ứng với mỗi i ∈ X, một và chỉ một phần tử f(i) ∈ S. Được gọi là một chỉnh hợp lặp chập k của S.
Nhưng do X là tập hữu hạn (k phần tử) nên ánh xạ f có thể xác định qua bảng các giá trị f(1), f(2), …, f(k).
Ví dụ: S = {A, B, C, D, E, F}; k = 3. Một ánh xạ f có thể cho như sau:

|   |   |   |   |
|:-:|:-:|:-:|:-:|
| **i** | 1 | 2 | 3 |
| **f(i)** | E | C | E |

Vậy có thể đồng nhất f với dãy giá trị (f(1), f(2), …, f(k)) và coi dãy giá trị này cũng là một chỉnh hợp lặp chập k của S. Như ví dụ trên (E, C, E) là một chỉnh hợp lặp chập 3 của S. Dễ dàng chứng minh được kết quả sau bằng quy nạp hoặc bằng phương pháp đánh giá khả năng lựa chọn:

Số chỉnh hợp lặp chập k của tập gồm n phần tử là $n^k$

## 1.2. CHỈNH HỢP KHÔNG LẶP

Khi f là đơn ánh có nghĩa là với ∀i, j ∈ X ta có f(i) = f(j) ⇔ i = j. Nói một cách dễ hiểu, khi dãy giá trị f(1), f(2), …, f(k) gồm các phần tử thuộc S khác nhau đôi một thì f được gọi là một chỉnh hợp không lặp chập k của S. Ví dụ một chỉnh hợp không lặp (C, A, E):

|   |   |   |   |
|:-:|:-:|:-:|:-:|
| **i** | 1 | 2 | 3 |
| **f(i)** | C | A | E |

Số chỉnh hợp không lặp chập k của tập gồm n phần tử là: $P_n^k = n(n-1)(n-2)...(n-k+1) = \frac{n!}{(n-k)!}$

## 1.3. HOÁN VỊ

Khi k = n. Một chỉnh hợp không lặp chập n của S được gọi là một hoán vị các phần tử của S.

Ví dụ: một hoán vị: 〈A, D, C, E, B, F〉 của S = {A, B, C, D, E, F}

|   |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| **i** | 1 | 2 | 3 | 4 | 5 | 6 |
| **f(i)** | A | D | C | E | B | F |

Để ý rằng khi k = n thì số phần tử của tập X = {1, 2, …, n} đúng bằng số phần tử của S. Do tính chất đôi một khác nhau nên dãy f(1), f(2), …, f(n) sẽ liệt kê được hết các phần tử trong S. Như vậy f là toàn ánh. Mặt khác do giả thiết f là chỉnh hợp không lặp nên f là đơn ánh. Ta có tương ứng 1-1 giữa các phần tử của X và S, do đó f là song ánh. Vậy nên ta có thể định nghĩa một hoán vị của S là một song ánh giữa {1, 2, …, n} và S.

Số hoán vị của tập gồm n phần tử = số chỉnh hợp không lặp chập n = n!

## 1.4. TỔ HỢP

Một tập con gồm k phần tử của S được gọi là một tổ hợp chập k của S. Lấy một tập con k phần tử của S, xét tất cả k! hoán vị của tập con này. Dễ thấy rằng các hoán vị đó là các chỉnh hợp không lặp chập k của S. Ví dụ lấy tập {A, B, C} là tập con của tập S trong ví dụ trên thì: 〈A, B, C〉, 〈C, A, B〉, 〈B, C, A〉, … là các chỉnh hợp không lặp chập 3 của S. Điều đó tức là khi liệt kê tất cả các chỉnh hợp không lặp chập k thì mỗi tổ hợp chập k sẽ được tính k! lần. Vậy số tổ hợp chập k của tập gồm n phần tử là: $C_n^k = \frac{n!}{k!(n-k)!}$

---

[Previous](/Part1._Enumeration_problem/README.md) | [Next](/Part1._Enumeration_problem/Lesson2._Generation_method/README.md)
