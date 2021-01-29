# Ch09_Sequential_Containers
###### tags: `C++ exercise`
[TOC]
# 9.1 循序容器總覽
- [ ] 9.1: 對於下列的程式任務，何者是最適當的?一個vector?一個deque或一個list?解釋你的選擇背後的原因。如果沒理由偏好任一種容器，也請解釋為什麼。
    ```
    // a: 讀取固定數目的字詞，在它們被輸入的過程中，以字母順序將它們插入到容器中。我們將在下一章看到，對於這種問題，關聯式容器會是較佳的解法。
    // 用list，因為會要隨機插入
    // b: 讀取未知數目的字詞。永遠都將新的字詞插入到尾端。從前端移除下一個值。
    // 用deque: 頭尾操作
    // c: 從一個檔案讀取未知數目個整數。排序這些數字，然後將它們印到標準輸出。
    // 用vector: 排序需要頻繁隨機訪問，排除list，不須頭尾操作，因此使用vector
    ```
# 9.2 容器程式庫概觀
- [ ] 9.2: 定義一個list，讓其中的元素是存放int的deque。
## 9.2.1 迭代器
- [ ] 9.3: 構成迭代器範圍的迭代器有什麼要求?
    ```
    // 它們指向同一個容器的元素，或超出尾端一個位置處。
    // 我們能夠藉由重複遞增begin來抵達end。
    ```
- [ ] 9.4: 寫一個函式接受指涉一個`vector<int>`的一對迭代器，以及一個int值。在該範圍中尋找那個值，並回傳bool指出是否有找到。
- [ ] 9.5: 改寫前面的程式來回傳一個迭代器指向所要求的元素。注意到這個程式必須處理沒有找到那個元素的情況。
- [ ] 9.6: 下列程式有什麼錯?你會如何更正之?
    ```
    list<int> lst1;
    list<int>::iterator iter1 = 1st1.begin(),
                        iter2 = lst1.end();
    while (iter1 < iter2)
    // list的迭代器不支持"<"喔
    // 改成(iter1 != iter2)
    ```
## 9.2.2 容器型別成員
- [ ] 9.7: 什麼型別應該被用作`int`組成的一個vector的索引?
    ```
    // vector<int>::iterator
    ```
- [ ] 9.8: 什麼型別應該用來讀取`string`組成的一個list的元素? 那寫入呢?
    ```
    // 讀:list<string>::const_reference
    // 寫:list<string>::reference
    ```
## 9.2.3 begin與end成員
- [ ] 9.9: begin和cbegin函式之間的差異為和?
    ```
    begin可能回傳iterator或是const_iterator
    cbegin一定回傳const_iterator
    ```
- [ ] 9.10: 下列四個物件的型別為何?
    ```
    vector<int> v1;  // vector<int>
    const vector<int> v2;  // const vector<int>
    auto it1 = v1.begin();  // vector<int>::iterator
    auto it2 = v2.begin();  // vector<int>::const_iterator
    auto it3 = v1.cbegin();  // vector<int>:: const_iterator
    auto it4 = v2.cbegin();  // vector<int>::const_iterator
    ```
## 9.2.4 定義和初始化一個容器
- [ ] 9.11: 為創建和初始化一個vector的六種方法都寫出一個例子。解釋每個vector會含有什麼值。
- [ ] 9.12: 解釋接受一個要拷貝的容器的建構器和接受兩個迭代器的建構器之間的差異。
    ```
    // 可以用別的容器的迭代器來建構另一個容器，只要裡面元素可以轉換，拷貝的建構器則無法
    ```
- [ ] 9.13: 你會如何以一個`list<int>`初始化一個`vector<double>`呢?那以一個`vector<int>`初始化呢?撰寫程式碼來檢查你的答案。
## 9.2.5 指定和swap
- [ ] 9.14: 寫一個程式來將一個list中的元素指定給一個vector，其中的list由char*指標組成，這些指標指向C-style的字元字串，而vector則是由string組成。
## 9.2.6 容器大小的運算
## 9.2.7 關係運算子
- [ ] 9.15: 寫一個程式來判斷兩個`vector<int>`是否相等。
- [ ] 9.16: 重複之前的程式，但將一個`list<int>`中的元素與一個`vector<int>`做比較。
- [ ] 9.17: 假設c1和c2是容器，下列用法在c1和c2的型別上設下了什麼限制(如果有的話)?
    ```
    if (c1<c2)  // c1和c2中的元素必須可以比較
    ```
# 9.3 循序容器的運算
## 9.3.1 新增元素至一個循序容器
- 練習9.18: 寫一個程式從標準輸入讀取一序列的string到一個deque中。使用迭代器撰寫一個迴圈來打印出這個deque中的元素。
- [ ] 9.19: 改寫前面練習的程式，改用一個list。列出你需要變更的地方
- [ ] 9.20: 寫一個程式從一個`list</int>`拷貝元素到兩個`deque`中。偶數值元素放到其中一個deque，而奇數的放到另一個。
- [ ] 9.21: 解釋前面使用insert的回傳值新增元素到一個list的迴圈如果改成插入到一個vector，那要如何才能運作`// 免改，只是性能變差`
- [ ] 9.22: 假設iv是由int組成的一個vector，那麼下列程式哪裡有誤呢?你會如何更正這些問題?
    ```
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    while (iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2*some_val);
    // 對iv插入元素，那iv的iter會失效
    // 兩個改法: 
    // 1. 利用insert回傳的iter，然後重設mid 
    // 2. 由於迭代次數已知，重寫迴圈
    ```
## 9.3.2 存取元素
- [ ] 9.23: 在本節的第一個程式中，如果c.size()是1，那val、val2、val3與val4的值會是什麼?
- [ ] 9.24: 寫一個程式使用at、下標運算子、front和begin擷取一個vector中的第一個元素，以一個空的vector測試你的程式。
## 9.3.3 清除元素
- [ ] 9.25: 在前面刪除了一個範圍元素的程式中，如果elem1和elem2相等，會發生什麼事?如果elem2或elem1與elem2兩者都是off-the-end迭代器呢?
- [ ] 9.26: 使用下列的ia定義，將ia拷貝到一個vector以及一個list中。使用單迭代器版的earse從你的list移除奇數值，並從你的vector移除偶數值
    ```
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    ```
## 9.3.4 專用的forward_list運算
- [ ] 9.27: 寫一個程式來尋找並移除一個`forward_list<int>`中的奇數值元素。
- [ ] 9.28: 寫一個函式接受一個`forward_list<string>`以及兩個額外的string引數。這個函式應該找到第一個string然後緊接著它，將第二個string插入到它後方。如果那第一個string沒找到，那麼就將第二個string插入串列的尾端。
## 9.3.5 調整一個容器的大小
- [ ] 9.29: 如果vec存有25個元素，那麼vec.resize(100)會做些什麼事呢?如果我們接著寫了vec.resize(10)會怎樣呢?
    ```
    vec變為100個元素，後面插入值初始化的vec元素，接著寫後會刪到只剩前10個元素
    ``` 
- [ ] 9.30: 如果有的話，接受單一引數的resize版本對元素型別有和限制呢?
    ```
    容器元素的類別不可以沒有預設建構器
    ```
## 9.3.6 容器運算可能使迭代器變得無效
- [ ] 9.31: 前面移除偶數數值元素並複製奇數值元素的程式在list或forward_list上是行不通的，為什麼呢?請修改程式讓它在這些型別上也可行。
    ```
    // list和forward_list的迭代器不支援+=
    ```
- [ ] 9.32: 前面程式如果把對insert的呼叫寫成下列這樣，是合法的嗎?如果不是，為什麼呢?
    ```
    iter = vi.insert(iter, *iter++);  // 先做*iter++還是先固定iter
    ```
- [ ] 9.33: 在本節的最後一個例子中，如果我們沒有把insert的結果傳給begin的話會怎樣?寫個省略此指定的程式來看看你的預期是否正確。
    ```
    照理說改動vector的元素會讓迭代器失效
    ```
- [ ] 9.34: 假設vi是int所組成的，包括偶數值和奇數值的一個容器，請預測下列迴圈的行為。在你分析過這個迴圈後，寫一個程式來測試你的預期是否正確。
    ```
    iter = vi.begin();
    while (iter != vi.end())
        if (*iter %2)
            iter = vi.insert(iter, *iter);
        ++iter;
    // while沒括號，讓++變成最後執行
    // 只要有奇數，就會無窮迴圈，insert是往前插入
    ```
# 9.4 vector的增長方式
- [ ] 9.35: 解釋一個vector的capacity和其size之間的差異
    ```
    // size就是現在有多少元素
    // capacity就是它現在可以容納多少元素
    ```
- [ ] 9.36: 一個容器可以有小於它size的capacity嗎
    ```
    // 不可以
    ```
- [ ] 9.37: 為什麼list或array沒有capacity成員呢?
    ```
    array就固定了，list不需要固定
    ```
- [ ] 9.38: 寫一個程式來探索在你所用的程式庫中vector如何成長。
- [ ] 9.39:解釋下列的程式片段做些什麼事:
    ```
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (cin >> word)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);
    // 確保svec可以裝1024個元素，
    // 用cin添加元素，
    // 最把svec的元素量變成總共有的元素+元素個數/2，
    // 用空字串裝滿
    ```
- [ ] 9.40:如果前一個練習中的程式讀取256個字詞，那麼在resize之後，它的capacity最有可能是什麼?如果讀了512個呢?那1000個?1048個呢?
    ```
    256: 1024
    512: 1024
    1000: 1024
    1048: 2048
    ```
# 9.5 額外的string運算
## 9.5.1 建構字串的其他方式
- [ ] 9.41: 寫一個程式從一個`vector<char>`初始化一個字串。
- [ ] 9.42: 假設你想要一次讀取一個字元到一個string中，而你知道你至少得讀取100個字元，那你會如何增進你程式的效能呢?
    ```
    string s(200, ' ');
    ```
## 9.5.2 修改字串的其他方式
- [ ] 9.43: 寫一個函式，它接受三個string、s、oldVal與newVal。使用迭代器以及insert和erase函式，將s中出現的所有oldVal都取代為newVal。用它來取代常見的縮寫，例如把"tho"取代為"though"或"thru"取代為"through"，藉此測試你的函式
- [ ] 9.44: 使用一個索引和replace改寫前一個函式
- [ ] 9.45: 撰寫一個函式，接受代表名稱的一個string和另外兩個string，分別代表一個前綴(prefix)，例如"Mr."或"Ms."，以及一個後綴(suffix)，例如"Jr"或"III"。使用迭代器和insert及append函式，產生並回傳一個新的string，其中後綴和前綴被加到了所給的名稱。
- [ ] 9.46: 使用一個位置和長度改寫前面的練習，以管理string。這次僅使用insert函式。``
    ```
    // insert: 
    // 接受索引的版本會回傳對s的參考
    // 接受迭代器的版本會回傳一個迭代器，代表所插入的第一個字元
    ```
## 9.5.3 string搜尋運算
- [ ] 9.47: 寫一個程式在"ab2c3d7R4E6"這個string中找出每個數值字元，然後每個字母字元。寫出兩個版本的此程式。第一個應該使用find_first_of，第二個用find_first_not_of
- [ ] 練習9.48:給定前面9.5.3的name和numbers定義。請問numbers.find(name)會回傳什麼呢?
    ```
    string name("AnnaBelle");
    string numbers("0123456789");
    numbers.find(name);  // return string::npos
    ```
- [ ] 9.49: 如果一個字母的某部分延伸到中線之上，我們就說這個字母有一個ascender(出頭部分)例如d或f；如果一個字母的某部分延伸到中線之下，我們就說這個字母有一個descender(伸尾部分)。寫一個程式讀取含有字詞的一個檔案，並回報既不含有ascender也沒有descender的最長字詞。
## 9.5.4 compare函式
## 9.5.5 數值轉換
- [ ] 9.50: 寫個程式來處理其元素代表整數值的一個`vector<string>`。產生該vector中所有元素的總和。修改此程式，讓它加總代表浮點數值的string。
- [ ] 9.51: 寫出具有三個unsigned成員分別代表年、月、日的一個類別。撰寫一個建構器，接受一個代表日期的string。你的建構器應該處理各種日期格是，例如January 1, 1900、1/1/1900、Jan 1, 1900等等
# 9.6 容器轉接器
- [ ] 9.52: 使用一個stack來處理帶括號的運算式。當你看到一個左括號，就記錄下來。當你在左括號之後看到一個右括號，就將頂端往下一直到左括號的元素都從stack中pop出來。push一個值到stack上，代表一個帶括號的運算式已被取代。