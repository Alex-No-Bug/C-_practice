#include<iostream>
#include<string.h>
using namespace std;
class client
{
public:
    client()//�޲���
    {
        strcpy(name,"no name"); //name=new char[10]��������������������newָ����÷�
        age=0;
        type=0;
    }
    void set_client (char*name1,int age1,int type1);//�������������캯������
    friend int cmp_name(client c1,client c2);
    friend void sort(client*pc,int n);
    friend void display(client a[],int n);
private:
    char name[20];//�Ķ�����ָ��,��ָ��ȽϺ�
    int age;
    int type;
};
void client::set_client(char*name1,int age1,int type1)//���캯��
{
    strcpy(name,name1);
    name[sizeof(name)]='\0';
    age=age1;
    type=type1;

}
void sort(client*pc,int n)//��ͨ����  ������
{
    client temp;
    int i,j;
    for(j=1; j<n; j++)
        for(i=0; i<(n-1); i++)
        {
            if((strcmp(pc[i].name,pc[i+1].name))>0)//ǰ��Ĵ�
            {
                temp=pc[i];
                pc[i]=pc[i+1];
                pc[i+1]=temp;
            }
        }
}
void  display(client a[],int n)//��ͨ���� ��ʾ
{
    int i;
    for(i=0; i<n; i++)
        cout<<"name: "<<a[i].name<<"  age: "<<a[i].age<<"  type: "<<a[i].type<<endl;
}
int main()
{
    client c[3];
    int i,n;
    char str[20];//��ָ��
    int a;
    int b;
    for(i=0; i<3; i++)
    {
        cout<<"input the name age type:"<<endl;
        cin>>str;
        cin>>a;
        cin>>b;
        c[i].set_client(str,a,b);              //�������ó�ʼ������
    }
    sort(c,3);
    display(c,3);//�ӡ�������
    return(0);
}
