#include<iostream>//ѧ������ѧ�ɼ�����������ܳɼ����� ������ע��
#include<string.h>
using namespace std;
class Grade //������ɼ�
{
private:
    int num;
    char name[20];
    int math,computer,sum;
public:
    Grade();//���캯��
    void show();
    void setgrade(int xnum,char*xname,int xmath,int xcomputer);//��ֵ��������
    int getmath()
    {
        return (math);
    };
    int getcomputer()
    {
        return (computer);
    };
    int total()//�����ܳɼ��ĺ���
    {
        sum=math+computer;
        return (sum);
    }
};
void Grade::show()//��ʾ����
{
    cout<<"  name:  "<<name<<"\t"
        <<"  num :  "<<num<<"\t"
        <<"  math:   "<<math<<"\t"
        <<"  computer:  "<<computer<<"\t"
        <<"  sum:      "<<sum<<"\t"<<endl;;//�Ʊ����˫����
}
Grade::Grade()//���캯��
{
    math=0;
    num=0;
    computer=0;
    strcpy(name,"****");
}
void Grade::setgrade(int xnum,char*xname,int xmath,int xcomputer)
{
    num=xnum;
    math=xmath;
    computer=xcomputer;
    strcpy(name,xname);
}
int main()
{
    Grade s[3],temp;//�������飬tempΪ��ʱ
    int i,j=0;
    int xmath,xcomputer,xnum;
    char xname[20];
    for(i=0; i<3; i++)//���г�ʼ��
    {
        cout<<"name is :"<<endl;
        cin>>xname;
        cout<<"student number,math,and computer is:"<<endl;
        cin>>xnum;
        cin>>xmath;
        cin>>xcomputer;
        s[i].setgrade(xnum,xname,xmath,xcomputer);
    }
    for(j=1; j<=2; j++) //��ĭ����
        for(i=0; i<2; i++)
        {
            if((s[i].total())<s[i+1].total())
            {
                temp=s[i];//������ֱ�Ӹ�ֵ
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
    for(i=0; i<3; i++)//�������
    {
        s[i].show();
    }
    return(0);
}
