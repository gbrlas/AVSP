#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<vector>

using namespace std ;


#define MAX 1001

int p[9];

	int number_array(int n,int a[])
	{
		int b[10];
		int cnt=0;
		while(n)
		{
			b[cnt++]=n%10;
			n/=10 ;
		}
		int k=cnt;
		 a[0]=cnt;
		for( int i=0;i<cnt;i++)
			a[k--]=b[i] ;
		
	}
	
	int array_number(int a[])
	{
		int dig=a[0];
		int lim=dig;
		int val=0;
		for(int i=1;i<=lim;i++)
			val+=(a[i]*p[dig--]);
		return val;	
	}
	
	int is_same(int a[],int b[])
	{
		int lim=max(a[0],b[0]) ;
		for(int i=1;i<=lim;i++)
			if(a[i]!=b[i])
				return 0;
			return 1 ;
	}
	
	int shift_array(int a[])
	{
		int temp=a[a[0]];
		for(int i=a[0];i>=2;i--)
		{
			a[i]=a[i-1];
		}
		a[1]=temp ;
	}
	
	int isvalid(int a[])
	{
		if(a[1]!=0)
			return 1;
		
		return 0;
			
	}
	
			int init_p(int pa[])
		{
			for(int i=0;i<10;i++)
				pa[i]=0;
		}

	
	int main()
	{
		//int a[10];
		p[1]=1;
		for(int i=2;i<=8;i++)
		p[i]=p[i-1]*10 ;
		//number_array(33324,a);
		//shift_array(a);
		//int res=array_number(a);
		//printf("%d\n",res);
			
			int test ;
			int a,b ;
			scanf("%d",&test);
			freopen("out14.txt","w",stdout);
			for(int i=1;i<=test;i++)
			{
				 //set< int > parent[MAX+1];
				 set< pair< int,int > > s;
				
				int pr[10];
				int f[10];
				int sec[10];
				init_p(pr);
				init_p(f);
				init_p(sec);
				scanf("%d %d",&a,&b);
				int temp ;
				for(int j=a;j<=b;j++)
				{
						number_array(j,pr);
						number_array(j,f);
						for(int k=1;k<pr[0];k++)
						{
							shift_array(f);
							temp=array_number(f);
							//printf("%d ",temp);
							if(j!=temp&&((j%10)))
							{
								if((temp>=a&&temp<=b)&&(isvalid(f)))
								{
									if(!s.count(make_pair(temp,j))){
									s.insert(make_pair(j,temp));
									//parent[temp].insert(j);
									//printf("%d %d\n",temp,j);
								}
							}
							
							}
						}
		        }
				printf("Case #%d: %d\n",i,s.size());
				s.clear();
				
			}
		}