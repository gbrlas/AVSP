#include <iostream>
#include <set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cout << "Case #" << i+1 << ": " ;
		set<int>se; se.clear();
		int rx,ry;
		cin >> rx;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				int x;
				cin >> x;
				if(i==rx) se.insert(x);
			}
		}
		cin >> ry;
		int cnt=0,res=0;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				int x;
				cin >> x;
				if(i==ry && se.find(x)!=se.end())
				{
					cnt++; res=x;
				}
			}
		}
		if(cnt==1) cout << res << endl;
		if(cnt==0) cout << "Volunteer cheated!" << endl;
		if(cnt>=2) cout << "Bad magician!" << endl;
	}
}