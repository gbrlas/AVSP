#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)
#define _INF (1e9+1)
#define ll long long
#define _N 100001
#define MP make_pair 
#define x first
#define y second
#define _no_char '_'
#define _NONE -1

using namespace std;			

ll i,j,N,M,n,m,k,p;

int main()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-attempt3.out","w",stdout);
	
	string a[3],s[3];
	s[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	a[0] = "our language is impossible to understand";
	s[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	a[1] = "there are twenty six factorial possibilities";
	s[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	a[2] = "so it is okay if you want to just give up";
	
	int c[260];
	int len;
	
	char t;
	for(t='a';t<='z';t++)
	{
		c[t]=_NONE;
	}
	
	rep(i,3)
	{
		len = s[i].length();
		rep(j,len)
		c[s[i][j]]=a[i][j];
	}
	int k=0;
	char from='\0', too='\0';
	
	for(t='a';t<='z';t++)
	{
		if (c[t]==_NONE) 
		{
			if (from == '\0') from =t;
			too=t;
		}
	}
	
	//printf("fr = %c\n",from);
	//printf("to = %c\n",too);
	c[from] = too;
	c[too] = from;
	
	/*
	i=2;
	len = s[i].length();
	
	rep(j,len)
	printf("%c",s[i][j]);
	
	printf("\n");
	
	rep(j,len)
	printf("%c",c[s[i][j]]);

	printf("\n");
	*/
	cin>>N;
	string st;
	char buf[200];
	getline(cin,st);
	rep(i,N)
	{
		getline(cin,st);
		//cout<<buf<<endl;
		//st = buf;
		len = st.length();
	//	printf("len = %d\n%s\n",len,st.c_str());
		
		printf("Case #%i: ",i+1);
		
		rep(j,len)
		printf("%c",c[st[j]]);
		
		printf("\n");
	}	
	
	
 
	return 0;
}

