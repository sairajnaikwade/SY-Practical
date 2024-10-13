#include<iostream>
using namespace std;

class complex{    
public:
int real;
int imaginary;

complex(){
  real=0;
  imaginary=0;   
}

void input(int x){
    cout<<"Equation: "<<x+1<<endl;
    cout<<"Enter the Real Part: ";
    cin>>real;
    cout<<"Enter the Imaginary Part: ";
    cin>>imaginary;
    display();
}

void display(){
    cout<<real<<" + i("<<imaginary<<")"<<endl;
}

complex operator *(complex &a){
   complex temp;

   temp.real=(real * a.real) - (imaginary*a.imaginary);
   temp.imaginary=(real * a.imaginary) + (imaginary * a.real);

    return temp;
}

complex operator +(complex &a){
  complex temp;
  
  temp.real=(real+a.real);
  temp.imaginary=(imaginary+a.imaginary);

  return temp;
}

complex operator -(complex &a){
  complex temp;
  
  temp.real=(real-a.real);
  temp.imaginary=(imaginary-a.imaginary);

  return temp;
}


};

int main(){
    complex number[3];
    int ch;
    do
    {   cout<<"Menu\n1.Addition\n2.Substraction\n3.Multiply\n4.Divide\n5.Exit\n";
        cin>>ch;
         switch (ch)
        {
         
        case 1:

        for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] + number[1];

        cout<<"\nAddition is: \n";
        number[2].display();
        
        break; 

        case 2:

         for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] - number[1];

        cout<<"\nSubstraction is: \n";
        number[2].display();
        
        break; 

        case 3:

        for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] * number[1];

        cout<<"\nAnswer is: \n";
        number[2].display();
        
        break; 

        case 4:

        break;

        case 5:
        break; 
       
        default:
            cout<<"Wrong choice...\n";
            break;
        }
    } while (ch!=5);
    

    return 0;
}
