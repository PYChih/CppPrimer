# ch12_Dynamic_memory
###### tags: `C++Primer`
[TOC]
- static、stack and heap
    - static
        - 任何函式外定義的變數
    - stack: 
        - 定義在函式內的非static物件
    - heap
        - 動態配置的物件
# 12.1 動態記憶體與智慧指標
- new和delete
    - new: 動態記憶體配置並選擇性的初始化一個物件
        - 回傳指標
    - delete: 摧毀物件，並釋放記憶體
        - 接受對一個物件的動態指標
- 智慧指標會自動刪除它所指的物件，讓動態記憶體的使用變得更容易
- memory標頭定義了兩個智慧指標型別和一個類別
    - shared_ptr
        - 允許多個指標指向相同的物件
    - unique_ptr
        - 擁有他所指的物件
    - weak_ptr
        - 弱參考，指向由一個shared_ptr管理的一個物件
## 12.1.1 shared_ptr類別
- shared_ptr是模板，所以要多給型別`shared_ptr<string> p;`
- 預設初始化的智慧指標持有null指標
- 用在判斷式等於測試是否為null
    ```
    if (p && p->empty())
    ```
### make_shared函式
- 用make_shared創建智慧指標
    ```
    // p是一個智慧指標指向一個動態配置的vector<string>
    // p的型別是shared_ptr<vector<string>>
    auto p = make_shared<vector<string>>(); 
    // p3是一個智慧指標指向一個整數有值42
    shared_ptr<int> p3 = make_shared<int>(42);
    ```
- make_shared定義於memory標頭
- 以使用模板類別的方式呼叫(就是加角括號指定型別)
### 拷貝和指定shared_ptr
- 可以想像成一個shared_ptr背後有一個計數器，當我們拷貝就遞增，摧毀就遞減(例如超出範疇就會被摧毀)
- 當計數器降為0，shared_ptr就會自動釋放它所管理的物件
    ```
    auto r = make_shared<int> (42); // r是一個智慧指標，指向有值42的int，現在計數是1
    r = q; // r跑去指q，現在42沒人指了，計數器遞減，然後本來配置給42的記憶體就釋放了
    //同時q的計數器會遞增
    ```
### shared_ptr會自動摧毀它們的物件
- 每個類別都有一個解構器(和建構器一樣)
- 當指向一個物件的最後一個shared_ptr被摧毀，shared_ptr就會自動摧毀shared_ptr所指的那個物件(透過解構器)
### 並自動釋放關聯的記憶體
- 例子:
    - 一個動態配置Foo型別的函數，回傳shared_ptr
    - 一個函數操作Foo配置的物件
        - 在函數裡呼叫動態配置的函數
        - 經歷: 回傳時創建+1，拷貝給回傳等到左手邊+1，函數結束摧毀-1，離開呼叫的函數-1，所以就被摧毀了
### 其資源具有動態生命週期的類別
- 想使用動態記憶體的情況:
    - 不知道需要多少物件(就像vector)
    - 不清楚確切型別(15章涵蓋)
    - 想在數個物件共用資料
### 定義StrBlob
- 範例: 定義一個類別，使用動態記憶體來讓數個物件共用相同的底層資料
- 私有成員: 一個叫data的shared_ptr指向動態配置的`vector<string>`
- 公開成員函式:
    - empty()、push_back()、size()，都是去呼叫vector的對應成員函數
### StrBlob建構器
- 定義預設建構器: 配置空的vector string
### 元素存取成員
- `pop_back`、`front`、`back`必須在存取元素前檢查元素是否存在
- 因此在private定義了check的成員函式
- check的引數除了size_type還有一個string叫msg用來描述出了啥錯
### 拷貝指定和摧毀StrBlob
- StrBlob的資料成員是一個share_ptr，然後那個share_ptr指向一個`vector<string>`
- 所以StrBlob配置的vector就會在指向那個vector的最後一個StrBlob被摧毀的時候被摧毀

## 12.1.2 直接管理記憶體
- new、delete用來動態配置、釋放記憶體
- 使用new、delete的類別無法仰賴預設定義的拷貝、指定、摧毀
### 使用new來動態配置和初始化物件
- new回傳一個指標指向他所配置的物件
    ```
    // 幾個new的使用範例
    int *pi = new int; //預設初始化
    string *ps = new string;//預設初始化
    int *pi = new int;//預設初始化
    int *pi = new int(1024); //這個是直接初始化
    string *ps = new string(10, '9');//使用建構器
    vector<int> *pv = new vector<int>{0, 1, 2, 3}; //串列初始化
    string *ps1 = new string; //預設初始化
    string *ps = new string(); //值初始化
    int *pil = new int; //預設初始化
    int *pi2 = new int(); //值初始化
    ```

- 要記得內建類別預設初始化會有未定義的值
### 動態配置的const物件
- 使用new來配置const物件
    ```
    const int *pci = new const int(1024);
    const string *pcs = new const string;
    ```
### 記憶體耗盡
- 如果new沒辦法配置記憶體，會擲出`bad_alloc`例外
- `int *p2 = new (nothrow) int; //配置失敗回傳null指標`
- 這個形式的new稱為placement new: 可以傳入額外的引數給new
- nothrow是一個程式庫定義的物件
- bad_alloc和nothrow都定義在new標頭
### 釋放動態記憶體
- delete用來釋放記憶體

### 指標值和delete
- delete用法:
    ```
    delete p; //p指向一個動態物件或null
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33); //直接初始化
    double *pd2 = pd;
    delete i; //error, not ptr
    delete pi1; //undefine pi1 not dynamic
    delete pd; //ok
    delete pd2;// undefine already delete
    delete pi2; // ok. delete null 
    const int *pci = new const int(1024);
    delete pci; //ok 
    ```
- 編譯器無法分辨指標指向動態或靜態物件(危險)
- 編譯器無法知道指標指向的位置是否已被釋放(危險)
- const無法修改，但是可以摧毀
### 動態配置的物件會持續存在直到它們被釋放為止
- 三種常見的問題
    - 忘記delete(memoryu leak)
    - 在物件刪除後使用它(未定義)
    - 重複刪除相同的記憶體(未定義)
### 在delete後重置一個指標的值
- delete一個指標後，該指標變得無效，但指標將持續持有(被釋放的)動態記憶體的位置，這就是懸置指標。
- 如果要保留該指標就指定nullptr給那個指標
### ...只能提供有限的防護
- 可能本來有兩個傢伙指向一個動態記憶體，delete之後，記得把a改成指向nullptr，但b就仍然是懸置指標
    ```
    int *p(new int(42);
    auto q = p;
    delete p;
    p = nullptr;
    ```
- 要找出指向相同記憶體的指標是出乎意料困難的事

## 12.1.3 併用shared_ptr與new
- 可以使用new回傳的一個指標來初始化一個智慧指標
    ```
    shared_ptr<int> p2(new int(42));
    ```
- 接受指標的智慧指標是explicit的
    - 因此無法隱含的將內建指標轉為智慧指標
    ```
    shared_ptr<int> p1 = new int(1024);//錯誤，沒辦法把指標直接轉成智慧指標
    shared_ptr<int> p2(new int(1024));
    // ok: 直接初始化
    ```
- 基於相同理由，一個回傳型別是智慧指標的函式沒辦法回傳指標
    ```
    shared_ptr<int> clone(int p) {
        return new int(p); //錯誤，隱含轉換了指標
    }
    ```
    ```
    shared_ptr<int> clone(int p){
        return shared_ptr<int>(new int(p)); // ok: 直接初始化並回傳
    }
    ```
- 可以把智慧指標繫結置其他種資源的指標，要這樣做要提供自己的運算來取代delete。($12.1.4)
### 別混合使用普通的指標和智慧指標
- 使用一個內建指標來存取某個智慧指標所擁有的物件，是很危險的事情，因為我們並不知道那個物件何時被摧毀
- 建議使用make_shared創建智慧指標
    - 思考一個例子: 有個函數的參數是一個shared_ptr，我們由內建指標創建物件，暫存的傳入給該函數，則該物件在離開函數時將會被釋放而造成錯誤
### ...而且別使用get來初始化或指定另一個智慧指標
- 智慧指標有一個get成員函式，回傳一個內建指標指向智慧指標所管理的物件，而使用get的程式碼必定不能delete那個指標
- 只將get回傳的指標傳給你知道不會delete那個指標的程式碼
- 永遠都不要使用get來初始化或指定給另一個智慧指標
    - 兩個獨立的shared_ptr指向相同的記憶體，結果是未定義
### 其他的shared_ptr運算
- `reset`: 指定新的值給shared_ptr
    ```
    shared_ptr<int> p; // p是一個shared_ptr，預設初始化為未定義的int
    p = new int(1024); // 錯誤，無法把普通指標指定給智慧指標
    p.reset(new int(1024)); // p指向一個新的物件
    ```
- `unique`: 如果計數是1則回傳true
    ```
    if (!p.unique())
        p.reset(new string(*p)); //如果不是unique，代表這塊有其他人用，所以把這個智慧指標拿去指一個新的東西
    *p += newVal; // 變成唯一指標了，改值不會有問題
    ```
## 12.1.3 併用shared_ptr與new
## 12.1.4 智慧指標和例外
- 比較smart_ptr和new
    - 假設在函式內定義了smart_ptr，接著例外發生，退出函式，smart_ptr會自動釋放記憶體
    - 假設在函式內定義了一對new和delete，接著例外發生，退出函式，那記憶體就不會被釋放
### 智慧指標和愚類別(Dumb Classes)

### 使用我們自己的刪除程式碼
- 智慧指標的常見陷阱:
    - 別用相同的內建指標來初始化(或reset)一個以上的指標。
    - 別delete回傳自get()的指標
    - 別使用get()來初始化或reset另一個智慧指標
    - 如果你使用get()所回傳的一個指標，要記得那個指標會在對應的最後一個智慧指標消失後就變得無效
    - 如果你使用一個智慧指標來管理new所配置的記憶體以外的資源，記得傳入一個刪除器

## 12.1.5 unique_ptr
- 一次只有一個`unique_ptr`可以指向一個給定的物件
    - unique_ptr被摧毀時會摧毀所指向的物件
- 定義unique_ptr時，通常會把它繫結到new所回傳的一個指標
    ```
    unique_ptr<double> p1; // 可以指向double的一個unique_ptr
    unique_ptr<int> p2(new int(42)); // p2指向值為42的int
    ```
- 因為一個unique_ptr擁有所指的物件，它不支援一般的拷貝或指定
    - 可以將所有權從一個unique_ptr轉移給另一個unique_ptr
    ```
    unique_ptr<string> p2(p1.release()); // 放棄p1持有的指標的控制權，回傳p1的指標，並且讓p1變成null，然後現在p2有那個指標的所有權
    unique_ptr<string> p3(new string("Trex")); // p3是一個unique指標，有一個string的所有權
    p2.reset(p3.release());//跟第一行一樣，p3放棄所有權，回傳p3的指標，reset會讓p2指向裡面的物件，然後p2放棄本來指的物件
    ```
- release()通常用來轉移所有權
```
p2.release(); //錯的，p2不會釋放記憶體，而且我們會失去p2本來指的指標
auto p = p2.release(); ok
```
### 傳遞和回傳unique_ptr
- 在unique_ptr要被刪除的時候可以有一種特殊的拷貝: ex 從函式回傳
```
unique_ptr<int> clone(int p) {
    return unique_ptr<int>(new int(p));
}
```
### 傳入刪除器給unique_ptr
- 複寫unique_ptr的刪除器會影響unique_ptr的型別，所以要在角括號提供刪除器型別
- 改寫連線程式的具體例子:
```
void f(destination &d /*other param*./)
{
    connection c = connect(&d); //open connection
    unique_ptr<connection, decltype(end_connection)*>
    p(&c, end_connection);
}
```

## 12.1.6 weak_ptr
- weak_ptr所指的物件由某個shared_ptr所管理
    - weak_ptr不會改變shared_ptr的參考計數
- 創建weak_ptr: 由shared_ptr初始化它
    ```
    auto p = make_shared<int> (42); //有一個指向int42的shared_ptr p
    weak_ptr<int> wp(p);
    // weak_ptr wp 指向 shared_ptr所指的物件，但不會增加shared_ptr的計數
    ```
- 物件有可能不存在，所以無法使用weak_ptr來直接存取物件，取而代之，使用lock
```
if (shared_ptr<int> np = wp.lock()){
    // 如果np不是null就會進來
    // 如果p存在wp.lock()會回傳一個shared_ptr，指向p所指的那個物件
    //所以這裡可以安全地使用np
}
```
### 經過檢查的指標類別
- 定義StrBlob的伴隨指標類別StrBlobPtr
- 用處: 儲存一個weak_ptr指向它從之初始化的StrBlob的資料成員: data(data是一個shared_ptr指向一個vector`<string>`)
- 藉由使用weak_ptr可以防止使用者試著存取不存在的vector
- StrBlobPtr
    - 資料成員:
        - wptr: null或指向一個StrBlob中的一個vector
        - curr: 這個物件目前代表的元素的索引
```
class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) { } // 預設建構器
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }//傳入StrBlob和sz的建構器，那weak_ptr就會指去StrBlob的vector，跟shared_ptr共享物件
    string& deref() const; //成員函式deref
    StrBlobPtr& incr(); //前綴版本
private:
    //檢查成功的情況下check回傳shared_ptr
    shared_ptr<vector<string>>
        check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
```
- 預設建構器產生null的StrBlobPtr。
- StrBlobPtr無法繫結至const StrBlob(因為建構器)
- 定義check
```
shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); //這個vector 存在嗎
    if (!ret)
        // ret是null才會進來
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    //因為ret是wptr.lock，所以假設存在，那ret是一個shared_ptr指向StrBlob的那個vector<string>，取size所以得知，如果那個vector的size小於0也會爆error
    return ret;
    // 都沒事(size夠大、而且還存在，就給你用)
}
```
### 指標運算
- deref與incr函式
    - deref
    ```
    string& StrBlobPtr::deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; //這個回傳的是給了vector[index]的那個string
    }
    ```
    - incr
    ```
    StrBlobPtr& StrBlobPtr::incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr; 
        return *this;
    }
    ```
- incr會推進curr，而且會檢查是不是有超過end
- 替StrBlob加上begin和end:
    - 回傳StrBlobPtr指向StrBlob中的第一個元素或超出最後一個元素一個位置處
```
StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}//這邊用了以StrBlobPtr初始化的那個建構器，預設sz是0
StrBlobPtr StrBlob::end() 
{ return StrBlobPtr(*this, data->size());}
```

# 12.2 動態陣列
## 12.2.1 new與陣列
- 用new宣告一個陣列
```
int *pia = new int[42];
typedef int arrT[42];
int *p = new arrT;
```
### 配置一個陣列會產出對元素型別的一個指標
- 動態陣列不具備陣列型別，所以沒辦法用範圍for，也不能用beg和end(就是你去配置一個動態陣列，他回傳的還是對那個陣列元素的指標)
### 初始化由動態配置的物件所組成的一個陣列
- 預設初始化、值初始化、串列初始化
```
int *pia = new int[10];
int *pia2 = new int[10]();
string *psa = new string[10];
string *psa2 = new string[10]();
int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
```
- 剩餘的元素會是值初始化
### 動態配置一個空陣列是合法的
- `new int[0]`這個只要不要去解參考他就會合法
- 他會像一個off-the-end一樣
### 釋放動態陣列
- 要加`[]`
```
typedef int arrT[42];
int *p = new arrT;
delete [] p;
```
### 智慧指標和動態陣列
- uinque_ptr為動態陣列定義了對應的操作
    - 好處是他刪的時候預設就是delete[]
    - 還有可以直接用下標操作
```
// 使用unique操作動態陣列
unique_ptr<int[]> up(new int[10]);  // 型別是int[]，up是一個智慧指標，指向一個型別是int大小是10的陣列
for (size_t i = 0; i != 10; ++i) {
  up[i] = i;  // 可以直接用下標操作
}
```
- shared_ptr沒有提供支援
    - 所以硬要用的話要傳自己寫的`delete[]`
    `shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });`
    - 沒給就是未定義喔，因為等於用delete來刪陣列
    - 然後不給下標操作，所以要自己+位置然後解參考然後改值 
## 12.2.2 allocator類別
- new結合了配置和建構
- delete結合了解構和釋放
- 這有時候會浪費空間
    - 可能會建構從未使用的物件
    - 可能建構了之後又立馬指定新值
```
string *const p = new string[n];
string s;
string *q = p;
while (cin >> s && q != p+n)
    *q++ = s;
const size_t size = q-p;
// use this array
delete[] p;
```
### allocator類別
```
allocator<string> alloc;  // 能夠配置string的物件
auto const p = alloc.allocate(n);  // 配置n個未建構的string
```
### allocator配置未經建構的記憶體
- allocator配置的是未經建構的
- allocate回傳的是指標喔
```
allocator<string> alloc;
auto const p = alloc.allocate(n);
auto q = p;// q指向超過最後一個建構的元素一個位子
alloc.construct(q++); // *q是空string
alloc.construct(q++, 10, 'c'); // *q是cccccccccc
alloc.construct(q++, "hi"); //*q是hi
```
- 使用未經建構的記憶體是未定義的行為
- `destroy`
```
// 剛剛的construct是q++喔，所以q現在指在沒建構的地方
while(q != p)
    alloc.destroy(--q); //解構回去
```
- 只能destory已經建構的元素
- destroy完就可以deallocate，傳到deallocate的參數要跟當初allocate的參數一樣
### 拷貝與填入未初始化的記憶體之演算法
- 在目的地建構元素，而非指定給他們:
```
uninitialized_copy(b, e, b2) // 從be範圍copy到b2
uninitialized_copy_n(b, n, b2) // 從b copy n個到b2
uninitialized_fill(b, e, t) // 在be範圍建構t
uninitialized_fill_n(b, n t) // 從b建構n個t
```
- [ ] 範例程式
    - 有int構成的vector想拷貝到動態記憶體中，配置有vector中兩倍數目多的記憶體，後半部以給定值填入

# 12.3 使用程式庫: 一個文字查詢程式
- 範例程式: 為使用程式庫做個總結
    - 文字查詢程式(text-query program)
    - 以可能出現的字詞搜尋一個給定的檔案
    - 查詢的結果是該字詞出現的次數，以及一串行號，列出該字詞在哪出現
        - 一個字詞在一行出現多次，只會顯示一次行號
        - 行號遞增
## 12.3.1 此查詢程式之設計
- 開始設計一個程式的好方法是列出程式所需的運算
- 需求:
    - 因為需要記得每個字出現在哪行，所以需要一次讀取一行輸入、並將那些文字拆分成各別字詞
    - 擷取一個給定的字詞關聯的行號
    - 行號遞增而且不能重複
    - 印出輸入檔案出現在給定行號上的文字
- 滿足需求的程式庫機能
    - 使用`vector<string>`儲存整個輸入檔案的拷貝，想要印出某行時使用行號作為索引
    - 使用istringstream將每行拆成字詞
    - 用set存放每個字詞在輸入中出現的行號
    - 用map結果給定字詞的set
### 資料結構
- TextQuery類別
    - 成員:
        - vector : 存放文字
        - map: 把字詞關連到出現的行號所成的set
    - 運算:
        - 在map中查看給定字詞是否出現
            - 決定應該回傳什麼: 回傳另一個類別
    - 建構器:
- QueryResult類別
    - 成員:
    - 運算:
        - print: 印出QueryResult的結果
### 在類別間共用資料
- QueryResult所需的資料儲存在TextQuery物件中，我們不想拷貝
- 解法1: 回傳指向TextQuery物件的迭代器，可是有可能在呼叫QueryResult之前結果就已經被摧毀
- 解法2: 用shared_ptr反映資料結構的共享
### 使用TextQuery類別
- 設計類別時，先寫程式使用該類別可能會有幫助
## 12.3.2 定義查詢程式類別
- 基本的類別宣告
### TextQuery建構器
### QueryResult類別
### query函式
### 印出結果


## 查詢類別筆記
- [ ] 因為回傳型別是自訂類別，所以先宣告QueryResult
- 使用using讓類別更好懂
- [ ] ifstream讀取檔案
- [ ] 建構器初始器串列7.1.4
- [ ] shared_ptr
    - [ ] reset
- [ ] map的下標操作回傳啥
    - [ ] map的find
- [ ] set
    - [ ] insert
- [ ] 類別內的typedef
- [ ] 區域性的static物件
- [ ] 拿shared_ptr是直接解參考嗎
- [ ] 先解參考再拿成員就是`->`
- [ ] 成員函式裡創建一個static物件-.-
