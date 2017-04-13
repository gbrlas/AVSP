#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void main()
{

   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
	int n,sz,pos;
	cin>>n;
	char mn;
	bool find;
	string s;
	for(int i=0;i<n;i++)
	{
		find =false;
		cin>>s;
		sz=s.length();
		int k=sz-1;
		while(k>=1)
		{	
			if(s[k]<=s[k-1])
			{
				k--;
			}
			else
			{
				find=true;
				break;
			}
		}

		if(find)
		{
			int raz=10;
			pos=k-1;
			for(int f=k;f<sz;f++)
			{
				if(s[k-1]<s[f]&&raz>s[f]-s[k-1])
				{
					raz=s[f]-s[k-1];
					pos=f;
				}
			}
			swap(s[pos],s[k-1]);
			sort(s.begin()+k,s.end());
			cout<<"Case #"<<i+1<<": "<<s<<endl;
		}
		else
		{
			sort(s.begin(),s.end());
			mn=s[0];
			int t=0;
			for(int j=0;j<sz;j++)
			{
				if(s[j]!='0')	
				{
					t=j;
					break;
				}
			}
			swap(s[0],s[t]);
			cout<<"Case #"<<i+1<<": "<<s[0]<<"0";
			for(int i=1;i<s.length();i++)
				cout<<s[i];
			cout<<endl;
		}
	}
}