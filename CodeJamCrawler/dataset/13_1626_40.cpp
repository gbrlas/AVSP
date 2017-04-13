#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;

string NumberToString ( int Number )
{
	stringstream S;
	S << Number;
	return S.str();
}
string reverse(string s)
{
	int length = s.length() ;
	int hold, i, j;

	for (i = 0, j = length-1; i < j; i++, j--)
	{
		hold = s[i];
		s[i] = s[j];
		s[j] = hold;
	}
	return s;
}

bool ispalindrome(string s){
	if( reverse(s)==s )
		return true;
	else
		return false;
}

bool isSquare (double NUMBER){
	double d = sqrt(NUMBER);
	int i = d;
	if ( d == i )
		return true;
	else
		return false;
}

int main()
{
	freopen("C-small-attempt1.in", "rt", stdin);
	freopen("C-small-attempt1.out", "wt", stdout);
	int number=0;
	double x;
	int testcases;
	int num1,num2;
	cin>>testcases;
	for (int i = 1; i <= testcases; i++)//test cases
	{
		cin>>num1>>num2;
		number=0;
		for (int j = num1; j <= num2; j++)//range between 2 numbers
		{
			x=sqrt((double)j);
			if(ispalindrome(NumberToString(j)) && isSquare(j) && ispalindrome(NumberToString(x)))
			{
				number++;
			}
		}
		cout << "Case #" << i << ": " << number << endl;
	}
	return 0;
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

using namespace std;

int main () 
{
//freopen("B-small.in", "rt", stdin); 
//freopen("B-small.out", "wt", stdout);
int t,n,m,x,c=1;
cin >> t;
while(t--)
{
cin >> n >> m;
vector<vector<int> >v(n);
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
cin >> x;
v[i].push_back(x);
}
}
cout << "Case #" << c++ << ": " ;

}
return 0;
}
*/




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