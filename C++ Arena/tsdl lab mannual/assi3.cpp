#include<iostream>
#include<cmath>
using namespace std;
int main()
{
 float a,b,c;
 float d;
 cout<<"give the value of the first constant a:";
 cin>>a;
 cout<<"give the value of the second constant b:";
 cin>>b;
 cout<<"give the value of the third constant c:";
 cin>>c;
 d=(b*b)-(4*a*c);
 float D=sqrt(d);
 float x=((-b+D)/(2*a));
 float y=((-b-D)/(2*a));
 if (D>0)
 {
 cout<<"there are two roots:"<<x<<","<<y;
 }
 else if(D==0)
 {
 cout<<"there is only one root:"<<(-b/(2*a));
 }
 else
 {
 cout<<"the roots are imaginary!";
 }
 return 0;
}
