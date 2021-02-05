# Ch13_Copy_control
###### tags: `C++ exercise`
[TOC]
# 13.1 拷貝、指定與摧毀
## 13.1.1 拷貝建構器

- [ ] 13.1: What is a copy constructor? When is it used?
- [ ] 13.2: Explain why the following declaration is illegal:
``Sales_data::Sales_data(Sales_data rhs);``
- [ ] 13.3: What happens when we copy a StrBlob? What about StrBlobPtrs?
    - StrBlob只有一個資料成員，是一個智慧指針指向`vector<string>`，因為沒有定義拷貝建構器，所以編譯器會為我們合成一個合成的拷貝建構器，當我們拷貝一個StrBlob的時候，比如將b1定義為一個StrBlob預設初始化，b2定義為一個StrBlob並串列初始化指向`{"a", "an", "the"}`，那當我們令b1=b2；合成的拷貝建構器會把b2的data資料成員(那個智慧指針)的值拷貝給b1，結論是，在動態記憶體裡會有一個`vector<string>`，並且有兩個指針指向那個vector`<string>``
    - StrBlobPtr有兩個資料成員，一個是weak_ptr一個是curr，當我們拷貝一個StrBlob，會把本來的WeakPtr指標讓新的weakPtr指標指，而curr會從本來的curr拷貝一個過去
- [ ] 13.4: 假設Point是具有一個public拷貝建構器的類別型別，在這個程式片段中識別出該拷貝建構器的每個使用:
    ```
    Point global;
    Point foo_bar(Point arg) {  // 呼叫的時候從引數拷貝建構到arg
        Point local = arg, *heap = new Point(global);  // local拷貝建構器，heap拷貝建構器
        *heap = local;  // 拷貝指定運算子
        Point pa[4] = { local, *heap };  // 從local拷貝建構，從*heap拷貝建構
        return *heap;  // 從*heap拷貝指定或拷貝建構
    }
    ```
- [ ] 13.5: 使用拷貝建構器動態配置物件(新的類別需要動態配置新的資料成員，而不是複製成員的位址)
## 13.1.2 拷貝指定運算子
- [ ] 13.6: What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?
    ```
    - 重載的運算子函式的定義方式是一個函式名稱是operator加上運算子符號，比如說operator=
    回傳型別是左手邊物件的參考，運算子函式有一個回傳型別和一個參數列，參數代表運算元，左手邊的運算元會被繫結到隱含的this，所以回傳型別是類別物件的參考，return *this。
    - 當物件被指定的時候(某個型別有兩個變數a跟b，a=b就是把b指定給a，這時候拷貝指定運算子使用
    - 合成的版本會把右手邊的資料成員一個一個拷貝給左手邊
    - 沒定義的時候會自己合成一個
    ```
- [ ] 13.7:當我們指定一個StrBlob給另一個，會發生什麼事?那StrBlobPtr呢?
    ```
    - StrBlob只有一個資料成員，是一個智慧指針指向`vector<string>`，當指定一個StrBlob給另一個的時候，另一個的資料成員data(是一個智慧指針)會指向本來的data所指的那個物件(vector<string>)，然後shared_ptr的計數會增加
    - StrBlobPtr會把weak_ptr指的物件拷貝給新的StrBlobPtr，所以計數不會增加
    ```
- [ ] 13.8: 這裡要注意原本的資料成員都是動態配置的，所以拷貝指定的時候要把原本new出來的資料成員delete。

## 13.1.3 解構器
- [ ] 13.09: What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
    ```
    - 解構器是一個和類別名稱同名前面加上~的函數，沒有回傳值也沒有引數
    - 啥都不幹= =
    - 沒有定義解構器的時候會幫我們合成一個
    ```
- [ ] 13.10 : 當一個StrBlob物件被摧毀，會發生什麼事? 那StrBlobPtr呢?
    ```
    - 因為沒定義解構器，所以編譯器自己幫我們合成一個，他會按照成員的相反順序一個一個摧毀，因為StrBlob的資料成員是智慧指針，智慧指針會呼叫他的解構器，會發生的事情是遞減shared_ptr的計數，如果計數降到0那就會呼叫vector<string>的解構器來摧毀那個動態配置的物件。
    - StrBlobPtr會先摧毀curr，然後摧毀weak_ptr
    ```
- [ ] 13.11: 練習寫一個解構器(要記得delete動態配置的物件)
- [ ] 13.12: 對一個物件的參考或指標超出範疇時，解構器不會執行
- [ ] 13.13: 徹底搞懂拷貝控制成員就看這題
## 13.1.1 Three/Five規則
- [ ] 13.14: 假設numbered這個類別具備的預設建構器會為每個物件產生一個唯一的序號，儲存在名為mysn的一個資料成員中。假設numbered使用合成的拷貝控制成員，並給定下列這個函式:
    ```
    void f (numbered s) { cout << s.mysn << endl; }
    // 下面程式碼的輸出會是什麼?
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    ```
    - 創建a，a有序號a
    - b = a，拷貝指定運算子執行，把a個序號拷貝給b
    - c = b，拷貝建構器執行，把b的序號又給c
    - 所以abc會有相同的序號
- [ ] 13.15: 假設numbered具有一個拷貝建構器，它會產生一個新的序號。這會改變前面練習中呼叫的輸出嗎?如果會，為什麼呢，會產生什麼輸出呢
- [ ] 13.16: 如果f中的參數是const numbered&，會怎樣呢?那會改變輸出嗎?如果是，為什麼呢?會產生什麼輸出呢?
- [ ] 13.17: 撰寫對應於前三個練習的numbered和f，並檢查你是否正確地預測了輸出。

## 13.1.5 Using = default
## 13.1.6 防止拷貝
- [ ] 13.18: 定義一個Employee類別含有
    - 雇員名稱(employee name)
    - 唯一的雇員識別號
    - 預設建構器
    - 接受string代表名稱的建構器
    每個建構器都應該藉由遞增一個static資料成員來產生一個唯一的ID
- [ ] 13.19 為employee定義拷貝控制成員
    - [ ] 定義成delete
- [ ] 13.20 請說明當我們拷貝、指定或摧毀我們TextQuery與QueryResult類別的物件時，會發生什麼事?
    - TextQurey
        - TextQurey有一個shared_ptr指向文件檔案，一個map，key是查詢的文字，value是一個set對應該文字的行號
        - 拷貝: shared_ptr指向的位置會被拷貝，會拷貝出一個shared_ptr
        - 指定: 同上
        - 刪除: shared_ptr
    - QueryResult
        - 一個String，兩個shared_ptr
        - string被拷貝、shared_ptr也被拷貝
    - 都是類似指標的行為，shared_ptr"指向的位置"被拷貝，然後參考計數遞增
- [ ] 13.21 你認為TextQuery與QueryResult類別需要定義它們自己版本的拷貝控制成員嗎?如果是，為什麼呢?如果不是，為何不?實作你認為這些類別需要的任何拷貝控制運算。
    - 因為兩個類別依靠shared_ptr進行資源共享，且當計數降為0會自動釋放記憶體，因此可以不定義拷貝控制成員
# 13.2 拷貝控制與資源管理
- [ ] 13.22 : 把HasPtr寫的行為跟值一樣
## 13.2.1 行為表現跟值一樣的類別
- [ ] 13.23 : 注意物件被指定給自身的情況
- [ ] 13.24: 如果本節中的HasPtr版本沒有定義一個解構器，會發生什麼事?如果HasPtr沒有定義拷貝建構器呢?
    - 解構器: 沒定義的話動態配置的string不會被刪除喔
    - 拷貝建構器: 那編譯器會幫我們合成一個，行為會是去拷貝*ps指的位置，那有發生呼叫解構器的時候就有可能重複刪除同一個動態配置的記憶體，結果就會未定義
- [ ] 13.25: 假設我們想要定義行為像是一個值的StrBlob版本。也假設我們想要繼續使用一個shared_ptr以讓我們的StrBlobPtr類別仍然可以使用對vector的一個weak_ptr。你修改過的類別將會需要一個拷貝建構器和拷貝指定運算子，但不需要解構器。解釋這個拷貝建構器和拷貝指定運算子必須做什麼。說明此類別不需要解構器的原因
    - 拷貝建構器:
        - StrBlob本來的行為是大家指向同個動態配置的`vector<string>`，改成想要像值一樣的行為的話，拷貝建構的時候要make一個shared_ptr然後用本來指著的`vector<string>`初始化。StrBlobptr就預設的就好
    - 拷貝指定運算子:
        - 開一個新的temp的shared_ptr用本來的值初始化
        - 然後讓本來的shared_ptr.reset(temp)
    - 解構器:
        - 因為shared_ptr不需要delete，所以不需要解構器
- [ ] 13.26: 定義你剛剛說的那個StrBlob
## 13.2.2 定義行為表現跟指標一樣的類別
- [ ] 13.27: 把HasPtr改成指標行為
- [ ] 13.28: ==實作一個二叉樹...==
# 13.3 Swap(對調)
- [ ] 13.29: 解釋為什麼swap(HasPtr&, HasPtr&)中對swap的呼叫不會導致遞迴迴圈
    - 因為裡面用的是程式庫的swap
- [ ] 13.30: 為你類值版本的HasPtr撰寫並測試一個swap函式。賦予你的swap一個列印述句，來提示它何時被執行。
- [ ] 13.31: 賦予你的類別一個<運算子，並定義由HasPtr所構成的一個vector。賦予那個vector一些元素，然後sort那個vector。注意swap何時被呼叫。
    - [ ] 快排、插入排序 
- [ ] 13.32: 定義一個swap函式對HasPtr的類指標版本有什麼好處嗎?如果有，好處是什麼?若無，為什麼呢?
    - 自訂swap省在減少額外的配置?
    - 指標版本的沒東西省了
# 13.4 一個Copy-Control範例
- [ ] 13.33: 為什麼Message的save和remove成員的參數是一個Folder&? 為什麼我們不把那個參數定義為Folder?或是const Folder&?
    - 因為save和remove會改變folder，所以要馬傳指標要馬傳參考，而且不能是const
- [ ] 13.34: 撰寫本節所描述的Message類別
- [ ] 13.35: 如果Message使用合成版的拷貝控制成員，那會發生什麼事?
    - 拷貝: 假設本來有一個Message m1，拷貝建構器是合成的: 新建了一個Message m2，擁有和m1一樣的contents，folders的內容指出有哪些folder存放了m2，可是所有的folder(裡的set)都不會有m2的指針
- [ ] 13.36: 設計並實作對應的Folder類別。那個類別應該存有一個set指向那個Folder中的Message。
- [ ] 13.37: 新增成員到Message類別，以在folders中插入或移除一個給定的Folder*。這些成員類似於Folder的addMsg和remMsg運算
- [ ] 13.38: 我們並沒有使用copy and swap來定義Message的指定運算子，你認為為什麼呢?
# 13.5 管理動態記憶體的類別
- [ ] 13.39: 寫出你自己版本的StrVec，包括reserve、capacity，以及resize。
- [ ] 13.40: 為你的StrVec類別新增接受一個`initializer_list<string>`的建構器。
- [ ] 13.41: 在push_back內的construct呼叫中，為何我們使用後綴遞增?如果用的是前綴遞增，會發生什麼事
    - 因為first_free指向的是第一個尚未建構的元素位置，語意上來說就是建構了當前元素之後，first_free移動到下一個
- [ ] 13.42: 用你的StrVec類別來取代你TextQuery與QueryResult類別中的`vector<string>`作為測試
    - [ ] 不使用shared_ptr管理
- [ ] 13.43: 改寫free成員使用for_each和一個lambda來取代for迴圈以destroy元素。你偏好哪個實作?為什麼呢?
- [ ] 13.44: 撰寫一個名為String的類別作為程式庫string類別的簡化版本。你的類別應該至少要有一個預設建構器，以及接受對C-style字串的指標的一個建構器。使用一個allocator來配置你的String類別所用的記憶體。
# 13.6 移動物件
## 13.6.1 Rvalue參考
- [ ] 13.45: 說明rvalue reference和lvalue reference之間的區別
- [ ] 13.46: 何種參考可以被繫結到下列初始器?
    ```
    int f();
    vector<int> vi(100);
    int? r1 = f();
    int? r2 = vi[0];
    int? r3 = r1;
    int? r4 = vi[0] * f();
    ```
- [ ] 13.47: 賦予你在13.5練習13.44的String類別中的拷貝建構器和拷貝指定運算子一個述句，在每次該函式執行時，印出一則訊息。
- [ ] 13.48: 定義一個`vector<String>`並在那個vector上呼叫push_back數次。執行你的程式，看看String多常被拷貝。
## 13.6.2 移動建構器和移動指定
- [ ] 13.49: 新增一個移動建構器和移動指定運算子到你的StrVec、String與Message類別
- [ ] 13.50: 在你String類別的移動運算中放入列印述句，並重新執行13.6.1習題13.48用到一個`vector<String>`的程式，看看什麼時候避開了拷貝。
    - vector增長的時候全都改用了移動
    - [ ] 加入移動迭代器(13.6.2)
- [ ] 13.51: 雖然unique_ptr無法被拷貝，在12.1.5中，我們撰寫了一個clone函式，它會以值回傳一個unique_ptr。解釋為何那個函式是合法的，以及它是如何運算的。
    - unique_ptr不能拷貝但是可以移動
    - 在function以值回傳時會是rvalue，function外藉由移動指定運算子或移動建構器進行移動
- [ ] 13.52: 詳細解釋前面HasPtr物件的指定中發生了什麼事。特別是，逐步描述hp、hp2和HasPtr指定運算子中rhs參數的值有什麼變化。
    - 假設hp和hp2都是HasPtr物件
    - `hp = hp2;  // hp2是lvalue，所以hp2的值會被拷貝指定運算子拷貝給hp`
    - `hp = std::move(hp2);  // hp2被std::move轉成了rvalue，因此這邊變成移動指定運算子作用`
    ```
    // HasPtr有的又是移動又是拷貝的指定運算子:
    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }
    ```
    - 當rhs是lvalue，rhs會被拷貝建構器建構
    - 當rhs是lvalue，rhs會被移動建構器建構
    - 無論是哪個建構器，都swap this的指標和rhs的指標，這會讓資料成員的指標逐個被swap(這個swap是我們自己訂的)
- [ ] 13.53: 就底層的效能而言，HasPtr的指定運算子並非理想。請解釋為何如此。為HasPtr實作一個拷貝指定和移動指定運算子，並比較在你新的移動指定運算子底下執行的運算，和copy-and-swap的版本較之如何。
    - HasPtr的移動和拷貝都藉由rhs實作，多了一層中間層(冗餘)
- [ ] 13.54: 如果我們定義一個HasPtr移動指定運算子，但沒有變更copy-and-swap運算子，會發生什麼事呢?撰寫程式碼來測試你的答案。

## 13.6.3 Rvalue參考和成員函式
- [ ] 13.55: 新增push_back的一個rvalue reference版本到你的StrBlob。
- [ ] 13.56: 如果我們將sorted定義成下列這樣，那會發生什麼事?
    ```
    Foo Foo::sorted() const & {
        Foo ret(*this);
        return ret.sorted();
    }
    ```
    - 注意，這邊的ret是lvalue，所以會無盡調用自己
- [ ] 13.57: 如果我們將sorted定義成這樣，會發生什麼事呢?
    ```
    Foo Foo::sorted() const & { return Foo(*this).sorted(); }
    ```
    - 注意，這邊的Foo(*this)是右值，所以會調用右值版本的sorted()
- [ ] 13.58: 撰寫它們的sorted函式中有列印述句的Foo類別版本，以測試你為前兩個練習所提供的答案。