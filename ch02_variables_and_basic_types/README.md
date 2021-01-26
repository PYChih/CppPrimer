# Ch02_Variables_and_Basic_Types
###### tags: `C++ exercise`
[TOC]
# 2.1 原始內建型別
## 2.1.1 算數型別
- [ ] 2.1: int、long、long long 與short之間的差異是什麼?無號型別與有號型別之間的差異呢?float與double之間呢?
- [ ] 2.2: 若要計算抵押貸款的付款金額(mortgage payment)，你分別會用何種型別來表示利率(rate)、本金(principal)和償還金額(payment)?解釋你選擇該型別的原因。
## 2.1.2 型別轉換
- [ ] 2.3: 下面程式碼會產生什麼輸出呢?
    ```
    unsigned u = 10, u2 = 42;
    std ::cout <, u2 -u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2-i<<std::endl;
    std::cout << i - i2<<std::endl;
    std::cout << i - u<< std::endl;
    std::cout << u - i<<std::endl;
    ```
- [ ] 2.4: 寫一個程式來檢查你的預測是否正確。若不是就重複研讀本節，直到你了解問題出在哪為止。
## 2.1.3 字面值
- [ ] 2.5: 判斷下列每個字面值之型別。解釋四個範例中每組字面值之間的差異:
    ```
    (a). 'a'、L'a'、"a"、L"a"
    (b). 10、10u、10L、10uL、012、0xC
    (c). 3.14、3.14f、3.14L
    (d). 10、10u、10.、10e-2
    ```
- [ ] 2.6: 下列定義之間的差異是什麼(如果有的話)?
    ```
    int month =9, day =7;
    int month = 09, day = 07;
    ```
- [ ] 2.7 : 這些字面值代表什麼值呢？他們各有什麼型別呢？
    ```
    (a). "Who goes with F\145rgus?\012"
    (b). 3.14e1L 
    (c). 1024f 
    (d). 3.14L
    ```
- [ ] 2.8 : 使用轉義序列，寫出一個程式印出2M後面接著一個newline。修改這個程式，印出2，然後一個tab，然後一個M，後面接著一個newline。
    - Ascii table 參考: http://www.asciitable.com/
# 2.2 變數
## 2.2.1 變數的定義
- [ ] 2.9: 解釋下列定義。對那些不合法的定義，請解說何處出錯了，以及如何更正之。
    ```
    // a
    std::cin >> int input_value;  // 錯誤
    // b
    int i = {3.14};  // 警告，因為大括號
    // c
    double salary = wage = 999.99;
    // d
    int i = 3.14;  // 警告，值會被截斷
    ```
- [ ] 2.10: 下列每個變數各有什麼初始值呢(如果有的話)?
    ```
    std::string global_str;
    int global_int;
    int main() {
        int local_int;
        std:string local_str;
    }
    ```
## 2.2.2 變數宣告與定義
- [ ] 2.11: 解釋下列每一個是宣告還是定義:
    ```
    // a 
    extern int ix = 1024;
    // b
    int iy;
    // c
    extern int iz;
    ```
## 2.2.3 識別字
- [ ] 2.12: 下列哪一個名稱無效(如果有的話)?
    ```
    // a
    int double = 3.14;
    // b
    int _;
    // c
    int catch-22;
    // d
    int 1_or_2 = 1;
    // e
    double Double = 3.14;
    ```
## 2.2.4 一個名稱的範疇
- [ ] 2.13: 下列程式中j的值為何?
    ```
    int i = 42;
    int main() {
        int i = 100;
        int j = i;
    }
    ```
- [ ] 2.14: 下列程式合法嗎？若是，印出的會是什麼值呢？
    ```
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
    ```
# 2.3 複合型別
## 2.3.1 參考
- [ ] 2.15: 下列哪個定義是無效的(如果有的話)? 為什麼?
    ```
    // a
    int ival = 1.01;
    // b
    int &rvall = 1.01;
    // c
    int &rval2 = ival;
    // d
    int &rval3;
    ```
- [ ] 2.16: 如果有的話，下列哪個指定是無效的? 如果是有效的，請解釋原因。
    ``` 
    int i=0, &r1 = i; double d = 0, &r2 = d;
    // a
    r2 = 3.14159;
    // b
    r2 = r1;
    // c
    i = r2;
    // d
    r1 = d;
- [ ] 2.17: 下列程式碼會印出什麼呢?
    ``` 
    int i, &ri = i;
    i = 5; ri =10;
    std::cout << i << " " << ri <<    std::endl;
    ```
## 2.3.2 指標
- [ ] 2.18: 寫出程式碼來變更一個指標的值。寫出程式碼來變更該指標所指的值。
- [ ] 2.19: 解釋指標與參考之間的關鍵差異
    - 一個是對向(可以改來改去)，一個不是，一開始給了就給了，就像是別名一樣，所以沒初始化的話不會過。
- [ ] 2.20: 下列程式會做什麼事呢?
    ```
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    ```
- [ ] 2.21: 解釋下列的每個定義。指出那些是不合法的(如果有的話)，並說明原因。
    ```
    int i=0;
    double* dp = &i;
    int *ip = i;
    int *p = &i;
    ```
- [ ] 2.22: 假設p是對int的一個指標，請解說下列程式碼:
    ```
    if (p) // ...
    if (*p) // ...
    ```
- [ ] 2.23: 給定一個指標p，你能夠判斷p指向的是否為一個有效物件嗎？若是，為什麼呢，若不是，原因為何？
- [ ] 2.24: 為什麼p的初始化是合法的，但lp的不合法呢?
    ```
    int i = 42;
    void *p = &i;
    long *lp = &i;
    ```
## 2.3.3 了解複合型別之宣告
- [ ] 2.25: 判斷下列每個變數的型別和值。
    ```
    // a
    int * ip, i, &r = i;  // ip是一個指向int的指標，i是一個int，r是一個對int的參考
    // b
    int i, *ip = 0;  // i是一個int，ip是一個指向int的指標，預設指到nullptr
    // c
    int* ip, ip2;  // ip是一個指向int的指標，ip2是一個int
    ```
# 2.4 const限定詞
- [ ] 2.26: 下列何者是合法的？
    ```
    // a
    const int buf; // const int 必須被初始化
    // b 
    int cnt = 0; //定義一個int
    // c
    const int sz = cnt; //定義一個const int
    // d
    ++cnt; ++sz; // const不能被改變
    ```
## 2.4.1 對const的參考
## 2.4.2 指標與const
- [ ] 2.27: 下列哪個初始化是合法的? 請解釋原因。
    ```
    // a
    int i = -1, &r = 0;  // 一般的參考不可以參考字面值
    // b
    int *const p2 = &i2;  // const指標
    // c
    const int i = -1, &r=0;
    // d
    const int *const p3 = &i2;
    // e
    const int *p1 = &i2;
    // f
    const int &const r2;
    // g
    const int i2 = i, &r = i;
    ```
- [ ] 2.28: 解釋下列定義。指出其中非法的定義。
    ```
    // a
    int i, *const cp;
    // b
    int *p1, *const p2;
    // c
    const int ic, &r = ic;
    // d
    const int *const p3;
    // e
    const int *p;
    ```
- [ ] 2.29: 使用前一個練習中的變數，請問下列哪個指定是合法? 請解釋原因。
    ```
    // a
    i = ic;
    // b
    p1 = p3;
    // c
    p1 = &ic;
    // d
    p3 = &ic;
    // e
    p2 = p1;
    // f
    ic = *p3;
    ```
## 2.4.3 頂層的const
- [ ] 2.30: 指出下列宣告所宣告的物件是否有頂層或低層的const
    ```
    const int v2 = 0; // v2不給改，是頂層 
    int v1 = v2;//v1拷貝了v2的值，v2的const被忽略
    int *p1 = &v1, &r1 = v1;//p1是指向int的指標，r1是對v1的參考，v1是int
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    ```
- [ ] 2.31: 給定上一個練習的宣告，請判斷下列的指定是否合法。解釋每個例子中頂層或低層const是如何套用的。
    ```
    r1 = v2;
    p1 = p2;
    p2 = p1;
    p1 = p3;
    p2 = p3;
    ```
## 2.4.4 constexpr與常數運算式
- [ ] 2.32: 下列程式碼是否合法? 若非，你要如何讓它變得合法?
    ```
    int null = 0, *p = null;
    ```
# 2.5 處理型別
## 2.5.1 型別之別名
## 2.5.2 auto型別指定符
- [ ] 2.33: 使用本節的變數定義，判斷下列這些指定式各會發生什麼事:
    ```
    a = 42; // i是int, r是i的參考, a=r代表把一個int複製給a, 所以a是int，然後被賦值42。
    b = 42;  // ci是一個const int，b=ci，讓b是一個普通int，所以b是int，然後被賦值42。
    c = 42;  // const int &cr = ci，cr是對const物件的參考，然後c=cr所以c是普通int
    d = 42;  // d = &i，所以d是一個指向int的指針，型別應該會錯
    e = 42;  // auto e = &ci, 所以e是const int*，所以這個也是型別錯
    g = 42;  // auto &g = ci, g是ci的參考，所以有型別const int&，所以g不給改
    ```
- [ ] 2.34: 寫一個包含前一個練習中的變數和指定的程式。在指定前後印出那些變數，以監察你在前面練習的預測是否正確。如果不是，就研讀範例，值到你認為你知道是什麼引導你走向錯誤結論為止。
- [ ] 2.35: 判斷從下列各個定義推導出來的型別。一旦你找出型別，就寫個程式來看看你是否正確。
    ```
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    // i是const int
    // j是普通int (頂層int丟棄)
    // k是const int的參考，所以k有型別const int&
    // p放了i的位子，所以p有型別const int*
    // j2是const int
    // k2是const int&
    ```
## 2.5.3 decltype型別指定符
- [ ] 2.36: 在下列程式碼中，判斷每個變數的型別，以及程式碼執行完畢之後每個變數的值。
    ```
    int a =3, b=4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    // a 是 int 值4
    // b 是 int 值4
    // c 是 int 值 4
    // d 是 int& 值4
    ```
- [ ] 2.37 : 指定(assignment)是會產出參考型別的運算實例。型別會是指涉左邊運算元型別的一種參考，也就是說，如果i是一個int，那麼運算式i = x的型別就會是int&。藉由這個知識，判斷這段程式碼中每個變數的型別與值。
    ```
    int a =3, b=4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    // a 是 int 值3
    // b 是 int 值4
    // c 是 int 值3
    // d 是 int& 值3
    ```
- [ ] 2.38 : 描述decltype和auto之間型別推導的差異。給出一個運算實例，讓auto和decltype都會推導出相同的型別，以及一個會推導出不同型別的運算實例。
# 2.6 定義我們自己的資料結構
## 2.6.1 定義Sales_data型別 
- [ ] 2.39: 編譯下列程式，看看你如果忘了類別定義後的分號，會發生什麼事。記住這種訊息以便未來參考。
    ```
    struct Foo { /* empty */ }  // 注意: 沒有分號
    int main() {
        return 0;
    }
    ```
- [ ] 2.40: 寫出你自己版本的Sales_data類別
## 2.6.2 使用Sales_data類別
- [ ] 2.41 使用你的Sales_data類別來改寫1.5.1、1.5.2和1.6中的練習。就現在來說，你應該將你的Sales_data類別定義在跟main函式相同的檔案中。
## 2.6.3 撰寫我們自己的標頭檔
- [ ] 2.42: 寫出你自己版本的Sales_data.h標頭，並用它來改寫$2.6.2的練習
