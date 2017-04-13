#include<iostream>
using namespace std;

int main()
{
  int t,n,k;
  int x=1;
 int i,y;
 int cnt=1;
  cin>>t;
  int a[20],r,pos,s,sum,pos_start;
  while(t--)
  {
     cin>>r>>k>>n;
     for(i=0;i<n;i++)
       cin>>a[i];
     pos = pos_start =0;
     s = 0;
     sum =0;
     while(r--)
     {
       s=0;
       while(s<k)
       {
	 if(s+a[pos] > k)
	   break;
	 s+=a[pos];
	 pos++;
	 if(pos==n)
	   pos=0;
	 if(pos==pos_start)
	   break;
       }
       sum+=s;
       pos_start = pos;
     }
     cout<<"Case #"<<cnt<<": "<<sum<<endl;
     cnt++;
    
    
  }
  return 0;
}