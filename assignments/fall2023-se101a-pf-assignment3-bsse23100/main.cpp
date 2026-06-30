#include <iostream>
using namespace std;

void q1()
{int r;
double a;
cout<<"radius=";
cin>>r;
a=3.14*r*r;
cout<<"area=";
cout<<a<<endl;

    // Write your solution for question 1 here
}
void q2()
{int f;
    int c;
    cout<<"temperature in fahrenheit=";
    cin>>f;
    c=(f-32)*5/9;
    cout<<"temperature in celsius=";
    cout<<c<<endl;

    // Write your solution for question 2 here
}
void q3()
{int r;
    double v;
    cout<<"radius=";
    cin>>r;
    v=(4/3)*3.14*r*r*r;
    cout<<"volume=";
    cout<<v<<endl;
    // Write your solution for question 3 here
}
void q4()
{string n;
    string a;
    string jt;
    cout<<" enter name"<<endl;
    cin>>n;
    cout<<" enter age"<<endl;
    cin>>a;
    cout<<"enter job title"<<endl;
    cin>>jt;
    cout<<"name of employee=";
    cout<<n<<endl;
    cout<<"age of employee=";
    cout<<a<<endl;
    cout<<"job title of employee=";
    cout<<jt<<endl;




    // Write your solution for question 4 here
}
void q5()
{int f;
    int t;
    int l;
    int hl;
    int sl;
    int sum;
    cout<<" enter food expense"<<endl;
    cin>>f;
    cout<<"enter transportation expense"<<endl;
    cin>>t;
    cout<<"enter lodging expense"<<endl;
    cin>>l;
    cout<<"enter hotel room  expense"<<endl;
    cin>>hl;
    cout<<"enter sim load expense"<<endl;
    cin>>sl;
    sum=f+t+l+hl+sl;
    cout<<"total=";
    cout<<sum<<endl;

    // Write your solution for question 5 here
}

int main() {
    q1();
    q2();
    q3();
    q4();
    q5();

    return 0;
}
