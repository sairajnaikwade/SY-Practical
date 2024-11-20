//pizza parlour shop
#include<iostream>
using namespace std;
class pizza
{
    public:
    int size,qty,priceS=100,priceM=150,priceL=200,cost;
    void order()
    {
        cout<<"Enter choice for the size(1.Small 2.Medium 3.Large):";
        cin>>size;
        cout<<"Enter the quantity:";
        cin>>qty;
        cout<<"Order placed successfully !"<<endl;
    }
    void display()
    {
        cout<<"\t";
        if(size==1)
        {
            cout<<"Small";
            cost=priceS*qty;
        }else if(size==2)
        {
            cout<<"Medium";
            cost=priceM*qty;
        }else{
            cout<<"Large";
            cost=priceL*qty;
        }
        cout<<"\t"<<qty;
        cout<<"\t\t"<<cost<<endl;
        
    }
    void delDisplay()
    {
        cout<<"Size:";
        if(size==1)
        {
            cout<<"Small";
        }else if(size==2)
        {
            cout<<"Medium";
        }else{
            cout<<"Large";
        }
        cout<<"\nQuantity:"<<qty;
        cout<<"\nCost:"<<cost<<"\n\n";
    }
};
int main()
{
    class pizza p[10];
    int ch,cnt;
    int top=-1,front=-1,rear=-1,s=10;
    do{
        cout<<"1.Place order\t2.Deliver order\t3.Display\t4.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://place an order
                   if(rear==s-1)
                   {
                    cout<<"Order list is full"<<endl;
                   }else{
                    rear++;
                    p[rear].order();
                    if(front==-1)
                    {
                        front=0;
                    }
                   }
                   break;

           case 2://deliver order
                   if(front==-1 || rear<front)
                    {
                        cout<<"Order list is empty"<<endl;
                    }else{
                        cout<<"order deliver:"<<endl;
                        p[front].display();
                        front++;
                        cout<<"Order Delivered successfully !"<<endl;
                    }
                    if(front>rear)
                    {
                        front=-1;
                        rear=-1;
                    }
                        
                    break;
            case 3://display the orders
                   cnt=1;
                   cout<<" orders :"<<endl;
                   cout<<"Sr.no\tSize\tQuantity\tCost"<<endl;
                   for(int i=front;i<=rear;i++)
                   {
                    cout<<cnt;
                    p[i].display();
                    cnt++;
                   }
        }
    }while(ch!=4);
}
