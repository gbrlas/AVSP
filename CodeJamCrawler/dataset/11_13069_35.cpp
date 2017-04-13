#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#define MAXN 105
using namespace std;
int n;
char mp[MAXN][MAXN];
double wp[MAXN],owp[MAXN],oowp[MAXN],rat[MAXN];
void cal_wp()
{
    int cnt,win;
    for(int i=0;i<n;i++){
        wp[i]=0;
        cnt=win=0;
        for(int j=0;j<n;j++){
            if(mp[i][j]=='0')
                cnt++;
            else if(mp[i][j]=='1'){
                cnt++;
                win++;
            }
        }
        if(cnt)
            wp[i]=(double)(win)/(double)(cnt);
    }
}
void cal_owp()
{
    int cnt,win,ccnt;
    for(int i=0;i<n;i++){
        owp[i]=0;
        ccnt=0;
        for(int j=0;j<n;j++){
            if(mp[i][j]=='.')
                continue;
            ccnt++;
            win=cnt=0;
            for(int k=0;k<n;k++){
                if(j==i||k==i)
                    continue;
                if(mp[j][k]=='0')
                    cnt++;
                else if(mp[j][k]=='1'){
                    cnt++;
                    win++;
                }
            }
            if(cnt)
                owp[i]+=(double)(win)/(double)(cnt);
        }
        if(ccnt)
            owp[i]/=ccnt;
    }
}
void cal_oowp()
{
    int cnt;
    for(int i=0;i<n;i++){
        cnt=0;
        oowp[i]=0;
        for(int j=0;j<n;j++)
            if(mp[i][j]!='.'){
                cnt++;
                oowp[i]+=owp[j];
            }
        if(cnt)
            oowp[i]/=cnt;
    }
}
void cal_rat()
{
    for(int i=0;i<n;i++)
        rat[i]=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
}
void solve()
{
    cal_wp();
    cal_owp();
    cal_oowp();
    cal_rat();
    for(int i=0;i<n;i++)
        cout<<rat[i]<<endl;;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            //gets(mp[i]);
            scanf("%s",mp[i]);
        printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}
