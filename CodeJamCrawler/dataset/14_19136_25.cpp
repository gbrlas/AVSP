#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstring>

#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) scanf("%lld",&i)
#define psl(i) printf("%lld ",i)
#define pal(i) printf("%lld\n",i)

#define pb push_back
#define fr(i,s,n) for(int i=s;i<n;i++)

#define De_bug 0
#define pdeb(s,i) if(De_bug)cout<<"DEBUG "<<s<<" "<<i<<endl;

#define MOD 1000000007

using namespace std;

int main()
{
    int t, r, n;
    s(t);
    fr(cn, 1, t+1)
    {
        map<int, bool> table;
        s(r);
        fr(i,0,4)
        {
            fr(j,0,4)
            {
                s(n);
                if(i==r-1)
                    table[n] = true;
            }
        }
        vector<int> answer;
        s(r);
        fr(i,0,4)
        {
            fr(j,0,4)
            {
                s(n);
                if(i==r-1)
                    if(table[n])
                        answer.pb(n);
            }
        }
        if(answer.size()==1)
        {
            printf("Case #%d: %d\n", cn, answer[0]);
        }
        else if(answer.size()==0)
        {
            printf("Case #%d: Volunteer cheated!\n", cn);
        }
        else
        {
            printf("Case #%d: Bad magician!\n", cn);
        }
    }
}
