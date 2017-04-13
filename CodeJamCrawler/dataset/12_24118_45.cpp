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

int power(int base,int p)
{
    int ans= 1;
    for (int i=1; i<=p; ++i) ans*= base;
    return ans;
}

int digit(int a)
{
    int res= 0;
    while (a)
    {
        res++;
        a/= 10;
    }
    return res;
}

bool func(int n,int m)
{
    int a= n,dig= digit(a),dig2= digit(m),rem;
    //if (dig!=dig2) return 0;

    while (1)
    {
        rem= a%10;
        a/= 10;
        a= rem*power(10,dig-1)+a;
        //printf("%d\n",a);
        if (a==n) break;
        if (a==m) return 1;
    }
    return 0;
}

int main()
{
    //cout<<func(12345,33212)<<endl;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,x,a,b;
	scanf("%d",&t);

	for (x=1; x<=t; ++x)
	{
        scanf("%d%d",&a,&b);
        int i,j,cnt= 0;

        for (i=a; i<=b; ++i)
        {
            for (j=i+1; j<=b; ++j)
            {
                if (func(i,j) || func(j,i))
                {
                    //printf("%d %d\n",i,j);
                    cnt++;
                }
            }
        }
        //cnt/= 2;
        printf("Case #%d: %d\n",x,cnt);
	}

	return 0;
}
