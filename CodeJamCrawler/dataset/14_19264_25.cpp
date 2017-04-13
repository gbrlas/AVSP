#include<stdio.h>
int main()
{
	freopen("C:\\Users\\jehovah\\Downloads\\test.in","r",stdin);
	freopen("C:\\Users\\jehovah\\Downloads\\output.txt","w",stdout);
    int j,i,p;
    double x,c,f,t=0,m,n,b=2.0,a,d;
	scanf("%d",&j);
	p=j;
	while(j!=0)
	{
		scanf("%lf %lf %lf",&c,&f,&x);
		for(i=0;i<x;i++)
		{
			a=c/b;
			d=x/b;
			if(a+x/(b+f)<d)
			{
			b=b+f;
			t=a+t;
			//printf("%lf %lf\n",t,d);
			}
			else
			break;
		}
		
		t=t+d;
		printf("Case #%d: %.7lf\n",p-j+1,t);
		a=0;
		b=2;
		d=0;
		t=0;
		j--;
		
	}
	
}
