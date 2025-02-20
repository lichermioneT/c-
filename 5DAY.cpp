#include<iostream>
using namespace std;

// 复习
// 六个默认成员函数
// 不实现 编译器默实现

// 构造函数 初始化
// 析构函数 清理工作
// 内置类型不处理 自定义类型会调用这个成员的构造和析构函数


// 拷贝构造 类实现同步
// 赋值重载
// 浅拷贝：将对象按字节一个一个拷贝过去
// 编译器默认生成的够用 

// 深拷贝：

class stack
{
private:
    int* _a;
    size_t _size;
    size_t _capacity;

public:
    // 构造函数 数据初始化
    // 构造函数 推荐全缺省
    stack(int n = 0)
    {
        _a = (int*) malloc(sizeof(int)*n);
        _size = 0;
        _capacity = n;

    }

    // 析构函数 数据清理工作
    ~stack()
    {   
        if(_a != nullptr)
        {
            free(_a);
            _a = nullptr;
            _size = _capacity = 0;
        }
      
    }



};
// class date
// {
// private:
//     int _year;
//     int _month;
//     int _day;

// public:
//     // 构造函数
//     date(int year = 0, int month = 1, int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     // 拷贝构造
//     date(const date& d)
//     {
//             _year = d._year;
//             _month = d._month;
//             _day = d._day;
//     }

//     //  等于运算符重载实现赋值
//     //  运算符重载 是为了让自定义类型 像内置类型一样使用
//     //  赋值运算
//     // d2 = d1 就是 d2.operator(this, d1)  this就是d2的地址
//     // d2 = d1 的返回值是d2才能支持连等 d3 = d2 = d1
//     date& operator=(const date& d)
//     {
//         if( this != &d)
//         {
//             _year = d._year;
//             _month = d._month;
//             _day = d._day;
//         }
//         return *this; // 出去作用域 数据还在使用引用返回
        
//     }

//     void print()
//     {
//         cout<< _year << " - " << _month << " - " << _day <<endl;
//     }
//     // 析构函数
//     ~date()
//     {

//     }


// };
// 自定义类型传参数和返回值，在可以的情况下，尽量使用引用，减少拷贝使用  
// 引用就是数据别名 就是数据的常量指针 

class date
{
private:
    int _year;
    int _month;
    int _day;
public:

    // 判断是不是闰年 并且返回月份
    int GetMonthDay(int year,int month)
    {
        static int monthDays[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((year % 4 == 0 && year % 100 != 0) || year % 400 ==0)
        {
            return 29;
        }
        else
        {
         return monthDays[month];
        }
    }
    
    // 构造函数实现初始化
    date(int year = 0, int month = 1, int day = 1)
    {
        if(day>=1&& month <= 12 && day <=GetMonthDay(year, month)&& year >= 0)
        {
            this->_year = year;
            this->_month = month;
            this->_day = day;
        }
        else
        {
            cout<<"日期初始化有误"<<endl;
        }
    }

    // 实现赋值运算 为了实现连续赋值 这里面函数的返回值类型！
    date operator = (const date& d)
    {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
        return *this; // this只是一个指针
    }

    bool operator >(const date& d)
    {
        if(this->_year > d._year)
        {
            return true;
        }
        else if(this->_year == d._year && this->_month > d._month)
        {
            return true;
        }
        else if(this->_year == d._year && this->_month > d._month && this->_day > d._day)
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
        return this->_year == d._year && this->_month == d._month && this->_day == d._day;
    }

    bool operator<(const date& d)
    {
        // return !(*this > d || *this == d);
        return !(this->operator>(d)||this->operator==(d));
    }

    bool operator != (const date& d)
    {
        return !(this->operator==(d));
        // return !(*this==d);
    }

    bool operator>=(const date& d)
    {
        return !(this->operator<(d));
        return !(*this < d);
    }

    bool operator<=(const date& d)
    {
        return !(this->operator>(d));
        return !(*this > d);
    }

    date& operator + (int day)
    {
        date ret = *this;
        ret._day += day;
        while (ret._day > GetMonthDay(ret._year,ret._month))
        {
            ret._day -= GetMonthDay(ret._year, ret._day);
            ret._month++;
        }
        

    }
    
  











































    ~date()
    {
        // cout<< "析构函数实现函数资源清理" <<endl;
    }

    // 拷贝构造 这里
    date (const date& d)
    {   
       if(this != &d)
       {
            this->_year = d._year;
            this->_month = d._month;
            this->_day = d._day;
       }

    }
































    void print()
    {
        cout<< _year << "-" << _month << "-" << _day <<endl;
    }

};





int main()
{
    // date d1(2000,20,10);
    // date d2(d1); // 构造d2的时候用d1去初始化
    // date d3;
    // d3 = d1; // 两个对象都已经存在都初始化好了，现在我想把d1的数据拷贝给d3
    // date d5 = d1; // 拷贝构造 用d1的数据初始化d5

/*
    int i = 0;
    j = 1;
    k = 2;
    i = j = k; 连续赋值 k先赋值给j 返回值j在赋值给i。
*/

    // date d5;
    // date d6;
    // d6 = d5 = d1; // 连续赋值 
    

    // date d1(2000,2,10);
    // date d2(2000,2,11);
    // d1 = d2;

    // d1.print();
    // d2.print();
    
    // date d3(d2);
    // d3.print();


// 浅拷贝问题 值拷贝
// 指针并且给它开了空间  析构函数现实空间的两次释放
// 解决深拷贝

    date d1(2000,2,10);
    date d2(2000,2,11);
    
    cout<< (d1 == d2) <<endl;




















    return 0;
}