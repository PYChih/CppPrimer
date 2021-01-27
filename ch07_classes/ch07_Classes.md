# ch07_Classes
###### tags: `C++Primer`
[TOC]
- 類別背後的概念: 資料抽象化、封裝
    - 資料抽象化: 區分介面和實作
        - 介面: 類別使用者能用的運算
        - 實作: 包含資料成員、成員函式、在介面上的運算是怎麼提供的等等
    - 封裝: 藉由封裝強化區分介面和實作
- 使用資料抽象化和封裝的類別會定義一個**抽象資料型別**，在抽象資料型別中，類別設計者擔心類別如和實作，使用該類別的程式設計師不需要知道型別的運作方式。取而代之，他們會抽象的思考型別所做的事。
# 7.1 定義抽象資料型別
- Sales_item是一個抽象資料型別
    - 我們沒辦法存取儲存在一個Sales_item物件中的資料成員
- Sales_data不是一個抽象資料型別
    - 它讓該類別的使用者存取其資料成員，並要求使用者寫他們自己的運算
    - 我們得定義運算給Sales_data的使用者使用
    - 一旦有了運算，我們就能封裝其資料成員
## 7.1.1 設計Sales_data類別
- Sales_data的介面由下列運算構成:
    - 回傳物件的ISBN的isbn成員函式
    - 能將一個Sales_data物件加到另一個的combine成員函式
    - 一個名為add的函式，用以相加兩個Sales_data物件
    - 從一個istream讀取資料到一個Sales_data物件中的read函式
    - 在一個ostream上印出一個Sales_data物件的值的print函式
### 使用修改過後的Sales_data類別
## 7.1.2 定義修訂版的Sales_data類別
- 資料成員
    - bookNo: 代表ISBN的string
    - units_sold: 指出該本書售出幾本的一個unsigned
    - revenue: 代表那些交易銷售總額的一個double
- 成員函式
    - combine
    - isbn
    - **avg_price**: 這個函式，並不對外提供一般使用。它會是實作的一部分，而非介面的一部分
- 成員函式必須在類別內部**宣告**。
- 可以在類別本身內**定義**，或在類別主體外部
- 定義在類別中的函式隱含就是inline的
### 定義成員函式
### 介紹this
- 成員函數會隱含的傳入一個叫this的指標
- 因為呼叫成員函式的時候預設是在某個物件上呼叫，然後this指的就是那個物件
- this預設情況就是一個永遠指著該物件的指標，所以是一個`*const`
### 介紹const成員函式
- this依照正常程序初始化，只是我們不用寫出來
- this本身是const指標(*const)
- 這推得如果物件是const，this會無法初始化，因為this預設是普通的指標
- 要對const物件可行需要有const成員函式，定義方法就是在函數參數列後面加上const
- note: 是const的物件以及對const物件的參考或指標，只可以呼叫const成員函式
### 類別範疇和成員函式
- 一個類別本身就是一個範疇
- 編譯器會兩步驟處理類別: 成員宣告先編譯，再處理成員函式的主體
### 在類別外定義一個成員函式
- 定義成員函式必須符合它的宣告
- 在類別外部定義的成員之名稱必須包括它所屬的類別的名稱
    ```
    double Sales_data::avg_price() const {
        if (units_sold)
            return revenue/units_sold;
        else
            return 0;
    }
    ```
- 這邊的範疇運算子(::)指出我們定義的是在Sales_data類別範疇中宣告的名為avg_price的函式
- 有這個範疇運算子，使用revenue和units_sold就是隱含的指涉Sales_data的成員
### 定義一個回傳this物件的函式
- 用在某個成員函式會改那個物件的值的時候要return `*this`
- 不需要使用隱含的this指標來存取成員函式，但需要使用this來存取作為一個整體的該物件
    ` return *this;  // 回傳函式在其上被呼叫的那個物件`
- combine函式的行為被設計的像是複合指定運算子`+=`
- 這個函式被呼叫的物件代表指定的左運算元
- 右運算元是作為一個明確的引數傳入的:
    ```
    Sales_data& Sales_data::combine(const Sales_data &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;  // 回傳在其上這個函式被呼叫的那個物件
    }
    ```
- 呼叫`total.combine(trans);`
- total的位址會繫結到隱含的this參數，而rhs則會繫結到trans
- 當combine執行`units_sold += rhs.units_sold;`
- 效果就是將結果存回total.units_sold
- 內建的指定運算子會回傳它們的左運算元作為一個lvalue
- 要回傳一個lvalue，我們的combine函式必須回傳一個參考，因為左手邊的運算元是一個Sales_data物件，回傳型別就是Sales_data&
## 7.1.3 定義非成員的類別相關函式
- note: 一般來說，是類別介面一部分的非成員函式應該宣告在與類別本身相同的標頭中
### 定義read和print函式
- IO類別無法被拷貝，所以只能藉由參考來傳遞
- 對資料流的讀取或寫入會變更資料流，因此參考指是一般的參考
    ```
    istream &read(istream &is, Sales_data &item) {
        double price = 0;
        is >> item.bookNo >> item.units_sold >> price;
        item.revenue = price * item.units_sold;
        return is;
    }
    ostream &print(ostream &os, const Sales_data &item) {
        os << item.isbn() << " " << item.units_sold << " "
           << item.revenue << " " << item.avg_prict();
        return os;
    }
    ```
### 定義add函式
- 接受兩個Sales_data物件，回傳一個新的Sales_data物件來表示他們的總和
    ```
    Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
        Sales_data sum = lhs;
        sum.combine(rhs);
        return sum;
    }
    ```
## 7.1.4 建構器
- 類別定義其初始化由定義叫**建構器**(constructors)的特殊成員函式
- 建構器的名稱與類別相同、沒有回傳型別、有參數列、函式主體，建構器可以有多個(重載)
- 建構器不可以被宣告為const
- 建構器會在類別型別的物件被創建時執行
- 假設有個const物件，它會在建構器創建完才展現const性質，所以建構器可以寫入const物件
### 合成的預設建構器
- 回想我們前面的類別，都沒有初始化，所以我們知道它們是預設初始化的
- 類別控制預設初始化的方式是定義一個特殊的建構器叫**預設建構器**
- 預設建構器不接受任何引數
- 如果我們沒有明確的定義任何建構器，編譯器就會隱含的為我們定義預設建構器
- 編譯器產生的建構器稱為合成的預設建構器
- 合成的預設建構器初始化方法如下:
    - 如果類別成員有初始器可用，就用它來初始化該成員
    - 否則，就預設初始化該成員
### 某些類別無法仰賴合成的預設建構器
- 如果類別有一個成員有類別型別，而那個類別沒有**預設建構器**，那麼編譯器就無法初始化該成員
- 如果我們有定義建構器，類別就不會有預設建構器
- 一個類別必須定義預設建構器:
    - 原因1: 編譯器只會在一個類別沒有宣告建構器的時候產生一個預設建構器
    - 原因2: 對某些類別來說，合成的預設建構器所做的事情是錯的
    - 原因3: 有時候編譯器無法合成，如果類別型別的成員沒有預設建構器，那麼編譯器就無法初始化該成員
### 定義Sales_data建構器
- 我們定義四個具有下列參數的建構器
    - 從之讀取交易紀錄的一個istream&
    - const string&用來代表ISBN、一個unsigned代表出售量以及一個double代表售出價格
    - 代表ISBN的一個const string&。這個建構器會為其他的成員使用預設值
    - 一個空的參數列(預設建構器)
    ```
    struct Sales_data {
    // 新增的建構器
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);
    // 跟之前一樣的成員
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    };
    ```
### =default所代表的意義
- 在新標準下，如果我們想要預設行為，可以在參數列後寫上=default要求編譯器為我們產生建構器
### 建構器初始器串列
- 在建構器的參數列後面，加上:以及以逗號分隔的每個資料成員加上括號，以及一個大括號主體，就是建構器初始器串列
    ```
    Sales_data(const std::string &s): bookNo (s) { }
    Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) {}
    ```
- 為被創建的物件提供初始值
- 當某個成員在建構器初始器串列中被省略了，他就會隱含的被初始化，使用的程序與合成的預設建構器相同
- 建構器使用類別內的初始器通常是最好的
### 在類別主體外定義一個建構器
- 建構器沒有回傳型別
    ```
    Sales_data::Sales_data(std::istream &is) {
    read(is, *this)
    }
    ```
- 建構器可以有空的建構器初始器串列
- 這個例子雖然是空的建構器初始器串列，每個成員還是有先被預設初始化
- 沒有出現在建構器初始器串列中的成員是由對應的類別內初始器來初始化，或者是預設初始化
## 7.1.5 拷貝、指定與解構
### 某些類別不能仰賴合成的版本
- 會在類別物件本身之外配置資源的類別
- 需要動態記憶體的許多類別可以使用一個vector或string來管理動態記憶體
- 當我們拷貝或指定具有vector成員的一個物件，vector類別會負責該成員中元素的拷貝或指定工作。vector被摧毀時，成員也會被摧毀，而那個vector中的那些元素也會因此被摧毀
# 7.2 存取控制與封裝
- 使用存取指定符來強制施加封裝
    - public指定符後定義的成員，程式的所有部分都能存取它們。public成員定義了類別的介面
    - private指定符後定義的成員，類別的成員函式可以存取他們，但使用該類別的程式碼無法存取，private的部分封裝(隱藏)了實作。
### class或struct關鍵字
- class和struct嚴格來說只是風格上的不同
- 一個類別可以在第一個存取指定符之前定義成員
- struct: 第一個存取指定符之前是public。
- class: 第一個存取指定符之前是private。
## 7.2.1 Friends
- 外部函式無法存取private成員，除非設成friend
- 一個類別能夠允許另一個類別或函式存取其非public成員，方法是讓那個類別或函式變為一個friend
- 設為friend的方式是為那個函式引入前面接著關鍵字friend的宣告
    ```
    class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    }
    ```
- friend宣告在一個類別定義內只能出現一次，可以在類別中的任何地方
- 一般來說，將friend宣告集中在類別定義的開頭或尾端會是個好主意
### Friends的宣告
- 注意: friend宣告只會影響到存取控制，並不是函式的一般性宣告。
- 為了要讓類別的使用者能夠看到每個friend，通常會在與類別本身相同的標頭中宣告每個friend(在類別外部)
- 許多編譯器並沒有強制實施friend函式必須在使用前於類別外部宣告的這種規則

# 7.3 額外的類別功能
- 型別成員
- inline成員函式
- mutable資料成員
- 類別型別成員的類別內初始器
- 從成員函式回傳`*this`
- 定義和使用類別型別、類別朋友關係(class friendship)
## 7.3.1 再訪類別成員
### 定義一個型別成員
- 定義型別的成員必須在被使用前就出現，結果就是，型別成員通常都會出現在類別的開頭處。
    ```
    class Screen {
    public:
        typedef std::string::size_type pos;
        // using pos = std::string::size_type;
    private:
        pos cursor = 0;  // 游標
        pos height = 0, width = 0;
        std::string contents;
    }
    ```
### 類別screen的成員函式
- 有類別內初始器的話，就可以隱含的初始化那個資料成員
    ```
    class Screen {
    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
        char get() const {return contends[cursor];}
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
    private:
        pos cursor = 0;
        pos height =0, width = 0;
        std::string contents;
    };
    ```
### 讓成員變為inline
- 可以在類別內宣告inline，也可以在類別外再宣告成inline
    ```
    inline
    Screen &Screen::move(pos r, pos c) {  // 這個inline沒在本來類別內的宣告裡
        pos row = r*width;
        cursor = row + c;
        return *this;
    }
    char Screen::get(pos r, pos c) const {// 類別宣告的時候就是inline了
    pos row = r*width;
    return contents[row + c];
    }
    ```
- 在宣告和定義上都指定inline是合法的，然而，只在類別外的定義上指定inline可以使類別更容易閱讀
### 重載成員函式
### mutable資料成員
- 一個mutable資料成員永遠都不會是const的，即使它是一個const物件的一個成員
- Screen一個名為access_ctr的mutable成員，我們用它來追蹤每個Screen成員函式被呼叫的頻率
    ```
    class Screen {
    public:
        void some_member() const;
    private:
        mutable size_t access_ctr;  // 即使是在一個const物件中也可以修改
    };
    void Screed::some_member() const {
        ++access_ctr;
    }
    ```
- `some_member`是一個const的成員函式，但它仍然可以變更`access_ctr`的值
### 類別型別的資料成員的初始器
- 初始化類別型別的一個成員，我們是在提供引數給那個成員的型別的某個建構器
- 在此我們以單一元素的初始器串列初始化了我們的vector成員
- 初始器含有一個Screen值，被傳入到`vector<Screen>`建構器來創建一個單元素的vector
    ```
    class Window_mgr {
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};
    }
    ```
## 7.3.2 回傳`*this`的函式
- 新增能在游標位置或給定位置設定字元的函式:
    ```
    class Screen {
    public:
        Screen &set(char);
        Screen &set(pos, pos, char);
    };
    inline Screen &Screen::set(char c) {
        contents[cursor] = c;
        return *this;
    }
    inline Screen &Screen::set(pos r, pos col, char ch) {
        contents[r*width + col] = ch; //將指定位置設定成指定值
        return *this;
    }
    ```
- 回傳一個參考的函式是lvalue，因此`myScreen.move(4,0).set('#')`會在同一個物件上執行
### 從一個const成員函式回傳*this
- 新增`display`運算，用來印出Screen的內容
- 希望display也能夠引入set和move(就是set和move之後display)
- 邏輯上來說display不會改變它的物件，所以display應該是const
- 因此display的回傳型別是const Screen
- 如果display是const就沒辦法內嵌到一系列動作
    ```
    Screen myScreen;
    // 如果display回傳一個const參考，那麼對set的呼叫就是一個錯誤
    myScreen.display(cout).set('*');
    ```
- 即使myScreen是一個非const物件，對set的呼叫也無法編譯
- const版本的display回傳對const的一個參考，而我們無法在const物件上呼叫set
### 基於const的重載
- 我們可以依據它是否為一個const成員來重載一個成員函式
    ```
    class Screen {
    public:
    // 基於物件是否為const的display重載
    Screen & display(std::ostream &os)
    {do_display(os); return *this;}
    const Screen &display(std::ostream &os) const
    {do_display(os); return *this; }
    private:
        void do_display(std::ostream &os) const {os << contents;}
    }
    ```
- 建議: 為共通的程式碼使用私有的工具函式(private utility functions)
    - 我們為了display定義了一個個別的do_display運算
    - 這樣做的幾個理由:
        - 避免在多個地方撰寫相同程式碼的一種習慣
        - 預期display的運算會隨著類別的演進而變得更加複雜。隨著所涉及的動作變得越來越複雜，將那些動作寫在同一個地方就顯得越來越合理
        - 可能會想在開發過程中為do_display新增除錯資訊，而這些資訊會在該程式碼的最終正式版本中移除，如果只有一個do_display定義需要更改以新增或移除除錯程式碼，那麼事情就會簡單的多
        - 這個額外的函式呼叫並不涉及任何多餘負擔
## 7.3.3 類別型別
- 就算兩個類別有相同的成員，定義出來的類別仍然是不同的型別
- 定義類別型別的兩種方法:
    - `Sales_data item1;`
    - `class Sales_data item1;`
### 類別宣告
- 宣告類別而不定義，稱為前向宣告
- 前向宣告後稱為不完整的類別
- 可以定義指向不完整類別的指標或參考(因為參考不是物件，然後指標就只要留一個位置放指標就好)
- 可以宣告(但不能定義)使用不完整類別作為參數或回傳型別的函式
- 資料成員只能在一個類別已經定義的前提下被指定為那個類別(因為會不知道要留多少空間，不過static例外)
- 一個類別可以有指向自己型別的指標或參考作為資料成員(反過來說，不能有是自己的資料成員)
    ```
    class Link_screen {
        Screen window;
        Link_screen *next;  // 這是一個Link_screen的指標型別的資料成員
        Link_screen *prev;
    }
    ```
## 7.3.4 重訪朋友關係
- 類別的朋友:
    - 把類別定義成類別的朋友(要宣告過)
    - 把外面的函式定義成類別的朋友(可以inline)
    - 把別的類別的成員函式定義成類別的朋友(要定義過)
### 類別之間的朋友關係
- Window_mgr類別有成員需要存取它管理的Screen物件的內部資料
    - 為Window_mgr新增clear的成員函式
    - 它會將一個特定的Screen的內容重置為全部空白
        - clear需要存取Screen的private成員
        - 要允許這種存取，Scree可以將Window_mgr標示為它的朋友
    ```
    class Screen {
    // window_mgr的成員能夠存取類別Screen的私有部分
        friend class Window_mgr;
        // ... Screen類別的其餘部分
    };
    ```
- 一個friend類別的成員函式可以存取與它建立朋友關係的類別的所有成員，包括非public成員
    ```
    class Window_mgr {
    public:
        // 視窗上的每個畫面的位置ID
        using ScreenIndex = vector<Screen>::size_type;
        // 將位於給定位置的Screen重製為全部空白
        void clear(ScreenIndex);
    private:
        vector<Screen> screens{Screen(24, 80, ' ')};
    };
    void Window_mgr::clear(ScreenIndex i) { 
        Screen &s = screens[i];
        s.contents = string(s.height * s.width, ' ');
    }
    ```
- 朋友關係沒有遞移性
- 每個類別都控制哪些類別或函式是其朋友
### 讓一個成員函式變為一個Friend
- 不必讓整個Window_mgr都變為朋友，可以只讓clear成為Screen的朋友
- 當我們宣告一個成員函式為friend，我們必須指出那個函式所屬的類別為何:
    ```
    class Screen {
        friend void Window_mgr::clear(ScreenIndex);
    };
    ```
- 要讓一個成員函式變為一個朋友，需要詳細考慮順序排列:
    - 定義Window_mgr類別，它宣告但無法定義clear。
    - clear可以使用Screen的成員之前，Screen必須被宣告才行
    - 接著，定義類別Screen，包括clear的friend宣告
    - 最後，定義clear，它現在可以參考Screen中的成員了。
### 重載函式與朋友關係
- 朋友關係需要一個一個宣告(替每個重載函式)
### Friend宣告和範疇
- 被用在一個friend宣告之前，類別和非成員函式並不一定要已經被宣告了
- 當一個名稱首次出現在一個friend宣告中，那個名稱會被隱含的被假設成是周圍範疇的一部分
- 然而，這個friend本身實際上並不是在那個範疇中宣告的。
    ```
    struct X {
        friend void f();  // friend函式可以被定義在類別主體喔
        X() { f(); }  // 錯誤: f沒有宣告
        void g();
        void h();
    };
    void X::g() {return f();}  // 錯誤: f沒有宣告
    void f();
    void X::h() {return f();}  // ok
    ```
- friend影響到存取權，但並不是一般意義上的宣告
# 7.4 類別範疇
- 每個類別都定義自己的新範疇，在類別範疇外，一般的資料和成員函式只能透過物件、參考、指標，使用成員存取運算子來存取
- 使用範疇運算子在類別中存取型別成員
- 任一種情況下，跟在運算子後的名稱都必須是所關聯的類別之成員
    ```
    Screen::pos ht=24, wd = 80;  // 使用screen所定義的pos型別
    Screen scr(ht, wd, ' ');
    Screen *p = &scr;
    char c = scr.get();  // 從物件scr擷取get成員
    c = p->get();  // 從p所指的物件擷取get成員
    ```
### 範疇與定義在類別外的成員
- 當一個成員函式是定義在類別主體之外，在回傳型別中使用的任何名稱都在類別範疇之外
- 為Window_mgr新增一個名為addScreen的函式，用以新增另一個畫面到顯示器
    ```
    class Window_mgr {
    public:
        // 新增一個Screen到視窗並回傳其索引
        ScreenIndex addScreen(const Screen&);
    };
    // 進入到Window_mgr範疇之前會先看到回傳型別
    Window_mgr::ScreenIndex
    Window_mgr::addScreen(const Screen &s) {
        screens.push_back(s);
        return screens.size()-1;
    }
    ```
## 7.4.1 名稱查找與類別範疇
- 名稱查找的順序
    - 首先，在那個名稱使用所處的區塊尋找該名稱的宣告。這只會考慮在使用前宣告的那些名稱
    - 如果找不到那個名稱，就去外層的範疇找
    - 如果找不到宣告，那該程式有錯
- 定義在類別內的成員函式中，名稱的解析方式看起來可能會與這些查找規則不同。主因是類別定義會以兩個階段處理
    - 首先，成員宣告會被編譯
    - 只有在看過整個類別後，函式主體才會被編譯。
- 成員函式的定義會在編譯器處理完該類別中所有的宣告之後才會被處理
### 類別成員宣告的名稱查找
- 雙步驟的處理僅適用於在一個成員函式主體中使用的名稱
- 在宣告中使用的名稱，包括用於回傳型別和參數型別的名稱，在使用前都必須已經見過
- 如果一個成員宣告用了尚未在類別內見過的名稱，編譯器就會在該類別定義處的範疇中尋找那個名稱
    ```
    typedef double Money;
    string bal;
    class Account {
    public:
        Money balance() {return bal;}
    private:
        Money bal;
    };
    ```
- 當編譯器看到balance函式的呼叫，它會在Account類別中尋找Money的宣告
- 編譯器只會考慮Account內在Money的使用之前出現的那些宣告。
- 因為找不到匹配的成員，接著編譯器就會在外圍範疇中尋找宣告
- 這個例子，編譯器會找到Money的typedef宣告
- 另一方面，banance的函式主體只會在整個類別都被看過之後處理，因此return的bal是函式內的成員，而非外層的string
### 型別名稱是特殊的
- 即使來自某個外層範疇的名稱已經在內層範疇中被使用，內層範疇仍然可以重新定義那個名稱
- 然而，在一個類別中，如果某個成員用了來自某個外層範疇的一個名稱，而那個名稱是一個型別，那麼該類別後續就不能重新定義那個名稱
    ```
    typedef double Money;
    class Account {
    public:
        Money balance() {return bal; }
    private:
        typedef double Money;  // 錯誤，無法重新定義Money
        Money bal;
    };
    ```
- 型別名稱的定義通常應該出現在一個類別的開頭。
- 用到那個型別的任何成員都會在該型別名稱已經被定義之後才會被看到。
### 成員定義內的一般區塊範疇名稱查找
- 在一個成員函式主體中使用的名稱之解析過程如下:
    - 首先，在那個成員函式內找尋該名稱的宣告。如同以往，函式主體中，只有出現在該名稱使用處之前的宣告會被考慮
    - 如果成員函式內找不到宣告，就在類別內找尋宣告。類別的所有成員都會納入考慮。
    - 如果類別中找不到那個名稱的宣告，就在成員函式定義之前找尋在範疇中的宣告
- 一般來說，把另一個成員的名稱用在一個成員函式中做為參數的名稱，不會是什麼好主意。
- 然後，為了展示名稱如何解析:
    ```
    int height;
    class Screen {
    public:
        typedef std::string::size_type pos;
        void dummy_fun(pos height){
            cursor = width * height; // 參數那個height
        }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
    };
    ```
### 類別範疇之後，就在外圍範疇中尋找
- 即使外層的物件被遮蔽了，你還是可以使用範疇運算子來存取該物件
### 名稱會在檔案中它們出現處被解析
# 7.5 再訪建構器
## 7.5.1 建構器初始器串列
- 定義變數的時候，我們通常會立即初始化它們，而非定義它們，然後再指定值給它們。
### 建構器初始器有時是必要的
- 並不總是可以忽略成員是初始化的還是被指定的
    - 是const或參考的成員必須被初始化
    - 若成員所屬的類別型別沒有定義預設建構器，那也必須被初始化
    ```
    class ConstRef {
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
    };
    ```
- ci和ri必須被初始化。對於這些成員，省略其建構器初始器會是種錯誤
    ```
    ConstRef::ConstRef(int ii) {
        i = ii;  // ok
        ci = ii;  // 錯誤: 無法對const進行指定
    ri = i;  // 錯誤: ri沒有初始化
    };
    ```
- 明確的初始化參考和const成員`ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) {}`
- 建議: 使用建構器初始器
### 成員初始化的順序
- 建構器初始器串列僅指定了要用來初始化成員的值，而非那些初始化進行的順序
- 成員會以他們出現在類別定義中的順序來初始化
- 避免使用成員來初始化另外的成員(如果可以)
- 以成員宣告的順序來撰寫建構器初始器是一個好主意
### 預設引數和建構器
- 為其所有參數提供了預設引數的建構器也定義預設建構器
## 7.5.2 委派建構器
- 新標準拓展了建構器初始器的使用，讓我們定義所謂的委派建構器(delegating constructors)
- 一個委派建構器使用自己類別的另一個建構器來進行初始化
- 它將部分/或全部的工作委派給了其他建構器
- 委派建構器會有
    - 一個成員初始器串列
    - 一個函式主體
- 成員初始器串列會有單一個項目，其名稱是該類別本身
- 這個類別名稱後面跟著一串放在括號內的引數
- 這個引數列必須匹配該類別中另一個建構器
    ```
    class Sales_data {
    public:
        //非委派的建構器以對應的引數初始化成員
        Sales_data(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnt), revenue(cnt*price) { }
        //剩餘的建構器都會將工作委派給其他建構器
        Sales_data(): Sales_data("", 0, 0){}
        Sales_data(std::string s): Sales_data(s, 0, 0) {}
        Sales_data(std::istream &is):Sales_data(){read(is, *this);}
    };
    ```
## 7.5.3 預設建構器的腳色
- 預設建構器會在一個物件是預設初始化或者值初始化的時候自動被使用
- 預設初始化:
    - 在區塊範疇定義非static變數或陣列而不帶初始器的時候
    - 一個類別本身所具有的成員的型別會使用合成的預設建構器的時候
    - 當類別型別的成員沒有在建構器初始器串列中被明確初始化的時候
- 值初始化:
    - 陣列初始化的過程中，當我們提供的初始器數目少於陣列大小時
    - 不帶初始器定義一個區域性static物件的時候
    - 當我們寫出型式為T()的運算式，而其中T是一個型別名稱的時候(接受單一個引數來指定其vector大小的vector建構器就用了一個這種的引數來值初始化其元素初始器)
### 使用預設建構器
- 常見錯誤:
    ```
    Sales_data obj(); 宣告了一個函式而非物件
    Sales_data obj2; obj2是一個物件而非函式
    ```
## 7.5.4 隱含的類別型別轉換
- 能以單一個引數被呼叫的建構器定義了從該建構器的參數型別轉成其類別型別的一種隱含轉換
    ```
    string null_book = "9-999-99999-9";  // null_book是一個string
    Sales_data& combine(const Sales_data&);  // combine是在Sales_data裡的成員函式，接受一個Sales_data物件，然後把它做成對const Sales_data的一個參考，最後回傳一個對Sales_data的參考
    Sales_data item;  // 我們有一個Sales_data型別的物件叫item
    item.combine(null_book);  // 可以直接combine null_book，因為隱含了型別轉換
    ```
### 只允許一個類別型別的轉換
- 這樣不合法，因為轉換有兩個
    ```
    item.combine("9-999-99999-9");  // combine要的是const Sales_data&
    ```
- 想要改成合法:
    ```
    item.combine(string("9-999-99999-9"));
    item.combine(Sales_data("9-999-99999-9"));
    ```
### 類別型別轉換並不一定總是有用
    ```
    item.combine(cin);
    ```
- 我們等同於創建了一個會在其值被加到item中之後就會被捨棄的物件
### 抑制建構器所定義的隱含轉換
- 我們可以在需要隱含轉換的情境中避免建構器的使用，方法是將建構器宣告為``explicit:``
    ```
    class Sales_data {
    public:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) {}
        explicit Sales_data(const string &s): bookNo(s) {}
        explicit Sales_data(std::istream&);
    };
    ```
- 現在這兩個建構器都不能被用來隱含的創建一個Sales_data物件
- 前面的兩個做法都沒辦法編譯
- ``explicit``關鍵字只有用在能以單一個引數呼叫的建構器上的時候才有意義。
- explicit只能在類別內的時候做，不會在類別主體外所做的定義上重複出現
### explicit建構器只能用於直接初始化
- 我們無法把explicit建構器用於拷貝初始化，必須使用直接初始化
    ```
    // note: null_book is a string
    Sales_data item1(null_book); // 直接初始化，ok
    Sales_data item2 = null_book;  // explicit建構器不能拷貝初始化
    ```
### 為轉換明確的使用建構器
- 雖然編譯器不會把一個explicit建構器用於隱含的轉換，我們還是可以明確使用這種建構器來迫使轉換發生
    ```
    item.combine(Sales_data(null_book));
    item.combine(static_cast<Sales_data>(cin));
    ```
### 具有explicit建構器的程式庫類別
- 接受型別為const char*的單一參數的string建構器不是explicit
- 接受一個大小的vector建構器是explicit
## 7.5.5 彙總類別
- 一個彙總類別賦予使用者對其成員的直接存取，並具有特殊的初始化語法，若符合下列條件，就可以說類別是一個aggregate
    - 所有資料成員都是public
    - 沒有定義任何建構器
    - 沒有類別內初始器
    - 沒有基礎類別或virtual函式
- 可以提供由大括號圍起的初始器串列來初始化一個彙總類別
## 7.5.6 字面值類別
- 一個constexpr函式的參數和回傳型別必須是字面值型別(literal types)。
- 除了算數型別、參考和指標，某些類別也是字面值型別
- 資料成員全都是字面值型別的彙總類別是字面值型別
- 符合下列限制的非彙總類別也會是字面值型別
    - 資料成員全都得有字面值型別
    - 類別必須至少有一個constexpr建構器
    - 如果一個資料成員有一個類別內初始器，那麼內建型別的成員的初始器必須是一個常數運算式，或者，如果成員有類別型別，那麼初始器就必須使用該成員自己的constexpr建構器
    - 類別必須為它的解構器使用預設定義，也就是負責摧毀該類別型別的物件的那個成員
### constexpr建構器
- 一個constexpr建構器必須初始化每個資料成員
- 初始器必須使用一個constexpr建構器或者是一個常數運算式
- 一個constexpr建構器被用來產生是constexpr的物件，並用於constexpr函式中的參數或回傳型別
- 例子:
    ```
    class Debug {
    public:
        constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
        constexpr bool any() {return hw || io || other;}
        void set_io(bool b) {io = b;}
        void set_hw(bool b) {hw = b;}
        void set_other(bool b) {hw = b;}
    private:
        bool hw; // 除了io錯誤之外的硬體錯誤
        bool io; // io錯誤
        bool other; // 其他錯誤
    };
    ```
- 使用範例
    ```
    constexpr Debug io_sub(false, true, false);  // 定義一個constexpr類別的物件叫io_sub，使用constexpr建構器
    if (io_sub.any())  // 等同於if(true)
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false);  // 正式版沒有除錯
    if (prod.any())  // 等同於if(false)
        cerr << "print an error message" << endl;
    ```
# 7.6 static類別成員
- 類別有的時候需要與該類別關聯的成員，而非該類別的物件
- 例子:
    - 一個銀行帳號類別可能需要一個資料成員來表示目前的基礎利率，我們會想要將這個利率關聯到該類別，而非每個各別的物件
### 宣告static成員
- 在宣告上加上static來指出一個成員關聯至類別本身
- 一個static資料成員的型別可以是const、參考、陣列、類別型別等
- 例子:
    ```
    class Account {
    public:
        void calculate() { amount += amount * interestRate;}
        static double rate() { return interestRate;}
        static void rate(double);
    private:
        string owner;
        double amount;
        static double interestRate;
        static double initRate();
    };
    ```
- 一個類別的static成員存在於任何物件之外。物件不會含有與static資料成員關聯的資料
- interestRate物件只有一個，由所有的Account物件共用。
- static成員函式沒有繫結至任何物件，它們沒有this指標，結果就是static成員函式不能是const
- 不能在一個static成員的主體中使用this
    - 這項限制適用於this的明確使用
    - 也適用於呼叫一個非static成員時對this的隱含使用?
### 使用類別的static成員
- 透過範疇運算子直接存取一個static成員:
    ```
    double r;
    r = Account::rate()
    ```
- 即使static成員不是其類別的物件的一部分，我們可以使用類別的一個物件、參考或指標來存取一個static成員
    ```
    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();
    ```
- 成員函式可以直接使用static成員，無須範疇運算子
    ```
    class Account {
    public:
        void calculate() {amount += amount * interestRate;}
    private:
        static double interestRate;
    };
    ```
### 定義static成員
- 可以在內部或外部定義static成員函式，在外部定義static成員不會重複static關鍵字
    ```
    void Account::rate(double newRate) {
        interestRate = newRate;
    }
    ```
- 因為static資料成員不是類別型別的各別物件的一部分，它們不會在我們創建類別的物件時被定義，結果就是: 它們不會由類別的建構器來初始化
- 此外，我們不可以在類別內初始化一個static成員，取而代之，我們必須在類別主體外定義並初始化每個static資料成員
- 定義一個static資料成員的方式類似於在類別外定義類別成員函式的方式。
- 下面的述句定義了名為interestRate的物件，它是類別Account的一個static成員，並有double的型別
    ```
    double Account::interestRate = initRate();
    ```
- 一旦類別名稱被看見，定義的剩餘部分就會在該類別的範疇內，結果就是，我們可以直接使用initRate作為interestRate的初始器，而不用資格修飾
- 注意: initRate()是private的喔
- 確保物件只剛好被定義一次的最好辦法，就是將static資料成員的定義放在還有類別非inline成員函式的定義的相同檔案中。
### static資料成員的類別內初始化
- 一般來說類別的static成員不可以在類別主體中初始化
- 可以為具有const整數型別的static成員提供類別內初始器，這種初始器必須是常數運算式
- 必須為是字面值型別的constexprs的static成員在類別主體中初始化
    ```
    class Account {
    public:
        static double rate() { return interestRate; }
        static void rate(double);
    private:
        static constexpr int period = 30;  // period是一個常數運算式
        double daily_tbl[period];
    };
    ```
- 如果該成員只被用在編譯器能夠直接替換上該成員值的情境中，那麼一個已初始化的const或constexpr static就不需要分別定義。然而，如果我們是在無法代換上其值的情境中使用該成員，那麼該成員就必須有一個定義存在。
- 如果period只用來定義daily_tbl的維度，就不需要在Account外部定義period。然而，如果我們省略了定義，那麼很有可能即使是看似無關緊要的程式變更都可能導致程式無法編譯，就因為少了定義。
- 如果有在類別內部提供一個初始器，那麼成員的定義就必定不能指定一個初始值
    ```
    constexpr int Account::period;  // 類別定義中有提供初始器
    ```
- 即使一個const static資料成員是在類別主體中初始化的，那個成員一般來說還是應該被定義在類別定義之外
### static成員能以一般成員無法被使用的方式使用
- 一個static資料成員可以有不完整的型別，特別是，一個static資料成員的型別可以跟它所屬的類別型別相同。一個非static資料成員被限制只能被宣告為對其類別的一個物件之指標或參考
    ```
    class Bar {
    public:
        //...
    private
        static Bar mem1;  // static成員可以有不完整的型別
        Bar *mem2;  // ok, 指標成員可以有不完整的型別
        Bar mem3;  // 錯誤，資料成員必須有完整的型別
    };
    ```
- static和一般成員之間的另一個差異是，我們可以把一個static成員當作一個預設引數使用
    ```
    class Screen {
    public:
        // bkground指的是一個靜態成員
        // 它會在之後的類別定義中被宣告
        Screen& clear(char = bkground);
    private:
        static const char bkground;
    };
    ```
- 一個非static資料成員不可以被用作預設引數，因為其值是它作為成員所屬的物件的一部分。
- 使用一個非static資料成員作為預設引數，並不會提供要從之獲取該成員的值的物件，所以是種錯誤。