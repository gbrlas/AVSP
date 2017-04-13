#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1006
using namespace std;
int main()
{
	FILE *f=fopen("A-small-attempt3.in","r");
	int t,h,co=0;
	fscanf(f,"%d",&t);
	//cin>>t;
	h=t;
	
	while(t--)
	{
		
		co++;
		int r1,t1;
		fscanf(f,"%d",&r1);
		//cin>>r1;
		for(int i=0;i<(r1-1)*4;i++)
			fscanf(f,"%d",&t1);
			//cin>>t1;
		int arr[17]={0};
		for(int i=0;i<4;i++)
		{
			fscanf(f,"%d",&t1);	
		//	cin>>t1;
			arr[t1]=1;
		}
		for(int i=0;i<16-(r1*4);i++)
			fscanf(f,"%d",&t1);
			//cin>>t1;
		int r2;
		fscanf(f,"%d",&r2);
		//cin>>r2;
		for(int i=0;i<(r2-1)*4;i++)
			fscanf(f,"%d",&t1);
		int arr1[17]={0},counter=0;
		for(int i=0;i<4;i++)
		{
			fscanf(f,"%d",&t1);
			//cin>>t1;
			arr1[t1]=1;
		}
		for(int i=0;i<16-(r2*4);i++)
			fscanf(f,"%d",&t1);
			//cin>>t1;
		int j=0;	
		for(int i=1;i<17;i++)
		{
			if(arr1[i]==1 && arr[i]==1)
			{
				counter++;
				j=i;
			}
		}
		FILE *fp;
		if(t==h-1)
			fp=fopen("out.txt","w");
		else
			fp=fopen("out.txt","a");
		//cout<<counter<<endl;
		if(counter==1)
			fprintf(fp,"Case #%d: %d\n",co,j);
			//cout<<"Case #1: "<<j<<endl;
		else if(counter>1)
			fprintf(fp,"Case #%d: Bad magician!\n",co);
			//cout<<"Case #2: Bad magician!"<<endl;
		else if(counter==0)
		{
			fprintf(fp,"Case #%d: Volunteer cheated!\n",co);	
			//cout<<"Case #3: Volunteer cheated"<<endl;
		}
	}
}
