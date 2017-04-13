#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
int t,a,b;
int i,j,k,h=1;
int digits[10],num,count,newnum,sum;

FILE *fp1,*fp2;

fp1=fopen("C-small-attempt1.in","r");
fp2=fopen("C.out","w");

vector <int> arr;

fscanf(fp1,"%d",&t);

while (t--)
{
fscanf(fp1,"%d%d",&a,&b);
sum=0;

for(j=a;j<=b;j++)
{
count=0;
num=j;
while (num!=0)
{
digits[count++]=(num%10);
num=num/10;
}


arr.resize(0);

for(num=(count-1);num>=0;num--)
{
newnum=0;

for(k=num;k>=0;k--)
{
newnum=newnum*10+digits[k];
}

for(k=(count-1);k>num;k--)
{
newnum=newnum*10+digits[k];
}

if((newnum>j) && ((newnum>=a) && (newnum<=b)))
{

for(k=0;k<arr.size();k++)
{
if(arr[k]==newnum)
break;
}
if(k==arr.size()){

arr.push_back(newnum);
sum=sum+1;
}	
}
}
}
fprintf(fp2,"Case #%d: %d\n",(h++),sum);
}
fclose(fp1);
fclose(fp2);
return(0);
}	

