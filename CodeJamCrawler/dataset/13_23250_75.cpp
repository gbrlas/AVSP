#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 

 
int main()
{
freopen("input","r",stdin);
freopen("output","w",stdout);
int array[6]={1,4,9,121,484,1001};
int  T,A,B;
int ptr1,ptr2;
scanf("%d",&T);
 int casenumber=0;

while(T--)
{      casenumber++;
	 ptr1=4;
	ptr2=0;

	scanf("%d%d",&A,&B);
	for(int i=5;i>=0;i--)
	{
	
	if(A>array[i]){ptr1=i;break;}
	else if(A==array[i]){ptr1=i-1;break;}
	
	}
	for(int i=0;i<6;i++)
	{
	 if(B<array[i]){ptr2=i;break;}
	else if(B==array[i]){ptr2=i+1;break;}	
	}
	
printf("Case #%d: %d\n",casenumber,ptr2-ptr1-1);

}
 
    
    
// system("pause");  
return 0;
}
