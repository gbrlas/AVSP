#include<stdio.h>
int main()
{
	int i,j,k,a[100],t;
	char s[1000],c;
	freopen("a1.in","r",stdin);
freopen("c2.txt","w",stdout);
	
  scanf("%d%c",&t,&c);
  for(k=0;k<t;k++)
  {
  gets(s);
  // puts(s);
	for(i=0;i<100;i++)
	a[i]=0;
	 
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='w') { a[1]++;  }
		if(s[i]=='e') { a[2]+=a[1]; a[7]+=a[6];  a[15]+=a[14];}
		if(s[i]=='l') { a[3]+=a[2];}
		if(s[i]=='c')  { a[4]+=a[3]; a[12]+=a[11]; }
		if(s[i]=='o')  { a[5]+=a[4]; a[10]+=a[9]; a[13]+=a[12]; }
		if(s[i]=='m') { a[6]+=a[5]; a[19]+=a[18]; }
		if(s[i]==' ') { a[8]+=a[7]; a[11]+=a[10]; a[16]+=a[15]; }
		if(s[i]=='t') { a[9]+=a[8]; }
		if(s[i]=='d') { a[14]+=a[13]; }
		if(s[i]=='j')  { a[17]+=a[16]; }
		if(s[i]=='a')  { a[18]+=a[17] ;}
	   for(j=0;j<100;j++)
	   a[j]=a[j]%10000;
	}
	printf("Case #%d: ",k+1);
	if(a[19]/1000==0) printf("0");
	if(a[19]/100==0)  printf("0");
	if(a[19]/10==0)   printf("0");
	printf("%d\n",a[19]);
  }
}
