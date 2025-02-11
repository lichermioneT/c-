#include<iostream>
#include<time.h>
using namespace std;

// static修饰的是变量的声明周期
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap_c(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 引用在解引用直接就编译器帮你解决了的
// 这里面引用没有开空间 直接引用指向传入参数的空间
void swap_cpp(int& r1, int& r2) // 直接把数据的权限传入给r1,r2
{
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int count1()
{
    static int n = 0;
    n++;
    return n; // 返回临时变量 相当于数据的临时拷贝
}

int& count2()
{
    static int n = 0; // 只会执行一次的  不论函数调用多少次
    n++;
    return n; // 返回的是临时变量的引用
}

int c ;
int& add(int a, int b)
{
    c = a + b;
    return c;
}


struct A
{
    int a[10000];
};

struct A a;
A testfunc1()
{
    return a;
}


A& testfunc2()
{
    return a;
}

// 在调用处展开 不建立栈帧
// 频繁调用的小函数
// inline 空间换时间
// 具体实现还是要看编译器
inline int addx(int left, int right)
{
    return left + right;
}

void func(int n)
{
    cout<< "整型" <<endl;

}

void func(int* n)
{
    cout<< "整型指针" <<endl;
    
}

int main()
{
// 简单理解引用就是给空一块空间取别名
    // int a = 10;
    // int& b = a;
    // int& c = b;
    // cout<< "a的地址是," << &a <<endl;
    // cout<< "b的地址是," << &b <<endl;
    // cout<< "c的地址是," << &c <<endl;

    // int x = 55;
    // c = x;
    // cout << a <<endl;

// 权限  简单理解const修饰只能是读 不能修改的
// 权限只能缩小 不能放大的
    // int a = 10;
    // const int& b = a;
    // cout<< b <<endl;

// 常量指针
    // int num = 100l;
    // int * const p = &num; // 常量指针必须初始化的
    // *p = 55;
    // cout<< num <<endl;

    // const int x = 10;
    // int y = x; // 这里面代码只是读取了x的数据 但是不是影响原来x的

    // int z = 20;
    // const int r = z; // 这里面r也只是读取z里面的数据  也没有修改权限的

// 指针的权限
    // const int a = 10;
    // const int& b = 20;
    // int c = 20;

    // int& d = c;
    // const int* cp1 = &a; // 这里面不能修改指向的数据
    // // int* p1 = cp1; // 不能的 权限的放大 

    // int* p2 = &c;
    // const int* cp2 = p2; // 可以的这里面的指向的数据只能是只读的


// 引用的使用场景 
// 引用做函数参数
    // int a = 0;
    // int b = 1;

    // swap_c(&a, &b);
    // cout<< a <<endl;
    // cout<< b <<endl;

    // swap_cpp(a, b);
    // cout<< a <<endl;
    // cout<< b <<endl;

// 引用作为函数返回值
// 实际上是返回空间的别名 注意函数返回值的的权限
    // const int& num = count1(); // 接收临时变量的常属性
    // int& ri = count2();
    // cout<< num <<endl;
    // cout<< ri <<endl;

    // int& ret = add(1,2);
    // add(3,4);
    // cout<< "add(1, 2) is " << ret <<endl;

// 函数使用引用返回 那么返回的变量出了函数的作用域还存在 就可以使用引用返回 否则不安全的

// 函数性能测试  

// 指针和引用的区别
    // 引用相对来说安全一些的
    // int a = 10;
    // int& b = a; // b就是a的别名 不用开辟空间的
    // int* p = &a; // 开辟一个指针变量存放a的地址 解引用可以找到a

    // a = 100;
    // cout<< b <<endl;
    // cout<< *p <<endl;

    // int* const pi = &a;
    // *pi = 55;

    // cout<< b <<endl;
    // cout<< *p <<endl;
    // cout<< *pi <<endl;

    // cout<< sizeof(b) <<endl;

// 内联函数
    // 频繁调用函数是有消耗的
    // c语言使用宏函数 宏函数不用建立
    // c++使用内联函数
    // int ret = addx(3,5);

// auto关键字  自动推导变量
    // int a = 10;
    // auto b = a; // b的类型是根据a的类型推导出是int
    // auto c = 'a';
    // int& t = a;
    // auto& d = a;
    // auto* e = &a;
    // auto f = &a;

    // cout<< typeid(a).name() <<endl;
    // cout<< typeid(b).name() <<endl;
    // cout<< typeid(c).name() <<endl;
    // cout<< typeid(t).name() <<endl;
    // cout<< typeid(d).name() <<endl;
    // cout<< typeid(e).name() <<endl;
    // cout<< typeid(f).name() <<endl;

    // auto x = 10;       // x 被推导为 int
    // auto y = 3.14;     // y 被推导为 double
    // auto z = "hello";  // z 被推导为 const char*

    // const auto a = 10;       // a 被推导为 const int
    // auto& b = a;             // b 被推导为 const int&
    // auto c = b;              // c 被推导为 int（去掉了 const 和引用）

// 范围for 类似遍历数据 自动数据
// 范围for 使用数组变量
    // int array[] = {1,2,3,4,5};
    // c语言实现的方法
    // for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    // {
    //     array[i] *= 2;
    // }

    // for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    // {
    //     cout<< array[i] <<endl;
    // }

    // c++ 的范围for
    // for(auto& e : array) // 自动推出e的类型  取出数据给一个别名 这样就操作了数据
    // {
    //     e *= 2;
    // }

    // for(auto e : array)
    // {
    //     cout<< e <<endl;
    // }

// c++    nullptr指针
// c++里面直接定义就是宏定义00
    int* p1 = NULL;
    int* p2 = nullptr; // c++里面推荐的空指针
    func(0);
    
    func(nullptr);









































    return 0;
}