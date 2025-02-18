#include<iostream>
using namespace std;

class Date
{
public:
    // // 无参构造函数
    // Date()
    // {
    //     _year = 0;
    //     _month = 0;
    //     _day = 0;
    // }

    // // 有参数构造函数
    // Date(int year, int month, int day)
    // {
    //     _year = year;
    //     _month = month;
    //     _day = day;
    // }

    // 全缺省
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
        cout<< "date" << this <<endl;
    }

    void Print()   // 隐含的this指针
    {
        cout<< _year << "_" << _month << "_" << _day <<endl;
    }

    // 一般的类 可以不写的
    ~Date()
    {
        cout<< "~Date" << this << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

class Stack
{
public:

    // 对象创建时自动调用 完成初始化工作
    Stack(int n = 0)
    {
        _a = (int*)malloc(sizeof(int)*n);
        _size = 0;
        _capacity = n;
    }
    // 对象生命周器到了以后 完成清理工作
    ~Stack()
    {
        free(_a);
        _a = nullptr;
        _size = _capacity = 0;
    }
private:
    int* _a;
    int _size;
    int _capacity;
};


class Date2
{
public:
    Date2(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator == (const Date2& d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator > (const Date2& d)
    {
        if(_year > d._year)
        {
            return true;
        }
        else if(_year == d._year && _month > d._month)
        {
            return true;
        }
        else if(_year == d._year && _month == d._month && _day > d._day)
        {
            return true;
        }
        return false;
    }

    Date2(const Date2& d)
    {   
        // 限制修改数据的权限  引用的本质就是常量指针  这里相当于就是一个指针指向这个数据。
        // d直接指向传入的数据 
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void Print()
    {
        cout<< _year << "-" << _month << "-" << _day <<endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

void func(Date)
{

    
}

class date
{
public:
    // 构造函数实现初始化的

    int GetMonthDay(int year, int month)
    {   
        // 一年当中的天数
        static int monthDays[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if((month == 2 &&(year % 4 == 0 && year % 100 != 0)) || year % 400 ==0)
        {
            return 29;
        }
        return monthDays[month];
    }

    date(int year = 0, int month = 0, int day = 0)
    {
        // _year = year;
        // _month = month;
        // _day = day;
        if(_year >= 0 && _month >= 1 && _month <= 12 && _day >=1 && _day <= GetMonthDay(year, month) )
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout<< "非法日期" <<endl; 
        }

    }

    // 拷贝构造实现
    date(const date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    // 运算符实现重载
    bool operator < (const date& d)
    {
        if(_year < d._year)
        {
            return true;
        }
        else if(_year == d._year && _month < d._month)
        {
            return true;
        }
        else if(_year == d._year && _month == d._month && _day < d._day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator == (const date& d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }


    bool operator <= (const date& d)
    {
        // 复用上面的来实现
        return *this < d || *this == d; 
    }

    bool operator >= (const date& d)
    {
        return !(*this < d);
    }

    bool operator != (const date& d)
    {
        return !(*this == d);
    }



private:
    int _year;
    int _month;
    int _day;
};

int main()
{
// 类的6个默认成员函数
// 默认构造函数 基本类型不回初始化的 对自定义类型会调用自己的构造函数初始化
// 默认构造函数 编译器生成的 全缺省 不写参数的 不传参就可以调用了
// 构造函数 初始化成员变量
// 默认构造函数可以实现函数重载的
    // Date d1;
    // d1.Print();
    // Date d2(2000, 2, 17);
    // d2.Print();

// 析构函数清理资源 例如动态开辟的空间 文件开闭 文件描述符
// 无参数无返回值 有且只有一个
// 后进先出来
// 默认析构函数 处理自定义类型的 基本类型不处理的
    // Date d1;
    // Date d2;

    // Stack s1;

// 内置类型不处理 自定义类型 调用它的构造、析构函数。


// 拷贝构造
    // Date2 d1(2000,2,10);
    // Date2 d2(d1); // 先传入参数
    // Date2 d3 = d1; //拷贝构造
    // d1.Print();
    // d2.Print();
    // d3.Print();

// 运算符重载
// 自定义类型比较大小 自己定义 
// 传参数有尽量const加引用
// operator
// 写成成员函数 这样方便访问成员变量的
// c++函数定了返回类型 就必须要有返回值的
// C++里面并不是所有的都能重载
    // Date2 d1(2000,2,10);
    // Date2 d2(2000,2,13);
    // d1 == d2;// d1.operator==(d2); 实际上是这样子 但是这里面 有一个隐含的tish指针 指向调用的数据
    // cout << (d1 == d2) <<endl;
    // cout << (d1 > d2) <<endl;



// 实现一个完善的日期类
    date d1(2025,2,11);
    date d2(2025,2,11);
// 日期类实现运算符重载
    // cout << (d1 > d2) <<endl;
    // cout << (d1 < d2) <<endl;
// 复用来实现




// 高内聚 低耦合



























    return 0;
}