#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
int pr(int i)
{
	int temp=1;
	for(int j=1;j<=i;j++)
	{
		temp=temp*10;
	}
	return temp;
}
int swap1(int a,int i)
{
	int p=pr(i),n=0;
	int temp=a%p;
	int div=a/p;
	int t=div;
	while(t!=0)
	{
		t=t/10;
		n++;
	}
	p=pr(n);
	if(temp==0)return div;
	return temp*p+div;
}
int chk(int a,int b)
{
	int no=0,res=0;
	int temp=a;
	while(temp!=0)
	{
		temp=temp/10;
		no++;
	}
	for(int i=1;i<no;i++)
	{
		for(int j=a;j<=b;j++)
		{
			int swp=swap1(j,i);
			if(j!=swp && swp<=b && j<swp)
				{
					res++;
				}
		}
	}
	return res;
}
int main()
{
	int a[50],b[50];
	FILE *fp,*out;
	if((fp=fopen("C-small-attempt0.in","r"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	if((out=fopen("br.txt","w"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	getc(fp);
	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%d",&a[i]);
		getc(fp);
		fscanf(fp,"%d",&b[i]);
		getc(fp);
	}
	int res;
	for(int i=0;i<n;i++)
	{
		fprintf(out,"Case #%d: ",i+1);
		res=chk(a[i],b[i]);
		fprintf(out,"%d\n",res);
	}
	fclose(fp);
	fclose(out);
}
