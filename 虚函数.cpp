#include<iostream>
#include<math.h>//图形
using namespace std;
class Shape
{
public:
    virtual double area()=0;
};
class Circle:public Shape//圆
{
public:
    Circle(double rr):r(rr) {};
    virtual double area()
    {
        return(3.14*pow(r,2));
    }
private:
    double r;
};
class Triangle:public Shape//三角
{
public:
    Triangle(double ww,double hh):w(ww),h(hh) {}
    virtual double area()
    {
        return(0.5*w*h);
    }
private:
    double w,h;
};
void outarea(Shape &s)
{
    cout<<s.area()<<endl;
}
int main()
{


    double a,b,d;
    cout<<"input the r:"<<endl;
    cin>>a;
    Circle c(a);
    cout<<"the circle area is:";
    outarea(c);
    cout<<"input the w:"<<endl;
    cin>>b;
    cout<<"input the h:"<<endl;
    cin>>d;
    Triangle t(b,d);
    cout<<"The triangle is :";
    outarea(t);
    return (0);
}
