#include<stdio.h>
#include<stdlib.h>


int isperiod(long int i)
{
int p[9]={1,10,100,1000,10000,100000,1000000,1000000,100000000};
int j=1,k=0,l;
for(;j<=i;j*=10,k++);
//a[k--]='\0';
//printf("i%ld j%d k%d\n",i,j,k);

l=i;
for(j=0;j<k/2;j++)
	{
	l=l/10+(l%10)*p[k-1];
	//if(i==1212) printf(" D%dD ",l);
	if(i==l) return j+1;	
	}
	
return 0;
}

void ito(long int i, char a[])
{
int j=1,k=0;
for(;j<=i;j*=10,k++);
a[k--]='\0';
//printf("i%ld j%d k%d\n",i,j,k);
for(;k>=0;k--)
	{
	a[k]=i%10+'0';
	i/=10;
	}
	
		
}

int main()
{
int i,j,k,t,a,b,l,T,f1,f2,p,pf;
long ans;
char num1[10],num2[10];
scanf("%d", &t);

for(T=0;T<t;T++)
	{ 

	ans=0;
	scanf("%d",&a);
	scanf("%d",&b);
	
	ito(b,num2);
	p=0;
	for(i=a;i<b;i++)
		{
		//k=i;
		ito(i,num1);
		p=isperiod(i);
		pf=0;
		for(l=0;num1[l];l++);
	///	if(i==1212) printf("%d\n",p);
		for(j=1;j<l;j++)
			{		f1=0;f2=0;
			for(k=0;k<l;k++)
				{
				if(f1&&f2) {ans++; pf++;break;}
				///if(i==2022)
				//printf("%d: %c %c %c j%d k%d\n",i,num1[(j+k)%l],num1[k],num2[k],j,k);
				if(!f1)
					{//if(i==2022)
					//printf("GO1\n");
					if(num1[(j+k)%l]>num1[k]) f1=1;
					else if((num1[(j+k)%l]-'0')<(num1[k]-'0')) break;
					}
				if(!f2)
					{//if(i==2022)
				//printf("GO2\n");
					if(num1[(j+k)%l]<num2[k]) f2=1;
					else if(num1[(j+k)%l]>num2[k]) break;
					}
				//printf("\n");
	
				}
			if((k==l)&&(f1)) {pf++;ans++;}
			}
		if(p&&pf) ans= ans-pf+pf*p/l;	
		}	
	printf("Case #%d: ",T+1);
	printf("%ld\n",ans);
	}

return 0;
}
