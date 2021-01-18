# Exercise_13_04
> Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
```
Point global;
Point foo_bar(Point arg) // 1:non const param
{
    Point local = arg, *heap = new Point(global) ; // 2 copy initial, ??
    *heap = local; // 3
    Point pa[ 4 ] = { local, *heap }; // 4, 5
    return *heap; //6
    }
```