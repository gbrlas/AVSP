#include <iostream>
#include <math.h>
using namespace std;
bool Perv(unsigned long long);
void main()
{
	FILE *f1,*f2;
	f1=fopen("D:\\inp.txt","r");
	f2=fopen("D:\\out.txt","w");
	int kol=0;
	fscanf(f1,"%d\n",&kol);
	
	for(int k=0;k<kol;++k)
	{
		unsigned long long int a,b;
		int kil=0;
		long double b1;
	fscanf(f1,"%I64d%I64d\n",&a,&b);
		
		for(unsigned long long ch=a;ch<=b;++ch)
		{
			if(ch==10000)
				b1=1;
		   if(Perv(ch))	
		   {
			   b1=pow(float(ch),float(0.5));
			   if(Perv(b1)&&b1-int(b1)==0)
			   {
				   kil++;
			   }
		   }
         
		}
		fprintf(f2,"Case #%d: %d\n",k+1,kil);
	}
	fclose(f1);
	fclose(f2);
}
bool Perv(unsigned long long ch)
{
	char str[100];
	sprintf(str,"%d",ch);
	for(int i=0;i<(strlen(str)/2);++i)
	{
		if(str[i]!=str[strlen(str)-i-1])
			return(0);
	}
	return(1);
}