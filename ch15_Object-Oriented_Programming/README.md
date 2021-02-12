# ch15_Object-Oriented_Programming
###### tags: `C++ exercise`
[TOC]
# 15.1 OOP之概觀
# 15.2 定義基礎與衍生類別
## 15.2.1 定義基礎類別
- [ ] 15.1: 什麼是虛擬成員
    - 基礎類別預期衍生類別會覆寫的成員會在宣告前使用virtual關鍵字
    - 除了建構器以外的成員都可以是虛擬成員
    - 在類別內宣告必須加上virtual關鍵字，類別外的函式定義不能加上virtual關鍵字
    - 就算解構器沒做事，也需要定義一個虛函式的解構器
- [ ] 15.2: protected存取指定符與private有何不同
    - 衍生類別就像基礎類別的使用者一樣，不能取用基礎類別的private成員
    - 但有時候會希望衍生類別可以取用，這時候就可以把成員定義成protected
    - 使用者不能取用protected也不能取用private
    - 但衍生類別可以取用protected，一樣不能取用private
    - 基礎類別的friend也可以取用protected
- [ ] 15.3: 定義你自己版本的Quote類別和print_total函式
## 15.2.2 定義衍生的類別
- [ ] 15.4: 下列宣告，如果有的話，何者是不正確的?請解釋原因
    ```
    class Base { ... };
    // a
    class Derived : public Derivec { ... };
    // b
    class Derived : private Base { ... };
    // c
    class Derived : public Base;
    // a: 無法從自己衍伸出自己(要繼承要先有定義)
    // b: 這是定義不是宣告
    // c: 宣告不包含衍生串列
    ```
    
- [ ] 15.5: 定義你自己版本的Bulk_quote類別。
- [ ] 15.6: 傳入Quote及Bulk_quote物件給15.2.1練習中你的print_total函式，以測試它
- [ ] 15.7: 定義一個類別來實作一個有限制的折扣策略，購買書籍的折扣最高只套用到一個給定的本數限制上，如果購買本數超過該限制，超出限制的那些書就只適用正常的價格。
## 15.2.3 轉換與繼承
- [ ] 15.8 定義靜態型別和動態型別
    - 靜態型別在編譯時就已經確定了，是宣告時的型別或表達式生成的型別
    - 動態型別則是變數或表達式的內存中對象的型別
    - 動態型別直到runtime才確定
    - 如果一個變數不是指針也不是參考，則它的竟態型別和動態型別永遠一樣
    - 但基礎類別的指針或參考的動態型別可能與它的靜態型別不一樣
- [ ] 15.9 一個運算式的靜態型別什麼時候會與它的動態型別不同?給出靜態與動態型別不同的3個例子
    - 以參考傳遞衍生類別到接受基礎類別的函式中
    - 以指標傳遞衍生類別到接受基礎類別的函式中
    - 將一個衍生類別的位址指定給指向基礎類別的指標
- [ ] 15.10: 回想一下8.1的討論。解釋8.2.1會把一個ifstream傳入Sales_data的read函式的那個程式是如何運作的
    - read函式接受一個istream，然後ifstream繼承於istream，我們將ifstream傳遞給接受istream的參考的函數
# 15.3 虛擬函式
- [ ] 15.11: 為你的Quote類別階層架構新增一個虛擬的debug函式，以顯示各個類別的資料成員。
- [ ] 15.12: 把一個成員函式同時定義為override和final可能會有用處嗎?為什麼有或為什麼沒有?
    - 不是就覆寫上層的而且不給下層的覆寫
- [ ] 15.13: 給定下列類別，解釋每個print函式的功用:
    ```
    class base {
    public:
        string name() { return basename; }
        virtual void print(ostream &os) { os << basename; }
    private:
        string basename;
    };
    class derived : public base {
    public:
        void print(ostream &os) { print(os); os << " " << i; }
    private:
        int i;
    };
    // base version:
    // 印出basename成員(一個string)
    // derived version
    // 呼叫print，因為沒用範疇指名是base的
    // 所以會一直呼叫自己變無窮遞迴
    // 然後印出i
    ```
    
- [ ] 15.14: 給定來自前一個練習的類別以及下列物件，判斷執行時期被呼叫的函式是哪一個:
    ```
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;
    // a
    bobj.print();
    // base
    // b
    dobj.print();
    // derived
    // c
    bp1->name();
    // 指向base的指標
    // base
    // d
    bp2->name();
    // 靜態型別是指向base的指標
    // 動態型別是指向derived的base部分
    // 會印出base的name
    // e
    br1.print();
    // br1是對base的參考
    // 呼叫base的print
    // f
    br2.print();
    // br2的靜態型別是對base的參考
    // 參考自derived
    所以這個print呼叫derived的
    ```
# 15.4 抽象基礎類別
- [ ] 15.15: 定義你自己版本的Disc_quote和Bulk_quote
- [ ] 15.16: 改寫代表一個有限制的折扣策略的類別，也就是你在15.2.2的習題中寫的那個，改繼承自Disc_quote。
- [ ] 15.17: 試著定義型別為Disc_quote的一個物件，看看你會從編譯器得到什麼錯誤
    ```
    error: invalid cast to abstract class type ‘Disc_quote’
    ```
# 15.5 存取控制與繼承
- [ ] 15.18: 給定前面15.5的類別，假設每個物件的型別就如註解中所指的那樣，請判斷下列那些指定是合法的。解釋那些非法的為何不被允許:
    ```
    Base *p = &d1;  // d1有型別Pub_Derv
    // p會指向d1的基礎類別的部分
    p = &d2;  // d2有型別Priv_Derv
    // 因為是private繼承，所以使用者不應該知道
    p = &d3;  // d3有型別Prot_Derv
    // Prot對user來說應該是不知道
    p = &dd1;  // dd1有型別Derived_from_Public
    // 可以，public繼承的衍生類別
    p = &dd2;  // dd2有型別Derived_from_Private
    // 非法
    p = &dd3;  // dd3有型別Derived_from_Protected
    // 非法
    ```
- [ ] 15.19: 假設前面的每個類別都有一個這種形式的成員函式:
    ```
    void memfcn(Base &b) { b = *this; }
    ```
    那麼對每個類別，請判斷這個函式是否合法
- [ ] 15.20: 撰寫程式碼來測試你對前面兩個習題的答案
- [ ] 15.21: 挑選下列含有一整個族系的型別的通用抽象層之一(或自己找一個)。將那些型別組織為一個繼承階層架構:
    ```
    // a 圖形檔案格式 (gif, tiff, jpeg, bmp)
    // b 幾何基元(例如方塊圓形球體圓錐體)
    // c C++語言型別(例如類別、函式、成員函式)
    ```
- [ ] 15.22: 對於你在前一個習題中挑選的類別，請識別出一些可能的虛擬函式，以及public和protected成員
# 15.6 繼承之下的類別範疇
- [ ] 15.23: 假設前面類別D1想要覆寫它繼承而來的fcn函式，你會如何修改那個類別?假設你修改了那個類別，讓fcn符合Base中的定義，那一節中的那些呼叫會如何被解析呢?
    - 想要override參數就要一樣，所以要把fcn的參數改成空的
    - 解析呼叫變成正常的使用繼承
    - bp1呼叫Base
    - bp2呼叫D1
    - bp3呼叫D2
# 15.7 建構器和拷貝控制
## 15.7.1 虛擬解構器
- [ ] 15.24: 何種類別需要虛擬解構器?一個虛擬解構器必須進行什麼作業
    - 有繼承階層架構的類別需要虛擬解構器(基礎類別會把解構器定義成虛擬的)
    - 假設有一個基礎類別Base和一個衍生類別Derived，以及一個指向基礎類別的指標p
    - 當我們delete p的時候，有可能是delete Derived類別，也有可能是delete Base類別，這時候Derived類別就會需要使用virtual的Base類別解構器
## 15.7.2 合成的拷貝控制與繼承
- [ ] 15.25: 我們為什麼為Disc_quote定義了一個預設建構器?移除那個建構器對Bulk_quote的行為有什麼影響(如果有的話)
    - 因為有定義拷貝建構器，所以不會自動合成預設建構器
    - 如果沒有預設建構器，Bulk_quote就不會自己合成預設建構器，因為他的基礎類別沒有
## 15.7.3 衍生類別的拷貝控制成員
- [ ] 15.26: 定義Quote和Bulk_quote的拷貝控制成員，進行與合成版本相同的工作。賦予它們與其他的建構器列印述句，以識別正在執行的是哪個函式。使用這些類別撰寫程式，並預測什麼物件會被創建或摧毀。把你的預測和輸出做比較，並持續實驗，值到你的預測正確為止
## 15.7.4 繼承的建構器
- [ ] 15.27: 重新定義你的Bulk_quote類別來繼承其建構器
# 15.8 容器與繼承
- [ ] 15.28: 定義一個vector存放Quote物件，但把Bulk_quote物件放到這個vector中。計算這個vector中所有元素的總net_price(淨價)
- [ ] 15.29: 重複你的程式，但這次儲存對型別Quote物件的shared_ptr。解釋這個版本所產生的總和與前一個程式不一致的地方，如果沒有偏差，就解釋為何沒有
## 15.8.1 撰寫一個Basket類別
- [ ] 15.30: 撰寫你自己版本的Basket類別，並用它來比較相同交易紀錄的價格，如前面練習所使用的那樣
# 15.9 重訪文字查詢
## 15.9.1 一個物件導向的解法
- [ ] 15.31: 給定了都是string的s1、s2、s3與s4，判斷下列運算式會創建出什麼物件
    ```
    // a
    Query(s1) | Query(s2) & ~ Query(s3);
    // b
    Query(s1) | (Query(s2) & ~Query(s3));
    // c
    (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
    ```
## 15.9.2 Query_base與Query類別
- [ ] 15.32: 當型別為Query的一個物件被拷貝、移動、指定或摧毀，會發生什麼事
    - Query只有一個shared_ptr資料成員且沒有定義自己的拷貝控制成員，因此拷貝、移動、指定、摧毀只會針對那個shared_ptr執行拷貝、移動、指定、摧毀
- [ ] 15.33: 那麼型別為Query_base的物件呢?
    - Query_base是個抽象基礎類別，有預設的拷貝、指定，移動不會定義會由拷貝執行，沒有資料成員，而且是純虛的，因此指涉這個類別的指針指涉的都是這個類別的衍生類別
## 15.9.3 衍生的類別
- [ ] 15.34: 對於在15.3中建置的運算式:
    ```
    // a 列出處理那個運算式的過程中所執行的建構器
    // b 列出從cout << q進行的rep呼叫
    // c 列出從q.eval()進行的eval呼叫
    ```
- [ ] 15.35: 實作Query與Query_base類別，包括rep的定義，但省略eval的定義
- [ ] 15.36: 在建構器和rep成員中放入列印述句，並執行你的程式碼來檢查第一個練習中你對a和b的答案
- [ ] 15.37: 如果衍生類別有型別`shared_ptr<Query_base>`而非Query的成員，你的類別需要做出什麼變更呢?
- [ ] 15.38: 下列的宣告是合法的嗎?如果不是，為什麼呢?如果是，請解釋該宣告的意義
    ```
    BinaryQuery A = Query("fiery") & Query("bird");
    AndQuery b = Query("fiery") & Query("bird");
    OrQuery c = Query("fiery") & Query("bird");
    ```
## 15.9.4 eval函式
- [ ] 15.39: 實作Query和Query_base類別。藉由估算並印出像圖15.3中那樣的一個查詢來測試你的程式
- [ ] 15.40: 在OrQuery的eval函式中，如果它的rhs成員回傳一個空集合，會發生什麼事?如果它的lhs成員這麼做，會發生什麼事?如果rhs和lhs都回傳空集合呢?
- [ ] 15.41: 重新實作你的類別，使用指向Query_base的內建指標，而非shared_ptr。記得你的類別將無法再使用合成的拷貝控制成員
- [ ] 15.42: 設計並實作下列的增強功能:
    ```
    // a
    僅一個句子印出一次字詞
    // b
    引入一個歷程系統，其中使用者能夠藉由數字參考之前的查詢，可能是對之進行增補，或將它與另一個查詢結合
    // c
    允許使用者限制結果範圍，如此只有給定範圍的文字行中的匹配會被顯示出來
    ```