#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Book {
public:
string author;
string title;
int price;
string publisher;
int stock;
          
          void Input(int x)
          { cout<<"Book "<<x+1<<" Details: \n";
            cout<<"Enter the Title: ";
            cin>>title;
            cout<<"Enter the Author: ";
            cin>>author;
            cout<<"Enter the Publisher: ";
            cin>>publisher;
            cout<<"Enter the Price: ";
            cin>>price;
            cout<<"Enter Avaibale Stock: ";
            cin>>stock;
            cout<<endl;
          }

          void Display(int x)
          {   cout << setw(15) << left << title
             << setw(15) << left << author
             << setw(15) << left << publisher
             << setw(10) << right << price
             << setw(10) << right << stock << endl;
          }
};


int main()
{   Book B[10];
    int ch,N=0,temp,tempstock,tempprice,flag;
    string tempauthor,temptitle;

 
 do{
    cout<<"Menu\n1.Input Lot\n2.Display\n3.Search\n4.Exit\n";
    cin>>ch;

    switch (ch)
    {
    case 1:
        cout<<"Enter the Lot Size: ";
        cin>>temp;

        for (int i = N; i < N+temp; i++)
        {
            B[i].Input(i);
        } 
        N+=temp;
        break;
    case 2:
            cout << setw(15) << left << "Title"
                 << setw(15) << left << "Author"
                 << setw(15) << left << "Publisher" 
                 << setw(10) << right << "Price"
                 << setw(10) << right << "Stock" << endl;

            cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;
            
        for (int i = 0; i < N; i++)
        {
            B[i].Display(i);
        }

        break;
    case 3:
        cout<<"Enter the Book Title: ";
        cin>>temptitle;
        cout<<"Enter the Book Author: ";
        cin>>tempauthor;
        flag=0;

        for (int i = 0; i < N; i++)
        {
            if (B[i].title==temptitle && B[i].author==tempauthor)
            {
                cout<<"Books is Available\nBook Details:\n";
                cout<<"Title: "<<temptitle<<endl<<"Author: "<<B[i].author<<endl<<"Publisher: "<<B[i].publisher<<endl<<"Price: "<<B[i].price<<endl<<"Available Stock: "<<B[i].stock<<endl;
                cout<<"Enter the no. of Copies to be Isuued: ";
                cin>>tempstock;
                if (B[i].stock<tempstock)
                {
                    cout<<"That much No. of Copies are not Available at the Moment...\n";
                }
                else
                {
                    tempprice=tempstock*B[i].price;
                    cout<<"Total Price of Copies: "<<tempprice<<endl;
                    B[i].stock-=tempstock;
                }
                flag=1;
                break;
            }       
        }
        if(flag==0)
        {
        cout<<"Book Not Found";
        }        
         
        break;
    case 4:
        break;

    default:
        cout<<"Wrong Choice\n";
        break;
    }
 }while(ch!=4);





return 0;    
}
