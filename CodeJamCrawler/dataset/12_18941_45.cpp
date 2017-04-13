#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>


using namespace std ;

int p[11][31] ;
int sum[101] ;
int logic(int p,int s)
{
	
	if(s==28&&p>=8)
		return 1;
	if(s==28&&p<8)
		return -1;
	if(s==29&&p>8)
		return 1;
	if(s==29&&p<8)
		return -1;
	if(s==30&&p>9)
		return 1;
		if(s==30&&p<10)
		return -1;
		int t=s;
	if(t<=28){
	if(s<p)
		return -1 ;
	
		s-=p;
	
	if(2*p-4>s||2*p+4<s)
		return -1 ;
	if(2*p-4==s||2*p-3==s)
		return 0;
	if((2*p-2<=s&&2*p+2>=s)&&(2*p-2<=18&&2*p+2<=20))
		return 1;
	if((2*p+3==s||2*p+4==s)&&(2*p+3<=20&&2*p+4<=20))
		return 0;
		
	return -1 ;
	}
}	
	
	
	


int flush()
{
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=30;j++)
		{
			p[i][j]=0;
		}
	}
}

int main()
{
	
	int test ;
	
	int n,sup,mv,;
	
	scanf("%d",&test);
	int cnt=0;
	freopen("out13.txt","w",stdout);
	while(test--)
	{
		int bts=0;
		int bss=0;
		int bboth=0;
		int bns=0;
		int result=0;
		int ts=0,ss=0;
		int ns=0,both=0;
		scanf("%d %d %d",&n,&sup,&mv) ;
		for(int i=1;i<=n;i++)
			scanf("%d",&sum[i]) ;
		for(int j=1;j<=n;j++)
		{
			
			for(int i=mv;i<=10;i++)
			{
				p[i][sum[j]]=logic(i,sum[j]) ;
			
			}
		
			
			
		}
			for(int j=1;j<=n;j++)
			{
				bts=0;
				bss=0;
				bboth=0;
				for(int i=mv;i<=10;i++)
				{
					if(p[i][sum[j]]==1)
						bts=1;
					if(p[i][sum[j]]==0)
						bss=1;
					if(bts==1&&bss==1)
						bboth=1;
					
				}
				
			//	result=result+(bts+bss-bboth);
				ts+=bts;
				ss+=bss;
				both+=bboth;
				if(bts==0&&bss==0&&(sum[j]>=2&&sum[j]<=28))
					ns++ ;
			}
			if(ss-both>=sup)
			result=result+ts+sup;
			if(ss-both<sup)
				result=result+ts+ss-both;
				++cnt ;
				printf("Case #%d: %d\n",cnt,result);
			flush() ;
	}
}
