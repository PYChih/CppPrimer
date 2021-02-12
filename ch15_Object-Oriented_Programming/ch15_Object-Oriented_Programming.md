# ch15_Object-Oriented_Programming
###### tags: `C++Primer`
[TOC]
# 15.1 OOP之概觀
- 物件導向程式設計中的關鍵概念是資料抽象化、繼承，以及動態繫結
    - 藉由資料抽象化，我們定義將介面與實作分離的類別
    - 透過繼承，我們定義出類別作為模型，以捕捉相似型別之間的關係
    - 動態繫結則能讓我們使用那些型別的物件，部用去在意它們之間差異的細節
## 繼承
- 藉由繼承產生關聯的類別會有一種階層架構
- 架構的根部有基礎類別，其他的類別則會直接或間接繼承它
- 繼承自基礎類別的類別稱為衍生類別
- 基礎類別定義階層架構中那些型別共通的成員
- 衍生類別定義專屬衍生類別本身的成員
- 例子:
    - 定義Quote為基礎類別(沒有折扣的書)
    - 名為Bulk_quote的第二個類別(以某個數量折扣販售的書籍)
- 成員函式:
    - isbn()，回傳ISBN，此運算不依存於它所繼承的類別之細節，所以只會在Quote被定義
    - net_price(size_t)，回傳購買一本書特定數目的本數時的價格。型別限定，Quote和Bulk_quote都會定義它們自己的這個函式
- 基礎類別:
    - 區分取決於型別的函式(net_price)以及它預期衍生類別原封不動繼承的函式(isbn())
    - 取決於型別的函式(預期衍生類別會為自身定義的那些函式會被定義為virtual。
    ```
    class Quote {
    public:
        std::string isbn() const;
        virtual double net_price(std::size_t n) const;
    };
    ```
- 衍生類別
    - 必須指定它想要繼承的類別(藉由類別衍生串列class derivation list)這麼做
    - 一個冒號後面跟著一個逗號區隔的基礎類別串列，其中每一個都可以有選擇性的存取指定符(public...)
    ```
    class Bulk_quote : public Quote {
    public:
        double net_price(std::size_t) const override;
    };
    ```
- 由於public的使用，Bulk_quote的物件可以當作Quote物件來使用
- 衍生類別必須在自己的類別主體中包含它想要為自身定義的所有虛擬函式宣告(可以使用virtual關鍵字但不必要)
- 新標準讓一個衍生類別可以明確的表示他希望一個成員函式覆寫(override)它所繼承的一個virtual。它會在其參數列之後指定overried來這麼做
## 動態繫結
- 透過動態繫結，可以使用相同的程式碼來互換的處理型別為Quote或Bulk_quote的物件
- 例子: 一個透過給定購買本數時，印出書本總價的函數
    ```
    double print_total(ostream &os, const Quote &item, size_t n) {
        // 取決於繫結到item參數的物件之型別
        // 來呼叫Quote::net_price
        // 或呼叫Bulk_quote::net_price
        double ret = item.net_price(n);
        os << "ISBN: " << item.isbn()  // 呼叫Quote::isbn
           << " # sold: " << n << "total due: " << ret << endl;
        return ret;
    }
    ```
- item參數是對Quote的一個參考，我們可以在一個Quote物件或一個Bulk_quote物件上呼叫這個函式，兩者皆可。
- 因為net_price是一個虛函式，也因為print_total會透過一個參考呼叫net_price，所執行的net_price版本將會取決於我們傳入print_total物件的型別
    ```
    // basic的型別為Quote; bulk的型別為Bulk_quote
    print_total(cout, basic, 20);  // 呼叫Quote版本的net_price
    print_total(cout, bulk, 20);  // 呼叫Bulk_quote版本的net_price
    ```
- 因為要執行哪個版本的決策取決於引數的型別，該決策到runtime才能下定。因此動態繫結有時也被稱作執行期繫結
- Note: 在`C++`中動態繫結發生在一個虛擬函式透過對某個基礎類別的一個參考(或是指標)被呼叫之時
# 15.2 定義基礎與衍生類別
## 15.2.1 定義基礎類別
- Quote類別的定義
    ```
    class Quote {
    public:
        Quote() = default;
        Quote(const std::string &book, double sales_price):
              bookNo(book), price(sales_price) { }
        std::string isbn() const { return bookNo; }
        // 為指定數目的項目回傳總銷售金額
        // 衍生的類別會覆寫並套用不同的折扣演算法
        virtual double net_price(std::size_t n) const {
            return n * price;
        }
        virtual ~Quote() = default;  // 解構器的動態繫結
    private:
        std::string bookNo;
    protected:
        double price = 0.0;  // 正常的，未折扣價格
    };
    ```
- Note: 基礎類別一般都應該有一個虛擬解構器。即使他們不做任何工作，虛擬解構器也是必要的
### 成員函式與繼承
- 衍生類別會繼承他們基礎類別的成員，然後，一個衍生類別必須要能夠為像是net_price這樣取決於型別的運算提供自己的定義。在這種情況中，衍生類別必須提供自己的定義來覆寫(override)它從基礎類別繼承而來的定義
- 基礎類別必須區分它預期其衍生類別會覆寫的函式，以及那些它預期其衍生類別會原封不動繼承的函式。
- 預期衍生類別會覆寫的函式基礎類別將他們定義為virtual。當我們透過參考或指標呼叫一個虛擬函式，那個呼叫將會是動態繫結的，取決於該參考或指標所繫結的物件之型別，可能會執行基礎類別的版本，或是其中一個衍生類別的版本。
- 基礎類別指定一個成員函式應該被動態繫結的方式是在它的宣告前放上關鍵字virtual。任何非static的成員函式，除了建構器外，都可以是虛擬的。
- virtual關鍵字只會出現在類別內的宣告上，而且不可以用在出現於類別主體外的函式定義上。
- 在基礎類別中被宣告為virtual的函式在衍生類別中也隱含是virtual的
- 沒有被宣告為virtual的函式是在編譯時期解析的而非執行時期。(像是isbn，就只會有一個)
### 存取控制與繼承
- 衍生類別繼承在其基礎類別中定義的成員，然而衍生類別不一定會取用從基礎類別繼承而來的成員。
- 一個衍生類別可以存取其基礎類別的public成員，但不能存取private成員。
- 希望衍生類別使用基礎類別的成員時(仍然禁止其他使用者存取)，我們會在protected存取指定符後指定這種成員。
- Quote類別預期它的衍生類別定義它們自己的net_price函式，要這麼做，類別需要存取price成員，因此，Quote將那個成員定義為protected。
## 15.2.2 定義衍生的類別
- 一個衍生類別必須指出它繼承自哪個(或哪些)類別
- 在類別衍生串列中這麼做(一個冒號後面跟著以逗號分隔的一串之前定義過的類別之名稱)
    - 每個基礎類別名稱前面都可以接著一個選擇性的存取指定符，那會是public、protected或private其中之一
- 一個衍生類別必須宣告它想要覆寫的每一個繼承而來的成員函式
    ```
    class Bulk_quote : public Quote {  // Bulk_quote繼承自Quote
        Bulk_quote() = default;
        Bulk_quote(const std::string&, double, std::size_t, double);
        // 覆寫基礎版本以實作大量購買的折扣策略
        double net_price(std::size_t) const override;
    private:
        std::size_t min_qty = 0;  // 要套用折扣的最低購買量
        double discount = 0.0;  // 要套用的折扣
    };
    ```
- 在類別衍生串列中的存取指定符決定了一個衍生類別的使用者是否被允許知道該衍生類別繼承自其基礎類別
    - 衍生是public的，基礎類別的public成員也會變成衍生類別介面的一部分，此外，我們可以將公開衍生類別的一個物件繫結至對其基礎型別的一個指標或參考
    - 在bulk_quote使用public的衍生，bulk_quote的介面隱含就會有isbn函式，所以我們可以在預期Quote的指標或參考的地方使用一個Bulk_quote物件。
- 大多數的類別都僅直接繼承自一個基礎類別，這種形式的繼承被稱為單一繼承(衍生串列中有多個基礎類別的類別就是多重繼承)
### 衍生類別中的虛擬函式
- 衍生類別經常會(並非永遠)覆寫他們繼承的虛擬函式，如果一個衍生類別沒有覆寫來自其基礎的一個virtual，那麼，就跟其他成員一樣，衍生的類別會繼承定義在其基礎類別中的那個版本
- 衍生類別可以在它所覆寫的函式上使用virtual關鍵字，但這並非必要
- 新標準會讓衍生類別明確指出它希望某個成員函式覆寫它所繼承的一個virtual，它那麼作的方式是在參數列後指定override
    - 如果該成員是一個const或參考函式，那就是在const或參考資格修飾符之後
### 衍生類別物件和衍生對基礎的轉換
- 一個衍生類別函有多個部分
    - 子物件，含有衍生類別本身中定義的(非static)成員
    - 對應到衍生類別所繼承的每個基礎類別的子物件
- 例子: bulk_quote物件含有四個資料元素
    - 繼承自Quote的bookNo和price資料成員
    - Bulk_quote所定義的min_qty和discount成員
- 雖然標準並沒有指定衍生物件在記憶體中如何布局，我們可以把一個Bulk_quote物件想成由兩個部分構成，
    - 繼承自Quote的成員
    - Bulk_quote所定義的成員
- 一個物件的基礎部分和衍生部分並不保證會連續地儲存
- 因為衍生物件含有對應其基礎類別的子部分，我們可以把一個衍生型別的物件當成其基礎型別的物件使用。特別是，我們可以把一個基礎類別參考或指標繫結到一個衍生物件的基礎類別部分。
    ```
    Quote item;  // 基礎型別的物件
    Bulk_quote bulk;  // 衍生型別的物件
    Quote *p = &item;  // p指向一個Quote物件
    p = &bulk;  // p指向bulk的Quote部分
    Quote &r = bulk;  // r繫結至bulk的Quote部分
    ```
- 這種轉換經常被稱為衍生對基礎的轉換(derived-to-base conversion)，編譯器會隱含地套用衍生對基礎轉換
- Note: 一個衍生物件函有對應其基礎類別的子物件，這個事實是了解繼承運作方式的關鍵
### 衍生類別建構器
- 雖然一個衍生物件含有繼承自它基礎的成員，它無法直接初始化那些成員。
- 衍生類別必須使用一個基礎類別建構器來初始化它的基礎類別部分
- Note: 每個類別都控制它的成員如何被初始化
- 一個物件的基礎類別部分，會在建構器的初始化階段中，連同衍生類別的資料成員一起被初始化。
- 類似於我們初始化一個成員的方式，一個衍生類別建構器也會使用它的建構器初始器串列來串入引數到一個基礎類別建構器。
- Bulk_quote建構器:
    ```
    Bulk_quote(const std::string* book, double p,
                std::size_t qty, double disc) :
                Quote(book, p), min_qty(qty), discount(disc) { }
                // 跟之前一樣
    ```
- Note: 基礎類別會先被初始化，然後衍生類別的成員會以他們在類別中的宣告順序被初始化
### 從衍生類別使用基礎類別的成員
- 一個衍生類別可以存取其基礎類別的public和protected成員
    ```
    double Bulk_quote::net_price(size_t cnt) const {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    ```
- 一個衍生類別的範疇是內嵌在其基礎類別的範疇內
    - 一個衍生類別如何使用定義在自己類別的成員，和它如何使用定義在其基礎中的成員(例如price)之間並無差異
- 關鍵概念: 尊重基礎類別的介面
    - 每個類別都定義有自己的介面。
    - 與類別型別的一個物件互動時，應該使用該類別的介面，即使那個物件是某個衍生物件的基礎類別也是一樣
    - 衍生類別的建構器不應該直接初始化它基礎類別的成員。一個衍生建構器的建構器主體可以指定值給它的public或protected基礎類別成員。雖然它能夠對那些成員進行指定，它一般不應該這麼做。就像基礎類別的其他使用者，一個衍生類別應該尊重其基礎類別的介面，使用建構器來初始化它繼承而來的成員
### 繼承和static成員
- 如果一個基礎類別定義了一個static成員，整個階乘架構中就只定義了那麼一個成員。不管有多少類別衍生自一個基礎類別，每個static成員都只會存在單一實體。
    ```
    class Base {
    public:
        static void statmem();
    };
    class Derived : public Base {
        void f(const Derived&);
    };
    ```
- static成員遵守一般的存取控制規則，如果成員在基礎類別中是private的，那麼衍生類別就無法存取它。假設成員是可存取的，我們可以透過基礎或衍生來使用一個static成員
    ```
    void Derived::f(const Derived &derived_obj) {
        Base::statmem();
        Derived::statmem();
        // 衍生物件可被用來存起來自基礎的static
        derived_obj.statmem();  // 透過一個derived_obj存取
        statmem();  // 透過這個物件存取
        
    }
    ```
### 衍生類別的宣告
- 一個衍生類別的宣告方式和其他類別一樣，宣告含有類別名稱，但不包含其衍生串列
    ```
    class Bulk_quote : public Quote;  // 錯誤，宣告沒有包含衍生串列
    class Bulk_quote;  // ok
- 宣告的用途是公告一個名稱的存在，以及它所代表的是何種實體，例如一個類別、函式或變數。
- 衍生串列，以及定義所有的其他細節，都必須一起出現在類別主體中。
    ```
### 用作一個基礎類別的類別
- 在我們能夠將之用為一個基礎類別之前，一個類別必須被定義，而不僅是宣告:
    ```
    class Quote;  // 宣告了但未定義
    // 錯誤: Quote必須有定義
    class Bulk_quote : public Quote {...};
    ```
- 每個衍生類別都含有，而且可以使用，它繼承自其基礎類別的成員。要使用那些成員，衍生類別必須知道它們是什麼
- 這個規則的一個結果就是，你不可能從自身衍生出一個類別來
- 基礎類別本身也可以是一個衍生類別
    ```
    class Base { ... };
    class D1: public Base { ... };
    class D2: public D1 { ... };
    ```
- Base是D1的一個直接基礎，並且，是D2的一個間階基礎
- 每個類別都會繼承其值階基礎類別的所有成員。
- 最外沿的衍生類別會繼承它值階基礎的成員。直接基礎的成員包括它所繼承而來的那些
### 防止繼承
- 有時我們會定義不想要其他人繼承的類別。
- 又或者我們不想去考慮定義出來的類別是否適合作為一個基礎類別
- 新標準底下，我們可以在類別名稱後面加上final來防止一個類別被當成基礎來用
    ```
    class NoDerived final { };
    class Base { };
    class Last final : Base { };
    class Bad : NoDerived { };  // 錯誤: NoDerived是final
    class Bad2 : Last { };  // 錯誤: Last是final
    ```
## 15.2.3 轉換與繼承
- 了解基礎類別和衍生類別之間的轉換，是理解`c++`中物件導向程式設計運作的必要條件
- 一般來說我們只能將一個參考或指標繫結到型別與參考或指標相同的一個物件，或者是繫結到可接受的const轉換的一個型別
- 有繼承關係的類別是一個重要例外，我們可以將對一個基礎類別型別的指標或參考繫結到衍生自那個基礎類別型別的物件
- 例子: 可以把bulk_quote物件的位址指定給一個Quote*
- 這個事時有一個關鍵且重要的後果，當我們使用對基礎類別的一個參考或指標，我們並不知道那個指標或參考所繫結的物件的實際型別
- Note: 就像內建指標，智慧指標類別也支援衍生對基礎的轉換，我們可以將對衍生物件的一個指標儲存在對基礎型別的一個智慧指標中
### 靜態型別與動態型別
- 使用有繼承關係的型別時我們需要區分靜態型別與動態型別
- 靜態型別在編譯時期就已經知道了，它是一個變數所宣告的型別，或是一個運算式所產出的型別
- 動態型別則是記憶體中那個變數或運算式所代表的物件的型別。動態型別可能要到執行時期才能確定
    ```
    double ret = item.net_price(n);
    ```
- item的靜態型別是Quote&，動態型別則取決於item所繫結的引數之型別
- 不是參考也不是指標的一個運算式之動態型別永遠都會與該運算式的靜態型別相同
- Note: 必須了解的一個重點是，對一個基礎類別或參考的靜態型別可能會與其動態型別不同
### 基礎對衍生的隱含轉換並不存在
- 就是衍伸類別的參考你也不能傳基礎類別給它
- 衍生到基礎的轉換之所以能夠存在是因為每個衍生類別物件都含有基礎類別型別的指標或參考可以繫結的基礎類別部分。
- 有時有點令人意外的是，即使一個基礎指標或是參考繫結到一個衍生物件，我們還是無法從基礎轉為衍生
    ```
    Bulk_quote bulk;
    Quote *itemP = &bulk;
    Bulk_quote *bulkP = itemP;  // 錯誤: 無法將基礎轉為衍生
    ```
- 編譯器在編譯時期沒辦法知道某個特定的轉換在執行時期是否會是安全的，編譯器只會查看指標或參考的靜態型別以判斷轉換是否合法。
- 如果基礎類別有一或多個虛擬函式，可以使用一個dynamic_cast來請求在執行時期檢查某個轉換
- 在我們知道從基礎到衍生的轉換是安全的那些情況中，我們可以使用一個static_cast來覆寫編譯器的行為
### ...而物件之間也沒有轉換
- 衍生對基礎的自動轉換僅適用於對參考或指標型別的轉換
- 從衍生型別到基礎型別的轉換並不存在
- 當我們初始化或指定類別型別的一個物件，我們實際上是在呼叫一個函式。
- 初始化時我們呼叫的是一個建構器
- 當我們進行指定，我們呼叫的是指定運算子
- 這些成員一班都會有一個參數是對該類別型別的const版本的一個參考
- 因為這些成員接受參考，衍生對基礎的轉換能讓我們傳入一個衍生物件給基礎類別的某個拷貝或移動運算。這些運算不是虛擬的。
- 當我們傳入一個衍生物件給基礎類別的建構器，所執行的建構器是定義在基礎類別中
- 那個建構器只會知道那個基礎類別本身的成員
- 同樣，如果我們指定一個衍生物件給一個基礎物件，所執行的指定運算子會是定義在基礎類別中的那一個。那個運算子也只會知道基礎類別本身的成員
- 合成版本會逐個成員拷貝或指定類別的資料成員
    ```
    Bulk_quote bulk;  // 衍生型別的物件
    Quote item(bulk);  // 使用Quote::Quote(const Quote&)建構器
    item = bulk;  // 呼叫Quote::operator=(const Quote&)
    ```
- 當item被建構，Quote的拷貝建構棄就會執行，那個建構器只知道基礎類別的成員，它會從bulk的Quote部分拷貝那些成員，並忽略是bulk的Bulk_quote部分的那些成員。
- 因為Bulk_quote部分被忽略了，我們說bulk的Bulk_quote被切掉(sliced down)了
- WARNING: 當我們以衍生型別的一個物件來初始化或指定給基礎型別的一個物件，所拷貝、移動或指定的，只有那個衍生物件的基礎類別部分。該物見的衍生部分會被忽略。
# 15.3 虛擬函式
- 動態繫結發生在一個虛擬成員函式透過對一個基礎類別型別的參考或指標被呼叫時
- 因為到執行時期之前都不知道該函式的哪個版本會被呼叫，虛擬函式必須永遠都是有定義的
- 一般來說沒使用的函式就不用定義，但我們必須定義每一個虛擬函式，因為編譯器沒辦法判斷虛擬函式是否被使用
- 關鍵概念: 彼此有繼承關係的型別之間的轉換
    - 從衍生到基礎的轉換僅適用於指標或參考
    - 並不存在從基礎類別到衍生型別的隱含轉換
    - 衍生到基礎的轉換可能因為存取控制的關係而無法取用
    - 雖然自動轉換僅適用於指標或參考，繼承階層架構大多數類別都會(隱含或明確)定義拷貝控制成員。
    - 因此我們經常可以拷貝、移動或指定衍生型別的物件到一個基礎型別物件。
    - 然而拷貝移動指定衍生型別的物件到基礎型別的物件只會拷貝移動指定該物件中基礎類別部分的成員
### 對虛擬函式的呼叫可能會在執行時期解析
- 當虛擬函式透過參考或指標被呼叫，編譯器會產生代碼在執行時期決定要呼叫哪個函式
- 被呼叫的函式就是對應到該指標或參考所繫結的物件之動態型別的那一個
- 例子: print_total會在它名為item的參數(是對base的reference)上呼叫net_price
    - 這是由於item是參考，並且net_price是virtual
    ```
    Quote base("0-201-824700-1");
    print_total(cout, base, 10);
    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(cout, derived, 10);
    ```
- 重點是，動態繫結只會發生在一個虛擬函式透過指標或參考被呼叫時
- 關鍵概念: `c++`中的多型(polymorphism)
    - 彼此有繼承關係的型別是多型的型別(polymorphic types)
    - 因為我們可以使用這些型別的許多形式，同時忽略他們之間的差異
    - 參考和指標的靜態與動態型別可以不同的事實是`c++`支援多型的基石
    - 對非虛擬函式的呼叫都是在編譯時期繫結的
    - 在一個物件上呼叫任何函式(無論虛擬與否)也是在編譯時期繫結的
- Note: 只有在呼叫是透過一個參考或指標進行時，虛擬函式才會在執行時期解析。只有在那些情況下，一個物件的動態型別才可能與它的靜態型別不同
### 一個衍生類別中的虛擬函式
- 當衍生類別覆寫虛擬函式，它可以(但不是必要)重複virtual關鍵字，一旦函式被宣告為virtual，它在所有的衍生類別中都會是virtual的
- 覆寫繼承來的虛擬函式的一個衍生類別函式，跟它所覆寫的基礎類別型別必須有完全相同的參數型別
- 除非是回傳一個參考(或指標)，否則衍生類別中的virtual的回傳型別也必須跟基礎類別的函式的回傳型別相同
- 可以回傳參考或指標指向他們本身之間有繼承關係的型別的那些virtual
- 例子:
    - D衍生自B，基礎類別的virtual能夠回傳一個B*，而衍生類別版本的virtual可以回傳D*
- Note: 在基礎類別中是virtual的函式在衍生類別中也隱含是virtual的，當一個衍生類別覆寫一個virtual，基礎與衍生類別中的參數必須完全吻合
### final和override指定符
- 在衍生類別中定義一個與基礎類別的virtual同名但具有不同參數的函式是合法的
    - 這種情況衍生的版本並沒有覆寫基礎類別的版本
    - 這種宣告經常是一種失誤，為了避免這個失誤，可以在衍生類別中的一個虛擬函式上指定override，而且可以請求編譯器幫我們找出這種問題
- 如果一個標示為override的函式沒有覆寫既有的一個virtual，編譯器會報錯
    ```
    struct B {
        virtual void f1(int) const;
        virtual void f2();
        void f3();
    };
    struct D1 : B {
        void f1(int) const override3;  // ok: f1匹配基礎的f1
        void f2(int) override;  // 錯誤，B沒有f2(int)函式
        void f3() override;  // 錯誤: f3不是virtual
        void f4() override;  // 錯誤: B沒有名為f4的函式
    }
    ```
- 可以把一個函式標示為final。試圖覆寫被定義為final的函式的任何嘗試都會被標示為錯誤
    ```
    struct D2 : B {
        void f1(int) const final;
    };
    struct D3 : D2 {
        void f2();
        void f1(int) const;
    };
    ```
- final與override指定符出現在參數列(包括const)後面，以及尾端回傳後面
### 虛擬函式與預設引數
- 虛擬函式可以有預設引數，如果一個呼叫使用一個預設引數，所用的值會是我們透過它呼叫該函式的那個靜態型別所定義的值。
- 具有預設引數的虛擬函式在基礎和衍生類別中都應該使用相同的引數值
### 繞過虛擬機制
- 有的時候我們想要迫使呼叫使用那個virtual的某個特定版本，可以使用範疇運算子來這麼做
    ```
    double undiscounted = baseP->Quote::net_price(42);
    ```
- 這個呼叫會在編譯時期解析
- Note: 一般來說，應該只有成員函式(或friend)需要使用範疇運算子來避開虛擬機制
- 如果想要呼叫其基礎類別版本的一個衍生版虛擬函式省略了範疇運算子那個呼叫就會在執行時期解析為對衍生版本自身的呼叫，導致無限遞迴
# 15.4 抽象基礎類別
- 折扣方案:
    - 購買本數到特定數目前有優惠，之後原價
    - 數量折扣(超過最小購買量有折購)
- 共通點: 一個數量和一個折扣數
- 定義一個名為disc_quote的類別儲存數量和折扣數
- 讓Bulk_quote繼承自Disc_qutoe，每個衍生類別都定義自己版本的net_price
- 問題: 無法處理Disc_quote的price
### 純粹的虛函式
- 事實上我們想要完全防止使用者創建Disc_quote物件，這個類別代表書籍折扣的一般性概念而非某個具體的折扣策略
- 我們可以將net_price定義為一個純粹的虛擬函式
- 一個pure virtual並不需要被定義
- 指出一個虛擬函式是pure的方式是在函式主體的位置使用=0
- =0只能出現在類別主體中一個虛擬函式的宣告上
    ```
    class Disc_quote : public Quote {
    public:
        Disc_quote() = default;
        Disc_quote(const std::string &book, double price,
                   std::size_t qty, double disc)
                   : Quote(book, price),
                   quantity(qty),
                   discount(disc) { }
        double net_price(std::size_t) const = 0;
    protected:
        std::size_t quantity = 0;
        double discount = 0.0;
    };
    ```
- Disc_quote有建構器(為了給衍生類別使用)
- 我們無法直接定義這個型別的物件
- 我們可以為一個pure virtual提供定義。然後，其函式主體必須定義在類別外。也就是說我們無法在類別內為=0的一個函式提供函式主體
### 具有Pure Virtual的類別是抽象基礎類別
- 含有(或繼承了但沒覆寫)一個pure virtual函式的類別是抽象基礎類別(abstract base class)
- 我們無法(直接)創建型別為抽象基礎類別的物件
- 因為Disc_quote把net_price定義為pure virtual，所以我們無法定義型別為Disc_quote的物件
- 我們可以定義繼承自Disc_quote的類別的物件，只要那些類別有覆寫net_price
- note: 我們無法創建型別為抽象基礎類別的物件
### 衍生類別的建構器只會初始化它的直接基礎類別(Direct Base Class)
- 重新實作Bulk_quote來繼承Disc_quote而非直接繼承Quote:
    ```
    // 當同一本書賣出了指定的數目，就會套用折扣
    // 這個折扣被表示為一個小數，用以降低正常的價格
    class Bulk_quote : public Disc_quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
        Disc_quote(book, price, qty, disc) { }
    // 覆寫基礎版本以實作數量折扣策略
    double net_price(std::size_t) const override;
    };
    ```
- 關鍵概念: 重構: 新增Disc_quote到Quote的階層架構中就是重構的一個例子。重構涉及了重新設計類別階層架構，將某個類別的運算或資料移到另一個。在物件導向的應用中，重構是很常見的事情。
- 值得注意的是，即使我們改變了繼承階層架構，使用Bulk_quote或Quote的程式碼都無須改變，然而，當類別重構過(或以其他方式更改過)，我們就必須重新編一用到那些類別的任何程式碼。
# 15.5 存取控制與繼承
- 每個類別控制自己的初始化
- 每個類別也控制自己的成員對衍生類別是否可存取
### protected成員
- 就像private，protected對使用者而言無法存取
- 就像public，protected成員可以讓此類別所衍生的類別的成員和friend存取
- ==一個衍生類別或friend只能透過一個衍生物件來存取基礎類別的protected成員，衍生類別對基礎類別物件的protected成員沒有特殊存取權==
    ```
    class Base {
    protected:
        int prot_mem;
    };
    class Sneaky : public Base {
        friend void clobber(Sneaky&);
        friend void clobber(Base&);
        int j;
    };
    // clobber可以存取sneaky物件中的private和protected成員
    void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
    // 錯誤，clobber不能存取Base中的protected成員
    void clobber(Base &b) { b.prot_mem = 0; }
    ```
- 如果衍生類別(和friend)能夠存取一個基礎類別物件中的受保護的成員，那第二個版本的clobber就會是合法的，那個函式不是base的friend，但它卻被允許更改型別為base的一個物件，只要沿著Sneakuy這條線定義一個新的類別，我們就能繞過protected為任何類別所提供的防護
### public、private與protected的繼承
- ==對類別所繼承的一個成員的存取權==，受到基礎類別中那個成員的存取指定符，和衍生類別的衍生串列中的存取指定符的組合影響。思考下列階層架構:
    ```
    class Base {
    public:
        void pub_mem();  // public成員
    protected:
        int prot_mem;  // protected成員
    private:
        char priv_mem;  // private成員
    };
    struct Pub_Derv : public Base {
        // ok: 衍生類別可以存取protected
        int f() { return prot_mem; }
        // 錯誤:private成員對衍生類別而言是無法存取的
        char g() { return priv_mem;}
    };
    struct Priv_Derv : private Base {
        // private的衍生部會影響衍生類別中的存取
        int f1() const { return prot_mem; }
    }
    ```
- ==衍生的存取指定符不會影響一個衍生類別的成員(和friend)是否可以存取其直接基礎類別的成員==。
- 對基礎類別的成員之存取是由基礎類別本身中的存取指定符所控制。Pub_derv和Priv_derv可以存取protected成員，兩者皆不能存取priv_mem
- 衍生存取指定符的用途是控制衍生類別(包括其他衍生自衍生類別的類別)的使用者對繼承自Base的成員的存取權
    ```
    Pub_Derv d1;  // public繼承
    Priv_Derv d2;  // private繼承
    d1.pub_mem();  // public繼承可以直接存取
    d2.pub_mem();  // private繼承不能直接存取
    ```
- 一個衍生類別所用的衍生存取指定符也控制繼承了那個衍生類別的類別對基礎類別的存取
    ```
    struct Derived_from Public : public Pub_Derv {
        // ok: Base::prot_mem在Pub_Derv仍然是protected
        int use_base() { return prot_mem; }
    };
    struct Derived_from_Private : public Priv_Derv {
        // 錯誤: Base::prot_mem在Priv_Derv中是private
        int use_base() { return prot_mem; }
    };
    ```
- 使用protected的繼承: 那個base的public成員在那個類別中，就會是protected成員。使用者會沒辦法存取來自protected繼承的成員，但自己的成員和friend可以存取
### 衍生對基礎轉換的可用性
- 衍生對基礎的轉換是否可用，取決於是哪段程式碼試著使用轉換，也取決於在該衍生類別串列中所用的存取指定符，假設D繼承自B
    - 只有D公開繼承自B，使用者程式碼才可以使用衍生對基礎的轉換(使用者方面)
    - 如果使用protected或private來繼承B，使用者程式碼不可以使用這個轉換(使用者方面)
    - D的成員函式和friend可以使用對B的轉換，不管D是如何繼承自B的(衍生類別方面)
    - 如果D使用public或protected繼承自B，那麼衍生自D的類別的成員函式和friend就可以使用衍生對基礎的轉換(衍生的衍生)
    - 如果D私密的privately繼承自B，那麼這種程式碼就不可以使用這個轉換(衍生的衍生)
    - 上面這個呼應了，繼承的方式控制了使用者，不控制衍生類別，可是控制衍生類別的衍生類別
- Tip在你程式碼中任何給定的位置，如果基礎類別的一個public成員是可存取的，那麼衍生對基礎的轉換也會是可存取的，但反過來說就不是這樣
- 關鍵概念: 類別設計和protected成員
    - 介面(類別使用者)
    - 實作(類別實作者)
        - 衍生類別可取用
        - 基礎類別可取用
### 朋友關係與繼承
- 朋友關係沒有遞移姓，朋友關係也不可繼承
- 基礎類別的朋友對衍生類別沒有存取權
- 衍生類別的朋友對基礎類別也沒有特殊存取權
    ```
    class Base {
        // 新增朋友宣告；其它的成員跟之前一樣
        friend class Pal;  // Pal不能存取衍生自Base的類別
    public:
        void pub_mem();  // public成員
    protected: 
        int prot_mem;  // protected成員
    private:
        char priv_mem;  // private成員
    };
    class Sneaky : public Base {
        friend void clobber(Sneaky&);
        friend void clobber(Base&);
        int j;
    };
    class Pal {
    public:
        int f(Base b) { return b.prot.mem; }  // ok. public/ private/ protected都可以存取
        int f2(Sneaky s) { return s.j; }  // Pal不是Sneaky的朋友，儘管Sneaky衍生自Base
        int f3(Sneaky s) { return s.prot_mem; }  // ok: Pal是一個friend
    };
    ```
- f3是合法的可能令人驚訝，但它是每個類別都控制對自己成員的存取這個概念的邏輯延伸
- 注意這邊，基礎類別的朋友，可以存取衍生類別的基礎類別部分
- recall第一個例子，衍生類別的朋友，不可以存取基礎類別的protected成員，每個類別都控制自己成員的存取
- 當一個類別讓另一個類別成為一個朋友，朋友關係只對那個類別成立
- Note: 朋友關係無法繼承，每個類別都控制對其成員的存取
### 豁免個別成員
- 有的時候我們得變更衍生類別繼承的一個名稱的存取層級。
- 可以提供一個using宣告來這麼做:
    ```
    class Base {
    public:
        std::size_t size() const { return n; }
    protected:
        std::size_t n;
    };
    class Derived : private Base {
    // 注意: private的繼承
    public:
        // 讓與該物件的size有關的成員維持同樣的存取層級(把private繼承改成public)
        using Base::size;
    protected:
        // (把private繼承改成protected)
        using Base::n;
    }
    ```
- Derived的使用者能夠存取size成員
- 衍生自Derived的類別則可以存取n
- 類別內的using宣告可以指名間接或直接基礎類別的任何可存取成員(非private，因為private的using自己也不能拿)
- Note: 衍生類別只能為它被允許存取的名稱提供using宣告
### 預設的繼承防護等級
- struct和class唯一的差別僅在於成員的預設存取指定符，以及預設的衍生存取指定符
- 一個私密衍生的類別應該明確指定private，而非仰賴預設值。明確表示可以清楚指明私有繼承是刻意的，而非疏忽
# 15.6 繼承之下的類別範疇
- 每個類別都定義自己的範疇，在範疇下定義自己的成員
- 在繼承之下衍生類別的範疇是巢狀的，內嵌在基礎類別的範疇中
    - 有個名稱在衍生類別中無法解析，就會在外圍的基礎類別範疇中尋找那個名稱的定義
### 名稱查找發生在編譯時期
- 靜態型別決定了哪個物件的成員是合用的
- 即使靜態型別可能和動態型別不同，還是由靜態型別來決定什麼成員可以使用
- 例子: 我們想在Disc_quote新增一個discount_policy
    ```
    class Disc_quote : public Quote {
    public:
        std::pair<size_t, double> discount_policy() const {
            return {quantituy, discount};
        }
    }
    ```
- 我們只能透過型別為Disc_quote或Disc_quote的衍生類別的物件、指標、參考來使用discount_policy:
    ```
    Bulk_quote bulk;
    Bulk_quote *bulkP = &bulk;  // 靜態和動態相同
    Quote *itemP = &bulk;  // 靜態與動態不同
    bulkP->discount_policy();  // Bulk_quote是Dis_quote的衍生類別，在Bulk_quote找不到，然後去Dis_quote找，發現discount_policy()
    itemP->discount_policy();  // 錯誤，itemP的型別是Quote*
    ```
- bulk的成員透過itemP是看不見的
### 名稱衝突和繼承
- 衍生類別可以重複使用定義在它其中一個直接或間接基礎類別中的名稱
- 定義在內層範疇(衍生類別)的名稱會遮蔽外層範疇
    ```
    struct Base {
        Base(): mem(0) { }
    protected:
        int mem;
    };
    struct Derived : Base {
        // 初始化Derived::mem為i
        // Base::mem是預設初始化的
        Derived(int i): mem(i) { }
        // 回傳Derived的mem
        int get_mem() { return mem; }
    protected:
        int mem;  // 遮蔽基礎中的mem
    };
    ```
- get_mem內mem會被解析為Derived中的名稱
    ```
    Derived d(42);
    cout << d.get_mem() << endl;  // 印出42
    ```
- Note: 與基礎類別中某個成員同名的衍生類別成員會遮蔽那個基礎類別成員的直接使用
### 使用範疇運算子來使用被遮蔽的成員
- 透過範疇運算子來使用被遮蔽的成員
    ```
    struct Derived : Base {
        int get_base_mem() { return Base::mem; }
    };
    ```
- 除了覆寫繼承而來的虛擬函式，衍生類別通常不應該重複使用在它的基礎類別中定義的名稱
- 關鍵概念: 名稱查找與繼承
    - 給定`p->mem`會發生如下四個步驟
        - 判斷p的靜態型別，因為我們呼叫一個成員，那個型別必須是一個類別型別
        - 在對應p靜態型別的類別中查找mem，如果沒有找到，就在基礎類別中尋找，並一直往上找，如果到最後一個類別都沒有找到，這個呼叫就無法編譯
        - 一旦找到mem，就進行型別檢查，檢查這個呼叫是否合法
        - 假設呼叫合法，編譯器就產生程式碼，這會隨著呼叫是否為virtual而有變化
            - 如果mem是virtual，而呼叫是透過參考或指標進行，編譯器產生的程式碼依據動態型別判斷要執行哪個版本
            - 否則，編譯器產生一般呼叫
### 一如以往，名稱查找發生在型別檢查之前
- 內層範疇的函式不會重載外層範疇的函式
- 因此衍生類別的函式不會重載基礎類別的成員
- 如果衍生類別和基礎類別有相同名稱，衍生類別會遮蔽基礎類別，即使參數不同，一樣會遮蔽
    ```
    struct Base {
        int memfcn();
    };
    struct Derived : Base {
        int memfcn(int);  // 遮蔽基礎中的memfcn
    };
    Derived d;
    Base b;
    b.memfcn();  // 呼叫Bae的memfcn
    d.memfcn(10);  // 呼叫Derived的memfcn
    d.memfcn();  // 錯誤，引述不匹配
    d.Base::memfcn();  // ok
    ```
### 虛擬函式與範疇
- 如果基礎與衍生成員所接受的引數不同，就沒辦法透過對基礎類別的參考或指標呼叫衍生版本了
    ```
    class Base {
    public:
        virtual int fcn();
    };
    class D1 : public Base {
    public:
        // 遮蔽基礎中的fcn, 這個fcn不是virtual
        int fcn(int);  // 參數列不同
        virtual void f2();  // Base中不存在的虛擬函式
    };
    class D2 : public D1 {
    public:
        int fcn(int);  // 非虛擬函式遮蔽d1::fcn(int)
        int fcn();  // 覆寫來自base的virtual
        void f2();  // 覆寫來自d1的virtual f2
    };
    ```
### 透過基礎類別呼叫一個被遮蔽的virtual
- 給定上述類別，呼叫這些函數
    ```
    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1 = &bobj;
    Base *bp2 = &d1obj;
    Base *bp3 = &d2obj;
    bp1->fcn();  // 虛擬呼叫，在執行時期呼叫Base::fcn
    bp2->fcn();  // 虛擬呼叫，在執行時期呼叫Base::fcn
    bp3->fcn();  // 虛擬呼叫，在執行時期呼叫D2::fcn
    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    bp2->f2();  // Base沒有f2
    d1p->f2();  // 虛擬呼叫，在執行時期呼叫D1::f2
    d2p->f2();  // 虛擬呼叫，在執行時期呼叫D2::f2
    // 更複雜的呼叫
    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    p1->fcn(42);  // 錯誤，base沒有fcn(int)
    p2->fcn(42);  // 呼叫D1::fcn(int)
    p3->fcn(42);  // 呼叫D2::fcn(int)
    ```
- 呼叫非虛擬函式時，動態型別不重要，被呼叫的版本僅取決於指標的靜態型別
### 覆寫重載的函式
- 成員函式(虛擬與否)可以被重載
- 衍生類別可以重載它所繼承的零或多個重載函式
- 如果衍生類別希望所有的重載版本都能夠過其型別取用，那它就必須覆寫它們全部，或者都不覆寫
- 有的時候為了覆寫該類別需要特化的那個函式而覆寫每一個基礎版本，會是很繁瑣的工作
- 這個問題的解決方法是: 為那個重載成員提供一個using宣告。
- 一個using宣告僅指定一個名稱，不可以指定參數列。因此，為一個基礎類別成員函式使用的一個using宣告會把那個函式的所有重載實體都帶到衍生類別的範疇，所有名稱都帶過來之後，衍生類別就只需要定義真正取決於其型別的那些函式
- 類別內使用using的正常規則也適用於重載函式的名稱，基礎類別中函式的每個重載實體必須是衍生類別可取用的
- 那些沒有被衍生類別重新定義的重載版本的存取權，則會是using宣告處生效的存取全

# 15.7 建構器和拷貝控制
- 建構器
- 解構器
- 拷貝、移動建構器
- 拷貝、移動指定運算子
## 15.7.1 虛擬解構器
- 基礎類別一般應該定義一個虛擬解構器
    - 這個解構器需要是virtual的，才能讓繼承階層架構中的物件是可以動態配置的
- recall: 解構器會在我們delete對一個動態配置的物件的指標時執行
- 如果指標指向某個繼承階層架構中的一個型別，那個指標的靜態型別有可能會與被摧毀的物件的動態型別不同
- 例子: delete型別為`Quote*`的一個指標，那個指標所指的可能會是一個Bulk_quote物件
    - 如果該指標指向Bulk_quote，編譯器就必須知道它應該執行Bulk_quote的解構器才行
    ```
    class Quote {
    public:
        // 如果只像衍生物件的基礎指標被刪除了，就會需要虛擬的解構器
        virtual ~Quote() = default;  // 解構器的動態繫結
    };
    ```
- 和其它的virtual一樣，衍生自Quote的類別會有虛擬解構器，不管他們用的是合成的解構器或是定義他們自己的版本，只要基礎類別的解構器是virtual的，當我們delete對基礎的一個指標，就會執行正確的解構器
    ```
    Quote *itemP = new Quote;  // 相同的靜態與動態型別
    delete itemP;  // Quote版本的解構器被呼叫
    itemP = new Bulk_quote;  // 靜態與動態型別不同
    delete itemP;  // Bulk_quote的解構器被呼叫
    ```
- 當對基礎的一個指標指向一個衍生物件，在其上執行delete時，如果基礎的解構器不是virtual的，就會出現未定義的行為
- 基礎類別的解構器是:如果一個類別需要解構器，它也會需要拷貝和指定這個經驗法則的重要例外。
- 基礎類別幾乎一定會需要解構器，如此它才能讓解構器是virtual的
### 虛擬解構器匯關閉合成的移動
- 如果一個類別定義了一個解構器，即使是使用=default，編譯器也不會為那個類別合成一個移動運算
## 15.7.2 合成的拷貝控制與繼承
- 合成版本就跟其他任何合成版本一樣，逐個初始化、指定、摧毀
- 此外，這些合成的成員會使用來自基礎類別的對應運算初始化、指定或摧毀一個物件的基礎部分
    - 合成的Bulk_quote預設建構器會執行Dis_quote的預設建構器，而後者會接著執行Quote的預設建構器
    - Quote的預設建構器會將BookNo預設初始化為空字串，並使用類別內的初始器來將price初始化為零
    - Quote建構器執行完畢，Disc_quote建構器接著執行，使用類別內初始器來初始化qty和discount
    - Disc_quote建構器執行完成，Bulk_quote建構器接續執行
- 拷貝建構器也一樣
- 重要的是，對應的成員要是可存取的，而不是已刪除函式
- 因為Quote定義了虛擬的解構器，所以他沒有移動運算，Quote沒有移動運算的事實也意味著他的衍生類別也沒有
### 基礎類別和衍生類別中的Deleted拷貝控制
- 一個基礎類別被定義的方式也可能導致衍生類別的成員被定義為deleted:
    - 如果基礎類別中的預設建構器、拷貝建構器、拷貝指定運算子或解構器是deleted或無法取用(比如private)，那麼衍生類別中對應的成員也會被定義為deleted，因為編譯器無法使用基礎類別的成員來建構、指定或摧毀物件的基礎類別部分
    - 如果基礎類別有無法取用或deleted的解構器，那麼衍生別中合成的預設和拷貝建構器也會被定義為deleted，因為沒有辦法摧毀衍生物件的基礎部分
    - 編譯器不會合成一個deleted的移動運算。如果基礎類別中對應的運算是deleted或無法取用，那們我們使用=default來請求一個移動運算時，他在衍生類別中會是一個已刪除函式，因為基礎類別的部分無法移動。如果基礎類別的解構器是deleted或無法取用，移動建構器也會是deleted。
- 例子:
    ```
    class B {
    public:
        B();
        B(const B&) = delete;
    };
    class D : public B {
    };
    D d;  // D合成的預設建構器使用B的預設建構器
    D d2(d); // 錯誤: D的合成版拷貝建構器是deleted，因為他的基礎類別的拷貝建構器被delete了
    D d3(std::move(d));  // 錯誤，
    ```
- B有一個可存取的預設建構器，以及一個明確刪除的拷貝建構器，因此我們不能移動也不能拷貝型別為B的物件(因為B有定義拷貝建構器(定義為已刪除)所以B的移動建構器不會合成，在這樣的情況下移動就會是拷貝來執行，可是拷貝被刪了，所以d3隱含的使用拷貝成員也會錯)
- 實務上如果一個基礎類別沒有預設的拷貝或移動建構器，那麼其衍生類別通常也不會有
### 移動運算和繼承
- 大多數的基礎類別都定義有虛擬解構器，因此預設情況下基礎類別一般不會得到合成的移動運算
- 預設情況下，衍生自沒有移動運算的基礎類別的類別也不會得到合成的移動運算，因為基礎類別中移動運算的缺乏會抑制其衍生類別合成移動運算
- 我們的Quote類別可已使用合成的移動運算，然而，Quote必須明確的定義那些成員(因為他有定義解構器)。一旦他定義了移動運算，他也必須明確的定義拷貝的版本(不然拷貝就會被定義成delete)
    ```
    class Quote {
    public:
        Quote() = default;  // 合成的預設建構器
        Quote(const Quote&) = default;  // 合成的拷貝建構器
        Quote(Quote&&) = default;  // 合成的移動建構器
        Quote& operator=(const Quote&) = default;  // 合成的拷貝指定運算子
        Quote& operator=(Quote&&) = default;  // 合成的移動指定運算子
        virtual ~Quote() = default;  // 合成的虛擬解構器
    };
    ```
## 15.7.3 衍生類別的拷貝控制成員
- 衍生類別建構器的初始化階段會初始化一個衍生物件的基礎類別部分，也會初始化它自己的成員
- 衍生類別的拷貝或移動建構器必須拷貝或移動它的基礎部分。以及那個衍生類別自己的成員
- 同樣，衍生類別的指定運算子也必須指定衍生物件的基礎部分中的成員
- 不同於解構器，解構器只負責摧毀衍生類別所配置的資源，一個物件的成員是隱含的被摧毀的，衍生物件的基礎類別部分也會自動被摧毀
- 當一個衍生類別定義了拷貝或移動運算，那個運算就負責整個物件的拷貝或移動，包括基礎類別的成員
### 定義一個衍生的拷貝或移動建構器
- 當我們為衍生類別定義拷貝或移動建構器，我們一般會使用對應的基礎類別建構器來初始化物件的基礎部分
    ```
    class Base { };
    class D: public Base {
    public:
        // 預設情況下，基礎類別的預設建構器初始化一個物件的基礎部分
        // 要使用拷貝或移動建構器，我們必須明確的在建構器初始器串列中呼叫那個建構器
        D(const D& d) : Base(d)  // 拷貝基礎的成員 { }
        D(D&&) : Base(std::move(d))  // 移動基礎的成員 { }
    };
    ```
- 初始器Base(d)傳入一個D物件給基礎類別的建構器。
- 雖然理論上Base可以有具備一個型別為D的參數的建構器，但實務上不太可能取而代之，Base(d)會(一般來說)匹配Base的拷貝建構器
- 型別為D的物件d會被繫結倒那個建構器中的Base&參數
- Base的拷貝建構器會將d的基礎部分拷貝到正在創建的物件中
- 假設那個基礎類別的初始器被省略了
    ```
    // 可能有錯的D拷貝建構器定義
    D(const D& d) { }
    ```
- Base的預設建構器會被用來初始化一個D物件的基礎部分
- 預設情況下，基礎類別的預設建構器會初始化一個衍生物件的基礎類別部分
- 如果我們想要拷貝(或移動)基礎類別部分，我們必須在衍生類別的建構器初始器串列中明確使用基礎類別的拷貝(或移動)建構器
### 衍生類別的指定運算子
- 就像拷貝和移動建構器，衍生類別的指定運算子也必須明確的指定它的基礎部分:
    ```
    // Base::operator=(const Base&)
    D &d::operator=(const D &rhs) {
        Base::operator=(rhs);  // 指定基礎部分
        // 如同以往的指定衍生類別中的成員
        // 妥當的處理自我指定並釋放現有資源
        return *this;
    };
    ```
- 這個運算子一開始會先明確的呼叫基礎類別的指定運算子來指定衍生物件基礎部分的成員。
- 基礎類別運算子(應該要)會正確的處理自我指定，並在適當的時候釋放左運算元基礎部分中的舊有值，然後從rhs指定新的值
- 衍生的建構器或指定運算子可以使用他對應的基礎類別運算，不管基礎類別運算是定義了自己的版本，或是使用合成版本
### 衍生類別的解構器
- 一個物件的資料成員會在解構器的主體執行完成後，被隱含的摧毀
- 一個物件的基礎類別部分也會被隱含的摧毀
- 因此，不同於建構器和指定運算子，解構器只需負責摧毀由衍生類別所配置的資源
    ```
    class D: public Base {
    public:
        // Base::~Base自動被調用
        ~D() { }
    };
    ```
- 物件是以他們被建構的相反順序來摧毀的: 衍生的解構器會先執行，然後調用基礎類別的解構器，如此一值在繼承階層架構中往回進行。
### 在建構器和解構器中對virtual的呼叫
- 基礎部分先被建構，然後建構衍生部分
- 衍生部分先被摧毀，然後摧毀基礎部分
- 所以建構衍生部分的時候，類別是不完整的
- 摧毀基礎部分的時候，類別也是不完整的
- 考慮到這個不完整性，編譯器在建構或解構的過程中，對待物件的方式，就好像他的型別改變了一樣
- 一個物件正在建構的時候，他會被視為跟建構器有相同的類別；對虛擬函式的呼叫被繫結的方式就會好像他們跟建構器本身有相同的型別一樣。對解構器來說也是一樣。這種繫結適用於值接被呼叫的virtual或建構器(或解構器)逤呼叫的函式間接呼叫的virtual
- 為了理解這個行為: 請思考如果一個virtual的衍生類別版本從一個基礎類別建構器被呼叫，那會發生什麼事?
    - 這個virtual大概會存取衍生物件的成員，畢竟如果這個virtual不需要使用衍生物件的成員，衍生類別或許使用基礎類別中的版本就好。然而，基礎建構器執行的時候，那些成員尚未初始化。如果這種存取是被允許的，那程式大概會當掉
- Note: 如果建構器或解構器呼叫一個virtual，所執行版本會是對應到建構器或解構器型別的那一個
- ==不太了解的規則==
    - 基礎類別通常需要有一個virtual版本的解構器
## 15.7.4 繼承的建構器
- 在新標準底下，衍生類別可以重複使用其直接基礎類別所定義的建構器。
- 就繼承的一般意義而言，這種建構器並沒有被繼承，但我們還是很常形容這種建構器是繼承而來的
- 跟類別只能初始化它的直接基礎類別一樣，一個類別只能從他的值階基礎繼承建構器
- 一個類別不能繼承預設、拷貝和移動建構器
- 如果編譯器沒有直接定義那些建構器，編譯器會一如以往的合成他們
- 衍生類別繼承其基礎類別建構器的方式是提供一個using宣告，指名其(直接)基礎類別。
    ```
    class Bulk_quote : public Disc_quote {
    public:
        using Disc_quote::Disc_quote;  // 繼承Disc_quote的建構器
        double net_price(std::size_t) const;
    };
    ```
- 一般來說using宣告只會使一個名稱在目前範疇變得可見
- 套用到建構器的時候，using宣告會使編譯器產生程式碼。
- 編譯器會產生對應到基礎類別中的每個建構器
- 編譯器會在衍生類別中產生一個具有相同參數列的建構器
- 編譯器產生的建構器會有這種形式:
    ```
    derived(parms) : base(args) { }
    ```
- 以Bulk_quote為例子:
    ```
    Bulk_quote(const std::string &book,
        double price, std::size_t qty,
        double disc) :
    Disc_quote(book, price, qty, disc) { }
    ```
    - 這種時候，如果衍生類別有自己的資料成員，他們會被預設初始化
### 繼承的建構器的特徵
- 不同於一般成員的using宣告，建構器的using宣告不會改變繼承的建構器的存取層級
    - 不管using宣告出現在哪裡，基礎中是private的建構器，在衍生中也會是private
- using宣告無法指定explicit或constexpr
    - 如果基礎的建構器是explicit或constexpr，那繼承而來的有一樣屬性
- 預設引數不會被繼承，取而代之，衍生的類別會得到多個繼承的建構器，具有預設引數的美個參數都會依序被省略
- 預設、拷貝、移動建構器不會被繼承
- 相同參數的建構器可以繼承來之後覆寫

# 15.8 容器與繼承
- 我們沒辦法定義出容器來存放不同的物件，因此如果我們想用容器來儲存源於某個繼承階層架構的物件，我們通常必須間接的儲存那些物件。
- 假設我們想要定義一個vector來存放一位顧客想要買的數本書，我們無法使用一個vector來存放Bulk_quote物件。我們無法把Quote物件轉換為Bulk_quote，所以我們不能把Quote物件放到那個vector
- 比較不明顯的是，我們也不能使用存放型別為Quote的物件的一個vector。在這種情況中，我們可以把Bulk_quote物件放到容器，然而，那些物件將不再是Bulk_quote物件:
    ```
    vector<Quote> basket;
    basket.push_back(Quote("0-201-824701-1", 50));
    // ok，但只會拷貝物件的Quote部分到basket中
    basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
    // 呼叫Quote所定義的版本，印出750，也就是15*50
    cout << basket.back().net_price(15) << endl;
    ```
- basket中的元素是Quote物件。當我們新增一個Bulk_quote物件到這個vector，它的衍生部分會被忽略
- 因為衍生物件被指定給一個基礎型別物件時會被切掉，容器和有繼承關係的型別並沒有辦法很好的一起使用
### 把(智慧指標)，而非物件，放在容器中
- 當我們需要一個容器存放有繼承關係的物件，我們通常會定義容器來存放對基礎類別的指標(最好是智慧指標)。一如以往，那些指標所指的物件之動態型別可以是基礎類別型別，或衍生自該基礎的某個型別
    ```
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0=201=82470-1", 50));
    basket.push_back(
        make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    cout << basket.back()->net_price(15) << endl;
    ```
- 因為basket存放的是shared_ptr，我們必須解參考basket.back()所回傳的值，以取得要在其上值型net_price的物件。
- 值得注意的是，我們把basket定義為了`shared_ptr<Quote>`，然而在第二個push_back中，我們傳入一個shared_ptr給一個Bulk_quote物件。就像我們可以把對衍生型別的一個普通指標轉為對基礎型別的一個指標，我們也可以把對衍生型別的一個智慧指標轉為對基礎類別型別的一個智慧指標。因此，`make_shared<Bulk_quote>`會回傳一個`shared_ptr<Bulk_quote>`物件，它會在我們呼叫push_back的時候被轉為`shared_ptr<Quote>`
## 15.8.1 撰寫一個Basket類別
- 定義輔助類別管理物件導向的指標
- 定義一個類別表示購物籃
    ```
    class Basket {
    public:
        // 使用合成的預設建構器
        void add_item(const std::shared_ptr(Quote> &sale)) {
            items.insert(sale);
        }
        // items的每個指標都指向quote
        double total_receipt(std::ostream&) const;
    private:
        // 用來比較shared_ptr的函數
        static bool compare(const std::shared_ptr<Quote> &lhs,
                            const std::shared_ptr<Quote> &rhs) {
            retrun lhs->isbn() < rhs->isbn();
        }
        // 存放多個quotes的multiset，以compare成員排序
        std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
    };
    ```
- 使用multiset來存放交易紀錄，如此可以存放同一本書的多筆交易
- 一本給定的書存在multiset，那同一本書的交易紀錄也會被放在一起
### 定義Basket的成員
- basket的成員:
    - 資料成員
        - 一個multiset用來存放交易紀錄
    - 運算成員
        - add_item用來新增交易紀錄
        - total_receipt印出basket內容的明細
    ```
    double Basket::total_receipt(ostream &os) const {
        double sum = 0.0;  // 運行總和
        // iter指向具有相同ISBN的一批元素中的第一個元素
        // upper_bound回傳一個迭代器指向剛超過那批元素結尾的地方
        for (auto iter = items.cbegin();
                  iter != items.cend();
                  iter = items.upper_bound(*iter)) {
            sum += print_total(os, **iter, items.count(*iter));          
        }
        os << "Total Sale: " << sum << endl;
        return sum;
    }
    ```
- 在for中呼叫upper_bound來跳過匹配目前建值的所有元素
### 隱藏指標
- 重新定義additem直接接受一個Quote物件
    ```
    void add_item(const Quote &sale);
    void add_item(Quote &&sale);
    ```
- 問題: 使用make shared需要指出型別，完全只傳Quote會使得折價商品被(sliced down)
### 模擬虛擬拷貝
- 賦予虛擬成員配置自身的一個拷貝
    ```
    class Quote {
    public:
        virtual Quote* clone() const & { return new Quote(*this);}
        virtual Quote* clone() && { return new Quote(std::move(*this)); }
    };
    class Bulk_quote : public Quote {
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {
        return new Bulk_quote(std::move(*this));
    }
    };
    ```
- 一個給rvalue clone，一個給lvalue clone
- 自己new完再綁給shared_ptr
    ```
    class Basket {
    public:
        void add_item(const Quote &sale) {
            items.insert(std::shared_ptr<Quote>(sale.clone()));
        }
        void add_item(Quote&& sale) {
            item.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
        }
    };
    ```

# 15.9 重訪文字查詢
- 應該支援的查詢:
    - 查詢匹配一個給定string的文字行
    - NOT查詢，使用~運算子來產出不匹配查詢的文字行
    - OR查詢，使用|運算子來回傳匹配兩個查詢任一個的文字行
    - AND查詢，使用&運算子回傳兩個查詢都匹配的文字行
- 測試程序:
    ```
    std::ifstream file("data/test.txt");
    TextQuery tQuery(file);
    Query q = Query("Daddy") & Query("Bird") | Query("wind");
    std::cout << q.eval(tQuery);
    ```
- 輸出會印出查詢，使用括弧來指出該查詢被解讀的方式。
## 15.9.1 一個物件導向的解法
- 不該直接使用TextQuery衍生出程式，字詞查詢會找尋特定的一個字詞。為了讓一個NOT查詢是字詞查詢的一種，我們必須能夠識別出NOT查詢要搜尋的字詞
- 我們的每種Query都Has a TextQuery、而不是Is a TextQuery
- NOT查詢會有一個它要將其值反轉的查詢
- AND查詢和OR查詢會有他們要將其結果結合的兩個查詢
- 讓不同種類的查詢是具有一個共通基礎類別的幾個獨立類別
    ```
    WordQuery
    NotQuery
    OrQuery
    AndQuery
    ```
- 這些類別有兩個運算:
    - eval，接受一個TextQuery物件(文檔)，回傳一個QueryResult。eval函式會使用給定的TextQuery物件來找出該查詢匹配的文字行
    - rep，回傳底層查詢的string表示值。這個函式會為eval所用來創建一個QueryResult以表示匹配，並被輸出運算子用來印出查詢運算式
### 抽象基礎類別
- 我們的四個查詢彼此沒有繼承關係，這暗示我們需要定義一個抽象基礎類別，命名為Query_base
- Query_base把eval和rep定義為pure virtual
- andQuery與orQuery共有一個特性: 每個都有兩個運算元，因此我們會定義另一個抽象基礎類別，BinaryQuery
- 關鍵概念: 繼承vs合成
    - 當我們繼承，這個衍生類別應該反映出(Is A)的關係
    - 另一種常見關係是Has A。以Has A關係產生關連的型別之間意味著成員身分的存在
### 將一個階層架構隱藏在一個介面類別中
- 使用者層級的程式碼不會直接使用繼承的類別
- 而是希望:
    ```
    Query q = Query("fiery") & Query("bird") | Query("wind");
    ```
- 因此我們會定義一個名為Query的介面類別
- 這個類別儲存對Query_base的一個指標，這個指標繫結到衍生自Query_base型別的一個物件。
- Query類別提供跟Query_base類別相同的運算: 有eval用來估算關聯的查詢，以及rep用來產生string版本的查詢，同時定義重載的輸出運算子來顯示關聯的查詢
- 接受一個string的Query建構器會產生一個新的WordQuery。
### 理解這些類別的運作方式
- 概括查詢程式的設計:
- 查詢程式的介面類別和運算
    - TextQuery
    - QueryResult
    - Query
    - Query q(s)
    - q1 & q2
    - q1 | q2
    - ~q
- 查詢程式的實作類別
    - Query_base
    - WordQuery
    - NotQuery
    - BinaryQuery
    - OrQuery
    - AndQuery
## 15.9.2 Query_base與Query類別
### Query類別
- Query_base
    - 抽象基礎類別: eval與rep都是pure virtual
    - Query會指到它，然後呼叫eval與rep，所以Query要是friend
    - 解構器是protected
- Query
    - 對Query_base繼承階層架構的介面(並將之隱藏)
    - 每個Query物件都會存放一個shared_ptr指向對應的Query_base物件
    - Query要定義自己版本的eval和rep(它不在繼承架構裡，它的rep和eval用來呼叫Query_base的rep和eval)
    - 建構器: 接受string，創建wordquery，然後把shared_ptr繫結到它
    - &、|、~運算子分別創建AndQuery、OrQuery、NotQuery物件，這些運算子回傳一個Query物件繫結到這個新產生的物件
    ```
    Query("a");  // 產生一個WordQuery
    Query("a") & Query("b") // &運算子input兩個query，output一個query，指向一個AndQuery，然後那個AndQuery自己裡面會指向本來input的兩個Query
    ```
    - 為了這個運算，Query要有一個接受Query_base的建構器，然後建構出一個新的Query
        - 這個建構器會是private的(不給使用者用)
    - 一個接受string的建構器，裡面會產生一個WordQuery，在把指標綁到shared_ptr
    - Query的eval和rep使用virtual的Query_base運算
### Query輸出運算子
- 輸出運算子呼叫rep
## 15.9.3 衍生的類別
- 衍生自Query_base的類別最有趣的地方在於他們是如何被表示的
- WordQuery類別最直接明瞭，它的功用就是存放搜尋字詞
- NotQuery有單一個運算元
- AndQuery與OrQuery有兩個運算元
- 然而，我們不儲存Query_base指標，我們的類別會使用Query物件，像使用者程式碼因為介面類別的使用而簡化，我們使用相同類別簡化我們自己的類別
### WordQuery類別
- 一個WordQuery會搜尋一個給定的string。
- 它是會實際在給定的TextQuery物件上進行查詢的唯一運算
- Query會使用WordQuery建構器，因此要把Query設為friend
- WordQuery建構器: 接受一個string
- string資料成員: 搜尋的string
- virtual rep : 回傳搜尋的那個string
- virtual eval: 接受一個textQuery，回傳一個QueryResult(就和一般的QueryResult用法一樣)
- 所有成員都是private
### NotQuery類別與~運算子
- friend Query operator~(const Query &)
    - 因為~Query要生成一個NotQuery所以要是friend
- 建構器:
    - 接受一個query
- rep(): 
    - 呼叫底層的query然後加上~
- 資料成員:
    - 一個指向Query_base的shared_ptr
- 注意: 如果在Query裡面include了NotQuery會有先告順序的錯誤問題
### BinaryQuery類別
- Note: BinaryQuery類別沒有定義eval函式，所以繼承了一個pure virtual。因此BinaryQuery也是一個抽象基礎類別，我們無法創建BinaryQuery型別的物件
- 資料成員:
    - lhs、rhs
    - opsym (string)
- rep: 呼叫底層的rep
### AndQuery與OrQuery類別和關聯的運算子
- 兩個都繼承自BinaryQuery
- 建構器:
    - 要用兩個Query建構
- 之後可以定義Query的&和|

## 15.9.4 eval函式
- OrQuery的eval回傳其兩個運算元結果的聯集
- AndQuery則回傳交集
- NotQuery回傳補集
- 假設QueryResult具有能讓我們迭代過QueryResult所存放的行號集合的begin和end成員
- 假設QueryResult有一個名為get_file的成員，會回傳一個shared_ptr指向我們在其上執行查詢的底層檔案
### OrQuery::eval
- 對eval的呼叫:
    - 使用者是呼叫Query的eval(是指著`shared_ptr<Query_base>`的指針
        - Query_base的rep是virtual，會呼叫對應的And/or/not/word
    - 每個呼叫都會產出一個QueryResult，我們要將這些QueryResult集合成新的set
- OrQuery:
- 目標是回傳一個有聯集的Query Result
- 使用接受迭代器初始化的set建構器(給它lhs的set)
- 把set insert rhs的begin和end
- Query的string被換成的rep的string
### AndQuery::eval
- 類似OrQuery
- 交集由set_intersection實作
- 把插入迭代器當成目的地
### NotQuery::eval
- 實作not