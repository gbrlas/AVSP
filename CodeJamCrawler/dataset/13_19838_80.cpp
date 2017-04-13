// my.cpp : Defines the entry point for the console application.
//
//#define BBB a
#include "stdafx.h"
#pragma once
#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <math.h>
#include <iostream>

using namespace std;


long long palindrome(long long n)
{
long long r=0;
long long x =n;
while(x>0)
	{
	r=r*10;
	r=r + (x%10);
	x=x/10;
	}
if (n==r)
	return 1;
else
return 0;

}

long long find(long long ll,long long ul)
{
long long n,temp,ctr=0;

for(n=ll;n<=ul;n++)
	{
		temp=sqrt(float(n));
		long long floor (temp);
		if((temp*temp)==n)
			{
				if(palindrome(temp) ==1 && palindrome(n) ==1)
					{
						ctr++;
					//	cout<<n<<'\t';
				}
			}
	}
//cout <<ctr<<'\t';
return ctr;
}



//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	int a;
	int caseno=0;
	FILE *ifptr,*ofptr;
	ofptr = fopen("C-small-attempt1-output.TXT","w"); /* open for writing */
	ifptr = fopen("C-small-attempt1.in","r");
	 
	int T,i,ans;
	long long LL,UL,n,t;
	char temp[16];


//LL=100;
//UL=1000;
//ans=find(LL,UL);


//#ifdef AAA
	a = getc(ifptr) ;
//	cout<<T;
   while (a!= EOF)
   {
	   i=0;
	   while(a!=' ' && a!='\n')
		   {
			   temp[i++]=a;
			   a = getc(ifptr);
			}
	T=atoi(temp);
	cout<<"T= "<<T<<"\n";
	while(T--)
	{
		a = getc(ifptr);
		i=0;
		while(a!=' ' && a!='\n')
		   {
			   temp[i++]=a;
			   a = getc(ifptr);
			}
		temp[i]='\0';
		LL=atoi(temp);
		cout<<"Lower Limit="<<LL;
		
		a = getc(ifptr);
		i=0;
		while(a!=' ' && a!='\n' &&a!=EOF)
		   {
			   temp[i++]=a;
			   a = getc(ifptr);
			}
		temp[i]='\0';
		UL=atoi(temp);
		cout<<"\tUpper Limit ="<<UL;
		ans = find (LL,UL);	
	cout<<"\t ans = "<<ans<<'\n';		
	fprintf(ofptr,"Case #%d: %d \n",++caseno,ans);
		}
	
	a = getc(ifptr);
   
   }

	fclose(ofptr);
	fclose(ifptr);
//#endif	
	//cout<<"\n press any key to exit";
	//cin>>a;
	return 0;
}

