#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>//3���û�   4λ����  4λ�˺�
using namespace std;
class account
{
    int i,j;
public:
    account()//�޲����Ĺ��캯��
    {
        strcpy(number,"123");
        for(i=0; i<4; i++)
            pass[i]=0;
        balance=0;
    }
    void get_account(char number1[4],int pass1[4],double balance1=0)//���캯��
    {
        strcpy(number,number1);
        number1[3]='\0';
        for(i=0; i<4; i++)
            pass[i]=pass1[i];
        balance=balance1;
    };
    virtual void withdraw(double m);//ȡ��   �麯��
    void desposit(double m);//���
    void display();//��ʾ
    void changepass();
protected://�����ñ����࣡!�ʼǼ�����Ϊ��protected
    char number[4];
    int pass[4];
    double balance;
};
void account::withdraw(double m)//ȡ��!!!ɾȥvirtual
{
    if(m>balance)
    {
        cout<<"����"<<endl;
    }
    else
        cout<<"��ȡ��"<<endl;
}
void account::desposit(double m)//���
{
    balance+=m;
    cout<<"��"<<balance<<endl;
}
void account::changepass()//�޸����룬��
{
    int pass2[4];
    int i,j;
    int flag=0;
    while(flag==0)
    {
        cout<<"���������룺"<<endl;
        for(i=0; i<4; i++)
        {
            pass[i]=getch();
            putchar('*');
        }
        system("CLS");//��������
        cout<<"��ȷ�ϣ�"<<endl;
        for(i=0; i<4; i++)
        {
            pass2[i]=getch();
            putchar('*');
        }
        for(j=0; j<4; j++)
        {
            if(pass[j]!=pass2[j])//�޸�δ�ɹ�
            {
                flag=0;
                break;
            }
            else
                flag=1;
        }
    }
}

class credit:public account//�������ÿ�
{
    int i;
public:
    credit()//�޲�����
    {
        strcpy(number,"123");
        for(i=0; i<4; i++)
            pass[i]=0;
        balance=0;
        over_draft=0;
    }
    void get_credit(char number1[4],int pass1[4],double balance1,double over_draft1)//:get_account(number1,pass1,balance1)//�˴���bug������ϸ�������ϵ�,����д����Ĳ��֣�����ʵ����������дһ���ʼ��Ҳ��
    {

        over_draft=over_draft1;//���
        strcpy(number,number1);
        number1[3]='\0';
        for(i=0; i<4; i++)
            pass[i]=pass1[i];
        balance=balance1;
    }
    virtual void withdraw(double m);
    int cmp(char m_number[4]);//�Ƚ��ַ����Ƿ����
    friend void open();//��¼ȡ���
private:
    double over_draft;
};
void credit::withdraw(double m)//��д��͸֧����,,friend���麯��������Ҫ
{
    if(m>balance)
    {
        cout<<"����"<<endl;
        cout<<"͸֧"<<(m-balance)<<"Ԫ"<<endl;
    }
    else
    {
        cout<<"��ȡ��"<<endl;
    }
}
int credit::cmp(char m_number[4])//���ַ���������д
{
    return(strcmp(number,m_number));
}
void open(credit  a[3])//��¼ȡ���
{
    int i,j;
    char m_number[4];//�˺�
    int m_pass[4];//����
    int flag1=0;
    while(1)
    {
        int result=MessageBox(NULL,TEXT("ȷ��Ҫ��Ǯ��"),TEXT("welcome to bank"),MB_ICONINFORMATION|MB_YESNO);//С����
        switch(result)
        {
        case IDYES://������Ŀ
        {
            MessageBox(NULL,TEXT("���\n�����˺ź�����"),TEXT("welcome to bank"),MB_OK);
            for(i=0; i<4; i++) //�����˺�
            {
                cin>>m_number[i];
            }
            for(i=0; i<3; i++) //��߲�ѯ
            {
                if(a[i].cmp(m_number)==0)//һ����� ������
                {
                    while(flag1==0)
                    {
                        cout<<"����������"<<endl;
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
        {MessageBox(NULL,TEXT("ȡ��"),TEXT("OK"),MB_OK);}
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
        cout<<"��ӭ�����������У�"<<endl;//������
        Sleep(1000);//��ʱ����
        system("CLS");//��������
        cout<<"������3���˵���Ϣ"<<endl;
        for(i=0; i<3; i++)
        {
            cout<<"�˺ţ�"<<endl;
            cin>>number0;
            cout<<"����"<<endl;
            for(i=0; i<4; i++)
            {
                cin>>pass0[i];
            }
            cout<<"Ǯ��"<<endl;
            cin>>balance0;
            a[i].get_credit(number0,pass0,balance0,balance0);
        }
        /*                                  ��һ����Ϊ���ȡ��                                */
        Sleep(1000);//����Ϊ��λ
        system("cls");//��������
        open(a);
        return(0);
    }
