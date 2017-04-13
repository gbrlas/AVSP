#include <iostream>
//#include <iomanip>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
//#define MAX 1006
using namespace std;
int main()
{
	FILE *ff=fopen("B-small-attempt2.in","r");
	int t,y,co=0;
	fscanf(ff,"%d",&t);
	//cout<<t<<endl;
	y=t;
	while(t--)
	{
		co++;
	//	cout<<"case "<<co<<endl;
		double c,f,x;
		fscanf(ff,"%lf %lf %lf",&c,&f,&x);
	//	c=(double)(2.0000004+c*2);
	//	printf("%.7lf %lf %lf\n",c,2*f,2*x);
	//	cout<<c<<f<<x<<endl;
		double min,g[10000],h[10000];
		h[0]=0;
		g[0]=(double)(x/2);
		min=(double)g[0];
		//FILE *fp1=fopen("tester.txt","w");
		//if(co==93)
		//{
		//	printf("HELLO WORld %.7lf\n",min);
		//		fprintf(fp1,"hello %.7lf\n",g[0]);
		//}
		
		//fprintf(fp1,"hello\n");
		double raj=h[0];
		for(int i=1;i<10000;i++)
		{
			h[i]=(double)(2+(i-1)*f);
			h[i]=(double)(c/h[i]);
			//cout<<h[i]<<endl;
			
			//for(int j=0;j<i+1;j++)
				raj=(double)(raj+h[i]);
			g[i]=(double)(2+i*f);
			g[i]=(double)(x/g[i]);
			g[i]=(double)(g[i]+raj);
			//if(co==93)
			//	fprintf(fp1,"%d hello %.7lf hi %.7lf\n",i,g[i],raj);
			if(g[i]<=min)
				min=(double)g[i];
			else
				break;
			
			
			
		}
		//cout<<min<<endl;
		FILE *fp;
		if(t==y-1)
			fp=fopen("out4.txt","w");
		else
			fp=fopen("out4.txt","a");
		fprintf(fp,"Case #%d: %.7lf\n",co,min);
		
	}
	  
return 0;		
}
