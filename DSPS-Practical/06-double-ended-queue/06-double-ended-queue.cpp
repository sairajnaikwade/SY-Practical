//double ended queue
#include<iostream>
using namespace std;
int queue[10],front=-1,rear=-1;
int s=10,ele;
void rearAdd()
{
    if(rear==s-1)
    {
        cout<<"Queue is full"<<endl;
    }else{
        cout<<"Enter element:";
        cin>>ele;
        rear++;
        queue[rear]=ele;
        if(front==-1)
    {
        front=0;
    }
    }
    cout<<"front = "<<front<<"\trear = "<<rear<<endl;
    
}

void rearDel()
{
    if(rear==-1 || rear<front)
    {
        cout<<"Queue is empty"<<endl;
    }else{
        ele=queue[rear];
        cout<<"Deleted element is :"<<ele<<endl;
        rear--;
    }
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    cout<<"front = "<<front<<"\trear = "<<rear<<endl;
}

void frontAdd()
{
    if(front==0 && rear==s-1)
    {
        cout<<"Queue is full"<<endl;
    }else if(front<rear)
    {
        cout<<"Unable to insert at front"<<endl;
    }else if(front>0){
       front--;
       cout<<"enter element:";
       cin>>ele;
       queue[front]=ele;
    }
    cout<<"front = "<<front<<"\trear = "<<rear<<endl;
    
}

void frontDel()
{
    if(front==-1 || rear<front)
    {
        cout<<"Queue is empty"<<endl;
    }else{
        ele=queue[front];
        cout<<"Deleted element is :"<<ele<<endl;
        front++;
    }
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    cout<<"front = "<<front<<"\trear = "<<rear<<endl;
}

void display()
{
    int i;
    cout<<"Queue =\t";
    for(i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"\t";
    }
    cout<<endl;
    cout<<"front = "<<front<<"\trear = "<<rear<<endl;
}
int main()
{
    int ch;
    do{
        cout<<"1.Rear Add\t2.Rear Delete\t3.Front Add\t4.Front Delete\t5.Display\t6.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:rearAdd();
                   break;
            case 2:rearDel();
                   break;
            case 3:frontAdd();
                   break;
            case 4:frontDel();
                   break;
            case 5:display();
                   break;                                      
        }
    }while(ch!=6);
}
