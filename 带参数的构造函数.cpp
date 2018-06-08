#include<iostream>//带参数的构造函数
#include<string.h>
using namespace std;
class Student
{
public:
    Student(char*name,int hour,float grade)//构造函数
    {
        strcpy(m_name,name);//me赋值，调用字符串复制函数
        m_name[sizeof(name)]='\0';
        m_hour=hour;m_grade=grade;
    }
    void print()
    {
        cout<<"name:"<<m_name<<" "<<"hour:"<<m_hour<<" "<<"grade:"<<m_grade<<endl;
    }
protected:
    int m_hour;//保护声明
    float m_grade;
    char m_name[10];
};
int main()
{
Student ss("Tom",20,4.6);//必须加双引号
ss.print();
    return 0;
}
