//library management system
#include<iostream>
#include<string>
using namespace std;
class book
{
    public:
    string title;
    int cost;
    void accept()
    {
        cout<<"Enter title:";
        cin>>title;
        cout<<"Enter cost:";
        cin>>cost;
    }

    void display(int a)
    {
        cout<<a+1<<"\t"<<title<<"\t"<<cost<<endl;
    }
};
int main()
{
    class book b1[10],b2[10],b3[10];
    int i,j,k,n,temp,ch,n2,count=0,price[10],x=0,temp_cost[10],flag=0,q;
    string name[10],temp_title[10];
    do{
        cout<<"1.Accept\t2.sort in descending order\t3.cost less than 500rs\t4.duplicate entries using temp array\t5.duplicate entries without temp array\t6.Books more than 500rs\t7.display\t8.Unsorted array\t9.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://info()
                   cout<<"enter no.of books:";
                   cin>>n;
                   n+=count;
                   n2=n;
                   for(i=count;i<n;i++)
                   {
                    b1[i].accept();
                    b2[i]=b1[i];
                    b3[i]=b2[i];
                    count++;
                   }
                   break;
            case 2://sorting in descending order
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<n-i-1;j++)
                        {
                            if(b1[j].cost<b1[j+1].cost)
                            {
                                temp=b1[j].cost;
                                b1[j].cost=b1[j+1].cost;
                                b1[j+1].cost=temp;
                            }
                        }
                    }
                    break;
            case 3://display books having cost less than 500rs
                    q=0;
                   for(i=0;i<n;i++)
                   {
                    if(b1[i].cost<500)
                    {
                        name[q]=b1[i].title;
                        price[q]=b1[i].cost;
                        q++;
                    }else{
                        x++;
                    }
                   }
                   cout<<"sr.no\tTitle\tCost"<<endl;
                   for(i=0;i<q;i++)
                   {
                    cout<<i+1<<"\t"<<name[i]<<"\t"<<price[i]<<endl;
                   }
                   
                   break;
            
            case 4://delete duplicate entries using temparary 
                  q=0;
                  for(i=0;i<n;i++)
                  {
                    for(j=0;j<n-1;j++)
                    {
                        if(b1[i].title==b1[j].title && b1[i].cost==b1[j].cost)
                        {
                            
                        }else{
                            temp_title[q]=b1[i].title;
                            temp_cost[q]=b1[i].cost;
                            q++;
                        }
                    }
                    
                  }
                   cout<<"sr.no\tTitle\tCost"<<endl;
                   for(i=0;i<q;i++)
                   {
                    cout<<i+1<<"\t"<<temp_title[q]<<"\t"<<temp_cost[q]<<endl;
                   }
                  break;

            case 5://delete duplicate entries without using temp array
                  q=0;
                   for(i=0;i<n;i++)
                  {
                    for(j=0;j<n;j++)
                    {
                        if(b2[i].title==b2[j].title && b2[i].cost==b2[j].cost)
                        {
                           for(k=j;k<n;k++)
                           {
                            b2[k].title=b2[k+1].title;
                            b2[k].cost=b2[k+1].cost;
                           }
                           n2--;
                        }
                    }
                  }
                   cout<<"sr.no\tTitle\tCost"<<endl;
                   for(i=0;i<q;i++)
                   {
                    cout<<i+1<<"\t"<<b2[i].title<<"\t"<<b2[i].cost<<endl;
                   }
                   break;
            
            case 6://no.of books having cost more than 500rs
                  cout<<"No.of books having price more than 500rs are:"<<x<<endl;
                  break;

            case 7://display
                   cout<<"Sr.no\tTitle\tcost"<<endl;
                   for(i=0;i<n;i++)
                   {
                    b1[i].display(i);
                   }
                   break;
                   
            case 8://unsorted array
                   cout<<"Sr.no\tTitle\tcost"<<endl;
                   for(i=0;i<n;i++)
                   {
                     b3[i].display(i);
                   }
        }
    }while(ch!=9);
    return 0;
}
