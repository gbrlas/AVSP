#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<memory.h>
#define N 12510
using namespace std;

int s[10]={10,100,1000,10000,100000,1000000};
bool p[N][N];
int main()
{
	int t,cas=1;
	int mid,ans,len,a,b,t1,t2;
	int i,j;
	freopen("re.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{	
		ans=0;
		scanf("%d%d",&a,&b);
		len=0;
		mid=a;
		memset(p,0,sizeof(p));
		while(mid)
		{
			len++;
			mid/=10;
		}
        printf("Case #%d: ",cas++);
		if(len==1)
		{
			printf("0\n");
			continue;
		}
		mid=(a+b)/2;
		mid++;
		for(i=a;i<=b;i++)
		{   
            p[i][i]=1;    
			for(j=0;j<len;j++)
			{
				t1=i%s[j];
				t2=i/s[j];
				t1=t1*s[len-2-j]+t2;//cout<<i<<" "<<t1<<endl;system("pause");
				if(p[t1][i]||p[i][t1])
				continue;				
				if(t1<=b&&t1>=a)
				{
                              // cout<<i<<" "<<t1<<endl;//system("pause");
                                ans++;
                                p[t1][i]=p[i][t1]=1;
                 }
                 
			}
            p[i][t]=1;	
		}
		printf("%d\n",ans);//system("pause");
	}
	return 0;
}
		

