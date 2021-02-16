# Exercise 16.11
> The following definition of List is incorrect. How would you fix it?
> as commented below.
```
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
    //         ^^^^^^^^^  -- template is not a type, the type must be provided
private:
    ListItem *front, *end;
//  ^^^^^^^^ -- template is not a type, the type must be provided
};
```
- replate `ListItem` to `ListItem<elemType>`