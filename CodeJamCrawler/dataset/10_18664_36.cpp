#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t,i,n,j;
    int a[1000],b[1000];
    cin>>t;
    long int cnt;
    int caseno=1;
    while(t--)
    {
      cnt=0;
      cin>>n;
      for(i =0;i<n;i++)
	cin>>a[i]>>b[i];
      for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	  if((a[i]<a[j]&&b[i]>b[j]) ||(a[i]>a[j]&&b[i]<b[j]))
	    cnt++;
      cout<<"Case #"<<caseno<<": "<<cnt<<endl;
      caseno++;
    }
  
  
  return 0;
}