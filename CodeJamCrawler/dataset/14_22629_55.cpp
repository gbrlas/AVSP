#include <iostream>
#include <iomanip>
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
	FILE *ff=fopen("D-small-attempt0.in","r");
	int t,y,co=0;
	fscanf(ff,"%d",&t);
	//cout<<t<<endl;
	y=t;
	while(t--)
	{
		int m;
		fscanf(ff,"%d",&m);
		co++;
		double narr[m],karr[m];
		for(int i=0;i<m;i++)
			fscanf(ff,"%lf",&narr[i]);
		for(int i=0;i<m;i++)
			fscanf(ff,"%lf",&karr[i]);
		
		sort(narr,narr+m);
		sort(karr,karr+m);
		//for(int i=0;i<m;i++)
		//	cout<<narr[i]<<endl;
		int j=0,nw=m;
		for	(int i=0;i<m;i++)
		{
			while(narr[i]>karr[j])
			{
				if(j<m)
					j++;
				else if(j==m)
				{
					i=m;
					break;
				}	
				
			}
			if(j==m)
				break;
			j++;
			nw--;
		}
		int nw1=0;
		j=0;
		for(int i=0;i<m;i++)
		{
			while(narr[j]<karr[i])
			{
				if(j<m)
					j++;
				else
					break;
			}
			if(j==m)
				break;
			else if(narr[j]>karr[i])
			{
				nw1++;
				j++;
				karr[i]=2;	
			}
			
			
				
					
		}
		
		//cout<<nw<<endl;	
		
		
		
		FILE *fp;
		if(t==y-1)
			fp=fopen("out3.txt","w");
		else
			fp=fopen("out3.txt","a");
		fprintf(fp,"Case #%d: %d %d\n",co,nw1,nw);
		
	}
	  
return 0;		
}
