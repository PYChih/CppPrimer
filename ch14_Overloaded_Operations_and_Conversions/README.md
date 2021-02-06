# ch14_Overloaded_Operations_and_Conversions
###### tags: `C++ exercise`
[TOC]
# 14.1 基本概念
- [ ] 14.1: 重載運算子與內箭運算子之間有什麼差異呢?在哪些方面重載運算子會跟內建運算子一樣呢?
    - 不同:
        - 可以直接呼叫重載的運算子
        - 重載的運算子至少有一個型別是類別
        - 估算順序(逗號)短路運算(&&和||)沒有保留在重載運算子
    - 同:
        - 重載和內建運算子的優先級相同
        - 參數數目相同(二元、一元)
- [ ] 14.2: 為Sales_data的輸入、輸出、加法和複合指定運算子撰寫重載的宣告。
- [ ] 14.3: string與vector都定義了一個重載的`==`用以比較那些型別的物件。假設svec1與svec2是存放string的vector，請識別出下列各個運算式中套用了哪個版本的`==`:
    ```
    // a
    "cobble" == "stone";
    // b
    svec1[0] == svec2[0];
    // c
    svec1 == svec2;
    // d
    svec1[0] == "stone"
    ```
- [ ] 14.4: 說明如何判斷下列何者應該是類別成員:
    ```
    // a: %
    // b: %=
    // c: ++
    // d: ->
    // e: <<
    // f: &&
    // g: ==
    // h: ()
    ```
- [ ] 14.5: 在7.5.1練習7.40中，你為下列類別撰寫了輪廓。請判斷你的類別應該提供什麼重載運算子(如果需要的話)。
    ```
    // a: Book
    // b: Date
    // c: Employee
    // d: Vehicle
    // e: Object
    // f: Tree
    ```
# 14.2 輸入與輸出運算子
## 14.2.1 重載輸出運算子`<<`
- [ ] 14.6: 為你的Sales_data類別定義一個輸出運算子
- [ ] 14.7: 為你在$13.5練習中所寫的String類別定義一個輸出運算子。
    - [ ] const_cast?
- [ ] 14.8: 為7.5.1練習7.40中你選的類別定義一個輸出運算子
## 14.2.2 重載輸入運算子`>>`
- [ ] 14.9: 為你的Sales_data類別定義一個輸入運算子
- [ ] 14.10: 給定下列輸入，請描述Sales_data輸入運算子的行為:
    ```
    // a
    0-201-99999-9 10 24.95
    // b
    10 24.95 0-210-99999-9
    ```
    - a: 正常讀入
    - b: 把10轉成string讀入isbn，24讀入，.95讀入
- [ ] 14.11: 如果有的話，下列Sales_data的輸入運算子有什麼問題呢?如果我們提供這個運算子給前一個練習中的資料，會發生什麼事呢?
    ```
    istream &operator>>(istream &in, Sales_data &s) {
        double price;
        in >> s.bookNo >> s.units_sold >> price;
        s.revenue = s.units_sold * price;
        return in;
    }
    ```
    - 不會檢查讀取失敗的情況，遇到非法值會使用未初始化的double
- [ ] 14.12: 為你在$7.5.1練習7.40使用的類別定義一個輸入運算子。確保那個運算子能夠處理輸入錯誤
# 14.3 算術與關係運算子
- [ ] 14.13: 如果有的話，你認為Sales_data應該支援另外的哪些運算子?定義出你認為該類別應該包含的那些運算子
- [ ] 14.14: 為什麼你會認為定義operator+去呼叫operator+=會比較有效率，而不是反過來呢?
    - +=會直接拿繫結的rhs來加
    - operator+通常需要在函式裡面造一個臨時變量
- [ ] 14.15: 練習7.40中你所選的類別要定義算術運算子嗎?如果有請實作它們。如果沒有請解釋原因
## 14.3.1 相等性運算子
- [ ] 14.16: 為你的StrBlob(12.1.1)、StrBlobPtr(12.1.6)、StrVec(13.5)和String(13.5)類別定義相等性和不等性運算子
- [ ] 14.17: 你為$7.5.1練習7.40所選的類別應該定義相等性運算子嗎?如果是，請時作它們。如果不是，請解釋原因
## 14.3.2 關係運算子
- [ ] 14.18: 為你的StrBlob、StrBlobPtr、StrVec與String類別定義關係運算子
    - [ ] StrBlob、StrBlobPtr
    - [ ] StrVec
        - https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    - [ ] String
- [ ] 14.19: 你為7.5.1練習7.40所選的類別應該定義關係運算子嗎?如果是，請實作它們。如果不是，請解釋原因
    - 本來想按照revenue排序的(或是average prive)但容易遇到單一邏輯問題
# 14.4 指定運算子
- [ ] 14.20: 為你的Sales_data類別定義加法和複合指定運算子
- [ ] 14.21: 把Sales_data的運算子寫成+會進行實際的加法，而+=會呼叫+。討論這種做法的缺點，與$14.3和14.4定義這些運算子的方法做比較。
    - 先實作+: 左右運算元以對const的參考傳遞，拷貝建構左運算元給temp，將左運算元加上右運算元，回傳Sales_data的複製，解構Sales_data。再以+實作+=
    - 先實作+=: 之後實作+的時候，左右運算元以對const的參考傳遞，拷貝建構左運算元給temp，呼叫+=，回傳Sales_data的複製，解構
    - 兩個方法在+的時候步驟一樣，可是+=如果後實作步驟會多
- [ ] 14.22: 定義一種版本的指定運算子，可以將代表一個ISBN的string指定到Sales_data。
- [ ] 14.23: 為你的StrVec類別版本定義一個initializer_list指定運算子
- [ ] 14.24: 判斷你用於7.5.1練習7.40中的類別是否需要拷貝或移動指定運算子。如果是，就定義那些運算子。
- [ ] 14.25: 實作你的類別應該定義的任何其他指定運算子。解釋哪些型別應該用做運算元，以及原因。
# 14.5 下標運算子
- [ ] 14.26: 為你的StrVec、String、StrBlob與StrBlobPtr類別定義下標運算子
# 14.6 遞增與遞減運算子
- [ ] 14.27: 為你的StrBlobPtr類別新增遞增與遞減運算子
- [ ] 14.28: 為StrBlobPtr定義加法和減法，以讓那些運算子實作指標算術
- [ ] 14.29: 我們沒有定義遞增和遞減運算子的const版本，為什麼呢
# 14.7 成員存取運算子
- [ ] 14.30: 新增解參考和箭號運算子到你的StrBlobPtr類別，以及你在12.1.6練習12.22中所定義的ConstStrBlobPtr。注意到ConstStrBlobPtr中的運算子必須回傳const參考，因為ConstStrBlobPtr中的資料成員指向一個const vector。
- [ ] 14.31: 我們的StrBlobPtr類別並沒有定義拷貝建構器、指定運算子或解構器。為什麼這不會有問題
    - StrBlobPtr的成員有: 一個weak_ptr，一個size_t
    - 解構器: 他們都有各自的解構器，所以可以用合成的解構器
    - 拷貝建構器，他們可以使用合成的拷貝建構器
    - 指定運算子，他們可以使用合成的拷貝指定運算子 
- [ ] 14.32: 定義一個類別存放對StrBlobPtr的一個指標。為這個類別定義重載的箭號運算子
# 14.8 函式呼叫運算子
- [ ] 14.33: 一個重載的函式呼叫運算子可以接受多少個運算元
    - 0~n?
- [ ] 14.34: 定義一個函式物件類別來進行一種if-then-else運算: 這個類別的呼叫運算子應該接受三個參數。它應該測試它的第一個參數，而當測試成功，它應該回傳它的第二個參數；否則，它應該回傳它的第三個參數。
- [ ] 14.35: 撰寫一個像是PrintString的類別，從一個istream讀取一行輸入，並回傳一個string表示我們所讀到的東西。如果讀取失敗就回傳空的string。
- [ ] 14.36: 使用來自前面練習的類別，讀取標準輸入，並將每一行都儲存為一個vector中的一個元素。
- [ ] 14.37: 撰寫一個類別測試兩個值是否相等。使用該類別的物件和程式庫演算法寫一個程式來取代一個序列中給定的值出現的每個地方
## 14.8.1 Lambdas是函式物件
- [ ] 14.38: 寫一個類別測試一個給定的string之長度是否符合一個給定的界線。使用該類別的物件撰寫一個程式，回報一個輸入檔中，有多少字詞的長度落在1到10之間(包括兩端)。
- [ ] 14.39: 修改前面的程式，回報長度從1到9，以及10或更多的字詞分別有多少。
- [ ] 14.40: 改寫10.3.2的biggies函式，使用函式物件類別取代lambda。
- [ ] 14.41: 你認為新標準為何要新增lambda呢?說明你何時會使用lambda，何時會自行撰寫類別。
    - 函數對象在使用上的簡化
    - 當函數對象會被多次使用，就自行撰寫類別
    - 當函數對象使用一次或是很簡單就用lambda
## 14.8.2 程式庫定義的函式物件
- [ ] 14.42: 使用程式庫的函式物件和轉接器，定義一個運算來
    ```
    // a 計算大於1024的值有多少個
    // b 找出第一個不等於pooh的字串
    // c 將所有的值乘以2
    ```
- [ ] 14.43: 使用程式庫的函式物件，判斷一個給定的int值是否能夠以一個int容器中的任何元素來整除。
## 14.8.3 可呼叫的物件和function
- [ ] 14.44: 撰寫你自己版本的簡單桌上型計算器來處理二元運算
# 14.9 重載、轉換與運算子
## 14.9.1 轉換運算子
- [ ] 14.45: 撰寫轉換運算子來將Sales_data轉為string和double。你認為這些運算子應該回傳什麼值呢?
- [ ] 14.46: 說明定義這些Sales_data轉換運算子是否式好主意，以及它們是否應該為explicit。
    - 轉換為double有歧異，它有可能可以代表平均售價，也有可能代表revenue
    - 轉換為string可能可以不過我沒想到用途
    - 兩者都應該定義為explicit
- [ ] 14.47: 解釋這兩個轉換運算子之間的差異:
    ```
    struct Integral {
        operator const int();
        // 轉換後的型別是const int
        // 且轉換有可能可以改變物件本身的值(非const)
        operator int() const;
        // 轉換不會改變物件本身，回傳一個普通的int
    };
    ```
- [ ] 14.48: 判斷7.5.1練習7.40中你所用的類別是否應該有對bool的轉換。如果是，請解釋原因，並說明這個運算子是否應該是explicit。如果不是，請解釋為何不。
- [ ] 14.49: 不管那樣做是不是好主意，為前面練習的類別定義一個對bool的轉換。
## 14.9.2 避免模零兩可的轉換
- [ ] 14.50: 指出ex1和ex2可能的類別型別轉換程序。解釋這些初始化是否合法。
    ```
    struct LongDouble {
        LongDouble(double = 0.0);
        operator double();
        operator float();
    };
    // double可以轉成ld
    // ld可以轉成double
    // ld可以轉成float
    LongDouble ldObj;  // 定義一個ldObj
    int ex1 = ldObj;  // 錯誤
    // ex1可以由double轉成int
    // 也可以由float轉成int
    float ex3 = ldObj;
    // ldObj轉成float完全匹配
    ```
- [ ] 14.51: 指出呼叫每一個版本的calc所需要的轉換程序(如果有的話)，並解釋最佳的合用函式被選取的原因
    ```
    void calc(int);
    void calc(LongDouble);
    double dval;
    calc(dval);  // 哪個calc?
    // calc接受int或LongDouble
    // dval是double
    // 內建轉換從double到int可以呼叫calc
    // 使用者定義轉換double可以轉成LongDouble
    ```
## 14.9.3 函式匹配與重載的運算子
- [ ] 14.52: 如果有的話，哪個operator+會被選來套用到下列每一個加法運算式?列出候選函式、合用函式，以及每個合用函式的引數適用的型別轉換
    ```
    struct LongDouble {
        // 成員operator+用於說明用途
        // +通常是非成員
        LongDouble operator+(const SmallInt&)
        LongDouble(double = 0.0);
        operator double();
        operator float();
    };
    LongDouble operator+(LongDouble&, double);
    SmallInt si;
    LongDouble ld;
    ld = si + ld;
    ld = ld + si;
    ```
- `ld = si + ld;`
    - si只能轉成int
    - ld可以轉成double或float
    - 這邊的歧異在於operator+(int, double)和operator+(int, float)
    - 成員函式的那個只有在左運算元才被考慮(就是下一個)
- `ld = ld + si;`
    - ld有成員函式operator+(SmallInt)且為精確匹配
    - 其他可行的就是上一題的兩個
- [ ] 14.53: 給定前面SmallInt的定義，判斷下列加法運算式是否合法。如果是，用的是哪個加法運算子呢?如果不是，你會如何變更程式碼，讓它變得合法?
    ```
    SmallInt s1;
    double d = s1 + 3.14;
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
