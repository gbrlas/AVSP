#include<iostream>
#include<string>
using namespace std;

string arr[4];

bool Xwon();
bool Owon();

int main () 
{
	freopen("A-large.in", "rt", stdin); 
	freopen("A-large.out", "wt", stdout);

	int testcases;
	cin>>testcases;
	for (int i = 1; i <= testcases; i++)
	{

		for(int k=0;k<=3;k++)
			cin>>arr[k];

		if(Xwon())
			cout<<"Case #"<<i<<": "<<"X won";

		else if(Owon())
			cout<<"Case #"<<i<<": "<<"O won";

		else
		{
			bool dot = false;
			for(int Q=0;Q<=3;Q++)
				for(int W=0;W<=3;W++)
					if(arr[Q][W]=='.')
						dot = true;

			if(dot)
				cout<<"Case #"<<i<<": "<<"Game has not completed";
			else
				cout<<"Case #"<<i<<": "<<"Draw";
		}
		cout << "\n";
	}
	return 0;
}
bool Xwon()
{
	int x=0,M=0,L=0,H=0;
	for(int i=0;i<=3;i++)
	{
		if(arr[i][i]=='X'||arr[i][i]=='T')
			L++;
		x=M=0;
		for(int k=0;k<=3;k++)
		{
			if(arr[i][k]=='X'||arr[i][k]=='T')
				x++;
			if(arr[k][i]=='X'||arr[k][i]=='T')
				M++;

		}

		if(x==4||M==4)
			return true;
	}
	for(int a=0,g=3;g>=0;a++,g--)
		if(arr[g][a]=='X'||arr[g][a]=='T')
			H++;


	if(L==4||H==4)
		return true;

	else
		return false;
}


bool Owon()
{
	int x=0,M=0,L=0,H=0;
	for(int i=0;i<=3;i++){
		if(arr[i][i]=='O'||arr[i][i]=='T')
			L++;
		x=M=0;
		for(int k=0;k<=3;k++){
			if(arr[i][k]=='O'||arr[i][k]=='T')
				x++;
			if(arr[k][i]=='O'||arr[k][i]=='T')
				M++;

		}

		if(x==4||M==4)
			return true;
	}
	for(int a=0,g=3;g>=0;a++,g--)
		if(arr[g][a]=='O'||arr[g][a]=='T')
			H++;


	if(L==4||H==4)
		return true;
	else
		return false;
}







/*#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
using namespace std;

bool check(long long i)
{
string s="";
while(i)
{
s += (char)(i%10+48);
i/=10;
}
for(long long i=0;i<s.size()/2;i++)
{
if(s[i] != s[s.size()-1-i])
return false;
}
return true;
}

bool checkDouble(long long x)
{
long double y = sqrt((long double)x);
long long z = y;
if( z == y)
return true;
else
return false;
}

int main()
{
freopen("C-large-1.in", "rt", stdin); 
freopen("C-large-1.out", "wt", stdout);
int t;
long long a,b,ret,x,count=1;
cin >> t;
while(t--)
{
cin >> a >> b;
ret=0;
for(long long i=a;i<=b;i++)
{
if(checkDouble(i)){
x = sqrt((double)i);
if(check(i) && check(x))
ret++;
}
}
cout << "Case #" << count << ": " << ret << endl;
count++;
}
return 0;
}*/