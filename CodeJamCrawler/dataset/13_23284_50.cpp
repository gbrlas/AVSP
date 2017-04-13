#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[1000];
int perfect[200];
void palin()
{
	int i,j;
	for(i=1;i<10;i++) arr[i-1] =i;
	i=9;
	for(j=10;j<100;j++) if(j%10==j/10) arr[i++]=j;
	for(j=100;j<1000;j++) if(j%10==j/100) arr[i++]=j;
	
	int k=0;
	for(j=0;j<i;j++) 
	{
		
		double x=sqrt(arr[j]);
		int xx;
		if((int)x==x) 
		{
		xx=(int)x; 
		if(binary_search(arr,arr+i,xx)) perfect[k++]=arr[j];
	    }
	}
}
int main()
{
	palin();
	//for(int i=0;i<150;i++) cout<<perfect[i]<<" ";
	int t;
	cin>>t;
	int c;
	for(c=1;c<=t;c++)
	{
		int a,b;
		cin>>a>>b;
		int lower=lower_bound(perfect,perfect+5,a)-perfect;
		int higher=upper_bound(perfect,perfect+5,b)-perfect;
		cout<<"Case #"<<c<<": "<<higher-lower<<endl;
	}
}
