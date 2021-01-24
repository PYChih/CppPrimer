# Exercise 12_20
>Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).

    - TextQurey
        - TextQurey有一個shared_ptr指向文件檔案，一個map，key是查詢的文字，value是一個set對應該文字的行號
        - 拷貝: shared_ptr指向的位置會被拷貝，會拷貝出一個shared_ptr
        - 指定: 同上
        - 刪除: shared_ptr
    - QueryResult
        - 一個String，兩個shared_ptr
        - string被拷貝、shared_ptr也被拷貝
    - 都是類似指標的行為，shared_ptr"指向的位置"被拷貝，然後參考計數遞增