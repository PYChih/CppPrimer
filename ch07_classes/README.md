# Ch07_Classes
###### tags: `C++ exercise`
[TOC]
# 7.1 定義抽象資料型別
## 7.1.1 設計Sales_data類別
- [ ] 7.1: 為來自1.6的交易處理程式寫出另一個版本，使用你為2.6.1中練習所定義的Sales_data類別
## 7.1.2 定義修訂版的Sales_data類別
- [ ] 7.2: 為你在$2.6.2的練習寫的Sales_data類別加上combine和isbn成員。
- [ ] 7.3: 修改$7.1.1你寫的交易處理程式，使用那些成員
- [ ] 7.4: 撰寫一個名為Person的類別，代表一個人的名稱和地址。使用一個string來存放那些元素。後續的練習會逐步新增功能到這個類別 
- [ ] 7.5: 在你的Person中提供運算來回傳人的名稱和地址。這些函式應該是const嗎? 解釋你的選擇
## 7.1.3 定義非成員的類別相關函式
- [ ] 7.6: 定義你自己版本的add、read與print函式
- [ ] 7.7: 改寫你為$7.1.2中練習所寫的交易處理程式，使用這些新的函式。
- [ ] 7.8: 為什麼read將它的Sales_data參數定義為一個普通的參考，而print將其參數定義為對const的一個參考
    ```
    // read在給值，不能是const，print只是印值，一般來說不希望改就會給const
    ```
- [ ] 7.9: 為你在7.1.2練習中所寫的程式碼新增能夠讀取和印出Person物件的運算。
- [ ] 7.10: 下列if述句中的條件在做些什麼?
    ```
    if (read(read(cin, data1), data2))  // 因為read會回傳istream，所以是讀了data1之後又讀data2
    ```
## 7.1.4 建構器
- [ ] 7.11: 為你的Sales_data類別新增建構器，並寫一個程式來使用那每一個建構器。
- [ ] 7.12: 將接受一個istream的Sales_data建構器之定義移到Sales_data類別的主體中。
- [ ] 7.13: 改寫7.1.1的程式，使用這個istream建構器。
- [ ] 7.14: 寫出另一個版本的預設建構器，讓它將那些成員明確的初始化為我們提供做為類別內初始器的那些值。
- [ ] 7.15: 新增適當的建構器到你的Person類別中
## 7.1.5 拷貝、指定與解構
# 7.2 存取控制與封裝
- [ ] 7.16: 如果有的話，存取指定符在一個類別定義內出現的位置和頻率有什麼限制?怎麼樣的成員應該定義於一個public指定符後? 什麼種的應該是private
    ```
    // 一個類別可以含有零或更多個存取指定符
    // 存取指定符可以多常出現，沒有限制
    // 在介面中的成員應該定為public，實作部分的成員應該定義為private
    ```
- [ ] 7.17: 如果有的話，使用class和使用struct之間有什麼差異
    ```
    // class在第一個存取指定符之前是private
    // struct在第一個存取指定符之前是public
    ```
- [ ] 7.18: 什麼是封裝? 用處何在
    ```
    封裝強制分離了介面與實作部分
    確保了類別的private成員不會被任意的更改
    被封裝的部分的具體實現細節可以更而無需調整用戶級別的程式碼
    ```
- [ ] 7.19: 指出你的Person類別中哪個成員你會宣告為public，而哪個會定義為private。解釋你的選擇。
    ```
    // 建構器設置為public，name和address設為private
    ```
## 7.2.1 Friends
- [ ] 7.20: friend在什麼時候有用處呢? 討論使用friend的優缺點
    ```
    // 設為friend可以存取私有成員，壞處是可能破壞類別的封裝
    ```
- [ ] 7.21: 更新你的Sales_data類別來隱藏其實作。你寫來使用Sales_data運算的那些程式應該都要能繼續運作。重新編譯帶有你的新類別定義的那些程式，驗證它們仍然可運行
- [ ] 7.22: 更新你的Person類別，隱藏其實作。
# 7.3 額外的類別功能
## 7.3.1 再訪類別成員
- [ ] 7.23: 寫出你自己版本的Screen類別
    - 一個Screen代表顯示器上的一個視窗
    - 每個Screen都有一個string成員，存放那個Screen的內容
    - 以及三個string::size_type成員，用來代表游標的位置和畫面的高、寬
    - Screen的使用者不應該知道Screen使用一個string來存放資料
- [ ] 7.24: 賦予你的Screen類別三個建構器
    - 一個預設建構器、
    - 接受高寬值並初始化內容來放置給定數目個空白的建構器
    - 接受高寬值和一個用作畫面內容的字元的建構器
- [ ] 7.25: Screen能夠安全地仰賴預設版本的拷貝和指定嗎?如果是，為什麼呢?若非，為何不能?
- [ ] 7.26: 將Sales_data::avg_price定義為一個inline函式
## 7.3.2 回傳*this的函式
- [ ] 7.27: 為你版本的Screen新增move、set與display運算。執行下列程式碼來測試你的類別:
    ```
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    ```
- [ ] 7.28: 如果前面練習中的move、set與display的回傳型別為Screen而非Screen&，會發生什麼事?
    ```
    // 最後一個display會回到一開始創建的樣子
    ```
- [ ] 7.29: 修改你的Screen類別，讓move、set與display函式回傳Screen，檢查你在前一個練習的預測。
    ```
    // 7.28
    ```
- [ ] 7.30: 透過this指標來指涉成員是合法但多餘的動作。討論明確使用this指標來存取成員的優缺點
## 7.3.3 類別型別
- [ ] 7.31: 定義一對類別X與Y，其中X有指向Y的指標，而Y有型別為X的一個物件。
## 7.3.4 重訪朋友關係
- [ ] 7.32: 定義你自己版本的Screen和Window_mgr，其中clear是Window_mgr的成員，而且是Screen的朋友。
# 7.4 類別範疇
- [ ] 7.33: 如果我們賦予Screen一個定義如下的size成員，會發生什麼事呢? 修正你所找出的任何問題
    ```
    // 要在pos前面加上Screen::
    pos Screen::size() const {
    return height * width;
    }
    ```
## 7.4.1 名稱查找與類別範疇
- [ ] 7.34: 如果我們把pos的typedef放到前面Screen類別中作為該類別的最後一行，那會發生什麼事?
    ```
    // 編譯器報錯
    ```
- [ ] 7.35: 解釋下列程式碼，指出其中每個名稱的使用分別用到哪個Type或initVal的定義?說明你會如何修正遇到的任何錯誤? 
    ```
    // 把回傳型別加上Exercise::
    typedef string Type;
    Type initVal();
    class Exercise {
    public:
        typedef double Type;
        Type setVal(Type);
        Type initVal();
    private:
        int val;
    };
    Type Exercise::setVal(Type parm) {
        val = parm + initVal();
        return val;
    }
    ```
# 7.5 再訪建構器
## 7.5.1 建構器初始器串列
- [ ] 7.36: 下列的初始器有誤。找出並修正問題。
    ```
    // rem先初始化，base才初始化，
    // 因此這邊的rem會以未定義的base來初始化
    // 可以把定義順序反過來修正
    struct X {
        X (int i, int j): base(i), rem(base % j) {}
        int rem, base;
    };
    ```
- [ ] 7.37: 使用來自本節的Sales_data版本，判斷哪個建構器被用來初始化下列各個變數，並列出每個物件中資料成員的值:
    ```
    Sales_data first_item(cin);
    int main() {
        Sales_data next;
        Sales_data last("9-999-99999-9");
    }
    ```
- [ ] 7.38: 我們可能想要提供cin作為接受一個istream&的建構器之預設引數。寫出使用cin作為一個預設引數的建構器宣告
- [ ] 7.39: 讓接受一個string和接受一個istream&的兩個建構器都有預設引數是合法的嗎?若非，為何呢? `// 非法，函式重載不明確`
- [ ] 7.40: 選擇下列的抽象層(abstractions)之一(或你自己找的抽象層)。判斷該類別中需要什麼資料。提供適當的一組建構器。解釋你的決策。
    ```
    a book
    b. Date
    c. Employee
    d. Vehicle
    e. object
    f. tree
    ```
## 7.5.2 委派建構器
- [ ] 7.41: 改寫你自己版本的Sales_data類別，改為使用委派建構器。新增一個述句到每個建構器的主體，讓它們在被執行的時候印出一個訊息。盡可能以所有方式寫出宣告來建構一個Sales_data物件。研究輸出，直到你確信你了解委派建構器之間的執行順序為止。
- [ ] 7.42: 對於你為7.5.1的練習7.40所寫的類別，判斷其中是否有任何建構器可以使用委派。若有，就為你的類別撰寫委派建構器。如果沒有，就看看抽象層的清單，選出一個你認為會使用委派建構器的。為那個抽象層撰寫類別定義
## 7.5.3 預設建構器的腳色
- [ ] 7.43: 假設我們有一個名為NoDefault的類別，它有一個接受一個int的建構器，但沒有預設建構器。定義一個類別C，其中具有型別為NoDefault的一個成員。為C定義預設建構器
- [ ] 7.44: 下列的宣告是合法的嗎?如果不是，為什麼呢?
```
vector<NoDefault> vec(10);  // 主要就是像在vector<NoDefault>宣告的時候，vec(10)會用NoDefault的預設建構器來初始化，可是因為沒有預設建構器，所以就不會初始化了
```
- [ ] 7.45: 如果我們把前一個練習中的vector定義為存放型別為C的物件，那會怎樣?
```
// 合法喔
```
- [ ] 7.46: 如果有的話，下列哪個述句不是真的?為什麼?
    ```
    a. 一個類別至少必須提供一個建構器。  // 錯誤: 可以不提供，有合成的預設建構器
    b. 預設建構器是具有空的參數列的一個建構器。  // 正確，但提供預設參數的也是預設建構器
    c. 如果一個類別沒有有意義的預設值，類別就不應該提供預設建構器  // 錯誤，這樣有些情況類別將無法使用
    d. 如果一個類別沒有定義預設建構器，編譯器就會產生一個，將每個資料成員初始化為其關聯型別的預設值。  // 只有在沒有其他建構器的時候，才會生成合成的預設建構器
    ```
## 7.5.4 隱含的類別型別轉換
- [ ] 7.47: 說明接受一個string的Sales_data建構器是否應該為explicit。讓這個建構器成為explicit會有什麼好處呢? 缺點又有哪些?
```
//是，好處就是不能亂combine不存在的isbn，壞處是宣告的時候不能直接拷貝初始化(這也不算啥壞處吧)
```
- [ ] 7.48: 假設Sales_data的建構器不是explicit，下列定義中會發生什麼運算呢?如果Sales_data建構器是explicit，會發生什麼事呢?
    ```
    string null_isbn("9-999-99999-9");  // 創建了一個叫null_isbn的string
    Sales_data item1(null_isbn);  // 用一個string初始化了Sales_data
    Sales_data item2("9-999-99999-9");
    // 沒差別-.-
    ```
- [ ] 7.49: 對於下列三個combine的宣告，解釋如果我們呼叫i.combine(s)，而i是Sales_data，s是一個string，會發生什麼事?
    ```
    Sales_data &combine(Sales_data);  // 如果Sales_data(string)的建構器不是explicit，就會隱含的創建一個暫存的Sales_data，然後執行combine的述句
    Sales_data &combine(Sales_data&);  // 錯誤
    Sales_data &combine(const Sales_data&) const;  // 錯誤
    ```
- [ ] 7.50: 判斷你的Person類別的建構器是否應該為explicit。
- [ ] 7.51: 為什麼你會認為vector將它的單一參數建構器定義為explicit，但string沒有
    ```
    string要隱含轉換char
    vector的單一參數是int，普通的int不該被看成vector
    ```
## 7.5.5 彙總類別
- [ ] 7.52: 使用2.6.1我們第一個版本的Sales_data，解釋下列初始化。識別並修正任何問題
    ```
    Sales_data item = {"978-0590353403", 25, 15.00};
    ```
## 7.5.6 字面值類別
- [ ] 7.53: 定義你自己版本的Debug。
- [ ] 7.54: Debug中以set_開頭的成員應該被宣告為constexpr嗎?如果不是，為什麼呢?
    ```
    //set是member function，宣告為constexpr的話就需要滿足constexpr函式的條件: 所有的參數和回傳都是constexpr，而且恰有一個return述句
    ```
- [ ] 7.55: $7.5.5的data類別是一個字面值類別嗎? 如果不是，為何呢? 如果是，請解釋為什麼它是字面值類別
    ```
    // 資料成員全都是字面值型別的彙總類別是字面值型別
    // data是彙總類別，但string不是字面值型別    ```
# 7.6 static類別成員
- [ ] 7.56: static類別成員是什麼? static成員的好處是什麼? 它們與一般成員的差異在哪?
    ```
    - static類別成員是什麼: 宣告的時候帶有static關鍵字的類別成員，static由全體物件共享。
    - 獨立於類別物件的成員，舉例來說，我們有一個銀行帳戶的類別，我們會希望每個這個類別的物件都有一個成員叫基礎匯率，可是如果基礎匯率一改變，我們又要對每個物件都去改基礎匯率，顯得有點麻煩，因此可以把基礎匯率定成一個static成員，這樣改一次就可以。
    - static成員的好處: 可以針對類別來改動，讓某個變數與類別關聯
    - 與一般成員的差異: 一般成員與某個物件關聯，static成員與某個類別關聯；static成員可以當作預設參數，普通成員不能
    ```
- [ ] 7.57: 撰寫你自己版本的Account類別。
- [ ] 7.58: 如果有的話，下列哪個static資料成員宣告和定義是錯的?請解釋原因。
    ```
    // example.h
    class Example {
    public:
        static double rate = 6.5;
        static const int vecSize = 20;
        static vector<double> vec(vecSize);
    };
    // example.c
    #include "example.h"
    double Example::rate;
    vector<double> Example::vec;
    ```