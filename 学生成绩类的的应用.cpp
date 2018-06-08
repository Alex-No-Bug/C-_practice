#include<iostream>//学生的数学成绩，计算机，总成绩排名 容量，注释
#include<string.h>
using namespace std;
class Grade //构造类成绩
{
private:
    int num;
    char name[20];
    int math,computer,sum;
public:
    Grade();//构造函数
    void show();
    void setgrade(int xnum,char*xname,int xmath,int xcomputer);//赋值函数！！
    int getmath()
    {
        return (math);
    };
    int getcomputer()
    {
        return (computer);
    };
    int total()//计算总成绩的函数
    {
        sum=math+computer;
        return (sum);
    }
};
void Grade::show()//显示函数
{
    cout<<"  name:  "<<name<<"\t"
        <<"  num :  "<<num<<"\t"
        <<"  math:   "<<math<<"\t"
        <<"  computer:  "<<computer<<"\t"
        <<"  sum:      "<<sum<<"\t"<<endl;;//制表符用双引号
}
Grade::Grade()//构造函数
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
    Grade s[3],temp;//对象数组，temp为临时
    int i,j=0;
    int xmath,xcomputer,xnum;
    char xname[20];
    for(i=0; i<3; i++)//进行初始化
    {
        cout<<"name is :"<<endl;
        cin>>xname;
        cout<<"student number,math,and computer is:"<<endl;
        cin>>xnum;
        cin>>xmath;
        cin>>xcomputer;
        s[i].setgrade(xnum,xname,xmath,xcomputer);
    }
    for(j=1; j<=2; j++) //泡沫升序法
        for(i=0; i<2; i++)
        {
            if((s[i].total())<s[i+1].total())
            {
                temp=s[i];//类对象的直接赋值
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
    for(i=0; i<3; i++)//依次输出
    {
        s[i].show();
    }
    return(0);
}
