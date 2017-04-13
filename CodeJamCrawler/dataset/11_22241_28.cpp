#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int cases = 1;
	while(t>0)
	{
		int n,l,h;
		cin>>n>>l>>h;
		vector<int>a;
		for(int i=0;i<n;i++)
		{
			int t1;
			cin>>t1;
			a.push_back(t1);
		}
		int minm = 0;
		bool pos = false;
		for(int i=l;i<=h;i++){
			int c = 0;
			int fre = i;
			for(int j=0;j<a.size();j++){
				if( a[j]!=0 && i!=0 && (fre%a[j]==0 || a[j]%fre ==0))
				{
					c++;
				}
			}
			if(c == (int)a.size() && !pos)
			{
				minm = i;
				pos = true;
			}
		}
		cout<<"Case #"<<cases++<<": ";
		if(pos)
		{
			cout<<minm<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		t--;
	}
}