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
    size_t begin1 = clock();
    for(size_t i = 0; i < 10000; i++)
        testfunc1();
    size_t endl = clock();

    for(size_t i = 0; i < 10000; i++)
        testfunc2();

    size_t end2 = clock();
































    return 0;
}