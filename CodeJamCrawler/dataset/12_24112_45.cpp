#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,t;
	scanf("%d",&t);

	getchar();
	char a[110]= {"yhesocvxduiglbkrztnwjpfmaq"};

	for (x=1; x<=t; ++x)
	{

	    char s[110];
	    gets(s);
	    //puts(s);

	    int i,len= strlen(s);
	    for (i=0; i<len; ++i)
	    {
	        if (s[i]>='a' && s[i]<='z') s[i]= a[s[i]-'a'];
	    }
	    printf("Case #%d: ",x);
	    puts(s);
	}

	return 0;
}
