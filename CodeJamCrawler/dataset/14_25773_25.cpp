#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t;
cin>>t;


for(int m=1;m<=t;m++)
{
int a[17][17]={0},b[17][17]={0},c[4]={0},d[4]={0};
int count=0;
int n;
cin>>n;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
cin>>a[i][j];
for(int j=0;j<4;j++)
c[j]=a[n-1][j];
int n2;
cin>>n2;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
cin>>b[i][j];
for(int j=0;j<4;j++)
d[j]=b[n2-1][j];
int input;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
{
if(c[i]==d[j])
{input=c[i];
count++;}
}
cout<<"Case #"<<m<<":"<<" ";
if(count==1)
cout<<input<<endl;
else
if(count>1)
cout<<"Bad magician!"<<endl;
else
if(count==0)
cout<<"Volunteer cheated!"<<endl;
}
return 0;
}
