#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main (void)
{
int n,linia,ilosc;
int a,b,c,d;
int bufa,bufb,bufc,bufd,wyn;
string zagadka,bufor="0";

cin>>n;
for(int i=0;i<n;i++)
{
ilosc=0;//wyna=0;wynb=0;wync=0;wynd=0;
cin>>linia;
for(int j=0;j<4;j++){
cin>>a;
cin>>b;
cin>>c;
cin>>d;

if(j==linia-1){
bufa=a;
bufb=b;
bufc=c;
bufd=d;
}



}
cin>>linia;
for(int j=0;j<4;j++){
cin>>a;
cin>>b;
cin>>c;
cin>>d;
if(j==linia-1){
if(a==bufa||a==bufb||a==bufc||a==bufd){
wyn=a;
ilosc++;
}
if(b==bufa||b==bufb||b==bufc||b==bufd){
wyn=b;
ilosc++;
}
if(c==bufa||c==bufb||c==bufc||c==bufd){
wyn=c;
ilosc++;
}
if(d==bufa||d==bufb||d==bufc||d==bufd){
wyn=d;
ilosc++;
}
}


}
if(ilosc==0)
cout<<"Case #"<<i+1<<": Volunteer cheated!\n";
if(ilosc==1)
cout<<"Case #"<<i+1<<": "<<wyn<<endl;
if(ilosc>1)
cout<<"Case #"<<i+1<<": Bad magician!\n";
}



return 0;
}
