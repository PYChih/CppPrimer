# ch06_Functions
###### tags: `C++Primer`
[TOC]
# 6.1 函式基礎
- 我們透過呼叫運算子來執行一個函式(呼叫運算子是一對括弧)
- 呼叫運算子接受一個運算式，這個運算式是一個函式或指向一個函式
- 括弧裡面是以逗號分隔的一串引數(arguments)
- 引數用來初始化函式的參數
- 一個呼叫運算式的型別就是該函式的回傳型別
### 撰寫一個函式
- 寫一個函式來判斷一個給定的數字之階乘值
    ```
    int fact(int val) {  // 函式定義由一個回傳型別、一個名稱，以及一串零或多個參數所組成
    // 函式所進行的動作指定在一個述句區塊中，稱做函式主體
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
    }
    ```
### 呼叫一個函式
- 要呼叫fact，我們要提供一個int值，呼叫的結果也會是一個int
    ```
    int main() {
        int j = fact(5); // j = 120
        cout << " 5! is " << j << endl;
        return 0;
    }
    ```
### 參數與引數
- 引數是函是參數的初始器
- 傳入引數給函式參數
- 雖然我們知道哪個引數初始化哪個參數，我們無法保證引數被估算的順序
### 函式參數列
- 參數列可以是空的但不能省略
- 可以使用void來表示沒有參數`void f(void)`
- 一個參數列由逗號分隔的一串參數所組成，其中每個看起來都像帶有單一個宣告器的宣告
- 即使兩個參數的型別相同，型別還是必須重複
### 函式回傳型別
- 回傳型別不可以是陣列或函式型別，不過函式可以回傳指向一個陣列或函式的一個指標
## 6.1.1 區域物件
- 名稱具有範疇而物件具有生命週期
    - 一個名稱的範疇是在其中可以看到該名稱的那部分程式文字
    - 一個物件的生命週期是程式執行時該物件存在的期間
- 定義在函式內的參數與變數稱為區域變數
    - 它們對那個函式而言是區域性的，並且會遮擋在外層範疇中所做的宣告
- 定義在所有函式外的物件在程式的整個執行期間都會存在
- 區域變數的生命週期取決於它被定義的方式
### 自動物件
- 只在一個區塊執行時存在的物件被稱為自動物件。
- 執行離開一個區塊後，在該區塊中創建的自動物件之值是未定義的。
- 參數是自動物件，會在函式結束時被摧毀
### 區域static物件
- 有時候需要其生命週期可以在不同函式呼叫間存續的區域變數
- 我們可以將一個區域變數定義為static來獲得這種物件
- 區域性的static並不會在函式結束時被摧毀，他們在程式終結時才被摧毀
    ```
    size_t count_calls() {
        static size_t ctr = 0;
        return ++ctr;
    }
    int main() {
        for (size_t i = 0; i != 10; ++i)
            cout << count_calls() << endl;
        return 0;
    }
    ```
## 6.1.2 函式宣告
- 一個函式只能被定義一次，但可以多次宣告，我們可以宣告尚未被定義的一個函式
- 函式宣告沒有函式主體，被用一個分號取代`int face(int val);`
- 函式宣告也被稱為函式原型
### 函式宣告放在標頭檔中
- 宣告一個函式的標頭應該被引入到定義那個函式的源碼檔
## 6.1.3 個別編譯
### 編譯與連結多個源碼檔
- 例子
    - 假設我們fact函式的定義在名為fact.cpp的一個檔案中
    - 其宣告位在名為Chapter6.h的一個標頭檔中。
    - fact.cpp將會引入Chapter6.h標頭。
    - 將呼叫fact的一個main函式儲存在名為factMain.cpp的第二個檔案中
- 要產生一個可執行檔，我們必須告知編譯器要去哪找我們用到的所有程式
- 我們可能會這樣編譯那些檔案
    ```
    g++ factMain.cpp fact.cpp # 產生factMain.exe或a.out
    g++ factMain.cpp fact.cpp -o main
    ```
- 編譯器會讓我們將目的檔連接在一起形成一個可執行檔
    ```
    g++ -c factMain.cpp # 產生factMain.o
    g++ -c fact.cpp # 產生fact.o
    g++ factMain.o fact.o # 產生a.out
    g++ factMain.o fact.o -o main # 產生main
    ```
# 6.2 引數傳遞
- 每次我們呼叫一個函數，它的參數就會被創建，並由在呼叫中傳入的引數初始化
- 當一個參數是參考，我們會說其對應的引數是passed by reference(由參考傳遞)，或者說那個函式是called by reference
- 拷貝了引數值後，參數與引數就是互相獨立的物件了。我們說這種引數是passed by value(由值傳遞)，或者說那個函式是called by value(以值呼叫)
## 6.2.1 藉由值傳遞引數
### 指標參數
- 指標參數由型別是指標的引數初始化，那個指標會被拷貝，不過指標賦予我們對該指標所指的物件間接存取的能力
    ```
    void reset(int *ip) {
        *ip = 0;  // 變更ip所指的物件的值
        ip = 0;  // 指變更ip的區域性拷貝，引數沒有變化
    }
    ```
- 呼叫reset:
    ```
    int i = 42;
    reset(&i);  // i會被改成0
    cout << "i = " << i << endl;
    ```
## 6.2.2 藉由參考傳遞引數
- 更改reset程式，改接受一個參考而非一個指標:
    ```
    // 接受對int的一個參考並將給定的物件設為零
    void reset(int &i) {  // i只是傳給reset的物件的另一個名稱
        i = 0;  // 改變i所指涉的物件的值
    }
    ```
### 使用參考來避免拷貝
- 拷貝大型類別型別或大型容器的物件可能很沒效率。
- 某些類別型別是無法拷貝的
- 例子: 撰寫一個函式來比較兩個string的長度。因為string可能很長，我們希望避免拷貝它們，所以我們會讓參數是參考。因為比較兩個string並不涉及修改它們，我們希望會讓這些參數是對const的參考
- 在一個函式內不會被變更的參考應該要是對const的參考
    ```
    bool isShorter(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
    ```
### 使用參考參數來回傳額外資訊
- 一個函式只能回傳單一個值。
- 有的時候一個函式需要回傳多個值。參考參數就能讓我們回傳多個結果
- 例子:定義名為find_char的函式，回傳一個給定的字元在一個string中出現的第一個位置。我們也希望此函式回傳該字元出現的次數。
    - 目標: 定義能夠回傳一個位置(字元第一次發生)和出現次數的函式
    - 作法: 多傳入一個參考來放置出現的次數 
    ```
    // 回傳s中c第一個出現處的索引
    // 參考參數occurs計數c的出現次數
    string::size_type find_char(const string &s, char c, string::size_type &occurs) {
        auto ret = s.size();
        occurs = 0;
        for (decltype(ret) i=0; i!=s.size(); ++i) {
            if (s[i] == c) {
                if (ret == s.size())
                    ret = i;
                ++occurs;
            }
        }
        return ret;
    }
    ```
## 6.2.3 const參數與引數
- recall: 頂層const就是該物件本身是const
    ```
    const int ci = 42;  // ci是一個const int
    int i = ci;  // i是一個int，有ci的值，拷貝的時候頂層const(ci的)丟了
    int *const p = &i;  // p是*const，指向int，所以p指到i的位置，然後不能改指別人
    *p = 0;  // p指是不能改指別人，可以透過p改值
    ```
- 拷貝引數來初始化參數就和拷貝物件一樣，頂層const會被丟棄，結果就是有個參數是const我們可以傳是const的引數給他，也可以傳不是const的引數給他
    ```
    // 頂層const會被丟棄造就的可能令人訝異的結果
    void fcn(const int i) { /* fcn可以讀取但不能寫入i */ }
    void fcn(int i) { /* */ }  // 錯誤:重新定義了fcn 
    ```
### 指標或參考參數和const
- 記住參數初始化規則和變數一樣
    ```
    int i = 42;
    const int *cp = &i;  // cp是對const int的指標，所以不能由cp去改i
    const int &r = i;  // r是對const int的參考，所以不能由r去改i
    const int &r2 = 42;  // r2是對const int的參考，
    int *p = cp;  // 錯誤: p是指向int的指標，如果把cp指的東西給p指，那就可以改了
    int &r3 = r;  // 錯誤: r3是對int的參考，讓r3去參考對const int的參考
    int &r4 = 42;  // 錯誤
    ```
- 完全相同的初始化規則適用於參數傳遞
    ```
    // 接受對int的指標並把其值設為0的函數
    void reset(int *ip) {
        *ip = 0;
    }
    // 接受對int的參考並把其值設為0的函數
    void reset(int &i) {
        i = 0;
    }
    int i = 0;
    const int ci = i;
    string::size_type ctr = 0;
    reset(&i);  // 給的是一個int的位址: 呼叫接受int*版本的reset
    reset(&ci);  // 給的是一個const int的位址: 錯誤，底層的const保留
    reset(i);   // 給的是一個int: 呼叫接受int&版本的reset
    reset(ci);  // 給的是一個const int: 錯誤，底層的const保留
    reset(42);  // 錯誤，沒辦法直接參考字面值
    reset(ctr);  // 型別不吻合
    find_char("Hello World!", 'o', ctr);
    ```
### 盡可能使用對const的參考
## 6.2.4 陣列參數
- 我們無法拷貝一個陣列
- 我們使用一個陣列的時候，它通常會被轉換為一個指標
    ```
    // 三個相等的宣告
    void print(const int*);  // 指向const int 的指標
    void print(const int[]);  // 看起來是傳入const int陣列，可是會被型別轉換成指向const int的指標然後指在第一個元素
    void print(const int[10]);  // 明確了陣列大小
    ```
- 管理指標參數有三個常見的技巧:
    - 使用一個標記來指定一個陣列的範圍
    - 傳入兩個指標，一個指向陣列中的第一個元素，另一個指向陣列中最後一個元素後的一個位置
    - 明確地傳入一個大小參數
### 使用一個標記來指定一個陣列的範圍
- 需要陣列本身含有一個結尾標記，比如C-style的char array
    ```
    void print(const char *cp) {
        if (cp)
            while (*cp)
                cout << *cp++;
    }
    ```
### 使用標準程式庫的慣例
- 傳入兩個指標，一個指向陣列中的第一個元素，另一個指向陣列中最後一個元素後的一個位置
    ```
    void print(const int *beg, const int *end) {
        while (beg != end)
            cout << *beg++ << endl;
    }
    int j[2] = {0, 1};
    print(begin(j), end(j));
    ```
### 明確地傳入一個大小參數
- 就是定義一個第二參數指出陣列的大小
    ```
    void print(const int ia[], size_t size) {
        for (size_t i = 0; i != size; ++i){
            cout << ia[i] << endl;
        }
    }
    int j[] = { 0, 1 };
    print(j, end(j) - begin(j));
    ```
### 陣列參數與const
### 陣列參考參數
- 把參數定義為對陣列的一個參考
    ```
    void print(int (&arr)[10]) {
        for (auto elem : arr)
            cout << elem << endl;
    }
    ```
- 比較下面這兩個:
    ```
    f(int &arr[10])  // 錯誤: arr是一個大小是10的陣列，裡面放了對int的參考: 參考不是物件
    f(int (&arr)[10])  // arr是一個參考，繫結至有10個int的陣列
    ```
- 比較下面這兩個:
    ```
    int *ip[4];  // ip是一個大小是4的陣列，裡面放的是對int的指標
    int (*ip)[4];  // ip是一個指標，指向裡面放了4個int的陣列
    ```
- 這個有一個缺點喔，因為參考的型別包含了陣列大小
### 傳入一個多維陣列
- 維度是陣列的型別的一部分
- 因為編譯器會自動把陣列轉成指標，這件事在陣列的陣列上，會變成編譯器會忽略多維陣列的第一個維度
## 6.2.5 main: 處理命令列選項
- main的引數最常見的用途是讓使用者指定一組選項來引導程式的作業
- 例子:假設我們的main是個叫prog的可執行檔
    `prog -d -o ofile data0`
- 這樣的命令列選項會透過兩個(選擇性的)參數傳入給main
    `int main(int argc, char *argv[]) { }`
- argv是一個由指標組成的陣列
    `int main(int argc, char **argv)`
- argc是傳入那個陣列中的字串數
    - 在這個例子裡是5
## 6.2.6 帶有不定參數的函式
- 事先並不知道我們需要傳入多少引數給一個函式
- 新的標準提供兩種主要方式撰寫函數接受數目不定的引述
    - 如果所有引數有相同型別，傳入名為initializer_list的程式庫型別
    - 撰寫特殊的函式叫做variadic template
- 特殊的參數型別 ``ellipsis``
    - 這項機能通常只應該用於需要與C函式界接的程式中
### initializer_list參數
- initializer_list是一個程式庫型別
- initializer_list是一個模板型別，所以要給`<>`
    ```
    initializer_list<string> ls;  // string 所構成的initializer_list
    ```
- 注意: initializer中的元素永遠都是const
- 例子
    ```
    void error_msg(initializer_list<string> il) {
        for (auto beg = il.begin(); beg != il.end(); ++beg)
            cout << *beg << " ";
    }
    ```
### Ellipsis參數
- Ellipsis參數之所以會出現在`C++`中，是為了讓程式能與用到C程式庫中varargs機能的C程式碼互動
- Ellipsis參數應該只用於C與`C++`共通的型別之上。特別是，大多數類別型別的物件傳入給ellipsis參數時，都無法正確拷貝
    ```
    void foo(param_list, ...);
    void foo(...);
    ```  
# 6.3 回傳型別與return述句
- return述句會終結正在執行的函式，並將控制權交回到該函式被呼叫的地方。
    - `return;`
    - `return expression;`
## 6.3.1 沒有回傳值的函式
- 不帶任何值的return只能用於回傳型別為void的函式中
- 回傳void的函式不一定要含有一個return
## 6.3.2 回傳一個值的函式
### 值是如何回傳的?
- 值回傳的方式與變數和參數初始化的方式相同
- 可以回傳參考，這樣就不會被拷貝
### 永遠都不要回傳對區域物件的參考或指標
- 當函數執行完畢，儲存區會被釋放，當函數終止，對區域物件的參考會指涉已經無效的記憶體
    ```
    const string &manip() {  // 這行告訴我們它會回傳一個對const string的參考
    string ret;
    // ...
    if (!ret.empty())
        return ret;  // 這個不行，因為ret這個變數在函數結束就被銷毀了，回傳回去結果未定義
    else
        return "Empty";  // 這個也不行，"Empty"是區域性的暫存string
    }
    ```
- 回傳對區域物件的指標或參考結果都是未定義
### 回傳類別型別的函式與呼叫運算子
- 左結合(呼叫運算子)
- 優先序與點號以及箭號相同
- 結果就是: `auto sz = shorterString(s1, s2).size();`
### 回傳的參考是Lvalue
- 複習一下Lvalue: rvalue是物件的值，lvalue是物件的身分
- 一個指定式的左手邊出現函式呼叫的例子:
    ```
    char &get_val(string &str, string::size_type ix) {
    return str[ix];
    }
    int main() {
        string s("a value");
        cout << s << endl;
        get_val(s, 0) = 'A';
        cout << s << endl;
        return 0;
    }
    ```
### 串列初始化回傳值
- 新標準下函式可以回傳由大括號圍起的一串值。
- 記得用大括號括的話不能需要變窄的轉換
- 可以回傳空大括號，那暫存物件就會是值初始化
### 從main回傳
- 只要回傳型別不是void就必定要回傳一個值
- main是例外，main沒有return會自動回傳return 0;
### 遞迴
- 呼叫自己的函式無論是直接或是間接都是遞迴函式
    ```
    int factorial(int val) {
        if (val > 1)
            return factorial(val-1) * val;
        return 1;
    }
    ```
- 一個遞迴函式一定要有一個執行路徑不涉及遞迴呼叫
- main不可以自己呼叫自己
## 6.3.3 回傳對陣列的一個指標
- 因為陣列不會被拷貝，所以一個函式不能回傳一個陣列，但是可以回傳對陣列的指標或參考
- 使用typedef和using簡化陣列的回傳
    ```
    typedef int arrT[10];  // arrT是由十個int所構成的陣列這種型別的同義詞
    using arrT = int[10]; // 等效的arrT宣告
    arrT* func(int i);  // func回傳一個指標，指向由十個int所構成的陣列
    ```
### 宣告會回傳對陣列指標的函式
- 不使用型別別名時陣列維度必須被定義
    ```
    int arr[10];  // arr是一個有十個元素的int陣列
    int *p1[10];  // p1是由十個指向int的指標構成的一個陣列
    int (*p2)[10] = &arr;  // p2是一個指標，指向裝了10個int的陣列
    ```
- 回傳對陣列指標的函式的形式為:
    ```
    Type (*function(parameter_list)) [dimension]  // function回傳的東西是一個指標，指向裝了dimension個Type的陣列
    ```
- 維度必須接在函式的名稱後面出現
### 使用尾端回傳型別(Trailing Return Type)
- 一個尾端回傳型別跟在參數列後，前面接著`->`
- 為了表明回傳跟在參數列後，我們在回傳型別一般出現的地方使用`auto`
    ```
    auto func(int i) -> int(*)[10];
    // func接受一個int的引數
    // 回傳一個指標，指向有10個int的陣列
    ```
### 使用decltype
- 如果清楚函式為之回傳指標的陣列為何，就可以使用decltype
    ```
    int odd[] = {1, 3, 5, 7, 9};
    int even[] = {0, 2, 4, 6, 8};
    decltype(odd) *arrPtr(int i) {
        return (i%2) ? &odd : &even;
    }
    ```
- decltype不會自動把陣列轉成指標喔
# 6.4 重載的函式
- 相同範疇內，具有相同名稱但參數列不同的函式就是重載的
### 定義重載函式
- 參數列(數目、型別)一定要不相同，就算回傳型別不同也不能重載
### 判斷兩個參數型別是否不同
- 參數列有可能等效，即使看起來不同(就是用typedef宣告了別名，可是其實是相同的)
    ```
    Record lookup(const Account &acct); 
    Record lookup(const Account &);
    typedef Phone Telno;
    Record lookup(const Phone&);
    Record lookup(const Telno&);
    ```
### 重載與const參數
- 具有頂層的const的一個參數與沒有頂層的const的參數之間是無法區辨的
- 可以依據參數是對給定型別的const版本或非const版本的參考(或指標)來進行重載
### const_cast重載
### 呼叫一個重載的函式
## 6.4.1 重載與範疇
- 一般來說區域性的宣告一個函式都是壞主意
- 名稱的查找先於型別檢查
- 意思就是說，兩個函式，一個宣告在函數外面，一個宣告在函數裡面，就算符合函式重載的要求(就它們參數數目或型別不一樣)，一樣會錯，因為會先在當下範疇找函式名子，然後遮蔽外層的名子
# 6.5 特殊用途的功能
- 預設引數(default arguments)
- 行內(inline)
- constexpr函式
## 6.5.1 預設引數
- 就直接在宣告函式的時候給值
- 如果一個參數有預設引數，那麼跟在它後面的參數也都要有預設引數
### 以預設引數呼叫函式
- 預設引數由位置解析，意思就是說，給了某個預設引數的話，==前面==的也全都要給
### 預設引數宣告
- 一個函式可以宣告很多次
- 不過如果前面的宣告給了兩個引數
- 後面的至少要給兩個，而且前面給的不能改
- 意思就是可以加不能少
- 預設引數一般應該與函式宣告一起在適當的標頭中指定
### 預設引數初始器
- 區域變數不可以做為預設引數
- 型別能夠轉換為參數之型別的任何運算式
- 用作預設引數的名稱會在函式宣告的範疇解析，名稱所代表的值會在呼叫的時候估算
    ```
    typedef string::size_type sz;
    sz wd = 80;
    char def = ' ';
    sz ht();
    string screen(sz = ht(), sz = wd, char = def);
    string window = screen(); 
    void f2() {
        def = '*';  // 這個會改到，因為它是名稱所代表的值
        sz wd = 100;  // 隱藏wd的外層定義，但並未改變預設值
        window = screen(); 
    }
    ```
- 改變數的值有用，整個重新定義沒用
## 6.5.2 行內與constexpr函式
- 呼叫一個函式會比估算等效的運算式還要來的慢
- 大部分的機器上:
    - 呼叫之前會先儲存暫存器(registers)的內容
    - 回傳後復原
    - 引數可能需要拷貝
    - 程式會分支到新的位置
### inline函式避免了函式呼叫的負擔
- inline函式(通常)每次呼叫都會在行內就地展開
    ```
    cout << shorterString(s1, s2) << endl;  // 呼叫
    cout << (s1.size() < s2.size() ? s1 : s2) << endl;  // 就地展開
    ```
- 在函式的回傳型別前放上關鍵字`inline`來將shorterString定義為一個行內函式:
    ```
    // inline version:
    inline const string& shorterString(const string &s1, const string &s2) {
        return s1.size() <= s2.size() ? s1: s2;
    }
    ```
- `inline`的指定只是一種請求。編譯器可以選擇忽略這項請求
### constexpr函式
- constexpr函式是能被用在常數運算式中的一種函式
- constexpr函式的限制
    - return的型別必須是字面值型別
    - 每個參數都必須是字面值型別
    ```
    constexpr int new_sz() { return 42;}
    constexpr int foo = new_sz();  // foo是一個常數運算式，因為它的初始器是constexpr函數
    ```
- 可以這麼做的時候，編譯器會將對一個constexpr函數的呼叫取代為其結果值
- constexpr函式隱含就是inline的
- 一個constexpr函式不一定要回傳一個常數運算式
- 函式主體必須只含有剛好一個return述句
- 一個constexpr函式的主體可以含有其他的述句，只要那些述句不會在執行時期產生任何動作就行。舉例來說，一個constexpr函式可以含有null述句、型別別名，或是using宣告
### 將inline與constexpr函式放在標頭檔中
- inline和constexpr函式可以被定義很多次，可是一個給定的inline或constexpr的所有定義必須吻合，結果就是一般會定義在標頭檔中
## 6.5.3 用於除錯的輔助功能
- 使用類似header guards的技巧來條件式地執行除錯程式碼
- 程式可以含有只會在程式開發過程中執行的除錯程式碼
- 這種作法用到兩個前置處理機能`assert`和`NDEBUG`
### assert前置處理器巨集
- assert是一種前置處理巨集
- 前置處理巨集是行為有點類似inline函式的一種前置處理器變數
- assert巨集接受單一個運算式，用來當作一個條件:`assert(expr);`
- 如果該運算式為false，那麼assert會寫出一個訊息，然後終止程式。
- assert巨集定義在cassert標頭中
- 前置處理器的名稱是由前置處理器來管理，而非編譯器，因此我們會直接使用前置處理器名稱，不用為它們提供using宣告
### NDEBUG前置處理器變數
- assert的行為取決於名為NDEBUG的前置處理器變數的狀態
- 如果NDEBUG有定義，assert就什麼都不會做
- 預設情況下NDEBUG**沒有**定義
- 提供一個#define來定義NDEBUG藉此關閉除錯
    ```
    g++ -D NDEBUG main.C 
    ```
- 這個效果等同於在main.c的開頭寫上#define NDEBUG
- `__func__`變數
    ```
    void print(const int ia[], size_t size) {
    #ifndef NDEBUG
    // __func__是由編譯器所定義的一個區域性的static，用以存放函式的名稱
    cerr << __func__ << " : array size is " << size << endl;
    #endif
    }
    ```
- 用到一個名為`__func__`的變數來印出我們正在除錯的函式之名稱
- 編譯器會在每個函式定義`__func__`，它是一個區域性的static陣列，由const char所構成，用來存放函式名稱
- 前置處理器定義的除錯名稱:
    - __FILE__含有檔案名稱的字串字面值
    - __LINE__含有目前行號的整數字面值
    - __TIME__含有檔案編譯時間的字串字面值
    - __DATE__含有檔案編譯日期的字串字面值
- 使用這些常數在錯誤訊息中回報額外的資訊
    ```
    if (word.size() < threshold)
        cerr << "Error: " << __File__
             << " : in function " << __func__
             << " at line " __LINE__<<endl;
             << " compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << " word read was \"" << word
             << "\": Length too short" << endl;
    ```
# 6.6 函式匹配
- 當重載的函式有相同的參數數目:
    ```
    void f();
    void f(int);
    void f(int, int);
    void f(double, double = 3.14);
    f(5.6);  // 呼叫void f(double, double)
    ```
### 判斷候選函式與合用的函式
- 第一步: 為給定的呼叫識別出一組應該考慮的重載函式，這個集合中的函式就是候選函式
- 第二步: 從候選函式集合選出能以給定呼叫中的引數來呼叫的那些函式，選出來的函式就是合用的函式，所謂合用就是參數數目必須與引數數目相同，而且型別匹配
### 找出最佳匹配
- 引數和參數的型別之間越接近，匹配程度就越好
### 多個參數的函式匹配
- 規則:
    - 每個引數的匹配程度都不會比任何其他的合用函式差
    - 至少有一個引數的匹配程度比其他任何合用函式所提供的都還要好
## 6.6.1 引數型別之轉換
- 為可用來將每個引數之型別轉為其對應參數之型別的轉換方法做排名。
- 轉換法的排位方式如下:
    1. 完全符合
        - 引數和參數的型別完全相同
        - 引數是從陣列或函式型別轉為對應的指標型別
        - 頂層的const會被加到引數或從之移除
    2. 透過const轉換的匹配
    3. 透過提升的匹配
    4. 透過算數或指標轉換的匹配
    5. 透過類別型別轉換的匹配
### 需要提升或算數轉換的匹配
### 函式匹配與const引數
# 6.7 指向函式的指標
- 代表一個函式而非物件的指標
- 函式型別由其回傳型別和參數所決定
- 一個函式: 
    `bool lengthCompare(const string &, const string &);`
- 有型別``bool(const string&, const string&)``
- 宣告函式指標: ` bool (*pf) (const string &, const string &);  //未初始化`
### 使用函式指標
- 使用函式的名稱作為一個值，那個函式就會自動被轉為一個指標
- 例子:
    ```
    pf = lengthCompare;  // pf現在是指向名為lengthCompare函式的指標
    pf = &lengthCompare;  // 等效的指定
    ```
- 呼叫該函示:
    ```
    bool b1 = pf("hello", "goodbye");  // 呼叫lengthCompare
    bool b2 = (*pf)("hello", "goodbye");  // 等效的呼叫
    bool b3 = lengthCompare("hello", "goodbye");  // 等效的呼叫
    ```
### 對重載函式的指標
- 例子:
    ```
    void ff(int*);
    void ff(unsigned int);
    void (*pf1) (unsigned int) = ff;  // pf1指向ff(unsigned)
    ```
- 必須完全匹配
### 函式指標參數
- 無法定義函式型別的參數，但可以有參數是對函式的指標
- 把函數當成引數傳到參數列時會自動轉成指標
### 回傳對函式的指標
- 和陣列一樣，無法直接回傳一個陣列，但可以回傳對陣列的一個指標
- 編譯器會自動將一個函式回傳型別視為對應的指標型別
    ```
    using F = int(int*, int);  // F是一個函式型別，不是指標
    using PF = int (*) (int*, int);  // PF是一個指標型別
    ```
- 不同於具有函式型別的參數，這個型別不會自動被轉成指標
    ```
    PF f1(int);  // ok: PF是對函式型別的一個指標
    F f1(int);  // x: F是一個函式型別，不是指標，不能回傳一個函式型別
    F *f1(int);  // ok: 明確指定回傳型別是一個對函式的指標
    int (*f1(int))(int*, int); 
    // f1是一個函式，而且前面接著*，
    // 所以f1回傳一個指標，
    // 那個指標的型別本身有一個參數列，
    // 所以該指標指向一個函式，
    // 那個函式回傳一個int
    ```
- 使用尾端回傳簡化
    ```
    auto f1(int) -> int (*)(int*, int);
    ```
### 為函式指標型別使用auto或decltype
- 使用decltype簡化
    ```
    string::size_type sumLength(const string&, const string&);  // sumLength是一個函式
    string::size_type largerLength(const string&, const string&);
    decltype(sumLength) *getFcn(const string &);
    // getFcn回傳函式型別的指標
    ```
- decltype不會自動轉，所以前面加上了*





