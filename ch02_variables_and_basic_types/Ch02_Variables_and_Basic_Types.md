# Ch02_Variables_and_Basic_Types
###### tags: `C++Primer`
[TOC]
# 2.1 原始內建型別
- 算數型別
- void
## 2.1.1 算數型別
- 算數型別分為兩類
    - 整數值型別
        - 包括字元和boolean
    - 浮點數型別
- 算數型別所含的位元數隨機器不同而不同
    - 位元數可能不同，一個型別能表達的最大/最小值也不同
- 內建型別的機器層級表示法
    - 能夠定址的記憶體最小的組塊稱為一個位元組(byte)
    - 儲存的基本單位則稱作一個字組(word)
    - 在多數機器上，一個位元組有8個位元，而一個字組則是32或64位元。
### 有號和無號型別
- 型別int、short、long、long long全都是有號的。我們會在型別前面加上unsigned來獲得對應的無號型別。
- char、signed char、unsigned char是三種不同的型別(相對於整數只有兩種)。雖然有三種字元型別，表示法一樣只有兩種: 有號與無號，兩種型別何者等同於char取決於編譯器。
- 建議: 判斷要使用哪個型別
    - 當知道值不能為負時，就用一個無號型別。
    - 如果資料值比int保證的最大還大就用long long
    - 別在算術運算式使用一般的char或bool。只用他們存放字元或真假值，
    - 使用double進行浮點運算，float通常沒有足夠的精度，而且雙精度計算的成本與單精度計算的成本之間的差異微乎其微。
## 2.1.2 型別轉換
- 建議：避免未定義或由實作定義的行為
    - 避免由實作定義的行為： 例如假設int的大小是固定而且已知的值。這種程式被說是無法移植的。

### 涉及無號型別的運算式
- unsigned不能小於零，不然會繞回來

- 注意: 別混用有號與無號型別
## 2.1.3字面值
### 整數與浮點數字面值
- 使用十進位、八進位或十六進位記法來寫出一個整數字面值
    ```
    20;  // 十進位
    024;  // 八進位，以0開頭
    0x14;  // 十六進位，以0x或0X開頭
    ```
- 浮點數字面值
    ```
    3.14;
    3.14E0;
    0.;
    0e0;
    .001;
    ```
### 字元與字元字串字面值
- 一個字串字面值的型別為常數chars所成的陣列
    ```
    'a';  // 字元字面值
    "Hello World!";  // 字串字面值
    ```
- 編譯器會在每個字串字面值後附加一個null字元，因此字串字面值實際長度會比表面上多一
- `'A'`代表單一字元A，而`"A"`則代表兩個字元所組成的一個陣列: 字母A和null字元
- 看起來相鄰且只以空格分隔的兩個字串字面值會被串接
    ```
    std::cout << "a really, really long string literal "
                 "that spans two lines" << std::endl;
    ```
### 轉義序列
### 指定一個字面值的型別
- 寫一個long字面值，請使用大寫L，因為l太容易看成1
### Boolean與指標字面值
- true和false是型別bool的字面值
- nullptr則是指標字面值
# 2.2 變數
- 每個變數都有一個型別
## 2.2.1 變數的定義
- 簡單的定義: `int sum = 0, value;`
    - 一個定義可以選擇性的為他所定義的一或多個名稱提供一個初始值。
- 名詞解釋: 什麼是物件
    - 最廣義的用法：一個物件是具有型別的一個記憶體區域。我們會自由使用物件這個詞，不管指稱的物件有內建型別或類別型別、具名或不具名，或是否可讀寫。
### 初始器
- 一個被初始化(initialized)的物件會在它被創建之時得到所指定的值。
- 初始化並非指定。初始化發生在一個變數於創建之時被賦予一個值的時候。指定則會抹消一個物件目前的值，並以一個新的值取代之。
### 串列初始化
- 使用下列四種不同方式的任何一種來定義一個名為units_sold的int變數，並將之初始化為0
    ```
    int units_sold = 0;
    int units_sold = {0};
    int units_sold{0};
    int units_sold(0);
    ```
- 大括號用於初始化是作為新標準的一部分被引進的。
- 使用大括號初始被稱為串列初始化
- 如果初始器可能導致資訊損失，編譯器不會讓我們串列初始化內建型別的變數
    ```
    long double ld = 3.1415926536;
    int a{ld}, b = {ld};  // 錯誤: 需要轉換為更狹窄的型別
    int c(ld), d = ld;  // 可行，但值會被截斷
    ```
### 預設初始化
- 一開始定義變數的時候沒有使用初始器，變數會以預設的方式被初始化。這種變數會被賦予預設的值。這個預設值是什麼，取決於該變數的型別，也可能取決於該變數是在何處定義的。
- 在一個函式內定義的內建型別變數都是未初始化的
- 定義在一個函式主體內的內建型別未初始化物件會有未定義的值。我們未明確初始化的類別型別物件會有由該類別所定義的值。
## 2.2.2 變數宣告與定義
- 個別編譯能讓我們將程式分割為數個檔案，其中每一個都能獨立編譯。
- 為了支援個別編譯，`c++`區別所謂的宣告(declarations)和定義(definitions)。
- 注意: 未初始化的變數導致執行期問題
- extern 關鍵字
    ```
    extern int i; //宣告但不定義i
    int j; //宣告並定義k
    extern double pi = 3.1416 //定義
    ```
- note: 變數必須剛好只定義一次，但可以被宣告很多次
- 關鍵概念: 靜態定型
    - c++是一種靜態定型的語言，這代表型別是在編譯時期進行檢查。
## 2.2.3識別字
### 變數名稱的慣例
- 一個識別字應該對它的意義做出一些提示。
- 變數名稱一般都是小寫，也就是index，而非Index或INDEX。
- 就跟Sales_item一樣，我們定義的類別通常以一個大寫字母開頭。
- 帶有多個字詞的識別字應該在視覺上區別每一個字，舉例來說，student_loan或studentLoan，而非studentload。
## 2.2.4 一個名稱的範疇
- `c++`的範疇(scope)由大括號來界定
- 相同的名稱可以在不同的範疇中指涉不同的實體
# 2.3 複合型別
- 就是以其他型別來定義的一種型別
- 本章主要涵蓋參考(references)和指標(pointers)
- 一個宣告是一個基礎型別(basetype)後面接著一串宣告器(declarators)。每個宣告器指名一個變數，並賦予該變數一個與基礎型別關聯的型別。
## 2.3.1 參考
- 一個參考為一個物件定義了一個替代名詞
- 我們定義一個參考的方式是寫出`&d`這種形式的一個宣告器，其中d是被宣告的名稱:
    ```
    int ival = 1024;
    int &refVal = ival;  // 參考至ival (是ival的另一個名稱)
    int &refVal2;  // 錯誤: 一個參考必須經過初始化
    ```
- 因為參考沒辦法重新繫結，所以參考必須被初始化
### 一個參考就是一個別名(Alias)
- Note: 一個參考並不是一個物件，而只是一個已經存在的物件之另一個名稱。
### 參考的定義
- 例子:
    ```
    int i = 1024, i2 = 2048;
    int &r = i, r2 = i2;
    int i3 = 1024, &ri = i3;
    int &r3 = i3, &r4 = i2;
    ```
## 2.3.2 指標
- 不同於參考，一個指標本身就是一個物件。
- 定義一個指標型別的方式是寫出`*d`這種形式的宣告器，其中d是被定義的名稱。
    ```
    int *ip1, *ip2;
    double dp, *dp2;
    ```
### 取用一個物件的位址
- 一個指標存放另一個物件的位址
    ```
    int ival = 42;
    int *p = &val;
    ```
### 指標值
### 使用一個指標來存取一個物件
- Note: 我們只能解參考指向一個物件的有效指標
- 關鍵概念: 某些符號有多個意義
    ```
    int i = 42;
    int &r = i;  // r是一個參考
    int *p;  // p是一個指標
    p = &i;  // &被用在運算式中做為address-of運算子
    *p = i;  // *被用在一個運算式中做為dereference運算子
    int &r2 = *p  // *是dereference運算子
    ```
### NULL指標
- 使用字面值nullptr來初始化指標
- 將一個int變數指定給一個指標是不合法的，即使那個變數的值剛好是0也一樣
- 建議: 初始化所有指標
    - 未初始化的指標很難debug
    - 就算沒東西初始化，也把它指向nullptr
### 指定和指標
- 指標和參考都提供了對其他物件的間接存取
- 最重要的是，參考不是物件，指標是
- 指標可以指向不同的值
- 當我們使用一個參考，永遠是該參考最初繫結的那個物件
### 其他的指標運算
- 把指標放到if後面: 不是空指標就是true
- 把指標放進==: 有相同位子就是true，如果兩個都是null也是true
### `void*`指標
- `void*`是一個特殊的型別: 可以存放任何物件的位址
    ```
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd
    ```
- 我們能對一個void* 指標做的事情有限：
    - 將它與其他指標做比較
    - 將它傳給一個函式
    - 從一個函式回傳它
    - 將它指定給另一個`void*`指標
    - 無法做運算，因為不知道型別
## 2.3.3 了解複合型別之宣告
- 單一定義可以定義不同型別的變數
    `int i = 1024, *p = &i, &r = i;`
### 定義多個變數
- `int *p1, p2`這個宣告基礎型別是int，不過p1是int*、p2是int。

### 指向指標的指標
- 例子: 
    ```
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi
    cout << The value of ival\n"
         << "direct value: " << ival << "\n";
         << "indirect value : " << *pi << "\n"
         << "doubly indirect value :" << **ppi
         <<endl;
    ```
### 對指標的參考
- 參考不是物件。因此不能有對參考的指標。
- 指標是物件，所以我們能夠有對指標的一個參考。
    ```
    int i = 42;
    int *p;
    int *&r = p;
    r = &i;
    *r = 0
    ```
# 2.4 const限定詞
- 我們有辦法使一個變數無法變更，只要將該變數的型別定義為const即可`const int bufSize = 512;`
- 必須被初始化
### 初始化與const
- 一個物件的型別定義那個物件能夠執行的運算
- const的限制: 只能使用不會變更一個物件的那些運算
- 不會改變物件值的運算之中包含了初始化: 當我們使用一個物件來初始化另一個物件，其中任一個是否為const或兩者皆是，並不重要:
    ```
    int i = 42;
    const int ci = i;
    int j = ci;
    const int i = get_size();
    const int j = 42;
    ```
### 預設情況下，const物件是範疇限於一個檔案的區域物件
- 要在多個檔案之間共用一個const物件，你必須將那個變數定義為extern。
## 2.4.1 對const的參考
- 對const的參考無法被用來變更該參考所繫結的物件
- const物件一定要用對const的參考
    ```
    const int ci = 1024;
    int i = 2048;
    const int &r1 = ci;  // r1是對const的參考，ci是const int
    const int &r2 = i;  // r2是對const的參考，i是int
    int &r3 = ci; // 錯誤，ci是const，對const只能用對const的參考
    r1 = 24;  // 錯誤，const參考不能改
    r2 = 48;  // 錯誤，const參考不能改
    ci = 24;  // 錯誤，const不能改
    i = 48;  // ok，int可以改
    cout << r2 << endl;  //  r2現在是48，它是對const的參考，可是底層的物件可能會被改
    ```
- 判斷方式: 如果可以參考(不是用對const的參考)，那就可以改，但是本質上不能改const，所以這樣的述句會錯誤。
### 初始化與對const的參考
- 對const的參考，不一定要參考const，而且也可以參考字面值
    ```
    int i = 42;
    const int &r1 = i;  // 對const的參考繫結至普通的int
    const int &r2 = 1;  // 對const的參考繫結至字面值
    const int &r3 = r1 * 2;  // 對const的參考繫結至一個通用算式
    ```
### 對const的一個參考可能指涉不是const的一個物件
- const參考這個事情，只會限制我們可以透過那個參考做些什麼事
- 底層的物件可能不是const
    ```
    int i = 42;
    int &r1 = i;  // r1參考i，改r1會改i
    const int &r2 = i;  // const int r2參考i，r2不給改
    r1 = 0;  // 這個會改到i
    cout << "current i value : " << i << endl;
    cout << "current r2 value : " << r2 << endl;
    ```
## 2.4.2 指標與const
- 定義指向const或指向非const的指標(解參考後能不能改，這個和對const的參考一樣)
- 一個const只能給對const的指標指
- 對const的指標不能用來變更該指標所指的物件
    ```
    const double pi = 3.14;  // pi是個const
    double *ptr = &pi;  // 錯誤，const只能給對const的指標指
    const double *cptr = &pi;  // ok, 對const的指標指向一個const
    *cptr = 42;  // 錯誤，對const的指標不能改值 
    double dval = 3.14;  // dval是一個double
    cptr = &dval;  // 對const的指標去指非const可以，而且對const的指標可以去指別人，只是指到的值不給改
    ```
### const指標
- 在*之後放上const
    ```
    int errNumb = 0;
    int *const curErr = &errNumb;  // curErr永遠指向errNumb
    const double pi = 3.14;  // pi是個const
    const double *cptr = &pi;  // cptr是個對const的指標
    const double *const pip = &pi;  // 這個指標不能去指別人(因為*cont)，而且也不能從它這邊去改別人的值(因為指到的東西是const)
    ```
## 2.4.3 頂層的const
- 指標是能夠指向不同物件的一種物件，結果就是，我們能夠獨立地談論一個指標是否為const和它所指的物件是否為const
- 當一個指標能夠指向一個const物件，我們就稱那個const是一個低層const
- 頂層const表示一個物件本身是const
- 更廣義來說，物件本身不能改，const是頂層
    ```
    int i = 0;
    int *const p1 = &i;  // p1不能變更，const是頂層: p1是const指標
    const int ci = 42;  // ci不能變更，const是頂層
    const int *p2 = &ci;  // p2是指向const int的指標，p2可以改指別人，const是低層
    const int *const p3 = p2;  // 對p3來說，const int是低層，同上，*const是頂層
    const int &r = ci;  // r是對const的參考，r不能去改ci的值，但是ci的值可以改，所以const是低層
    ```
- 當我們在拷貝物件時，頂層的const會被忽略
    ```
    i = ci;  // 拷貝ci的值，頂層的const被忽略
    p2 = p3;  // p2可以改指別人，因為const是低層，可是p2沒辦法去改指到的人，也因此可以把p3給p2，不管p2指誰，p2都沒辦法去改它指到的人
    ```
- 頂層const可以被忽略，但低層const永遠不會被忽略
## 2.4.4 constexpr與常數運算式
- 常數運算式: 其值不能被改變，而且可在編譯時期估算的一種運算式(相對於編譯時期估算，也有執行時期估算)
- 例子:
    - 字面值是一種常數運算式
    - 從常數運算式初始化的一個const物件也是常數運算式
- 是否為常數運算式取決於其型別和初始器
    ```
    const int max_files = 20;  // max_files是一個常數運算式: 因為他是const物件，而且是由常數運算式初始化
    const int limit = max_files + 1;  // limit是一個常數運算式，因為他是const物件，由常數運算式初始化
    int staff_size = 27;  // 不是const物件，所以不是常數運算式
    const int sz = get_size();  // sz是一個const，可是他的值要等到runtime才知道，所以不是常數運算式(?)
    ```
### constexpr變數
- 在一個大型系統中可能很難確定一個初始器是否為常數運算式，我們可能以一個我們認為是常數運算式的初始器定義了一個const變數
- 使用constexpr宣告: 我們可以請求編譯器驗證一個變數是否為常數運算式，只要在一個constexpr宣告中宣告那個變數就行了
    ```
    constexpr int mf = 20; 
    constexpr int limit = mf+1;
    constexpr int sz = size();  // 只有在size是一個constexpr函式時ok
    ```
- 一般來說，為你要當作常數運算式的變數使用constexpr會是一個好主意。
### 字面值型別
- 能在一個constexpr中使用的型別被稱作字面值型別
- 算數、參考、指標都是字面值型別
- 還有其他字面值型別(比如字面值類別7.5.6)
- 在函式內定義的變數通常不會儲存在固定位址。因此我們不能使用一個constexpr指標來指向那種變數。
### 指標和constexpr
- 當我們在constexpr宣告中定義一個指標，其中的constexpr限定詞是套用到指標上，而非指標所指的型別
    ```
    const int *p = nullptr;  // p是一個指向const int的指標
    constexpr int *q = nullptr;  // q是一個constexpr指標，指向int，這個差別就是，他不能指別人，可是他指到的值是可以改的
    constexpt int *np = nullptr;  // np是常數指標，指向是null的int
    int j = 0;
    constexpr int i = 42;  // i的型別是const int
    // i和j必須定義在任何函式之外
    constexpr const int *p = &i;  // p是常數指標，指向型別為const int的i
    constexpr int *p1 = &j;  // p1是常數指標，指向型別為int的j
    ```
- constexpr會在它定義的物件上施加一個頂層的const
# 2.5 處理型別
## 2.5.1 型別之別名
- 以typedef定義型別之別名
    ```
    typedef double wages;  // wages是double的同義詞
    typedef wages base, *p;  // base是double的同義詞，p則是double*的同義詞
    ```
- using別名宣告
    ```
    using SI = Sales_item;  // SI是Sales_item的一個同義詞
    ```
- 別名宣告將=左手邊的名稱定義為出現在右手邊的型別的一個別名
### 指標、const以及型別別名
- 使用代表複合型別的別型別名和const的宣告可能產生令人意外的結果，不能直接用字面值替代來解讀，要搞清楚形容的對象。
    ```
    typedef char *pstring;  // 這代表：char *的別名是pstring，所以說，pstring是指向char的指標
    const pstring cstr = 0;  // 這個是指，以const修飾pstring，也就是說，cstr指的是對char的常數指標。意思就是const修飾的是一個指標，所以它是常數指標
    const char *pstring = 0;  // pstring是一個指標，指向const char，和上面不同，是一個指向const的指標
    const pstring *ps; // ps是一個指標，指向一個指向char的常數指標
    ```
## 2.5.2 auto型別指定符
- 讓編譯器為我們找出這個型別，只要是用auto型別指定符。
- 和double這樣的型別指定符不同，auto指定的不是特定型別，而是告知編譯器從初始推演出型別，由此可見使用auto作為其型別的變數必定要有一個初始器。
    ```
    auto item = val1 + val2;  // item初始化為val1+val2的結果
    ```
- 可以用auto一次宣告多個變數，但因為一個宣告只能涉及單一個基礎型別，宣告中的所有變數的初始器都必須有與彼此一致的型別
    ```
    auto i = 0, *p = &i;
    auto sz = 0, pi = 3.14;  // 錯誤: sz和pi的型別不一致
    ```
### 複合型別、const以及auto
- 編譯器為auto推倒的型別不一定會跟初始器的型別完全吻合
    ```
    int i = 0, &r = i;  // r是i的一個別名，它有型別int
    auto a = r;  // a的型別是int
    ```
- auto通常會忽略頂層的cont
    ```
    const int ci = i, &cr = ci;  // ci是一個const int，cr是一個對const int的參考
    auto b = ci;  // b 是一個int (頂層const丟棄)
    auto c = cr;  // c 是一個int 
    auto d = &i;  // d是一個int*
    auto e = &ci;  // e是一個 const int*
    auto &g = ci;  // g是對const int的參考
    ```
- 若希望具有頂層const
    `const auto f = ci;`
- 參考或指標是特定宣告器的一部分，而非該宣告基礎型別的一部分
    ```
    auto k = ci, &l = i;  // ci是const int，k是int，i是int，l是int&
    auto &m = ci, *p = &ci;  //ci是const int，m是對const int的參考，所以m的型別是const int&，p是指向const int的指標，所以p的型別是const int*，是說const int只能給const int*指，但是const int不一定都是指const int，也有可能是指int
    auto &n = i, *p = &ci; n是int的參考，所以n是int&，p是指向const int的指標，所以p是const int*所以這個會報錯
    ```
## 2.5.3 decltype型別指定符
- 想要編譯器從一個運算式推導出來的型別，但不想要使用那個運算式來初始化該變數: 使用decltype
- 回傳其運算元的型別。
    `decltype(f()) sum = x;  // sum具有f回傳的任何型別`
- 編譯器賦予sum的型別會與我們呼叫f回傳的型別相同。
- decltype會回傳該變數的型別，包括頂層const和參考:
    ```
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;  // x 是const int
    decltype(cj) y = x;  // y是const int &
    decltype(cj) z;  // 錯誤: 因為z是const int & 所以不能沒給初始值
    ```
### decltype和參考
- 某些運算式會使decltype產生參考型別
    - 涉及解參考的運算是會使decltype回傳參考
    ```
    int i = 42, *p = &i, &r = i;
    decltype(r);  // 這個會是參考型別，因為r是參考
    decltype(r+0) b;  // r是i的參考，i是int，int+0是int，b是int
    decltype(*p) c;  // 錯誤，c是int&，必須被初始化 
    ```
- decltype((variable))永遠都會是參考型別
- decltype(variable)只有在variable是參考時才會是參考。
# 2.6 定義我們自己的資料結構
- 最基本的層次，資料結構是將相關的資料元素聚集成組的一種方式，也是使用那些資料的一種策略。
- 我們藉由定義一個類別來定義出我們自己的資料型別。
## 2.6.1 定義Sales_data型別
- 我們類別的定義如下:
    ```
    struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    };
    ```
- 類別以關鍵字struct開頭，後面接著類別名稱，以及一個(可能為空的)類別主體。
- 結束類別主體的大括號後面必須跟著一個分號，分號的必要性是因為，我們可以在類別主體後定義變數。
    ```
    struct Sales_data { /* ... */} accum, trans, *salesptr;
    struct Sales_data { /* ... */ };
    Sales_data accum, trans, *salesptr;
    ```
### 類別資料成員
- 可為資料成員提供一個類別內的初始器。
- 沒有初始器的成員會以預設方式初始化
## 2.6.2 使用Sales_data類別
- 程式的輸入會是這樣:
    ```
    0-201-78345-X 3 20.00
    0-201-78345-X 2 25.00
    ```
- 每筆交易都存有一個ISBN、售出的本數，以及每本書賣出的售價(相同ISBN有可能售價不同)
### 相加兩個Sales_data物件
- 假設Sales_data類別定義於Sales_data.h中
- 整體而言程式有下列結構：
    ```
    #include <iostream>
    #include <string>
    # include "Sales_data.h"
    int main() {
        Sales_data data1, data2;
        // 讀取資料到data1和data2的程式碼
        // 檢查data1和data2是否有相同ISBN的程式碼
        //若是如此，印出data1和data2的總和
    }
    ```
### 讀取資料到Sales_data物件
- string型別用來保存一序列的字元
- 運算包括: >>(讀取)、<<(寫入)與==(比較字串)
- 撰寫程式碼來讀取第一筆交易:
    ```
    double price = 0; 
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // 從price和units_sold計算出總營收
    data1.revenue = data1.units_sold * price;
    ```
### 印出兩個Sales_data物件的總和
- 檢查兩個sales_data是否有相同的isbn，若是如此就印出總和
    ```
    if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    //印出: ISBN、總售出數、總營收、每本平均售價
    std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt !=0)
        std::cout << totalRevenue/totalCnt << std::endl;
        return 0; //代表成功
    } else { //交易紀錄沒有相同的ISBN
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1; //代表失敗
    }
    ```
## 2.6.3 撰寫我們自己的標頭檔
- 類別一般不會定義在函式內
- 當我們在函式外定義一個類別，在任何給定的原始碼檔案中，那個類別的定義只能有一個。
    - 為了確保定義只能有一個，通常類別定義在標頭檔中
    - 標頭通常含有在任何給定的檔案中只能被定義一次的實體(ex: 類別定義或const與constexpr變數)
- 因為標頭經常需要使用來自其他標頭的機能(ex 定義一個含有string成員的類別，必須include string.h標頭)，所以我們很可能會include一個標頭兩次以上，所以我們必須以引入多次也安全的方式來撰寫我們的標頭
- note: 每當一個標頭被更新，使用該標頭的那些原始碼檔案必須被重新編譯，以取得新的或變更過的宣告

### 前置處理器的簡介
- 我們通常依賴**前置處理器**: 是一個會在編譯器之前執行的程式，**前置處理器變數**就是由這個程式管理
- 當前置處理器看到``#include``，它會將那個``#include``取代為指定的標頭檔之內容
- c\+\+使用前置處理器來定義**標頭守衛(header guards)**
- 標頭守衛仰賴前置處理器變數
- 前置處理器變數有兩種可能的狀態: 已定義(defined)或未定義(not defined)。
- defined指示詞接受一個名稱，並將該名稱定義為一個前置處理器變數。
- 如果變數已經定義，``#ifdef``就會是true
- 如果變數沒有定義，``#ifndef``就會是true
- 如果測試結果為true，那麼接在``#ifndef``或``#ifdef``後一直到對應的``#endif``前的所有東西都會被處理。
- 範例:
```
#ifndef SALES_DATA_H
#define SALES_DATA_H // SALES_DATA_H就是一個前置處理器變數
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
```
- 前置處理器變數通常以全大寫寫成