#include<iostream>
using namespace std;
int main()
{
int n,i,j,k,l,r;
cin>>n;
int m[16];
int a[4][4];
for(i=0;i<n;i++)
{
for(k=0;k<16;k++)
m[k]=0;

for(j=0;j<2;j++)
{
cin>>r;
for(k=0;k<4;k++)
{
for(l=0;l<4;l++)
{
cin>>a[k][l];
if(r-1==k)
{
m[a[k][l]-1]++;
      }
    }
  }
}
j=0;
for(k=0;k<16;k++)
{
if(m[k]==2)
{
	l=k+1;
j++;
} 
   }
if(j==0)
cout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
else if(j==1)
cout<<"Case #"<<i+1<<": "<<l<<endl;
else
cout<<"Case #"<<i+1<<": Bad magician!"<<endl;

     }
return 0;
}
