# ch14_Overloaded_Operations_and_Conversions
###### tags: `C++Primer`
[TOC]
- 定義運算子套用到類別型別的物件上時的意義
- 為類別型別定義轉換，類別型別的轉換會像內建型別的轉換一樣，會在必要時被隱含用來將一個型別的物件轉為另一個型別
# 14.1 基本概念
- 以一個operator加上符號定義重載運算子
- 有一個回傳型別、一個參數列，以及一個主體
- 重載運算子函式的參數數目和該運算子所有的運算元數一樣。
- 在二元運算子中，左手邊的運算元會被傳入第一個參數，右手邊的運算元則被傳入第二個
- 除了重載的函式呼叫運算子()外，重載運算子不可以有預設引數
- note: 當一個重載運算子是一個成員函式，this會繫結到左運算元。成員運算子函式的(明確)參數數，比運算元數少一。
- 一個運算子函式必須是某個類別的一個成員，或至少有一個參數是類別型別，這太表我們無法改變運算子套用到內建型別運算元時的意義
    ```
    // 錯誤: 無法為int重新定義內建運算子
    int operator+(int, int);
    ```
- 只能重載既有的運算子，而且不能發明新的運算子符號QQ
- +-*&既是單元運算子也是二元運算子
### 直接呼叫一個重載運算子函式
- ==運算子函式的呼叫==
    ```
    // 對一個非成員的運算子函式之等效呼叫
    data1 + data2;  // 一般的運算式
    operator+(data1, data2);  // 等效的函式呼叫
    // 對成員運算子的呼叫
    data1 += data2;  // 基於運算式的呼叫
    data1.operator+=(data2);  // 對一個成員運算子函式的等效呼叫
    ```
### 某些運算子不應該重載
- 邏輯AND、邏輯OR以及逗號運算子對於運算元估算順序的保證並不會保留，重載的&&和||也不會保留短路估算QQ
- 一般來說，逗號，取址、邏輯AND、邏輯OR運算子都不應該被重載。
### 使用與內建意義一致的定義
- 當你設計一個類別，你永遠都應該先思考該類別要提供哪些運算
- 你知道有哪些運算，你才應該思考是否要把給個運算定義為一個普通函式或一個重載運算子
### 指定和複合指定運算子
- 負責任的程式設計師絕對不會定義operator+來進行減法
- 常見但仍不可取的，是扭曲一個運算子的正常意義以強迫符合一個給定的型別
### 選擇成員或非成員實作
- 運算子的指導原則
    - 指定(=)下標([])呼叫(())和成員存取箭號必須被定義為成員
    - 複合指定一般應當是成員
    - 會改變物件狀態的運算子通常應該是成員，比如說遞增遞減和解參考
    - 對稱的運算子，也就是可能會轉換他們運算元的，例如算術、相等性、關係、和位元通常應該被定義為一般的非成員函式
- 說明必須是非成員函式的運算子例子
    - 如果operator+是string類別的成員，就沒辦法char* + string

# 14.2 輸入與輸出運算子
- 支援IO的類別一般會為這些運算子定義重載的版本
## 14.2.1 重載輸出運算子`<<`
- 一般來說第一個參數是對一個非const ostream物件的參考
    - 非const是因為寫入資料流會改變其狀態
    - 傳參考是因為無法拷貝ostream物件
- 第二個參數應該是對const的一個參考，指向我們想要列印的型別
### Sales_data的輸出運算子
- 為Sales_data寫輸出運算子
    ```
    ostream &operator<<(ostream &os, const Salse_data &item) {
        os << item.isbn() << " " << item.units_sold << " "
           << item.revenue << " " << item.avg_price();
        return os;
    }
    ```
### 輸出運算子通常只會進行最少的格式化
- 一般來說，輸出運算子應該僅以最少的格式化印出物件的內容。它們不應該印出一個newline
### IO運算子必須是非成員函式
- 不能是成員函式的主因是這樣左運算元就不能是io，可是我們又想要混用
    ```
    Sales_data data;
    data << cout;  // 如果operator<<是Sales_data的一個成員，這樣能看嗎-.-
    ```
- IO運算子通常也需要印出非public的成員，結果就是通常會被宣告為friend
## 14.2.2 重載輸入運算子`>>`
- 輸入運算子的第一個參數都是一個參考，指向讀取來源的資料流，第二個參數則是指向作為存放位置(非const)物件的一個參考，此運算子通常會回傳對它被給定的資料流的一個參考。
### Sales_data輸入運算子
- Sales_data的輸入運算子
    ```
    istream *operator>>(istream &is, Sales_data &item) {
        double price;  // 沒必要初始化
        is >> item.bookNo >> item.units_sold >> price;
        if (is)  // 檢查輸入是否成功
            item.revenue = item.units_sold * price;
        else
            item = Sales_data();  // 輸入失敗，物件預設狀態
        return is;
    }
    ```
- note: 輸入運算子必須處理輸入可能失敗的可能性；輸出運算子一般不用去管
### 輸入過程中的錯誤
- 失敗類型
    - 錯誤的資料類型
    - end-of-file
- 不檢查每次讀取，而是在使用資料前讀取
- 記得讓物件恢復成一種有效的狀態
- 輸入運算子應該決定要做什麼事來進行錯誤復原，如果要做的話。
### 指出錯誤
- [ ] 8.1.2 例外處理
- 通常一個輸入運算子應該只設定failbit
- 設定eofbit暗指檔案已經耗盡
- 設定badbit則代表該資料流已損毀
- 這些錯誤最好留給IO程式庫本身來指出
# 14.3 算術與關係運算子
- 為了左運算元的自動轉換，算術和關係運算子會不是成員函式，由於不需要改變成員狀態，所以參數一般都是對const的參考
    ```
    // Sales_data的+運算子
    Sales_data
    operator+(const Sales_data &lhs, const Sales_data &rhs) {
        Sales_data sum = lhs;
        sum += rhs;
        return sum;
    }
    ```
- 算術運算子和相關的複合指定都有定義的類別，一般應該使用複合指定來實作算術運算子
## 14.3.1 相等性運算子
- 通常是比較每一個資料成員，然後只在所有對應的成員都相等時，才視兩個物件相等
- 設計原則:
    - 定義有==運算子的類別比較容易與程式庫容器和演算法並用
    - 如果一個類別定義了==，那個運算子一般應該判斷給定的物件是否含有等效的資料
    - 一般來說相等性運算子應該具有遞移性
    - 如果有==應該也有!=
    - 相等性或不等性，其中一個應該把工作委派給另一個。
- 相等性對它們來說有邏輯上意義的類別一般都應該定義operator==。定義有==的類別讓使用者能夠更容易把該類別與程式庫演算法一起使用
## 14.3.2 關係運算子
- 因為關聯式容器和某些演算法會使用小於運算子，定義operator<可能會有用處。
- 關係運算子應該
    - 定義出與作為關聯式容器的key必須滿足的需求(嚴格的弱次序，不能a<b然後b又<a)
    - 必須與==一致(如果兩個物件彼此!=，那麼一個物件就應該<另一個)
- Sales_data其實不應該定義<運算子
    - 以逐元素比較的方式定義沒有意義
    - 單比較某向元素與==不一致
- 如果<有唯一的邏輯定義存在，類別通常就應該定義<運算子。然後，而果類別也有==，就必須把<定義的與==產出的結果一致
# 14.4 指定運算子
- 除了拷貝和移動，還可以定義允許其他型別為右運算元的指定運算子
- `v = {"a", "an", "the"}`這個可以由接受initializer_list的指定運算子做
- `StrVec &operator=(std::initializer_list<std::string>);`
- note: 指定運算子可以重載，指定運算子，不管參數型別為何，都必須定義為成員函式。
### 複合指定運算子
- 指定運算子必須是，而複合指定運算子一般應該被定義為成員。這些運算子應該回傳一個參考指向左運算元。
# 14.5 下標運算子
- note: 下標運算子必須是一個成員函式
- 如果類別有一個下標運算子，它通常應該定義兩個版本: 一個回傳普通的參考，而另一個則是一個const成員，並回傳對const的一個參考。
- 指標有下標運算子(不管是指向陣列的指標還是指向int的指標)
- ![](https://i.imgur.com/GxvaYpu.png)

# 14.6 遞增與遞減運算子
- 定義有遞增和遞減運算子的類別應該前綴和後綴兩種版本都定義。這些運算子通常應該被定義為成員(沒有強制)。
### 定義前綴遞增或遞減運算子
- 為了與內建的運算子一致，前綴運算子應該回傳一個參考，指向對遞增過或遞減過的物件
    ```
    class StrBlobPtr {
     public:
      StrBlobPtr &operator++(); // 前綴
      StrBlobPtr &operator--();
      // 其他成員一如以往
    }
    ```
### 區分前綴與後綴運算子
- 前綴和後綴運算子都定義，會出現一般的重載無法區分的問題，為了解決這個問題後綴版本接受一個額外的(未使用)參數，型別為int
- 當我們使用這個運算子，編譯器會提供0作為這個參數的引數
- 為了與內件運算子一致，後綴運算子應該回傳舊的(未遞增或未遞減的)值。那個值會被回傳為一個值，而非一個參考。
- note: 那個int參數沒被使用，所以我們並未賦予它名稱
### 明確呼叫後綴運算子
- 明確呼叫後綴運算子的時候要傳入int
    ```
    p.operator++(0);  // postfix
    p.operator++(); // prefix
    ```
# 14.7 成員存取運算子
- Note: 箭號運算子必須是一個成員，解參考運算子沒必要是成員，但通常也應該是成員，
- 我們將這些運算子定義為const成員，擷取一個元素並不會改變StrBlobPtr的狀態
### 箭號運算子回傳值的限制
- Note: 重載的箭號運算子必須回傳對某個類別型別的一個指標，或是定義有自己箭號運算子的某個類別型別的一個物件。
- ==沒看很懂==
# 14.8 函式呼叫運算子
- 重載函式呼叫運算子，使得以它為型別的物件能被當作函式使用
- 名為absInt的struct具有一個呼叫運算子
    ```
    struct absInt {
        int operator() (int val) const {
            return val < 0 ? -val : val;
        }
    };
    // 使用
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    ```
- Note: 函式呼叫運算子必須是一個成員函式。一個類別可以定義多個版本的呼叫運算子，每個與其它的都必須在參數的數目和型別上有差異
- 定義有呼叫運算子的物件被稱為函式物件。這種物件行為就像函式
### 具有狀態的函式物件類別
- 讓使用者提供不同類別的資料流，或提供不同的區隔符號
    ```
    class PrintString {
    public:
        PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) { }
        void operator()(const string &s) const { os << s << sep; }
    private:
        ostream &os;
        char sep;
    };
    ```
- 函式物件最常用作泛用演算法的引數。
## 14.8.1 Lambdas是函式物件
- 當我們撰寫一個lambda，編譯器會將那個運算式轉譯為一個無名類別的一個無名物件
- 和lambda類似行為的物件
    ```
    [](const string &a, const string &b) { return a.size() < b.size();}
    class ShorterString {
    public:
      bool operator() (const string &s1, const string &s2) const {
          return s1.size() < s2.size()
      }
    };
    ```
### 表示具有捕捉的Lambdas的類別
- 當lambda以參考捕捉一個變數，程式必須確保參考所指的變數再那個lambda執行時仍然存在
- 以參考捕捉時沒有資料成員，以值捕捉時會拷貝為資料成員
    ```
    // lambda:
    [sz] (const string &a)
    // 同義類別:
    class SizeComp {
    public:
        SizeComp(size_t n) : sz(n) { }
        bool operator()(const string &s) const { return s.size() >= sz;}
    private:
        size_t sz;
    }
    ```
- 注意: 沒有預設建構器(已刪除)
- 該類別是否有預設的或已刪除的拷貝或移動建構器，則取決於所捕捉的資料成員之型別
## 14.8.2 程式庫定義的函式物件
- 標準程式庫定義了一組類別用以代表算術、關係和邏輯運算子。每個類別都定義了一個呼叫運算子以套用那個具名的運算。
    - plus類別的函式呼叫運算子會套用+到一對運算元
    - modulus類別定義的呼叫運算子會套用二元的%的運算子
    - equal_to類別則套用==
- 這些類別都是我們會為之提供單一個型別的模板
    - `plus<string>`會套用string的加法運算子到string物件
    - `plus<int>`的運算元是int
    - `plus<Sales_data>`對Sales_data套用+
    ```
    plus<int> intAdd;
    negate<int> intNegate;
    // 使用intAdd來相加
    int sum = intAdd(10, 20);  // sum = 30
    sum = intNegate(intAdd(10, 20));  // sum = -30
    ```
- 這些類別都定義在functional標頭中
    - 算術類別
    ```
    plus<Type>
    minus<Type>
    multiplies<Type>
    divides<Type>
    modulus<Type>
    negate<Type>
    ```
    - 關係類別
    ```
    equal_to<Type>
    not_equal_to<Type>
    greater<Type>
    greater_equal<Type>
    less<Type>
    less_equal<Type>
    ```
    - 邏輯類別
    ```
    logical_and<Type>
    logical_or<Type>
    logical_not<Type>
    ```
### 將一個程式庫函式物件與演算法並用
- 這些類別通常被用來複寫某個演算法所用的預設運算子。
- 預設情況排序演算法使用`operator<`
    - 所以預設的排序是遞增
- 使用範例: 把sort換成遞減:
    ```
    sort(svec.begin(), svec.end(), greater<string>());
    ```
- 這些程式庫函式物件的重要面向是，程式庫保證他們能用於指標
    - 比較兩個不相關的指標是未定義的
    ```
    vector<string*> nameTable;  // 指標所成的vector
    // 錯誤: nameTable中的指標是不相關的，因此<是未定義的
    sort(nameTable.begin(), nameTable.end(),
    [](string *a, string *b) { return a < b; })
    // ok: 程式庫保證指標型別上的less是定義良好的
    sort(nameTable.begin(), nameTable.end(), less<string*>());
    ```
## 14.8.3 可呼叫的物件和function
- `c++`的可呼叫物件: 函式與對函式的指標、lambda、bind所創建的物件，以及重載了函式呼叫運算子的類別
- 一個可呼叫物件有一個型別，比如說，每個lambda有它自己唯一的(無名)類別型別
- 函式與函式指標的型別隨著它們的回傳型別和引數型別而改變
- 不同型別的可呼叫物件可以共用**呼叫特徵式**
- **呼叫特徵式**指出呼叫物件會回傳什麼型別，以及必須在呼叫中傳入的引數型別
### 不同的型別可以有相同的呼叫特徵式
- 問題: 想要共用一個呼叫特徵式的數個可呼叫物件視為具有相同的型別
    ```
    // 一般的函式
    int add(int i, int j) { return i + j; }
    // lambda: 產生一個無名的函式物件類別
    auto mod = [](int i, int j) {return i % j; };
    // 函式物件類別
    struct divide {
        int operator()(int denominator, int divisor) {
            return denominator / divisor;
        }
    };
    ```
- 即使這些callable有不同型別，它們共用相同的呼叫特徵式`int(int, int)`
- 問題: 無法直接使用map直接做出函式表(問題在於，這幾個可呼叫物件的型別不同
### 程式庫的function型別
- 使用名為function的新程式庫解決這個問題，它定義在functional標頭
- function是一個模板，要在角括號內提供呼叫特徵式`function<int(int, int)>`
    ```
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j) { return i * j; };
    ```
- 將`function<int(int, int)>`放入map的value
### 重載的函式與function
- 無法直接把重載函式的名稱儲存到型別為function的一個物件中
    ```
    int add(int i, int j) { return i + j; }
    Sales_data add(const Sales_data&, const Sales_data&);
    map<string, function<int(int, int)>> binops;
    binops.insert( {"+", add} );  // 錯誤: 哪個add?
    ```
- 可以使用lambda解決
    ```
    binops.insert( {"+", [](int a, int b) {return add(a, b);}});
    ```
- 也可以使用函式指標解決
    ```
    int (*fp)(int, int) = add;
    ```
- Note: 新程式庫中的function類別與之前程式庫版本中名為unary_function和binary_function的類別無關。這些類別因為較廣義的bind函式而被棄用

# 14.9 重載、轉換與運算子
- 可以把某個型別藉由建構器(單一引數、非explic)轉換成我們的類別型別
- 我們也可以定義轉自(from)類別型別的轉換
- 轉換建構器(converting constructors)和轉換運算子(class-type conversions)定義類別型別的轉換(把某個自訂類別，轉換成目標類別)
## 14.9.1 轉換運算子
- 轉換運算子: 一種特殊的成員函式，可以把某個類別型別的值轉為其他型別的值
    ```
    operator type() const;
    ```
- 轉換運算子可定義給能夠讓函式回傳型別的任何型別(除了void以外)(所以不能轉換至一個陣列或一個函式型別)
- 轉換運算子沒有明確寫定的回傳型別，也沒有參數，而且他們必須被定義為成員函式。`operator 型別() const;`
- 轉換運算一般不應該改變他們正在轉換的物件。因此轉換運算子通常應該被定義為const成員
- Note: 一個轉換函式必須是成員函式，不能指定回傳型別，而且必須有一個空的參數列。這種函式通常應該是const的
### 定義具有轉換運算子的類別
- 定義一個小型類別，表示從0到255的範圍中的一個整數:(看這個的時候一直想到量化)
    ```
    class SmallInt {
    public:
        SmallInt(int i = 0) : val(i) {
            if (i < 0 || i > 255)
                throw std::out_of_range("Bad SmallInt value");
        }  // i是只能在(0, 255)的int
        operator int() const { return val; }
    private:
        std::size_t val;
    }
    ```
- 建構器會把算數型別的值轉為一個SmallInt
- 轉換運算子會把SmallInt物件轉為int:
    ```
    SmallInt si;
    si = 4;  // 4被轉為SmallInt
    si + 3;  // 隱含的將si轉為int，後面接著整數的加法運算
    ```
- 編譯器一次只會套用一個使用者定義的轉換
- 一個隱含的使用者定義轉換前後可以接著一個標準的(內建)轉換
    ```
    // double會透過內建的轉換被轉為int
    SmallInt si = 3.14;  // 呼叫SmallInt(int)建構器
    // SmallInt轉換運算子將si轉為int
    si + 3.14;  // 那個int會透過內建的轉換被轉為double
    ```
- 轉換運算子是隱含套用的，你沒辦法傳入引數給這些函式，因此轉換運算子不可以被定義成會接受參數
- 雖然轉換函式並沒有指定回傳型別，每個轉換函式都必須回傳其對應型別的一個值:
    ```
    class SmallInt;
    operator int(SmallInt&);  // 錯誤:非成員
    class SmallInt {
    public:
        int operator int() const;  // 錯誤:回傳型別
        operator int(int = 0) const;  // 錯誤:參數列
        operator int*() const { return 42;}  // 錯誤:42不是一個指標
    }
    ```
### 轉換運算子可能產出令人意外的結果
- 實務上類別鮮少提供轉換運算子。比較常見的是，使用者會對自動發生的轉換感到驚訝，而不是因為轉換的存在而得到幫助。
- 但，類別定義對bool的轉換並非不常見。
- 早期的問題:
    - 假設istream有對bool的轉換，那麼下列程式碼就能編譯:
    ```
    int i = 42;
    cin << i;  // 如果對bool的轉換是不明確的
    // 這邊cin轉成bool，然後bool被提升為int然後對bool做左移運算子
    ```
### explicit轉換運算子
- 為了防止隱含轉換bool造成的奇怪後果
    ```
    class SmallInt {
    public:
        // 編譯器不會自動套用這個轉換
        explicit operator int() const { return val; }
    };
    ```
- 如果轉換運算子是explicit的，我們仍然能夠進行轉換。然而，除了一個例外(條件運算式可以隱含轉)，我們必須透過強制轉型明確的那麼做。
    ```
    // 強制轉型:
    SmallInt si = 3;  // ok: SmallInt建構器不是explicit的
    si + 3;  // 錯誤，需要隱含的轉換，但operator int是explicit的
    static_cast<int>(si) + 3;  // ok: 明確請求轉換
    ```
- [ ] review 4.11.3: 任何定義良好的型別轉換，除了涉及低階const的那些，都可以使用一個static_cast來請求
    ```
    int i, j;
    double slope = static_cast<double>(j) / i;
    ```
- 編譯器會把一個explicit的轉換套用到用作條件的一個運算式上
    - if、while或do
    - for的條件
    - NOT OR And
    - ?:中的條件
### 轉換為bool
- 對bool的轉換通常是要用在條件中。因此，operator bool一般應該被定義為explicit。
## 14.9.2 避免模零兩可的轉換
- 要確保從類別型別到目標型別的轉換只存在一種方式。如果有多種方式可以進行轉換，很難寫出無歧異的程式碼
- 多轉轉換路徑的出現
    - 兩個類別提供相互轉換
        - 例子:
        - 類別A定義了接受B物件的轉換建構器
        - B本身也定義了隊型別A的一個轉換運算子
    - 定義多個轉換至或自他們之間本身就有轉換關係的類別
- 一般來說定義具有相互轉換，獲能夠轉自或轉至兩個算數型別的類別，都不是好主意
### 引數匹配與相互轉換
- 定義了兩種方式來從一個B獲得一個A
    ```
    // 兩個類別有相互轉換通常不是好主意
    struct B;
    struct A {
        A() = default;
        A(const B&);  // 把一個B轉換為A
    };
    struct B {
        operator A() const;  // 也將B轉換為A
    };
    A f(const A&);
    B b;
    A a = f(b);  // 錯誤
    // 有歧異的:f(B::operator A())
    // 或f(A::A(const B&))
    A a1 = f(b.operator A());  // ok 明確呼叫
    A a2 = f(A(b));  // ok 明確呼叫
    ```
### 歧異與對內建型別的多重轉換
- 最有問題的轉換: 類別定義的轉換會轉向(或轉自)多個本身有轉換關係的型別(轉至或轉自一個以上的算術型別)
- 以下類別具有的轉換建構器轉自兩個不同的算術型別，也有轉至兩個不同算術型別的轉換運算子:
    ```
    struct A {  // 這通常不是好主意
        A(int = 0);  // 從int轉A
        A(double);  // 從double轉A
        operator int() const;  // 從A轉int
        operator double() const;  // 從A轉double
    };
    void f2(long double);
    A a;
    f2(a);  // 錯誤: 有歧異
    // 可以是f(A::operator int())
    // 也可以是f(A::operator double())
    long lg;
    A a2(lg);  // 錯誤: 有歧異
    // 可以是A::A(int)
    // 也可以是A::A(double)
    ```
- note: 當兩個使用者定義的轉換被使用時，接在那個轉換函式之前或之後的標準轉換的位階，如果有的話，會被用來選擇最佳匹配
### 重載的函式和轉換建構器
- 在多個轉換之間挑選的過程會在呼叫重載函式時變得更複雜
- 如果有兩個或更多個轉換提供了合用的匹配，那麼那些轉換會被視為一樣好。
- 例子: 產生歧異的問題會出現在重載函式接受的參數只差在類別型別，而且那些類別定義了相同的轉換建構器:
    ```
    struct C {
        C(int);
    };
    struct D {
        D(int);
    };
    void manip(const C&);
    void manip(const D&);
    manip(10);  // 錯誤: 有歧異
    // manip(C(10))
    // 或manip(D(10))
    manip(C(10));  // ok
    ```
- 需要使用一個建構器或強制轉型來為一個重載函式呼叫中的引數進行轉換，經常是不良設計的跡象。 
### 重載函式和使用者定義的轉換
- 在對一個重載函式的呼叫中，如果兩個(或更多個)使用者定義的轉換提供了合用的匹配，那些轉換會被視為一樣好(上面的例子都是使用者定義所產生的歧異)
- 可能需要的任何標準轉換不會被考慮在內，是否也需要某個內建轉換，只會在重載的集合可以使用相同的轉換函式匹配時，才會被考慮
    ```
    struct E {
        E(double);
    };// E有轉自double的轉換
    void manip2(const C&);  // C有轉自int的一個轉換
    void manip2(const E&);
    // 錯誤，有歧異: 有兩個不同的使用者定義轉換可以使用
    manip2(10);  // manip2(C(10))
    // or manip2(E(10))
    ```
- 注意上面，即使其中一個呼叫需要標準轉換，而另一個是完全匹配，編譯器仍會將這個呼叫標示為錯誤
- Note: 在對一個重載函式的呼叫中，額外標準轉換的位階(如果有的話)只在合用的函式需要相同的使用者定義轉換時，才有重要性。如果需要的是不同的使用者定義轉換，那麼呼叫就有歧異。
## 14.9.3 函式匹配與重載的運算子
- 重載的運算子是重載函式
- 一般的函式匹配程序會被用來判斷要把哪個運算子，不管是內建或重載的，套用到一個給定的運算式上。
- 當運算子函式被用在一個運算式中，候選函式所成的集合會比我們使用呼叫運算子呼叫一個函式時還要廣
    ```
    // a sym b 可能是:
    a.operatorsym(b);
    operatorsym(a, b);
    ```
- 不同於函式呼叫，我們無法使用呼叫的形式來區分我們是在呼叫一個非成員或一個成員(運算子)
- 當我們將一個重載運算子用於類別型別的運算元上，候選函式包括:
    - 那個運算子一般的非成員版本
    - 內建版本
    - 如果左運算元有類別型別，類別定義的重載版本也會算在內
- note: 用於一個運算式中的運算子之候選函式集合，可能包含非成員及成員函式。
    ```
    class SmallInt {
        friend
        SmallInt operator+(const SmallInt&, const SmallInt&);
    public:
        SmallInt(int = 0);  // int to SmallInt
        operator int() const { return val; }  // SmallInt to int
    private:
        std::size_t val;
    };
    ```
- 歧異問題:
    ```
    SmallInt s1, s2;
    SmallInt s3 = s1 + s2;  // 使用重載的operator+
    int i = s3 + 0;  // 錯誤: 有歧異
    ```
- 第一個加法使用重載的+，接受兩個SmallInt。
- 第二個加法有歧異
    - 0可以轉為SmallInt，並使用SmallInt版本的+
    - s3可以轉為int，然後在int上用內建的加法
- 對算術型別的轉換函式和對相同類別型別的重載運算子都提供，可能會導致重載運算子和內建運算子之間的歧異