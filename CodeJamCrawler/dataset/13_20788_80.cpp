#include <iostream>
#include <string.h>
#include <string>
#define fs(x) for (x=0;x<4;x++)
using namespace std;
bool ans,f;
string s[4];
void sub(char q)
{
	int i,j;
	fs(i)
	{
		f=1;
		fs(j) if (s[i][j]==q || s[i][j]=='.') {f=0; break;}
		if (f) {ans=1; return;}
		f=1;
		fs(j) if (s[j][i]==q || s[j][i]=='.') {f=0; break;}
		if (f) {ans=1; return;}
	}
	if (ans) {return;}
	f=1;
	fs(i)
	{
		if (s[i][i]==q || s[i][i]=='.') {f=0; break;}
	}
	if (f) {ans=1; return;}
	f=1;
	fs(i)
	{
		if (s[i][3-i]==q || s[i][3-i]=='.') {f=0; break;}
	}
	if (f) {ans=1; return;}
}
int main()
{
	int z,t;
	cin>>t;
	for (z=1;z<=t;z++)
	{
		int i,j,k,l;
		for (i=0;i<4;i++) {cin>>s[i];}
		ans=0;
		sub('O');
		if (ans) {printf("Case #%d: X won\n",z); continue;}
		sub('X');
		if (ans) {printf("Case #%d: O won\n",z); continue;}
		f=0;
		fs(i) fs(j) if (s[i][j]=='.') {f=1; break;}
		if (f)
		{
			printf("Case #%d: Game has not completed\n",z);
		}
		else
		{
			printf("Case #%d: Draw\n",z);
		}
	}
}