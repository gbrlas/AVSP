#include<stdio.h>
int main()
{ int t,i,j,k,a,b;
	float p[100000],p1,p2,temp,l;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{	scanf("%d %d",&a,&b); 
	  p1=1;
		for(j=0;j<a;j++)
		 {scanf("%f",&p[j]);
     p1=p1*p[j];
   }
		l=p1*(b-a+1)+(1-p1)*(2*b-a+2);
		for(j=1;j<=a;j++)
			{ 	p1=1;
				for(k=0;k<a-j;k++)
					p1=p1*p[k];
				temp=p1*(b-a+1+2*j)+(1-p1)*(2*b-a+2+2*j);
				if(temp<l)
					l=temp;
			}
		if(l>b+2)
			l=b+2;
		printf("Case #%d: %f\n",i+1,l);			
	}
	return 0;
}	
				
