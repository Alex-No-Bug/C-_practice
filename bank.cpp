#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>//3名用户   4位密码  4位账号
using namespace std;
class account
{
    int i,j;
public:
    account()//无参数的构造函数
    {
        strcpy(number,"123");
        for(i=0; i<4; i++)
            pass[i]=0;
        balance=0;
    }
    void get_account(char number1[4],int pass1[4],double balance1=0)//构造函数
    {
        strcpy(number,number1);
        number1[3]='\0';
        for(i=0; i<4; i++)
            pass[i]=pass1[i];
        balance=balance1;
    };
    virtual void withdraw(double m);//取款   虚函数
    void desposit(double m);//存款
    void display();//显示
    void changepass();
protected://必须用保护类！!笔记记下来为何protected
    char number[4];
    int pass[4];
    double balance;
};
void account::withdraw(double m)//取款!!!删去virtual
{
    if(m>balance)
    {
        cout<<"余额不足"<<endl;
    }
    else
        cout<<"请取款"<<endl;
}
void account::desposit(double m)//存款
{
    balance+=m;
    cout<<"存款："<<balance<<endl;
}
void account::changepass()//修改密码，，
{
    int pass2[4];
    int i,j;
    int flag=0;
    while(flag==0)
    {
        cout<<"请输入密码："<<endl;
        for(i=0; i<4; i++)
        {
            pass[i]=getch();
            putchar('*');
        }
        system("CLS");//清屏函数
        cout<<"请确认："<<endl;
        for(i=0; i<4; i++)
        {
            pass2[i]=getch();
            putchar('*');
        }
        for(j=0; j<4; j++)
        {
            if(pass[j]!=pass2[j])//修改未成功
            {
                flag=0;
                break;
            }
            else
                flag=1;
        }
    }
}

class credit:public account//子类信用卡
{
    int i;
public:
    credit()//无参数的
    {
        strcpy(number,"123");
        for(i=0; i<4; i++)
            pass[i]=0;
        balance=0;
        over_draft=0;
    }
    void get_credit(char number1[4],int pass1[4],double balance1,double over_draft1)//:get_account(number1,pass1,balance1)//此处有bug，，仔细看看书上的,重新写这里的部分！！！实际这里重新写一遍初始化也行
    {

        over_draft=over_draft1;//余额
        strcpy(number,number1);
        number1[3]='\0';
        for(i=0; i<4; i++)
            pass[i]=pass1[i];
        balance=balance1;
    }
    virtual void withdraw(double m);
    int cmp(char m_number[4]);//比较字符串是否相等
    friend void open();//等录取款函数
private:
    double over_draft;
};
void credit::withdraw(double m)//重写的透支函数,,friend和虚函数都不需要
{
    if(m>balance)
    {
        cout<<"余额不足"<<endl;
        cout<<"透支"<<(m-balance)<<"元"<<endl;
    }
    else
    {
        cout<<"请取款"<<endl;
    }
}
int credit::cmp(char m_number[4])//对字符串函数重写
{
    return(strcmp(number,m_number));
}
void open(credit  a[3])//登录取款函数
{
    int i,j;
    char m_number[4];//账号
    int m_pass[4];//密码
    int flag1=0;
    while(1)
    {
        int result=MessageBox(NULL,TEXT("确定要存钱吗？"),TEXT("welcome to bank"),MB_ICONINFORMATION|MB_YESNO);//小弹窗
        switch(result)
        {
        case IDYES://存款的项目
        {
            MessageBox(NULL,TEXT("存款\n输入账号和密码"),TEXT("welcome to bank"),MB_OK);
            for(i=0; i<4; i++) //输入账号
            {
                cin>>m_number[i];
            }
            for(i=0; i<3; i++) //里边查询
            {
                if(a[i].cmp(m_number)==0)//一旦相等 输密码
                {
                    while(flag1==0)
                    {
                        cout<<"请输入密码"<<endl;
                        for(j=0; j<3; j++)
                        {
                            cin>>m_pass[j];
                        }
                        for(j=0; j<3; j++)
                        {
                            if(a[i].pass[j]!=m_pass[j])
                            {
                                flag1=0;
                                cout<<"error!!"<<endl;
                                break;
                            }
                            else
                                flag1=1;
                        }
                    }
                }
            }
        }

        case IDNO:
        {MessageBox(NULL,TEXT("取款"),TEXT("OK"),MB_OK);}
        }
    }
}
    int main()
    {
        int i,flag,j;
        credit a[3];
        char number0[4];
        int pass0[4];
        double balance0;
        cout<<"欢迎来到建设银行！"<<endl;//记下来
        Sleep(1000);//延时函数
        system("CLS");//清屏函数
        cout<<"请输入3个人的信息"<<endl;
        for(i=0; i<3; i++)
        {
            cout<<"账号："<<endl;
            cin>>number0;
            cout<<"密码"<<endl;
            for(i=0; i<4; i++)
            {
                cin>>pass0[i];
            }
            cout<<"钱数"<<endl;
            cin>>balance0;
            a[i].get_credit(number0,pass0,balance0,balance0);
        }
        /*                                  下一部分为存款取款                                */
        Sleep(1000);//毫秒为单位
        system("cls");//清屏函数
        open(a);
        return(0);
    }
