#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define repf(i,a,b) for(int i=(a); i<=(b); ++i)
#define repd(i,a,b) for(int i=(a); i>=(b); --i)
#define ll long long
#define PB(i) push_back(i)
#define MP make_pair
#define N 105
char a[N],b[N];
int test,n;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&test);
	repf(ror,1,test)
	{
		scanf("%d",&n);
		scanf("%s%s",a,b);
		int lena=strlen(a),lenb=strlen(b);
		int sum=0;
		int i=0,j=0,flag=0;
		while(true){
			if(a[i]==b[j]) ++j,++i;
			else if(i==0 && j==0){ flag=1;break;}
			else if(i==0){
				if(b[j]==b[j-1]) ++j,sum++;
				else { flag=1; break;}
			}
			else if(j==0)
			{
				if(a[i]==a[i-1]) ++i,sum++;
				else{flag=1; break;} 
			}
			else{
				if(a[i]==a[i-1]) sum++,++i;
				else if(b[j]==b[j-1]) sum++,++j;
				else {flag=1; break;}
			}
			if(i==lena)
				while(j<lenb)
					if(b[j]!=a[lena-1]){
						flag=1; break;
					}
					else sum++,++j;

			if(j==lenb)
				while(i<lena)
					if(a[i]!=b[lenb-1])
					{
						flag=1; break;
					}
					else sum++,++i;
            if(i==lena) break;
		}
		printf("Case #%d: ",ror);
		if(flag==1)
			printf("Fegla Won\n");
		else printf("%d\n",sum);
	}
	return 0;
}
