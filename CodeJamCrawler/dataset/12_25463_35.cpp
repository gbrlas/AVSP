#include <cstdio>
#include <iostream>

using namespace std;

#define openfile {freopen("A-small-attempt1 (1).in","r",stdin);freopen("a.out","w",stdout);}
#define debug 01

const char p[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int t;
string s;
char ch;

string trans(string s) {
	string res = "";
	for (int i=0;i<s.length();i++) {
		if (s[i]==' ') res += ' ';
		else  res += p[s[i]-97];
	}
	return res;
}

int main() {
	if (debug) openfile;
	cin >> t;
	scanf("%c",&ch);
	for (int i=0;i<t;i++) {
		getline(cin,s);	
		cout << "Case #" << i+1 << ": " << trans(s) << endl;
	}
}
