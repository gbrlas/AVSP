#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

int t;
cin>>t;


for(int m=1;m<=t;m++)
{
long double c,f,x;
cin>>c>>f>>x;
long double count=2.0;
long double ttime=0;
long double d=c;
long double p;
 while(((x-c)/count)>(x/(count+f))){
ttime+=(c/count);
count+=f;
}  
ttime+=(x/count);
printf("Case #%d: %.7llf\n",m,ttime);

}
return 0;
}
