#include<iostream>
using namespace std;
class Stock//������Ʊ��
{
public:
    Stock()
    {
        company_mark=000;shares=0;share_value=0;calculate();//���������Ĺ��캯������ʼ��
    }
    void acquire(double xcompany,double n,double pr);
    void sell(double num,double price);
    void buy(double num,double price);
    void calculate()//�����Ʊ�ܼ�ֵ
    {
        total_value=shares*share_value;
    }
    void show();//չʾ����
private:
    double shares;double share_value;double total_value;double company_mark;
};
void Stock::acquire(double xcompany,double n,double pr)//��ʼ�����Ʊ��״��
{
    if(n>0)//��֤Ϊ����
    {
        company_mark=xcompany;
        shares=n; share_value=pr; calculate();
    }
    else
    {
        cout<<"Number can not be negative!"<<endl;
    }
}
void Stock::sell(double number,double price)//��������
{
    if(number<0)
    {
        cout<<"Number can not be negative !"<<endl;
    }
    else if(number>shares)
    {
        cout<<"You can not sell stocks more than you have "<<endl;
    }
    else
    {
        shares=shares-number;
        share_value=price;
        calculate();
    }
}
void Stock::buy(double number,double price)//�������
{
    if(number<0)
    {cout<<"Number can not be negative!"<<endl;}
    else{shares=shares+number;share_value=price;calculate();}
}
void Stock::show()//��ʾ������
{
    cout<<"company mark is:"<<company_mark<<'\n'<<"total_value:"<<total_value<<endl;
}
int main()
{
    int flag;
    Stock Tom;//�����ƱΪtom���
    Tom.show();//��ʾ����ʼ������
    Tom.acquire();
    return 0;
}
