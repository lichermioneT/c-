#include<iostream>
// c++库里面所有的东西都是放在std命名空间里面的
// 日常联系不在乎跟库命名冲突
using namespace std;  // 直接展开



// 缺省参数
void func0(int a = 10)
{
    cout<< a <<endl;
}

// 全缺省
void func1(int a = 10, int b = 20, int c = 30)
{
    cout<< "a = " << a <<endl;
    cout<< "a = " << b <<endl;
    cout<< "a = " << c <<endl;
}

// 半缺省
void func2(int x, int y = 10)
{
    cout<< "x = " << x <<endl;
    cout<< "y = " << y <<endl;
}

// 函数重载 函数名相同 函数参数不同的 类型、顺序、个数
// 返回值不能作为区别的 
void func()
{
    cout<< "hhhhhhhh" <<endl;
}

void func(int x, int y)
{
    cout<< x <<endl;
    cout<< y << endl;
}

void func(int x)
{
    cout<< x <<endl;
}

void func(int x, float y)
{
    cout<< x <<endl;
    cout<< y << endl;
}


int main()
{
    // cout<< "hello world\n";
    // cout<< "hello world" <<endl;;

    // int i = 1;
    // double d = 2.1;

// 自动识别 通过函数重载实现
/*
character output
*/
    // cout<< "i = " << i <<endl;
    // cout<< "d = " << d <<endl;


// 输入流
/*
character input
*/
    // cin >> i;
    // cin >> d;

    // cout<< "i = " << i <<endl;
    // cout<< "d = " << d <<endl;


// 缺省参数
    //参数必须从左向右依次传递
    // func0();
    // func0(11);
    // func0(1000);

    // func1();
    // func1(10, 20);
    // func1(20, 20, 30);

    // func2(10);
    // func2(10, 30);



// 函数重载
    // 参数类型
    // 参数个数
    // 参数顺序
    // func();
    // func(10, 20);
    // func(10, 20.5f);

// extern "C"

// 引用也就是别名 给变量取一个其它的的名称
    // int a = 10;
    // int& ra = a;

    // ra = 100;
    // cout<< a <<endl;

    // a = 55;
    // cout<< a <<endl;

    // int& b = a;
    // b = 66;
    // cout<< a <<endl;

    // int& c = a;
    // c = 88;
    // cout<< a <<endl;

    // cout<< &a << endl;
    // cout<< &ra << endl;
    // cout<< &b << endl;
    // cout<< &c << endl;

    // int a = 1;
    // int& c = a;
    // int d = 2;
    // c = d;

    // cout<< &c <<endl;
    // cout<< &a <<endl;
    // cout<< &d <<endl;


// 取别名过后的权限 读写的更改
    // const int a = 10;
    // const int& b = a;
    // cout<< b <<endl;    

    // int c = 1;
    // int& d = c;
    // const int& e = c;

// 隐式类型转化
    int i = 0;
    double db = i; // 隐式类型转换  里面有个临时变量
    const double& rd = i; // 临时变量具有常量属性
    const float& rf = i;  // 临时变量具有常量属性








    return 0;
}