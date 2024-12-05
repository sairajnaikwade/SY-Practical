#include<iostream>
using namespace std;
class complex
{
    public:
    int real,img;
    int rres,ires;
    complex()
    {
        real=0;
        img=0;
    }
    complex(int r,int i)
    {
        real=r;
        img=i;
    }
    void display()
    {
        
    }
    void operator +(complex &c)
    {
        rres=real+c.real;
        ires=img+c.img;
        cout<<"Addition="<<rres<<"+"<<ires<<"i"<<endl;
    }
    void operator -(complex &d)
    {
        rres=real-d.real;
        ires=img-d.img;
        cout<<"Subtraction="<<rres<<"+"<<ires<<"i"<<endl;
    }
    friend void operator *(complex &obj1, complex &obj2);
    friend void operator /(complex &n1, complex &n2);
};
void operator *(complex &obj1,complex &obj2)
{
    obj1.rres=((obj1.real*obj2.real)-(obj1.img*obj2.img));
    obj1.ires=((obj1.real*obj2.img)+(obj1.img*obj2.real));
    if(obj1.ires>0)
    {
        cout<<"Multiplication="<<obj1.rres<<"+"<<obj1.ires<<"i"<<endl;
    }else{
        cout<<"Multiplication="<<obj1.rres<<""<<obj1.ires<<"i"<<endl;
    }
}
void operator /(complex &n1, complex &n2)
{
    int a=(n2.real*n2.real)-(-(n2.img*n2.img));
    n1.rres=((n1.real*n2.real)-(n1.img*(-n2.img)));
    n1.ires=((n1.real*(-n2.img))+(n1.img*n2.real));
    cout<<"Division="<<"("<<n1.rres<<"/"<<a<<")"<<"+("<<n1.ires<<"/"<<a<<")"<<"i"<<endl;
}
int main()
{
    class complex no1(2,3),no2(4,2);
    no1+no2;
    no1-no2;
    no1*no2;
    no1/no2;
}
