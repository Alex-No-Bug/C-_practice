#include<iostream>//�������Ĺ��캯��
#include<string.h>
using namespace std;
class Student
{
public:
    Student(char*name,int hour,float grade)//���캯��
    {
        strcpy(m_name,name);//me��ֵ�������ַ������ƺ���
        m_name[sizeof(name)]='\0';
        m_hour=hour;m_grade=grade;
    }
    void print()
    {
        cout<<"name:"<<m_name<<" "<<"hour:"<<m_hour<<" "<<"grade:"<<m_grade<<endl;
    }
protected:
    int m_hour;//��������
    float m_grade;
    char m_name[10];
};
int main()
{
Student ss("Tom",20,4.6);//�����˫����
ss.print();
    return 0;
}
