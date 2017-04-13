#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, s, t) for(i = (s); i < (t); i++)
#define rrep(i, s, t) for(i = (s)-1; i >= (t); i--)
using namespace std;
int t,n,m,s,p;
int min_,min_s;
vector<int> v;
int ret;
int h[101];
int g[100][100];
int ok[100][100];
bool checkraw(int hh, int row)
{
    //cout<<hh<<" row "<<row<<endl;
    int i,j;
    rep(j,0,m) {
        if(ok[row][j] || g[row][j]==hh) continue;
        break;
    }
    if(j>=m) {
        rep(j,0,m) {
            ok[row][j]=1;
        }
        return true;
    }
    return false;
}
bool checkcol(int hh, int col)
{
    //cout<<hh<<" col "<<col<<endl;
    int i,j;
    rep(i,0,n) {
        if(ok[i][col] || g[i][col]==hh) continue;
        break;
    }
    if(i>=n) {
        rep(i,0,n) {
            ok[i][col]=1;
        }
        return true;
    }
    return false;
}
void calc()
{
    int i,j,k,hh;
    ret = true;
    rep(hh,1,101) {
        if(!h[hh]) continue;
        rep(i,0,n) {
            rep(j,0,m) {
                if(ok[i][j] || g[i][j]>hh) continue;
                if(!checkraw(hh,i) && !checkcol(hh,j)) {
                    ret = false;
                    return;
                }
            }
        }
    }
}
void input()
{
    int i,j;
    cin>>n>>m;
    rep(i,1,101) h[i]=0;
    rep(i,0,n) {
        rep(j,0,m) {
            int hh;
            cin>>hh;
            g[i][j]=hh;
            h[hh]=1;
            ok[i][j]=0;
        }
    }
}
void output(int ncase)
{
    printf("Case #%d: %s\n",ncase,(ret?"YES":"NO"));
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
