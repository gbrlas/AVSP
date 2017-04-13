#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 

 
int main()
{
freopen("input","r",stdin);
freopen("output","w",stdout);
/*int array[6]={1,4,9,121,484,1001};*/
long long array[40]={1
,4
,9
,121
,484
,10201
,12321
,14641
,40804
,44944
,1002001
,1234321
,4008004
,100020001
,102030201
,104060401
,121242121
,123454321
,125686521
,400080004
,404090404
,10000200001
,10221412201
,12102420121
,12345654321
,40000800004
,1000002000001
,1002003002001
,1004006004001
,1020304030201
,1022325232201
,1024348434201
,1210024200121
,1212225222121
,1214428244121
,1232346432321
,1234567654321
,4000008000004
,4004009004004 
,100000000000001};
int  T;
long long A,B;
int ptr1,ptr2;
scanf("%d",&T);
 int casenumber=0;
int count=0;
while(T--)
{      casenumber++;
	 ptr1=40;
	ptr2=0;
	count=0;

	scanf("%lld%lld",&A,&B);
	for(int i=0;i<40;i++)
	{	
	if(array[i]>=A&&array[i]<=B)
	{count++;}
	
	}
	
printf("Case #%d: %d\n",casenumber,count);

}
 
    
    
// system("pause");  
return 0;
}
