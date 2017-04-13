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
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("..\\A-small-attempt1.in","r",stdin);freopen("..\\A-small-attempt1.out","w",stdout);
//	freopen("..\\A-large.in","r",stdin);freopen("..\\A-large.out","w",stdout);
	int l,d,n;
	cin>>l>>d>>n;
	char ch[20][5050];
	for(int i=0;i<d;i++)	
		for(int j=0;j<l;j++)	
			cin>>ch[j][i];
	for(int k=0;k<n;k++)
	{
		int count=0;
		int ex[20][26];
		for(int i=0;i<20;i++)
			for(int j=0;j<26;j++)
				ex[i][j]=0;
		string s;
		cin>>s;
		int i=0;
		for(int j=0;j<l;j++)
		{				
			if(s[i]=='(')
			{
				i++;
				ex[j][s[i]-'a']=1;
				i++;
				while(s[i]!=')')
				{
					ex[j][s[i]-'a']=1;
					i++;
				}
				i++;
			}
			else 
			{
				ex[j][s[i]-'a']=1;
				i++;
			}
		}
		for(int i=0;i<d;i++)
		{
			int check=1;
			for(int j=0;j<l;j++)
			{
				if( ex[j][ch[j][i]-'a']==0)
					check=0;
			}
			if(check)
				count++;
		}
		cout<<"Case #"<<(k+1)<<": "<<count<<endl;
	}
	return 0;
}

