#include<iostream>
using namespace std;
class Stock//声名股票类
{
public:
    Stock()
    {
        company_mark=000;shares=0;share_value=0;calculate();//不带参数的构造函数，初始化
    }
    void acquire(double xcompany,double n,double pr);
    void sell(double num,double price);
    void buy(double num,double price);
    void calculate()//计算股票总价值
    {
        total_value=shares*share_value;
    }
    void show();//展示函数
private:
    double shares;double share_value;double total_value;double company_mark;
};
void Stock::acquire(double xcompany,double n,double pr)//初始买入股票的状况
{
    if(n>0)//保证为正数
    {
        company_mark=xcompany;
        shares=n; share_value=pr; calculate();
    }
    else
    {
        cout<<"Number can not be negative!"<<endl;
    }
}
void Stock::sell(double number,double price)//卖出函数
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
void Stock::buy(double number,double price)//买进函数
{
    if(number<0)
    {cout<<"Number can not be negative!"<<endl;}
    else{shares=shares+number;share_value=price;calculate();}
}
void Stock::show()//显示出个项
{
    cout<<"company mark is:"<<company_mark<<'\n'<<"total_value:"<<total_value<<endl;
}
int main()
{
    int flag;
    Stock Tom;//定义股票为tom买的
    Tom.show();//显示出初始化内容
    Tom.acquire();
    return 0;
}
