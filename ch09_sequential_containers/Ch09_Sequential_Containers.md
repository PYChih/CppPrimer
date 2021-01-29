# Ch09_Sequential_Containers
###### tags: `C++Primer`
[TOC]
# 9.1 循序容器總覽
- 循序的容器型別
    - vector: 大小有彈性的陣列、快速的隨機存取、插入或刪除不在後端的元素可能會比較慢
    - deque: 有兩端開口的佇列(queue)。快速的隨機存取。在前端或後端的插入或刪除也快速
    - list: 雙向連結串列(double linked list)。僅支援雙向的循序存取。在list中任一點的插入或刪除都很快速。
    - forward_list: 單向連結串列(singly linked list)。僅支援單向的尋循序存取。在串列中任一點的插入與刪除都很快速。
    - array: 大小固定的陣列。支援快速的隨機存取。無法新增或刪除元素
    - string: 一種特化的容器，類似vector，包含字元。快速的隨機存取。在後端的插入與刪除都很快速
- 各自有不同的效能取捨
    - 新增或刪除容器元素的成本
    - 對容器元素進行非循序存取的成本
- 除了array這個例外(固定大小的容器)，容器都提供了有效率且彈性的記憶體管理。
- [ ] 為什麼list和forward_list的記憶體額外負擔與vector、deque與array相較之下，通常都很大
- forward_list的設計目標是希望比得上最佳的手寫的單向鏈結串列。
- forwaed_list沒有size()運算，對其它的容器而言，size保證是快速、常數時間的運算
### 判斷要使用哪個循序容器
- 一般來說最好是使用vector，除非有優先選用其他好容易的好理由。
- 如果你不確定要用哪個容器，就將你的程式碼寫成僅使用vector和list所共通的運算: 使用迭代器，而非下標，並且避免對元素的隨機存取。如此一來，必要時改用vector或list都會比較容易
# 9.2 容器程式庫概觀
- 容器型別上的階層架構體系
    - 所有的容器型別都提供的運算
    - 專屬於循序容器、關聯式容器、無序容器的運算
    - 只有這些容器的一個小子集能使用的運算
- 每個容器定義在與該型別同名的一個標頭檔案中
### 容器能存放的型別之限制
## 9.2.1 迭代器
- 迭代器全都定義了遞增運算子
- forward_list不支援遞減運算子
- 只有string、vector、deque與array的迭代器運算
    - 主要就是比較運算子還有+n-n跟迭代器相減
### 迭代器範圍
- begin和end的範圍稱作左包含區間`[ begin, end)`
### 使用左包含範圍對程式設計的影響
- 左包含範圍的三個便利性
    - 若begin等於end，那範圍就是空的
    - 如果begin不等於end，那麼範圍中至少會有一個元素，而begin指向該範圍中的第一個元素
    - 我們可以遞增begin數次，直到``begin==end``
## 9.2.2 容器型別成員
- 型別別名讓我們使用儲存在一個容器中的元素之型別，而不用知道那個型別為何
- 例子:
    ```
    // iter是list<string>所定義的iterator型別
    list<string>::iterator iter;
    // count是vector<int>所定義的difference_type型別
    vector<int>::difference_type count;
    ```
- 如果我們需要元素型別，我們會參照容器的value_type
- 如果我們需要對那個型別的一個參考，我們會使用``reference``或``const_reference``
## 9.2.3 begin與end成員
- 幾個版本的begin與end
    ```
    list<string> a = {"Milton", "Shakespeare", "Austen"};
    auto it1 = a.begin();  // list<string>::iterator
    auto it2 = a.rbegin();  // list<string>::reverse_iterator
    auto it3 = a.cbegin();  // list<string>::const_iterator
    auto it4 = a.crbegin();  // list<string>::const_reverse_iterator
    ```
- 沒有以c開頭的那些函式是重載的。也就是說，其實有兩個名為begin的成員。一個是const成員，回傳容器的const_iterator型別。另一個是非const的，並回傳容器的iterator型別
- 只有在一個const物件上呼叫這些迭代器，我們才會得到const版本的迭代器
- 就跟對const的指標和參考，我們可以把普通的iterator轉為對應的const_iterator，但反過來不行
    ```
    // 型別是明確指定的
    list<string>::iterator it5 = a.begin();
    list<string>::const_iterator it6 = a.begin();
    // iterator或const_iterator，取決於a的型別
    auto it7 = a.begin(); // 只有在a是const的時候為const_iterator
    auto it8 = a.cbegin(); // it8是const_iterator
    ```
- 若不需要寫入權限，就用cbegin和cend。
## 9.2.4 定義和初始化一個容器
### 將容器初始化為另一個容器的一個拷貝
- 由iterator初始化的建構器可以方便的拷貝一個子序列
    ```
    list<string> authors = {"Milton", "Shakespears", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
    list<string> list2(authors);  // 型別相符
    deque<string> authList(authors);  // 錯誤: 容器型別不符
    vector<string> words(articles); // 錯誤: 元素型別必須符合
    // ok: 將const char* 轉換為string
    forward_list<string> words(articles.begin(), articles.end());
    ```
- note: 當我們初始化一個容器作為另一個容器的一個拷貝，兩個容器的容器型別和元素型別都必須完全相同
### 串列初始化
- 串列初始化一個容器
    ```
    list<string> authors = {"Milton", "Shakespears", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
    ```
### 循序容器與大小相關的建構器
### 程式庫array有固定大小
- 程式庫array的大小也是其型別的一部分
    ```
    array<int, 42>;  // 型別為: 存放42個int的array
    array<string, 10>;  // 型別為: 存放10個string的array
    ```
- 要使用一個array，元素型別和大小兩者都必須指定
- 我們無法拷貝或指定內建陣列型別的物件，array沒有這種限制:
    ```
    int digs[10] = {0, 1, 2, 3, 4, 5};
    int cpy[10] = digs;  // 錯誤:內建陣列無法拷貝或指定
    array<int, 10> digits = {0, 1, 2, 3, 4, 5};
    array<int, 10> copy = digits;  //ok，只要array的型別吻合就行
    ```
## 9.2.5 指定和swap
- 可以從一個array拷貝到另一個array
- 但僅限於大小相同時
- array無法用大括號assign
- `c1.swap(c2)`將c1中的元素與c2中的元素互換，c1和c2必須是相同型別。swap通常會比從c2到c1拷貝元素還要快很多
### 使用assign(僅限循序容器)
- 指定運算子要求左運算元和右運算元要有相同的型別。它會將右運算元所有的元素拷貝到左運算元中。
- array也有一個名為assign的成員
- 可以使用assign來將一個vector的一個範圍的``char*``值指定給一個由string組成的list
    ```
    list<string> names;
    vector<const char*> oldstyle;
    names = oldstyle;  // 錯誤，型別不符合
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    ```
### 使用swap
## 9.2.6 容器大小的運算
- `forward_list`沒有``size``
## 9.2.7 關係運算子
- 比較的時候先比第一個不同的元素的大小，再比size
### 關係運算子會使用它們元素的關係運算子
# 9.3 循序容器的運算
- 循序與關聯式容器的差異在於它們組織其元素的方式。
- 剩餘部分涵蓋循序容器專屬的運算
## 9.3.1 新增元素至一個循序容器
- 容器使用不同的策略來配置(allocate)元素，而這些策略會影響到效能
### 使用push_back
- `push_back`會將一個元素附加到一個vector的後端
- 關鍵概念: 容器元素是拷貝
### 使用push_front
### 在容器中的指定位置新增元素
- vector沒有push_front，可是有insert，合法不代表便宜
### 插入一個範圍的元素
- 拷貝來自範圍的元素不能與原始元素相同(主因是迭代器會失效)
### 使用來自insert的回傳值
- insert是回傳新的第一個位置的iterator
- 如果範圍是空的就會回傳本來的迭代器
- 可以藉由使用insert的回傳值來做出push_front
    ```
    list<string> lst;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);
    ```
### 使用Emplace運算
- emplace傳入的參數是給建構器
## 9.3.2 存取元素
- 如果容器沒有元素，那麼這些存取運算會是未定義的。``c.back(), c.front(), c[n], c.at(n)``
    ```
    // 先檢查有元素存在，再解參考迭代器或呼叫front或back
    if (!c.empty()) {
        // val1 和 val2 是c中第一個元素的值的拷貝
        auto val1 = *c.begin(), val2 = c.front();
        // val3 和 val4 是c中最後一個元素的拷貝
        auto last = c.end();
        auto val3 = *(--last);  // 無法遞減forward_list迭代器
        auto val4 = c.back();  // forward_list沒有支援
    }
    ```
### 存取成員回傳參考
- 如果容器是const物件，回傳的就是對const的參考
### 下標和安全的隨機存取
- at會回傳out_of_range例外
## 9.3.3 清除元素
- 移除元素的成員並不會檢查引數，程式設計師必須在移除它們之前確保那些元素存在
### pop_front與pop_back成員
- 分別移除第一個與最後一個元素
- 不可以在一個空的容器上使用pop運算
### 在容器中移除一個元素
- erase移除回傳的是移除元素的後一個位子
### 移除多個元素
## 9.3.4 專用的forward_list運算
- forward_list的emplace_after, insert_after以及erase_after
- 在vector中insert(p, arg)是在p之前插入arg建構出來的東西，回傳建構的第一個
- 在forward_list中insert(p, arg)是在p之後插入arg，回傳建構的最後一個
- 為了這些操作，forward_list定了一個before_begin的迭代器
- forward_list的一般使用:
    ```
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();  // off the begin iterator
    auto curr = flst.begin();  // first element
    while (curr != flst.end()) {
        if (*curr % 2)  // if current number is odd
            curr = flst.erase_after(prev);  // delete odd and return (equal to ++curr)
        else {
            prev = curr;
            ++curr;
        }
    }
    ```
## 9.3.5 調整一個容器的大小
- `resize`操作
    - 如果目前大小大於resize大小，元素從後端刪除
    - 如果目前大小小於resize大小，元素加到容器後端
- 缺少插入引數的話: 值初始化

## 9.3.6 容器運算可能使迭代器變得無效
- 使用已經無效化的迭代器、參考、指標會是一個種嚴重的執行期錯誤
- 建議: 管理迭代器: 
    - 當你使用一個迭代器(或對某個容器元素的一個參考或指標)，最小化在其執行過程中會要求一個迭代器必須保持有效的程式部分，是一種好主意。
    - 因為新增或移除容器元素的程式碼可能無效化迭代器，你需要確保迭代器在每次更改容器的運算後，都有適當重新定位過。這個建議對於vector、string和deque來說特別重要
### 撰寫會改變一個容器的迴圈
- erase(p)刪除的是p的元素，回傳本來的p的後一個元素
    ```
    // 移除偶數值元素並插入重複的奇數值元素的怪異迴圈
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();  // 呼叫begin而非cbegin，因為會改變迴圈
    while (iter != vi.end()) {  // 每次都重取end
        if (*iter % 2) {  // 當遇到奇數
            iter = vi.insert(iter, *iter);  // 在迭代器前插入那個奇數，回傳指向插入的那個奇數的位置
            iter += 2;  // 因為是在之前插入，所以迭代器要遞增2
        } else  // 遇到偶數的時候
            iter = vi.erase(iter);  // 刪除那個偶數，回傳的是刪除的元素的後一個位置
            // 別推進迭代器，iter代表的是我們消除的元素之後的元素
    }
    ```
### 避免儲存end回傳的迭代器
- 在vector或string中新增或移除元素，或在一個deque中移除第一個元素以外的任何元素，end所回傳的元素永遠都會無效化
- ``while (begin != v.end())``盡量不要儲存end迭代器
# 9.4 vector的增長方式
- 元素必須是連續的，因此造成沒位置的話必須配置新的記憶體
    - vector增長的效率通常會比list或deque還要高
### 管理容量的成員
- ``capacity``: 容器可以存放多少元素
- ``reserve``:告訴容器應該準備好存放多少元素
    - reserve不會改變容器中的元素數，只影響vector會預先配置多少記憶體
    - 只有在所請求的空間超過目前的容量時，對reserve的呼叫會改變vector的容量
- ``resize``: 只會改變元素個數，不會改變容量
- shrink_to_fit來要求歸還不需要的記憶體(但沒辦法保證) 
### capacity和size
- 差異: size就是已經存放的元素個數，capacity則是配置更多空間之前，它能夠存放多少元素
- 空的capacity應該會設為零
- 在一個最初為空的vector上呼叫push_back n次來創建一個n元素的vector所需的執行時間永遠都不能超過n的常數倍

# 9.5 額外的string運算
## 9.5.1 建構字串的其他方式
- string s(cp, n);
    - s是cp所指的陣列的前n個字元(陣列至少有n個元素) 
- string s(s2, pos2);
    - s是s2這個string中從索引pos2開始的字元的拷貝，如果pos2>s2.size就是未定義 
- string s(s2, pos2, len2);
    - 從索引pos2開始拷貝len2個字元，如果pos2>s2.size就是未定義，不管len2多少，最多拷貝s2.size()-pos2個位元
    ```
    const char *cp = "Hello World!!!";  // null終結的陣列
    char noNull[] = {'H', 'i'};  // 不是null終結的陣列
    string s1(cp);  // 拷貝到cp中的null為止
    string s2(noNull, 2);  // 從noNull拷貝兩個字元
    string s3(noNull);  // 未定義:noNull不是null終結
    string s4(cp+6, 5);  // 從cp[6]開始拷貝5個字元
    string s5(s1, 6, 5);  // 從s1[6]拷貝5個字元
    string s6(s1, 6);  // 從s1[6]拷貝到s1的結尾
    string s7(s1, 6, 20);  // 因為20超過s1的size，所以只拷貝到s1的結尾
    string s8(s1, 16);  // 本意是從s1拷貝前16個字元，不過si的size小於16所以是擲出out of range
    ```
- 以const char*創建string，指標所指的陣列就必須null終結
### substr運算
- ``s.substr(pos, n)``: 回傳一個string包含s從pos開始的n個字元。pos預設是0
## 9.5.2 修改字串的其他方式
- string支持指定、assign、insert與erase運算
- 也定義了額外版本的insert和erase(支援string的insert和C-style char的insert)
    ```
    s.insert(s.size(), 5, '!');  // 結尾插入5個驚嘆號
    s.erase(s.size()-5, 5);  // 移除最後五個字元
    ```
- 接受C-style字元陣列的insert和assign
    ```
    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7);  // s == "Stately"
    s.insert(s.zie(), cp+7);  // s=="Stately, plump Buck"
    ```
### append和replace函式
- string定義的兩個額外的成員，append和replace
- append是在尾端插入的一種速記法:
    ```
    string s("C++ Primer"), s2 = s;
    s.insert(s.size(), "4 th Ed.");
    s2.append("4 th Ed");
    ```
- replace運算是呼叫erase和insert的一種速記法:
    ```
    s.erase(11, 3);  // 刪掉從11開始的三個字
    s.insert(11, "5th");
    s2.replace(11, 3, "5th")
    ```
- 插入和移除字元不等長
    ```
    s.replace(11, 3, "fifth")
    ```
### 變更一個string的許多重載方式
- assign永遠都會取代string的整個內容，
- append永遠新增到string的尾端
- replace提供了兩種方式來指定要移除的字元範圍，位置，長度或用迭代器範圍
### 9.5.3 string搜尋運算
- string的搜尋函式回傳的值是吻合處的索引，如果沒有匹配則回傳一個static成員，名為string::npos
- 程式庫將npos定義為了一個const string::size_type，並以-1這個值初始化
- 因為npos是unsigned型別，這個初始器意味著npos等於string可以有的最大可能大小
- string的搜尋函式回傳``string::size_type``型別，是一個unsigned型別。結果是:使用一個int或其他的有號型別來存放從這些函式回傳的值是個壞主意
- ``find``: 回傳找到的第一個匹配的索引，或在無匹配時回傳npos
    ```
    string name("AnnaBelle");
    auto pos1 = name.find("Anna");  // pos1==0
    ```
- 搜尋時大小寫有差異
- `find_first_of`對搜尋字串中任何字元的匹配
    ```
    string numbers("0123456789"), name("r2d2");
    auto pos = name.find_first_of(numbers);
    ```
- `find_first_not_of`找尋第一個沒有在搜尋引數中的位置
    ```
    // 找尋第一個非數值字元
    string dept("03714p3");
    auto pos = dept.find_first_not_of(numbers);
    ```
### 指定開始搜尋處
- 常見的方法是使用這個引數以迴圈處理所有出現的地方
    ```
    string::size_type pos = 0;
    // 每次迭代都會在name中找尋下個數字
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
        ++pos;
    ```
### 往回搜尋
- rfind
    ```
    string river("Mississippi");
    auto first_pos = river.find("is");  // 回傳1
    auto last_pos = river.rfind("is");  // 回傳4
    ```
- find_last_of : 搜尋匹配要找的string任何元素的最後一個字元
- find_last_not_of: 搜尋不匹配要找的string任何元素的最後一個字元
### 9.5.4 compare函式
- compare引數隨著比較兩個string或比較一個string和一個字元陣列而變。這兩種情況中，我們都可以比較整個字串，或其中的部分字串。
- s.compare(s2)
- s.compare(pos1, n1, s2)
- s.compare(pos1, n1, s2, pos2, n2)
- s.compare(cp)
- s.compare(pos1, n1, cp)
- s.compare(pos1, n1, cp, n2)
### 9.5.5 數值轉換
- 新標準引進了數個函式能在數值資料和程式庫的string之間進行轉換:
    ```
    int i = 42;
    string s = to_string(i);
    double d = stod(s);  // string to double
    string s2 = "pi = 3.14";
    d = stod(s2.substr(s2.find_first_of("+-.0123456789")))
    ```
- 如果string不能被轉換為一個數字，這些函式會擲出一個invalid_argument例外。如果轉換過程產生了一個無法表示的值，它們會擲出``out_of_range``。
# 9.6 容器轉接器
- 除了循序容器，程式庫還定義了三個循序容器轉接器: stack、queue與priority_queue
- 轉接器adaptor是程式庫中的一個概念，這包括了容器、迭代器，以及函式轉接器。
- 一個容器轉接器接受一個現有的容器型別，並讓它的行為表現的像另一個東西的一種機制。
- 例子:
    - stack轉接器接受一個循序容器，並讓它運作起來像一個stack一樣
### 定義一個轉接器
- 每個轉接器都定義了兩個建構器: 創建一個空物件的預設建構器，以及接受一個容器，並藉由拷貝所給的容器來初始化轉接器的另一個建構器。
    ```
    stack<int> stk(deq);
    ```
- 預設stack與queue都是以deque為基礎實作
- priority_queue在vector上實作
- 複寫容器型別: 在創建轉接器時，指名一個循序容器作為第二個型別引數
    ```
    // empty stack在vector上實作的空堆疊
    stack<string, vector<string>> str_stk;
    // str_stk2是在vector上實作的，而且最初存放有svec的一個拷貝
    stack<string, vector<string>> str_stk2(svec);
    ```
- 所有的轉接器都需要新增和移除元素的能力，因此不能建置在array上
- 不能使用forward_list，因為所有的轉接器都需要新增、移除或存取容器中最後一個元素
### 堆疊轉接器("Stack Adaptor")
- stack型別定義在stack標頭中。
    ```
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);  // intStack存有0...9包括兩端
    while (!intStack.empty()){  // 只要stack還有值
        int value = intStack.top();
        intStack.pop()
    }
    ```
- 每個容器轉接器都以底層容器型別所提供的運算子定義了自己的運算
- 我們只能使用轉接器的運算，不能使用底層容器型別的運算
    ```
    intStack.push(ix);
    ```
- 會在intStack作為基礎的deque物件上呼叫push_back。
- 雖然stack是以一個deque來實作，我們對於deque的運算並沒有直接的存取權。
- 不能在一個stack上呼叫push_back，我們必須使用名為push的stack運算
### 佇列轉接器("Queue Adaptors")
- queue和priority_queue轉接器定義在queue標頭中
- 預設情況，queue使用deque而priority_queue使用vector
