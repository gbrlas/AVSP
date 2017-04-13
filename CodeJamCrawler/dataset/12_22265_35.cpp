#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
//               abcdefghijklmnopqrstuvwxyz
const char s[]={"yhesocvxduiglbkrztnwjpfmaq"};
//                 abcdefghijklmnopqrstuvwxyz
//const char s[]={"ynficwlbkuomxsevzpdrjgatha"};

int task, cs=0;
char c[1000];
string ret;

int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	gets(c);
	while (gets(c))
	{
		ret = "";
		for (int i=0; c[i]; i++)
		if ( 'a'<=c[i] && c[i]<='z' )
			ret += s[c[i]-'a'];
		else
			ret += c[i];
		printf("Case #%d: %s\n", ++cs, ret.c_str());
	}
	return 0;
}
