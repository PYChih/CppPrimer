# Exercise 15.32
> What happens when an object of type Query is copied, moved, assigned, and destroyed?
- Query只有一個shared_ptr資料成員且沒有定義自己的拷貝控制成員，因此拷貝、移動、指定、摧毀只會針對那個shared_ptr執行拷貝、移動、指定、摧毀