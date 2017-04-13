/*By Zine.Chant*/
#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int n;
string s;
const char a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++)
	{
		getline(cin,s);
		printf("Case #%d: ",i);
		for (int i=0;i<s.length();i++)
			if (s[i]==' ') printf(" ");
			else printf("%c",a[s[i]-'a']);
		printf("\n");
	}
	return 0;
}
