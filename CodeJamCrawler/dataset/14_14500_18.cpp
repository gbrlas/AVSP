#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int main(int argc,char *argv[])
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("AA.out","w",stdout);
    int t,shu[150][150],len[150];
    string in[150];
    char aa[150][150];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        int flag=0;
        long long summ=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            cin>>in[i];
        memset(aa,0,sizeof(aa));
        memset(shu,0,sizeof(shu));
        for(int i=1;i<=n;i++)
        {
            int k=0;
            for(int j=0;j<=in[i].size()-1;j++)
            {
                if(aa[i][k]!=in[i][j])
                {
                    k++;
                    aa[i][k]=in[i][j];
                }
                shu[i][k]++;
            }
            len[i]=k;
        }
        for(int i=1;i<=n-1;i++)
            if(len[i]!=len[i+1])
                flag=1;
        if(flag==1)
            printf("Case #%d: Fegla Won\n",cas); 
        else {
        for(int i=1;i<=len[1];i++)
        {
            int sum=0;
            for(int j=1;j<=n-1;j++)
            {
                if(aa[j][i]!=aa[j+1][i])
                    flag=1;
            }
            if(flag==1)
                break;
            for(int j=1;j<=n;j++)
                sum+=shu[j][i];
            sum/=n;
            for(int j=1;j<=n;j++)
                summ+=abs(sum-shu[j][i]);
        }
        if(flag==1)
            printf("Case #%d: Fegla Won\n",cas);
        else    
        {
            printf("Case #%d: ",cas);
            cout<<summ<<endl;
        }
        }
    }
    return 0;
}

