#include<iostream>
#include<iomanip>
using namespace std;
class student{
    public:
    string name,clas;
    int roll;
    char div;
    int ans[5];
    void info()
    {
        cout<<"\nName:";
        cin>>name;
        cout<<"Class:";
        cin>>clas;
        cout<<"Roll no:";
        cin>>roll;
        cout<<"Division:";
        cin>>div;
    }
    void display()
    {
        cout<<roll<<"\t\t"<<name<<"\t\t"<<clas<<"\t\t"<<div<<endl;
    }
    void feed()
    {
        cout<<"\nEnter 1 for yes and 0 for No:"<<endl;
        cout<<"\n1.Was the event well-organized?(1/0):";
        cin>>ans[0];
        cout<<"\n2.Did you find the event informative?";
        cin>>ans[1];
        cout<<"\n3.Was the event duration appropriate?";
        cin>>ans[2];
        cout<<"\n4.Did the event meet your expectations?";
        cin>>ans[3];
        cout<<"\n5.Were the speakers/presenters engaging?";
        cin>>ans[4];
    }
};
int main()
{
    class student s[10];
    int ch,i,j,n,tempRol,flag,low,high,mid,temp=0,pos=0,temp2,count=0,sr;
    string tempClas;
    int good[10];
    do{
        cout<<"\n1.Add information\t2.Display\t3.Linear search\t4.Binary search\t5.Feedback\t6.Analysis\t7.Exit\nEnter choice:";
    cin>>ch;
    switch(ch)
    {
        case 1://information
              if(count<10)
              {
               cout<<"Enter no.of students:";
               cin>>n;
               temp2=pos+n;
               for(i=temp;i<pos+n;i++)
               {
                s[i].info();
                temp++;
                count++;
               }
               pos=i;
              }else{
                cout<<"\nlist is full";
              }
              for(i=0;i<count;i++)
              {
               good[i]=-1;
              }
               break;

        case 2://display
              cout<<"Roll no\t\tName\t\tClass\t\tDivision\n";
              for(i=0;i<temp2;i++)
              {
                s[i].display();
              }
              break;
              
        case 3://linear search
                flag=0;
               cout<<"\nEnter roll number for search:";
               cin>>tempRol;
               cout<<"Enter class:";
               cin>>tempClas;
               for(i=0;i<temp2;i++)
               {
                if(s[i].roll==tempRol && s[i].clas==tempClas)
                {
                    flag=1;
                    break;
                }
               }
               if(flag==1)
               {
                cout<<"\nStudent Attended the training program";
               }else{
                cout<<"\nNot attended the training program";
               }
               break;
               
        case 4://binary search 
               for(i=0;i<count;i++)  //sorting
               {
                for(j=i;j<count-i-1;j++)
                {
                    if(s[j].roll>s[j+1].roll)
                    {
                        //swapping of roll numbers
                        tempRol=s[j].roll;
                        s[j].roll=s[j+1].roll;
                        s[j+1].roll=tempRol;
                        //swapping of class
                        tempClas=s[j].clas;
                        s[j].clas=s[j+1].clas;
                        s[j+1].clas=tempClas;

                    }
                }
               }
               cout<<"\nEnter roll number for search:";
               cin>>tempRol;
               cout<<"Enter class:";
               cin>>tempClas;
               low=0;
               high=temp2-1;
               while(low<=high)  //binary search
               {
                mid=(low+high)/2;
                if(s[mid].roll==tempRol && s[mid].clas==tempClas)
                {
                    cout<<"\nStudent Attended the training program";
                    break;
                }else if(s[mid].roll>tempRol)
                {
                    high=mid-1;
                }else{
                    low=mid+1;
                }
               }
               if(low>high)
               {
                cout<<"\nNot attended the training program";
               }
               break;
        
        case 5://feedback
               flag=0;
               cout<<"\nEnter roll number for search:";
               cin>>tempRol;
               cout<<"Enter class:";
               cin>>tempClas;
               for(i=0;i<temp2;i++)
               {
                if(s[i].roll==tempRol && s[i].clas==tempClas)
                {
                    flag=1;
                    break;
                }
               }
               if(flag==1)
               {
                s[i].feed();
                good[i]=0;
               
                for(j=0;j<5;j++)
                {
                    if(s[i].ans[j]==1)
                    {
                        good[i]++;
                    }
                }
                good[i]=(good[i]*100)/5;
               }else{
                cout<<"\nNot attended the training program";
               }
            break;

        case 6://analysis
               sr=1;
               cout<<"\nSr.no\tRoll no\tClass\tName\tDivision\tRating\tRemark"<<endl;
               for(i=0;i<count;i++)
               {
                if(good[i]!=-1)
                {
                cout<<sr<<"\t"<<s[i].roll<<"\t"<<s[i].clas<<"\t"<<s[i].name<<"\t"<<s[i].div<<"\t\t"<<good[i]<<"%";
                if(good[i]>=80)
                {
                 cout<<"\tEvent should happen"<<endl;
                }else{
                 cout<<"\tEvent should NOT happen"<<endl;
                }
                sr++;
                }
                
               }
               break;
    }
    }while(ch!=7);
}
