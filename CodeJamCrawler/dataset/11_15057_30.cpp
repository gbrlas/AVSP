#include <stdio.h>

int sum(int [],int);
int ssum(int [],int);
int power(int,int);

int main()
 {
	int T,N,C[16],i,j,k,flag=0,max=-1,inter,sean[16],patrick[16],sf,pf;
	scanf("%d",&T);
	if(T<1 || T>100)
		return 1;
	for(k=0;k<T;k++)
	 {
		flag=0;
		max=-1;
		scanf("%d",&N);
		if(N<2 || N>15)
			return 1;
		for(j=0;j<N;j++)
		 {
			scanf("%d",&C[j]);
			if(C[j]< 1 || C[j]>1000000)
				return 1;
		 }
		for(i=1;i<power(2,N)-1;i++)
		 {
			sf=0;pf=0;
			for(j=0;j<N;j++)
			 {
				if((i & power(2,j)) !=0)
					sean[sf++]=C[j];
				else
					patrick[pf++]=C[j];
			 }
			if(sum(sean,sf)==sum(patrick,pf))
			 {
				flag=1;
				inter=ssum(sean,sf);
				if(inter>max)
					max=inter;
			 }
		 }
		if(!flag)
			printf("Case #%d: %s\n",k+1,"NO");
		else
			printf("Case #%d: %d\n",k+1,max); 
	 }
	return 0;
 }

int sum(int c[],int n)
 {
	int i,sum=0;
	for(i=0;i<n;i++)
		sum=sum ^ c[i];
	return sum;
 }

int ssum(int s[],int n)
 {
	int i,sum=0;
	for(i=0;i<n;i++)
 		sum+=s[i];
	return sum;
 }	

int power(int m,int n)
 {
	int prod=1,i;
	for(i=0;i<n;i++)
	 {
		prod*=m;
	 }
	return prod;
 }			
