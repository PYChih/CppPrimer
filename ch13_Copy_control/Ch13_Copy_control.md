# Ch13_Copy_control
###### tags: `C++Primer`
[TOC]
- 拷貝、移動、指定、摧毀由五個特殊的成員函式控制
    - 拷貝建構器
    - 拷貝指定運算子
    - 移動建構器
    - 移動指定運算子
    - 解構器

# 13.1 拷貝、指定與摧毀
- 拷貝建構器、拷貝指定運算子、解構器
## 13.1.1 拷貝建構器
- 拷貝建構器滿足
    - 1. 第一個參數是對類別型別的一個參考(而且幾乎都是const參考)
    - 2. 額外參數都有預設值
    ```
    class Foo {
     public:
         Foo(); // 預設建構器
         Foo(const Foo&); //拷貝建構器
    }
    ```
    
### 合成的拷貝建構器
- 直接定義一個建構器參數是對自己的const參考，並且把每個成員都用該參考初始化，就是合成的拷貝建構器做的事。
### 拷貝初始化
- 直接初始化和拷貝初始化的差異:
    ```
    string dots(10, '.'); //直接初始化
    string s(dots); //直接初始化
    string s2 = dots; //拷貝初始化
    string null_book = "9-999-99999-9"; // 拷貝初始化
    string nines = string(100, '9'); //拷貝初始化
    ```
    - 直接初始化: 就是讓建構器去匹配引數
    - 拷貝初始化: 要求編譯器把右手邊的運算元拷貝到正在建立的物件中
- 例子:
    - 程式庫容器會在初始化容器時拷貝初始化
    - 相較之下emplace所創建的元素是直接初始化的
- 拷貝初始化發生時間:
    - 使用===定義變數==時
    - 傳遞一個物件作為非參考型別的參數時
    - 非參考回傳型別的函式回傳物件時
    - 以大括號初始化元素時

### 參數和回傳值
- 為什麼拷貝建構器自己的參數必須是參考:
    - 因為函數呼叫的時候，如果不是參考型別，就會呼叫拷貝建構器，所以拷貝建構器自己要是參考
### 拷貝初始化的限制
### 編譯器可以繞過拷貝建構器
## 13.1.2 拷貝指定運算子
- 直接把一個類別放到等於的右邊就是拷貝指定運算子
```
Sales_data trans, accum;
trans = accum; //使用Sales_data的拷貝指定運算子
```
- 所以差異(拷貝指定運算子和拷貝建構器)是在指定
### 簡介重載指定
- 重載的運算子是一種函式，名稱有operator後面接著運算子符號(比如說operator=)
- 運算子函式有一個回傳型別和一個參數列
- 參數代表運算元
- 左手邊的運算元會被繫結到隱含的this
- `a=b`，在定義這個類別的時候，
    - 會有一個成員函式operator=
    - b會被當成函式的引數傳進去
    - 在函式裡面改this，之後就會改到a
- 指定運算子一般應該回傳一個參考指向它們的左運算元`Foo& operator=(const Foo&);`

### 合成的拷貝指定運算子
## 13.1.3 解構器
- 解構器也是一個成員函式
```
class Foo {
 public:
  ~Foo(); //解構器
  // ...
}
```
- 不接受參數(所以不能重載)
- 名稱由類別名稱前綴有一個波狀符號
### 解構器做些什麼事?
- 在建構器中，成員會在函式主體執行前被初始化
- 而成員依據它們在類別中出現的順序初始化
- 解構器相反
    - 函式主體先執行
    - 成員依照建構器相反順序摧毀
- 內建指標型別的成員的隱含解構並不會delete該指標所指的物件
### 當一個解構器被呼叫
- 每當物件被摧毀就會使用解構器
    - 變數在離開範疇時摧毀
    - 一個物件的成員會在他們是其一部份的物件被摧毀時摧毀(= =)
    - 容器中的元素在容器被摧毀的時候一起摧毀
    - 動態配置的物件，在delete運算子被套用到指項該物件的一個指標時被摧毀
    - 暫存物件會在該暫存物件在其中被創建的完整運算式結束時被摧毀
- note: 對一個物件的參考或指標超出範疇時，解構器不會執行
### 合成的解構器
## 13.1.4 Three/Five規則
### 需要解構器的類別就需要拷貝和指定
- 在建構器中動態配置記憶體，合成的解構器不會delete是指標的資料成員，因此這個類別需要定義一個解構器來釋放其建構器所配置的記憶體
- 在這樣的前提下，HasPtr也需要一個拷貝建構器和拷貝指定運算子，因為預設的拷貝建構器和拷貝指定運算子會直接拷貝指標成員，導致解構的時候會刪除重複的記憶體

### 需要拷貝的類別就需要指定、反之亦然
- 賦予每個物件自己唯一序號的類別(這個類別需要拷貝和指定，不一定需要解構)
- 這個例子也暗示了，需要拷貝就需要指定，需要指定也需要拷貝
## 13.1.5 Using = default
- 可以明確要求產生合成版本的拷貝控制成員，使用=default
- 只能在預設建構器或拷貝控制成員上使用。default
## 13.1.6 防止拷貝
- 大多數的類別都應該定義預設和拷貝建構器，以及拷貝指定運算子，不管是明確的或是隱含的
- 有的類別必須被定義成會防止拷貝或指定(比如iostream)，這個情況下就必須自己定義拷貝控制成員(因為編譯器會自己合成它)
### 將一個函式定義為已刪除
- 直接加=delete
- 需要出現在第一個宣告上(=default不用)
- ==編譯器的邏輯後果==: 一個預設成員只影響編譯器會產生什麼程式碼，因此=default在編譯器產生程式碼之前都不需要。另一方面，編譯器需要知道一個函式是否為已刪除，才能禁止嘗試使用它的運算
- ==已刪除函式在想要引導函式匹配時可能也有用處==
### 解構器不應該是一個deleted(已刪除)成員
- 沒解構器就不能被刪除
- = =可以動態配置具有已刪除解構器的物件，但是不能釋放他們
### 拷貝控制成員有可能被合成為deleted(已刪除)
- 基本上，拷貝控制成員會在無法拷貝、指定或摧毀該類別的某個成員時，被合成為已刪除
- 例子:
    - 有一個成員有以刪除的解構器，則合成解構器定義為已刪除
    - 成員有已刪除的拷貝建構器，那拷貝建構器定義為已刪除。如果成員有已刪除的解構器，拿拷貝建構器一樣定義成已刪除
    - 成員有已刪除的拷貝指定運算子，或是==有const參考成員==，合成的拷貝指定運算子會被定義為已刪除
    - 成員有已刪除解構器，或有沒有類別內初始器的參考成員，或有const成員沒有明確定義的預設建構器，而且那個成員沒有類別內初始器，那合成的預設建構器會被定義為已刪除
### private拷貝控制

# 13.2 拷貝控制與資源管理
- 有管理不在類別內資源的類別必須定義拷貝控制成員(比如有動態配置記憶體的)
- 一般來說可以決定類別的行為表現的像是值或是指標一樣

## 13.2.1 行為表現跟值一樣的類別
## 類值的拷貝指定運算子
- 指定運算子會結合解構器和拷貝建構器的動作
    - 要解構被指定的傢伙本來的東西
    - 然後拷貝右邊的給本來的傢伙
- ==關鍵概念:指定運算子==
    - 就算一個物件是指定給自身，指定運算子也得正確運作
    - 大多數指定運算子都與解構器和拷貝建構器有共通的作業
- 這麼麻煩的原因是:自我指定，如果沒有一個暫存物件先存的話，如果自我指定會指定一個已經刪除的物件給他
## 13.2.2 定義行為表現跟指標一樣的類別
- 為了有跟指標一樣的行為: 需要拷貝建構器和拷貝指定運算子來拷貝指標成員，而非那個指標所指的string(這個好像預設的就會做了)
- 需要解構器來釋放接受一個string的建構器所配置的記憶體
- 解構器不能單方面釋放它關聯的string，只能在指像那個string的最後一個Hasptr消失之後才能這麼做
### 參考計數
- 每個建構器都對應一個計數器(除了拷貝建構器)，初始化物件也不用
- 拷貝建構器不配置新的計數器，它拷貝所給物件的資料成員，包括計數器，且會遞增這個計數器，代表新加了一個使用者
- 解構器會遞減計數器，如果計數器降為零，解構器就會刪除那個狀態
- 拷貝指定運算子會遞增右手邊運算元的計數器，遞減左手邊運算元的計數器，如果左運算元的計數器降為零，拷貝指定運算子必須摧毀左運算元
- 問題: 計數器要放哪裡
    - 把計數器儲存在動態記憶體中
### 定義一個具備參考計數功能的類別

### 類指標的拷貝成員讓參考計數有點費勁
- 解構器:
    - 先遞減，然後如果遞減到0就delete

# 13.3 Swap
- 如果一個類別定義了它自己的swap，那麼演算法就會使用類別專用的版本，否則，它會使用程式庫所定義的swap函式
```
// 直觀想像的swap
// 一個拷貝，兩個指定
HasPtr temp = v1;
v1 = v2;
v2 = temp;
```
- 我們希望的swap
```
string *temp = v1.ps; // 上一個temp是拷貝物件，這個temp是拷貝指標
v1.ps = v2.ps; // 指定指標
v2.ps = temp; // 指定指標
```
### 撰寫我自己的swap函式
- 定義一個作用在我們類別的swap:
```

class HasPtr {
friend void swap (HasPtr&, HasPtr&);
};
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
```
### swap函式應該呼叫swap，而非std::swap
- 不要用std::swap，用using std::swap
- 這樣swap重載了(類別限定版和程式庫版)，類別限定版會是較佳的匹配(16.3解釋)
- 這邊遺留了一個遮蔽的問題，18.2.3解釋
### 在指定運算子中使用swap
- 有swap的類別會使用swap來定義他們的指定運算子
```
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}
```
- copy and swap技巧

# 13.4 一個Copy-Control範例
- 拷貝控制最常用於需要配置資源的類別
- 但資源管理不是一個類別需要這些成員的唯一原因
- 有些紀錄工作或其他動作，必須要由拷貝控制成員來做
- 概述:
    - Message:
        - 代表電子郵件
    - Folder
        - 可能出現訊息的目錄(directories)
- 每個Message都能出現在多個Folder中
- 任何給定Message的內容都指會有一份拷貝
- 拷貝指定運算子通常會進行跟拷貝建構器和解構器所需的相同的工作，那些共同的作業應該放到private的工具函式中
### Message類別
### save和remove成員
- save: 把message放到給定的folder中
    - save是針對某個message的動作
        - 當我們有一個新的message要save到某個folder
        - message裡面的set要insert
        - folder裡的set也要add
- remove: 把message移除
    - 有一個舊有的message要移除(從某個folder中)
        - 給定一個folder，從message的set erase
        - 到那個folder消除這個message
### Message類別的拷貝控制
- 拷貝msg1得到msg2，那msg2會出現在所有msg1都有出現的folder裡
    - 動作: for msg裡set的folder
        - 把新的msg插入到folder的set裡
### Message解構器
### Message的拷貝指定運算子
### Message的swap函式
        
# 13.5 管理動態記憶體的類別
- 實作一個簡化過的vector類別(固定拿string)
### 類別設計
- 資料成員
    - elements: 指向所配置記憶體的第一個元素
    - first_free: 指向緊接著最後一個實際元素後面
    - cap: 指向剛好超過所配置的記憶體結尾的地方
    - static alloc: 配置StrVec所用的記憶體
- 工具函式
    - alloc_n_copy: 配置空間並拷貝給定範圍的元素
    - free: 摧毀所建構的元素
    - chk_n_alloc: 確保有空間可以再新增一個元素，如果沒有空間就呼叫reallocate
    - reallocate: 在用盡空間時重新配置
### StrVec類別定義
### 使用construct
### alloc_n_copy成員
### free成員
### 拷貝控制成員
### 重新配置時，移動而非拷貝元素
### 移動建構器和std::move
- 移動建構器與move函式
### reallocate成員
# 13.6 移動物件
- note: 程式庫容器、string以及shared_ptr類別除了拷貝外，也支援移動。IO和unique_ptr類別可以移動但不能拷貝。
## 13.6.1 Rvalue參考
- rvalue reference: 必須繫結到rvalue的參考
    - 使用&&
    ```
    int i = 42;
    int &r = i;
    int &&r = i;  // 錯誤，i是lvalue
    int &r2 = i * 42;  // 錯誤，i*42是rvalue
    const int &r3 = i * 42;  // 對const的參考可以繫結到一個rvalue
    int &&rr2 = i * 42;  // ok，把rr2繫結到乘法的結果
    ```
- 無法將rvalue繫結到一個lvalue
- lvalue運算式指涉一個物件的身分(identity)
- rvalue運算式指涉一個物件的值(value)
### Lvalue是永恆的，Rvalue則是一時的
- note: rvalue reference指涉即將被摧毀的物件。因此，我們可以從一個rvalue reference所繫結的物件"偷取"狀態
### 變數是Lvalue
- note: 一個變數是一個lvalue，我們無法直接將一個rvalue reference繫結到一個變數，即使那個變數是定義為一個rvalue reference型別也一樣。
### 程式庫的move函式
- 可以明確地將一個lvalue強制轉型為它對應的rvalue reference
- 定義於utility的std::move
    ```
    int &&rr3 = std::move(rr1);  // ok
    ```
- 對move的呼叫也代表我們承諾，除了對它指定或摧毀它以外，我們不會再次使用rr1。
- note: 我們可以摧毀一個作為移動來源的物件，也可以指定新的值給它，但我們不能使用它的值
## 13.6.2 移動建構器和移動指定
- 如果我們自己的類別可以移動，就會有好處
- 定義移動建構器(move constructor)以及移動指定運算子(move-assignment operator)
- 移動建構器的初始參數是rvalue-reference
- 和拷貝建構器相同，額外的參數都必須有預設引數
- StrVec的移動建構器
    ```
    StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elements = s.first_free = s.cap = nullptr;
    }
    ```
### 移動運算、程式庫容器，以及例外
- 除非程式庫知道我們的移動建構器不會擲出例外，它會進行額外的工作已處理移動我們的類別型別的物件可能擲出的例外
- 使用`noexcept`告知函式不會擲出例外
    - 接在參數列後
    - 接在參數列和`:成員初始器`之間
- 如果定義出現在類別外，我們就必須在類別標頭中的宣告和定義上都指定noexcept。
- note: 不會擲出例外的移動建構器和移動指定運算子都應該被標示為noexcept。
- 程式庫如何與我們寫的型別物件互動
    - 雖然移動運算通常不會擲出例外，它們被允許這個做
    - 程式庫容器能夠保證例外發生時他們會進行一些處理(舉例來說，當呼叫push_back的時候若例外發生，vector本身不會改變)
### 移動指定運算子
- 必須對自我指定做好防護
    ```
    StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            rhs.elements = rhs.first_free = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }
    ```
- note: 使用來自右運算元的那些(可能相同的)資源之前，不要釋放左手邊的資源。
### 作為移動來源的物件在移動後必須可解構
- 一個移動運算後，moved-from物件必須仍然是一個有效的、可解構的物件，但使用者不能對它的值有任何假設
### 合成的移動運算
- 有定義拷貝成員的類別編譯器不會合成移動建構器和移動指定運算子
- 如果沒有移動運算，對應的拷貝運算就會透過函式匹配被用來代替移動運算
- 編譯器只會在類別沒有定義自己的拷貝成員，且該類別的非static資料成員能被移動時，自動合成移動建構器或移動指定運算子
- 編譯器可以移動內建型別，或是類別成員有定義對應的移動運算
    ```
    struct X {
        int i;  // 內建型別可以移動
        std::string s;  // string有定義它自己的移動運算
    };
    struct hasX {
        X mem;  // X有合成的移動運算
    };
    X x, x2 = std::move(x);  // 使用合成的移動建構器
    hasX hx, hx2 = std::move(hx);  // 使用合成的移動建構器
    ```
- note: 編譯器只會在一個類別沒有定義任何自己的拷貝控制成員，而且所有的資料成員都能移動建構或移動指定時，才會合成移動建構器或移動指定運算子。
- 假設Y是定義了自己的拷貝建構器但沒有野定義自己的移動建構器的類別
    ```
    struct hasY {
        hasY() = default;
        hasY(hasY&&) = default;
        y mem;  // hasY會有一個deleted的移動建構器
    };
    hasY hy, hy2 = std::move(hy);  // 錯誤:移動建構器已刪除
    ```
- 類別hasY明確地請求了一個移動建構器，但編譯器無法合成，因此hasY會得到一個delete的移動建構器
- 假設hasY省略了其移動建構器的宣告，那麼編譯器就完全不會合成hasY的移動建構器
- 如果一個類別有定義一個移動建構器或一個移動指定運算子，那麼該類別的合成拷貝建構器和拷貝指定運算子會被定義為deleted。
### Rvalue，Lvalue
- 對const的轉換vs完全匹配的rvalue
### ...但Rvalue會在沒有移動建構器的時候被拷貝
- note: 如果一個類別有一個可用的拷貝建構器，而沒有移動建構器，物件就會由拷貝建構器來"移動"，拷貝指定運算子和移動指定也類似
### Copy-and-Swap指定運算子與移動
- 函式匹配與移動運算:
    ```
    class HasPtr {  // 類值
    public:
        // 新增了移動建構器
        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
        // 指定運算子是移動指定運算子也是拷貝指定運算子
        HasPtr& operator=(HasPtr rhs) {
            swap(*this, rhs);
            return *this;
        }
        // 從string建構的建構器
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        // 拷貝建構器
        HasPtr(const HasPtr &p):
            ps(new std::string(*p.ps)), i(p.i) { }
        // 拷貝指定運算子
        HasPtr& operator=(const HasPtr &);
        // 解構器
        ~HasPtr() { delete ps; }
    private:
        std::string *ps;
        int i;
    };
    ```
- 新定義的指定運算子接受一個以值傳遞的HasPtr，呼叫時rhs會被拷貝或移動取決於物件是rvalue還是lvalue(由對應的拷貝建構器以及移動建構器執行)
    ```
    hp = hp2;  // hp2是一個lvalue，拷貝建構器用來拷貝hp2
    hp = std::move(hp2)  // 移動建構器用來移動hp2
    ```
- 無論使用的是拷貝或移動建構器，指定運算子的主體都會swap兩個運算元的狀態
- 建議: 更新The rule of three
    - 所有的五個拷貝控制成員應該被想成是一個單元，一般來說有一個定義，就應該定義他們全部
### Message類別的移動運算
- move_Folders: 移動建構器和移動指定運算子都需要的運算
    ```
    void Message::move_Folders(Message *m) {
        folders = std::move(m->folders);  // 使用set的移動指定
        for (auto f: folders) {
            f->remMsg(m);  // 從Folder移除舊的message
            f->addMsg(this);  // 新增這個Message到那個Folder
        }
        m->folders.clear();  // 確保摧毀m無害
    }
    ```
- 先把folders移動(每個message都有一個folder指出有哪些資料夾存了自己)
- message的移動建構器:
    - 使用std::move移動內容
    - 呼叫move_Folders來移動資料夾
    ```
    Message::Message(Message &&m): contents(std::move(m.contents)) {
        move_Folders(&m);
    }
    ```
- message的移動指定運算子
    ```
    Message& Message::operator=(Message &&rhs) {
        if (this != &rhs) {
            remove_from_Folders();
            contents = std::move(rhs.contents);  // 移動指定contents
        move_Folders(&rhs);  // 重設Folders以指向這個Message
        }
        return *this;
    }
    ```
### 移動迭代器
- "移動"物件到未經建構的記憶體中
- 移動迭代器轉接器(move iterator adaptor)
    - 一般迭代器的解參考回傳lvalue
    - 移動迭代器回傳rvalue
- make_move_iterator: 接受一個迭代器，回傳一個移動迭代器
- 傳入移動迭代器給uninitialized_copy:
    ```
    void StrVec::reallocate() {
        auto newcapacity = size() ? 2 * size() : 1;
        auto first = alloc.allocate(newcapacity);
        // 移動元素
        auto last = uninitialized_copy(make_move_iterator(begin()),
                                       make_move_iterator(end()),
                                       first);
        free();
        elements = first;
        first_free = last;
        cap = elements + newcapacity;
    }
    ```
- uninitialized_copy會在first的位置呼叫construct來建構，藉由呼叫解參考提供初始值，這時，由於make_move_iterator解參考傳入的是rvalue因此就會變成呼叫移動建構器
- 標準程式庫沒有保證那些演算法能與移動迭代器並用
- 你應該只把移動迭代器傳入你確信不會在對一個元素進行指定或將該元素傳給一個使用者定義的函式後存取那個元素的演算法
- 在類別實作程式碼之外，只有你確定你得進行移動而這個移動保證是安全的時候使用std::move
## 13.6.3 Rvalue參考和成員函式
- 同時提供拷貝和移動版本，也能為額外的成員函式帶來好處
- 一個版本接受對const的一個lvalue reference，而第二個版本接受對非const的一個rvalue reference。
- 有定義push_back的程式庫容器提供兩種版本: 一個有rvalue reference參數，另一個有const的lvalue reference。
    ```
    void push_back(const X&);
    void push_back(X&&);
    ```
- 一般來說沒必要為運算定義出會接受一個const X&&或一個(普通的)X&的版本。我們想要移動物件的時候，物件不能是const，同時，拷貝一個物件不應該改變被拷貝的物件，因此通常不會需要定義接受一個普通的X&參數的版本
- note: 區分移動或拷貝一個參數的重載函式通常會有一個接受const T&的版本，以及一個接受T&&的版本。
- 一個範例: 替StrVec製作兩種版本的push_back
    ```
    class StrVec {
     public:
      StrVec():
          elements(nullptr), first_free(nullptr), cap(nullptr) { }
      StrVec(const StrVec&);
      StrVec &operator=(const StrVec&);
      ~StrVec();
      void push_back(const std::string&);
      size_t size() const { return first_free - elements; }
      size_t capacity() const { return cap - elements; }
      std::string *begin() const { return elements; }
      std::string *end() const { return first_free; }
      void push_back(const std::string&);  // 拷貝元素
      void push_back(std::string&&);  // 移動元素
     private:
      static std::allocator<std::string> alloc;
      void chk_n_alloc()  // 新增元素用
          { if (size() == capacity()) reallocate(); }
      std::pair<std::string*, std::string*> alloc_n_copy
          (const std::string*, const std::string*);
      void free();  // 摧毀元素並釋放空間
      void reallocate();  // 取得更多空間並拷貝現有元素
      std::string *elements;
      std::string *first_free;
      std::string *cap;
    };
    // alloc定義於StrVec的實作檔案
    allocator<string> StrVec::alloc;
    ```
- 實作
    ```
    void StrVec::push_back(const string& s) {
        chk_n_alloc();
        alloc.construct(first_free++, s);
    }
    void StrVec::push_back(string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
    }
    ```
### Rvalue和Lvalue參考成員函式
- 有的時候我們想要強迫左運算元是lvalue
    - 為了避免像`s1+s2 = "wow!"  // rvalue被指定`
- 表明this的lvalue/rvalue特性與定義const時相同
    ```
    class Foo {
    public:
        Foo &operator=(const Foo&) &;  // 只能指定給可修改的lvalues
    };
    Foo &Foo::operator=(const Foo &rhs) & {
    return *this;
    }
    ```
- 一個參考資格修飾符只能出現在一個(非static的)成員函式上，而且必須在該函式的宣告及定義上都有。
- 只能在一個lvalue上執行由&資格修飾的函式
- 只能在一個rvalue上執行由&&資格修飾的函式
- 參考資格修飾符必須跟在const後面
### 重載和參考函式
- 基於它是否為const來重載以及，依據其參考資格修飾符來重載一個函式
    ```
    class Foo {
    public:
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        vector<int> data;
    };
    Foo Foo::sorted() && {  // 在rvalue排序，就地排序
        sort(data.begin(), data.end());
        return *this;
    }
    Foo Foo::sorted() const & {
        Foo ret(*this);  // 製作一個拷貝
        sort(ret.data.begin(), ret.data.end());  // 排序那個拷貝
        return ret;
    }
    ```
- 必須為全部的成員提供參考資格修飾符，或者全部不提供