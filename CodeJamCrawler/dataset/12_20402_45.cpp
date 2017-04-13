#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> VI;
typedef vector<string> VS;

#define Forall(i,v)   for(int i=0;i<(int)v.size();++i)
#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define Rep(i,n)      for(int i=0;i<(n);++i)

#define All(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define Sort(c) sort((c).begin(),(c).end())

char charmap[26] = {
'y', 'h', 'e', 's', 'o', 
'c', 'v', 'x', 'd', 'u', 
'i', 'g', 'l', 'b', 'k', 
/* p q r s t */
'r', 'z', 't', 'n', 'w', 
/* u v w x y */
'j', 'p', 'f', 'm', 'a', 
'q'};

string solve(string s)
{
	string r;
	size_t n = s.length();
	For(i,0,n)
	{
		r += isalpha(s[i])?
			charmap[s[i]-'a']
		:s[i];
	}
	return r;
}

int main(int argc, char* argv[])
{
	int num_of_test_cases;
	cin >> num_of_test_cases;
	
	string s;
	getline(cin,s);
	Rep(test_case,num_of_test_cases)
	{
		getline(cin,s);
		string r = solve(s);
		cout << "Case #" << test_case+1 << ": " << r << endl;
	}
	
	return 0;
}
