#include<stdio.h>
#include<conio.h>
void main(){

double rate;
int t,k;
double tm,t1,t2,x,c,f,ck=0;
FILE *fp1,*fp2;

fp1=fopen("in.in","r");
fp2=fopen("out.in","w");
clrscr();
fscanf(fp1,"%d",&t);
for(k=0;k<t;k++){
fscanf(fp1,"%lf %lf %lf",&c,&f,&x);
rate=2;tm=0;ck=0;
while(ck<x){
	t1=x/rate; //buys
	t2=c/rate + x/(rate+f);  //doesnt buy
	if(t1<t2){
		  ck=x;
		  tm+=t1;
		  }
	else    {
		tm+=(c/rate);
		rate+=f;
		}
	}
fprintf(fp2,"Case #%d: %0.7lf\n",k+1,tm);
}
getch();
}