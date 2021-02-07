# Exercise 15.02
> How does the protected access specifier differ from private?
- 衍生類別就像基礎類別的使用者一樣，不能取用基礎類別的private成員
- 但有時候會希望衍生類別可以取用，這時候就可以把成員定義成protected
- 使用者不能取用protected也不能取用private
- 但衍生類別可以取用protected，一樣不能取用private
- 基礎類別的friend也可以取用protected
- private member: base class itself and friend can access
- protected members: base class itself, friend and derived classes can access