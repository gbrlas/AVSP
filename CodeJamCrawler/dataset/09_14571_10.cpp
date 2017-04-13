#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,l,ans;
char IS[501],s[]="welcome to code jam";

void calc(int i,int j)
{
	for(;i<l;i++){
		if(j<18 && IS[i]==s[j])
			calc(i+1,j+1);
		if(j==18 && IS[i]==s[j])
			ans++;
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
    freopen("oo.txt","w",stdout);
    scanf("%d\n",&n);
    int c=1;
    while(n--){
		gets(IS);
		l=strlen(IS);
		ans=0;
		calc(0,0);
		ans%=10000;
		printf("Case #%d: %04d\n",c,ans);
		c++;
		//printf("%s\n",IS);
	}
	return 0;
}
