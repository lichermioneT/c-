#include<iostream>
using namespace std;

// 类里面可以定义成员变量，成员属性 成员方法,成员函数
class Steudent{

public:
    void showinfo()
    {
        cout<< _name <<endl;
        cout<< _age <<endl;
        cout<< _stduid <<endl;
    }
    



// 一般情况下成员变量都是比较私有的，都会定义成私有或者保护的
    char* _name;
    int _age;
    int _stduid;


};




int main()
{
    Steudent s1;
    s1._name = "lic";
    s1._stduid = 324;
    s1._age = 25;
    s1.showinfo();






































    return 0;
}