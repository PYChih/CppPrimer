# ch12_Dynamic_memory
###### tags: `C++ exercise`
[TOC]
# 12.1 動態記憶體與智慧指標
## 12.1.1 shared_ptr類別
- [ ] 12.1: 在這段程式碼最後，b1和b2會有多少個元素?
    ```
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"}; 
        b1 = b2;
        b2.push_back("about");
    }
    ```
- [ ] 12.2: 寫出你自己版本的StrBlob類別，包括const版的front和back
- [ ] 12.3: 這個類別需要const版本的push_back和pop_back嗎?如果是，就新增它們，如果不需要，為何呢?
- [ ] 12.4: 在我們的check函式，我們沒有檢查i是否大於零。為什麼省略該檢查不會有問題呢?
- [ ] 12.5: 我們並沒有讓接受一個initializer_list的建構器是explicit的。討論這種設計決策的優缺點
## 12.1.2 直接管理記憶體
- [ ] 12.6: 寫一個函式回傳一個動態配置的，由int所構成的vector。將那個vector傳入給另一個函式，它會讀取標準輸入來賦予那些元素值。將那個vector傳入另一個函式來印出我們讀到的值。記得在適當的時機delete那個vector
- [ ] 12.7: 重作前面的練習，這次使用shared_ptr
- [ ] 12.8: 說明下列函式是否哪裡有錯
    - memory leak
- [ ] 12.9: 解釋下列程式碼會做什麼事
    - 比較new和make_shared
## 12.1.3 併用shared_ptr與new
- [ ] 12.10: 解釋下列對前面的process函式的呼叫是否正確。如果不是如何更正
    - 沒毛病，先建了一個shared_ptr，傳到function處理shared_ptr，取用shared_ptr
- [ ] 12.11: 如果我們像這樣呼叫process，會發生什麼事
    - 使用get後的pointer再創建一個shared_ptr，造成兩個獨立的shared_ptr指向相同記憶體，並且其中一個離開函數後被刪除
- [ ] 12.12: 使用p和sp的宣告來解釋下列對process的呼叫，如果呼叫是合法的，請說明它做些什麼事。如果不是，請解釋原因
- [ ] 12.13: 如果我們執行下列程式碼，會發生什麼事?
    - 不要delete get之後的pointer(程式結束會double free)
## 12.1.4 智慧指標和例外
- [ ] 12.14: 撰寫你自己版本的函式來使用一個shared_ptr管理connection。
- [ ] 12.15: 改寫第一個練習，使用一個lambda取代end_connection函式
    - [ ] 使用unique_ptr管理connection。
## 12.1.5 unique_ptr
- [ ] 12.16: 當我們試著拷貝或指定一個unique_ptr，編譯器並不總是會給出容易理解的錯誤訊息。寫一個含有這些錯誤的程式，看看你編譯器的診斷資訊。
- [ ] 12.17: 下列哪些`unique_ptr`的宣告是合法的，或可能導致後續的程式錯誤?解釋每一個的問題所在。
- [ ] 12.18: 為什麼shared_ptr沒有release成員呢?
## 12.1.6 weak_ptr
- [x] 12.19: 定義你自己版本的StrBlobPtr並更新你的StrBlob，加上適當的friend宣告，以及begin和end成員
- [x] 12.20: 寫一個程式讀取一個輸入檔案，一次讀取一行到一個StrBlob中，並使用一個StrBlobPtr來印出那個StrBlob中的每個元素。
- [x] 12.21: 我們可以把StrBlobPtr的deref成員寫成這樣:
    ```
    std::string& deref() const
    { return (*check(curr, "dereference past end"))[curr]; }
    ```
    你認為哪個版本比較好，為什麼呢?
- [x] 12.22: 要對StrBlobPtr做出什麼變更，以創建一個能與const StrBlob合用的類別?定義一個名為ConstStrBlobPtr，可以指向const StrBlob的類別。
# 12.2 動態陣列
## 12.2.1 new與陣列
- [ ] 12.23: 寫一個程式來串接兩個字串字面值，將結果放到一個動態配置的char陣列中。寫一個程式來串接兩個程式庫string，它們的值跟第一個程式中使用的字面值一樣。
    - [ ] 熟悉一下字串字面值
- [ ] 12.24: 寫一個程式從標準輸入讀取一個字串到一個動態配置的字元陣列中。描述你的程式如何處理大小不定的輸入。給予你的程式一個長度超過你所配置的陣列的字串資料，藉此測試它。
- [ ] 12.25: 給予下列的new運算式，你會怎麼delete pa呢?`int *pa = new int[10];`
## 12.2.2 allocator類別
- [ ] 12.26: 使用allocator寫一個程式從標準輸入讀取一個string到一個動態配置的string陣列中
# 12.3 使用程式庫: 一個文字查詢程式
## 12.3.1 此查詢程式之設計
- [ ] 12.27: TextQuery和QueryResult類別只會用到我們已經涵蓋過的功能。先別往前看，寫出你自己版本的這些類別
- [ ] 12.28: 寫一個程式來實作文字查詢，但不定義類別來管理資料。你的程式應該接受一個檔案，並與使用者互動，以查詢那個檔案中的字詞。使用vector、map與set容器來存放該檔案的資料，以及產生查詢的結果。
- [ ] 12.29: 我們其實可以把用來管理使用者互動的迴圈寫成一個do while。改寫那個迴圈，使用do while。請解釋你偏好哪個版本以及原因
## 12.3.2 定義查詢程式類別
- [ ] 12.30: 定義你自己版本的TextQuery和QueryResult類別，並執行runQueries函式。
- [ ] 12.31: 如果我們使用一個vector而非一個set來存放行號，會有什麼差異呢?哪個做法比較好，為什麼。
    - 一行出現多次word的時候會重複印出
- [ ] 12.32: 改寫TextQuery和QueryResult類別，使用一個StrBlob而非一個`vector<string>`來存放輸入檔案。
    - [ ] 使用StrBlob+StrBlobPtr
- [ ] 12.33: 在第15章中，我們會擴充我們的查詢系統，並且會需要在QueryResult類別中添加一些額外的成員。新增名為begin和end成員，它們會回傳迭代器指向一個給定的查詢所回傳的行號set中，以及一個名為get_file的成員，回傳一個shared_ptr指向QueryResult物件中的檔案。
    - [ ] 使用StrBlob+StrBlobPtr