// #include<iostream>
// using namespace std;

// // 类里面可以定义成员变量，成员属性 成员方法,成员函数
// // 访问限定符

// // 类的声明 类似构建图纸并没有实际创建项目
// class Stack
// {
//     // 成员函数
//     // 成变量
// public:
//     void Push(int x) // 函数定义在类里面
//     {

//     }
//     void Pop(); // 函数定义在类的外面
//     // void empty();

// private:
//     int* _a;
//     int _size;
//     int _capacity; // 这里面都是声明
// };


// // 外面定义类的成员函数 注意域名解析
// void Stack::Pop()
// {

// }


// class Date
// {
// public:
//     void Init(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day; // 隐含的this指针 为什么能够访问成员变量
//     }

//     void Print()   // 隐含的this指针
//     {
//         cout<< _year << "_" << _month << "_" << _day <<endl;
//     }

// // 成员变量私有
// private:
//     int _year;
//     int _month;
//     int _day;
// };

// class A
// {
// public:
//     void PrintA()
//     {
//         cout<< _a <<endl;
//     }

//     void Show()
//     {
//         cout<< "Show()"<<endl;
//     }
// private:
//     int _a;
// };



// int main()
// {

// // 实例化出对象,相当于定义出了类的成员变量成员属性
//     Stack s1;
//     Stack s2;
//     Stack s3;
//     Stack s4;
//     s1.Push(2);

// // 类的实例化的对象只存储成员变量 不存储成员函数
// // 函数在代码区
// //  一个对象实例化N个对象，每个对象的成员变量都可以存储不同的值，但是调用的函数确是同一个的
// // 如果每个类里面都存放函数 函数都是一样的 浪费空间的
//     // cout<< sizeof(s1) <<endl;
//     // cout<< sizeof(Stack) <<endl; 
// // 内存对其规则
// // 没有成员变量的类的大小是1 



// // 隐含的this指针 
// // 访问限定符只能访问外面的数据访问
// // this是谁调用这个成员函数 this就指向谁
//     Date d1;
//     d1.Init(2025, 2, 15);
//     d1.Print(); // 谁调用就把谁的地址传入进去

// // 函数没有存放在对象里面的
//     A* p = NULL;
//     // p->PrintA(); // 程序崩溃的
//     // p->Show();

//     return 0;
// }





#include<iostream>
using namespace std;

// class Date
// {
// public:

//     // 自动调用函数 完成初始化数据
//     Date(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     // 构造函数的重载
//     Date()
//     {
//         _year = 0;
//         _month = 1;
//         _day = 1;
//     }

//     void Init(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day; // 隐含的this指针 为什么能够访问成员变量
//     }

//     void Print()   // 隐含的this指针
//     {
//         cout<< _year << "_" << _month << "_" << _day <<endl;
//     }

// // 成员变量私有
// private:
//     int _year;
//     int _month;
//     int _day;
// };



class Time
{
public:
    Time()
    {
        _hour = 0;
        _minute = 0;
        _second = 0;
        cout<< 6666 <<endl;
    }

private:
    int _hour;
    int _minute;
    int _second;
};

class Date1
{
public:
    // 编译器默认的无参 默认构造函数

    // 构造函数的更新
    // 小心两个缺省函数的歧义 
    // 无参数构造函数和全缺省构造函数都称为默认构造函数，默认构造函数只能有一个的
    Date1(int year = 0, int month = 1, int day = 1)
    {
        cout<< "Date1" <<endl;
        _year = year;
        _month = month;
        _day = day;
    }

    void Init(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day; // 隐含的this指针 为什么能够访问成员变量
    }

    void Print()   // 隐含的this指针
    {
        cout<< _year << "_" << _month << "_" << _day <<endl;
    }
    void Print_arr()
    {
        cout<< arr[0] <<endl;
        cout<< arr[2] <<endl;
        cout<< arr[1] <<endl;
    }

    ~Date1()
    {
        cout<< "~Date1" <<endl;
    }
// 成员变量私有
private:
    int _year;
    int _month;
    int _day;
    int arr[10];
    Time _t;
};

int main()
{
// 万一忘了初始化数据 是很危险的
  
// 默认成员函数 6个
// 构造函数 在对象构造时调用的函数，这个函数完成初始化工作
    // Date d1(2000,2,10);
    // d1.Print();
    
    // d1.Init(2000,2,11);
    // d1.Print();

    // Date d2;  // 这里只需要正常实例化类即可 不能添加括号的  函数重载使用
    // d2.Print();

// 默认生成的无参构造函数 双标狗c++
// 1针对内置类型的成员变量没有做处理
// 2针对自定义类型的成员变量，调用它的构造函数初始化
    // Date1 d1; // 编译器生成的构造函数 
    // d1.Print();




// 全缺省函数构造函数
    // Date1 d1;
    // d1.Print();

    // Date1 d2(2,2,3);
    // d2.Print();

// 默认构造函数 
// 自己实现无参的构造函数
// 自己实现全缺省函数
// 编译器自动生成的构造函数
// 特点不用传参数


// 析构函数  对象生命周器结束 自动调用 完成清理工作 ，不是完成的d1,d2的销毁
// 完成对象里面的资源清理 数据结构的开辟的空间
// 程序完成了 直接实现清理
    Date1 d1;
    Date1 d2;




































    return 0;
}

































































