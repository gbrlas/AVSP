#include<iostream>
#include<string>
using namespace std;
int n,m;//n is line,m is row
int checkpoint(int **data,int i,int j)
{
int flag1=1,flag2=1;
for(int k=0;k<m;k++)
	if(data[i][j]<data[i][k])
		flag1=0;
for(int k=0;k<n;k++)
	if(data[i][j]<data[k][j])
		flag2=0;
return (flag1|flag2);
}
int check(int **data)
{
for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		if(!checkpoint(data,i,j)) return 0;
return 1;
}

int main()
{
FILE *fin,*fout;
fin=freopen("B-small-attempt0.in","r",stdin);
fout=freopen("output.txt","w",stdout);
int num;
int result;
cin>>num;
for(int k=0;k<num;k++)
{
cin>>n;
cin>>m;
int **data=new int *[n];
for(int i=0;i<n;i++)
	data[i]=new int[m];
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
	cin>>data[i][j];
result=check(data);
cout<<"Case #"<<k+1<<": ";
if(result==1) cout<<"YES"<<endl;
if(result==0) cout<<"NO"<<endl;
for(int i=0;i<n;i++)
free(data[i]);
}
return 1;
}