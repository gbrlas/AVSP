#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("C-small-attempt5.in","r",stdin);freopen("C-small-attempt5.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int n;
	cin>>n;
	string ppp;
	getline(cin,ppp);
	const string str="welcome to code jam";
	for(int i=0;i<n;i++)
	{
		int a[20];
		for(int j=0;j<20;j++)
			a[j]=0;
		a[0]=1;
		string s;
		getline(cin,s);
		int l=s.length();
		for(int j=0;j<l;j++)
		{
			for(int k=0;k<19;k++)
			{
				if(s[j]==str[k])					
					a[k+1]+=(a[k]%10000);				
			}
		}		
		cout<<"Case #"<<(i+1)<<": "<<setfill('0')<<setw(4)<<(a[19]%10000)<<endl;
	}
	return 0;
}