# Ch03_Strings_Vectors_and_Arrays
###### tags: `C++Primer`
[TOC]
# 3.1 命名空間的using宣告
- ``std::cin``指使用範疇運算子``::``，代表使用來自命名空間std的名稱cin
- using宣告: ``using namespace::name;``
### 每個名稱都需要一個分別的using宣告
```
using std::cin;
using std::cout;
using std::endl;
```
### 標頭不應該包含using宣告
- 標頭內容會被拷貝到進行引入的程式文字中，因此標頭不應該包含using宣告。
# 3.2 程式庫的string類別
- 引入string標頭以使用string，加入適當的using
## 3.2.1 定義並初始化string
```
string s1;
string s2 = s1;
string s3 = "hiya";
string s4(10, 'c');
string s5("hiya");
```
### 初始化的直接和拷貝形式
## 3.2.2 在string上進行的運算
### 讀取和寫入string
- string會自動忽略所有前導空白
### 讀取未知數目的string
### 使用getline來讀取一整行
- Note: 導致getline回傳的newline會被丟棄，這個newline不會被儲存在string中
### string的empty和size運算
- 用``.``呼叫成員函式
### string::size_type型別
- `string.size()`回傳的是一個`string::size_type`型別，而且幾乎可以確定是無號
- 假設n存有負值，那麼`s.size() < n `幾乎可以確定會估算為true，因為n中的負值會被轉換為大型無號值
- 避免因為unsigned和int之間的轉換而產生的問題，只要不要在用到size()的運算式中使用int就行了
### 比較string
### string的指定
### 相加兩個string
### 相加字面值和string
- 字串字面值並非標準程式庫的string
- 字串字面值不能直接相加
- string可以直接相加
```
string s6 = s1 + ", " + "World";// 合法
string s7 = "hello" + ", " + s3;// 非法
```
## 3.2.3 處理一個string中的字元
- 建議: 使用c++版本的C程式庫標頭
- 在cctype標頭內有一組程式庫函式用來處理string

### 要處理每個字元? 那就用基於範圍的for
- 範圍for很適合用來處理針對某個string中的每個字元
```
string str("somw string")
for (auto c : str)
    cout << c << endl
```
- ==範圍for拿出來是拷貝==(也就是說c是拷貝str中對應的元素，這個例子裡c是char)
### 使用一個範圍for來變更一個string中的字元
- 把範圍for的declaration改成reference
```
string s("Hello World!!!");
for (auto &c : s)
  c = toupper(c);
cout << s << endl;
```
### 只處理某些字元?
- 使用下標(注意:下標是拿參考)
- Note: 對空的string使用下標運算，結果是未定義
- 索引的型別是(會被轉換為)`string::size_type`
- 使用迭代器
### 將下標用於迭代
### 將下標用於隨機存取
- 下標是未經檢查的: 所以使用下標一定要明確在程式裡確保小於size()，並且不會小於零(小於零可以用(string::size_type避免)
# 3.3 程式庫的vector類別
- `C++`具有類別模板以及函式模板
- note: vector是一個模板，不是一個型別。從vector產生的型別必須包含元素型別
- 可以定義vector來存放幾乎所有型別的物件，特別是，可以有其元素本身就是vector的vector
## 3.3.1 定義並初始化vector
- 拷貝一個vector必須有相同型別
### vector的串列初始化
- 拷貝初始化形式(給等於另一個vector)
- 提供類別內初始器(使用拷貝初始化或使用大括號)
- 只能在使用串列初始化的時候提供一串元素值
- [ ] 就是不能用小括號給一串string來初始化`vector<string>`
    ```
    vector<string> v1{"a", "an", "the"};  // 串列初始化
    vector<string> v2("a", "an", "the");  // 錯誤
    ```
### 創建特定數目的元素
- 使用計數,元素值創建`vector<int> ivec(10, -1);`
### 值初始化
- 省略值，只提供vector大小: `vector<int> ivec(10);`
    - 限制1: 有的類別就一定要初始化(無法預設初始化的類別就不能這樣造)
    - 限制2: 要使用直接形式的初始化
    ```
    vector<int> ivec(10);  // 十個int，每個都被預設初始化
    vector<int> v1 = 10;  // 錯誤:必須使用直接初始化來提供大小
    ```
- 省略值只提供大小的時候會預設初始化
### 串列初始器還是元素計數
```
vector<int> v1(10);  // 十個0
vector<int> v2{10};  // 一個10
vector<int> v3(10, 1);  // 十個1
vector<int> v4{10, 1};  // 10和1
vector<string> v5{"hi"};  // 一個hi
vector<string> v6("hi");  // 錯誤
vector<string> v7{10};  // 十個空字串
vector<string> v8{10, "hi"}  // 十個hi
```
- 少數情況下: 大括號是串列初始化，小括號是計數；可是拷貝的時候又可以直接拿(因為拷貝用小括號)
- 當我們使用大括號，我們說的是: 如果可能的話，我們想要串列初始化物件
- 如果我們使用大括號，但沒辦法用那些初始器來串列初始化物件，那麼那些值就會被用來建構物件(v7, v8)
- 要串列初始化物件，型別要對

## 3.3.2 新增元素到一個vector
- `push_back`: push_back(i)
- 關鍵概念: vector能夠有效率地增長
### 新增元素到vector對程式設計產生的影響
- 如果迴圈主體會新增元素的vector，那我們就不能使用範圍for
- 一個範圍for的主體必不能改變它所迭代的序列之大小
## 3.3.3 其他的vector運算
- 要使用size_type，我們必須指出它是在哪個型別中定義的，vector的size_type包括它的元素型別
    - 正確: `vector<int>::size_type`
    - 錯誤: `vector::size_type`
### 計算一個vector的索引
- 下標的型別是對應的size_type
- 範例程式: 假設我們有一組成績，範圍從0到100。我們想要計算有多少成績落入10分為一群的各個叢集。零與100分之間有101個可能的成績。這些成績可以用11個叢集來表示: 每10分一組的10個叢集，加上滿分100的一個叢集。第一個叢集會計數0到9的成績有幾個，第二個會計數從10到19的，依此類推。最後一個叢集計數有多少個分數達到了100分。
    - 輸入: 42 65 95 100 30 67 95 76 88 76 83 92 76 93
    - 輸出: 0 0 0 1 1 0 2 3 2 4 1
### 下標並不會增加元素
- 增加元素用push_back
- 空vector給下標執行期會是未定義
# 3.4 迭代器簡介
- 所有程式庫容器都有迭代器，但只有少數幾個支援下標運算子。
- 和指標一樣，迭代器提供給我們對一個物件的間接存取
## 3.4.1 使用迭代器
- 有的型別提供回傳迭代器的成員函式，名為begin和end: `auto b = v.begin(), e=v.end();`
- end回傳迭代器所在位置超出關聯的容器最後一個元素一個位置
- note: 如果容器是空的，begin和end回傳的迭代器就相等
### 迭代器運算
### 將迭代器從一個元素移向另一個
- end回傳的迭代器不代表任何元素，它不能被遞增或解參考
- 在for迴圈中使用`<`或是`!=`: 因為有的容器的迭代器並沒有定義`<`
    - [ ] 沒有定義`<`的容器?
### 迭代器型別
- 一般不會知道，也沒必要知道，一個迭代器的型別
- 具有迭代器的程式庫型別定義了名為iterator與const_iterator的型別
- 一個const_iterator的行為就像一個const指標，可讀取但不能寫入
- 專有名詞: 迭代器和迭代器型別
    - 迭代器可能用來指涉三種不同的實體
        - 可能是迭代器的概念
        - 可能是一個容器所定義的迭代器型別
        - 可能指的是作為迭代器的一個物件
### begin和end運算
- begin和end所回傳的型別取決於他們所作用的物件，如果物件是const，就回傳const_iterator，如果該物件並非const，就回傳iterator
- `C++11`: 可以主動請求const_iterator藉由: cbegin和cend
### 結合解參考和成員存取
- 解參考迭代器，就會得到該迭代器所代表的物件
- 有一個string組成的vector，it是參考到這個vector的一個迭代器。我們會這樣檢查it所代表的物件是否為空``(*it).empty()``
- 注意括弧是必要的。沒有括弧點號運算子會套用到it
- 為了簡化此問題，定義了(`->`運算子)
- it->mem是`(*it).mem`的一個同義詞
### 某些vector運算會使迭代器變得無效
- 用到迭代器的迴圈不應該新增元素到那些迭代器所參考的容器中
## 3.4.2 迭代器的算術運算
- vector和string迭代器所支援的運算
### 迭代器上的算術運算
- 兩個迭代器相減產生的型別是名為difference_type的有號整數型別
### 使用迭代器算數
- ==二元搜尋==
    - 在排序過的序列中尋找特定的一個值。
    - 查看最接近中間的元素
    - 如果是想要的，done
    - 不是的話，如果元素小於特定值，只看後半部，否則，前半部
# 3.5 陣列
- 如果你無法確定你需要多少元素，就用vector
## 3.5.1 定義並初始化內建的陣列
- 陣列尺寸必須在編譯時期就知道i.e. 尺寸必須是常數運算式
- 注意不能直接用變數指定size，除非變數是常數運算式
- 無法使用auto定義陣列
    ```
    unsigned cnt = 42;
    constexpr unsigned sz = 42;
    int arr[10];
    int *parr[sz];  // 元素是int*，有42個的陣列
    string bad[cnt];  // 錯誤: cnt不是常數運算式
    string strs[get_size()];  // 如果get_size()是常數運算式就ok，否則就錯誤
    ```
- 陣列持有的是物件，因此不會有由參考構成的陣列存在(vector也是)
### 明確地初始化陣列元素
- 大小為5，只給定前三個`int a[5] = {0, 1, 2};`
### 字元陣列是特殊的
- '' 和 ""初始化的陣列，大小會不一樣
- ""會自動加上null終止符
    ```
    char a1[] = {'C', '+', '+'};  // 串列初始化，沒有null
    char a2[] = {'C', '+', '+', '\0'};  // 串列初始化，明確的null
    char a3[] = "C++";  // 這個會自動加上null終止符
    const char a4[6] = "Daniel";  // 錯誤: null沒有空間放
    ```
### 沒有拷貝或指定
- 無法用另一個陣列初始化一個陣列(某些編譯器可以)
### 了解複雜的陣列宣告
- 定義持有指標的陣列相當簡單明瞭
- 定義對一個陣列的指標或參考就複雜了一點
    ```
    int *ptrs[10]; // ptrs是對int的指標構成的陣列
    int &refs[10]; //錯誤: 沒有參考構成的陣列
    int (*Parry)[10] = &arr;  // Parry指向由十個int所構成的陣列
    int (&arrRef)[10] = arr;  // arrRef指涉十個int所組成的陣列
    ```
- 了解陣列宣告一個可能比較容易的方式是從陣列的名稱開始，由內而外閱讀他們
- `int *(&array)[10] = ptrs;  // 幹這啥`

## 3.5.2 存取一個陣列的元素
- size_t是一種機器特定的無號型別，保證夠大可以容納記憶體中任何物件的大小，定義於cstddef標頭
- 使用下標應該使用size_t型別
### 檢查下標值
- 永遠確保下標值在範圍內
## 3.5.3 指標與陣列
- 當我們使用一個陣列，編譯器通常會將之轉換為一個指標，在多數運算式中，當我們使用陣列型別的一個物件，實際上我們使用的會是指向該陣列第一個元素的一個指標
    ```
    string nums[] = {"one", "two", "three"}
    string *p = &nums[0];
    string *p2 = nums;  // 等同於*p2 = nums[0]
    ```
- 用auto對陣列會推導出指標
- 用decltype則是推導出陣列
### 指標是迭代器
- 可以索取超出陣列最後一個元素一個位置的那個不存在的元素的指標
### 程式庫的begin和end函式
- 對於陣列可以使用程式庫的begin和end拿到類似迭代器的begin和end
    ```
    int ia[] = {0, 1, 2};
    int *beg = begin(ia);
    int *last = end(ia);
    ```
- 這些函式定義於iterator標頭中
### 指標算術
- 對陣列的指標加上整數值，回傳一個指標
- 相減兩個指標的結果會是一個ptrdiff_t的程式庫型別，定義在cstddef標頭中。
### 解參考和指標算術之間的互動
### 下標與指標
- 不同於vector和string，陣列的下標允許負值
- 藉此我們知道size_t並不是unsigned型別
    ```
    int ia[] = {0, 2, 4, 6, 8};
    int i = ia[2];
    int *p = ia;
    i = *(p + 2);
    int *p = &ia[2];
    int j = p[1];
    int k = p[-2];
    ```
## 3.5.4 C-Style的字元字串
- c++支援C-style的字串
- C-style字串並非一個型別，而是如何表示和使用字元字串的一種慣例。遵循此慣例的字串儲存在字元陣列中，並且是以null結尾的。
### C程式庫的字串程式
- 定義在cstring標頭中的函式:
    - `strlen(p);`
    - `strcmp(p1, p2);`
    - `strcat(p1, p2);`
    - `strcpy(p1, p2);`
- 常見的用法: 字串拼接
    ```
    strcpy(largeStr, cal);
    strcat(largeStr, " ");
    strcat(largeStr, ca2);
    ```
### 比較字串
- 直接比較char的陣列，比較的是指標的位子，一般來說未定義
- 想像string一樣比較要用strcmp(p1, p2)
### 呼叫者負責目的字串的大小
- string的串接: s1+s2
- 但對於兩個陣列的相加會是一種錯誤，因為實際是指標相加
- 要想串接要使用strcat(concatenating)
## 3.5.5 與舊有程式碼的介面
### 混用程式庫string和C-Style字串
- 可以從C-Style字串初始化string，反過來不能
- 有個叫c_str()的函數可以幹這個事。
### 使用一個陣列來初始化一個vector
- 使用begin來初始化vector
- 不過還是可以用array的指標來初始化vector
# 3.6 多維陣列
- 多維陣列就是由陣列所構成的陣列
- 定義陣列的陣列: `int ia[3][4];  // 大小為3的陣列，每個元素都是大小為4的int陣列`
- 更多維:`int arr[10][20][30] = {0};  // 大小為10的陣列，每個元素都是有20個元素的陣列，其中每個元素都是由30個int所組成的陣列`
- 第一個尺寸通常指row，第二個則是column
### 初始化一個多維陣列的元素
### 下標一個多維陣列
### 使用一個範圍for來處理多維陣列
- 要使用範圍for來處理多維陣列時，迴圈控制變數必須是參考(不然因為陣列指標的自動轉換，它會去迭代一個指標)
    ```
    for (const auto &row : ia)
        for (auto col : row)
            cout << col << endl;
    ```
### 指標與多維陣列
### 型別別名簡化了對多維陣列的指標