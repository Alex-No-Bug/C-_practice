#include<iostream>
#include<math.h>
using namespace std;
class Complex
{
public:
    Complex(double xreal,double ximage)
    {
        real=xreal;
        image=ximage;
    };
    double realcomplex()
    {
        return (real);
    };
    double compleximage()
    {
        return(image);
    };
    double abscomplex()
    {
        return(sqrt(real*real+image*image));
    };
private:
    double real;
    double image;
};
int main()
{
    Complex a(1.1,2.2);//�������a
    cout<<"a real is :"<< a.realcomplex()<<"a image is :"<<a.compleximage()<<"a abs is : "<<a.abscomplex()<<endl;//���Կո�
    return(0);
}
