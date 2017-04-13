#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
int palid(long int a){
	long int temp=0;
	long int aa=a;
	while (a > 0){
		int rem = a % 10;
		temp = temp * 10 + rem;
		a = a / 10; 
	}
	if (aa == temp){
		printf("%d",a);
		return 1;
	}
	else
		return 0;
}
int chk(long int l,long int h){
	long int s=sqrt(l);
	if(s*s<l)
		s++;
	int count=0;
	
	while(s*s<=h){
		if(palid(s*s)==1){
			if(palid(s)==1){
				count++;
			}
		}
		s++;
	}
	return count;
}
int main()
{
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
	int no,res;
	fscanf(fp,"%d",&no);
	getc(fp);
	for(int i=0;i<no;i++){
		long int l,h;
		fscanf(fp,"%ld",&l);
		getc(fp);
		fscanf(fp,"%ld",&h);
		getc(fp);
		printf("%ld %ld\n",l,h);
		int p=chk(l,h);
		fprintf(out,"Case #%d: ",i+1);
		fprintf(out,"%d\n",p);
	}
	//cin>>res;
}