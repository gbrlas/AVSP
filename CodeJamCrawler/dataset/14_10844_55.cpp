#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std; 
 
int g[2002][2002];
int n;
int visited[2002];
int link[2002];
 
bool find(int a)
{
        for(int i=n+1;i<=2*n;i++)
        {
                if(g[a][ i ]==1&&!visited[ i ])
                {
                        visited[ i ]=true;
                        if(link[ i ]==0||find(link[ i ]))
                        {
                                link[ i ]=a;
                                return true;
                        }
                }
        }
        return false;
}
 
int main()
{
    ifstream cin("D-small-attempt2.in");
    ofstream cout("a.out");
    long num_case; cin>>num_case;
    double w1[1002],w2[1002];
    for(long i_case = 1; i_case <= num_case; i_case++)
    {
        memset(g,0,sizeof(g));
        memset(link,0,sizeof(link));
        cout<<"Case #"<<i_case<<": ";
        cin>>n;
        for(long i = 1; i <= n; i++)
            cin>>w1[i];
        sort(w1+1,w1+n+1);
        for(long i = 1; i <= n; i++)
            cin>>w2[i];
        sort(w2+1,w2+n+1);
        for(long i = 1; i <= n; i++)
            for(long j = 1; j <= n; j++)
        if(w1[i] > w2[j])
            g[i][n+j] = 1;
        long ans = 0;
        for(long i = 1; i <= n; i++)
        {
            memset(visited,0,sizeof(visited));
            if(find(i)) ans++;     
        }
        cout<<ans<<" ";
        ans = 0;
        for(long i = 1; i <= n; i++)
        {
            long flag = 0;
            for(long j = 1; j <= n-i+1; j++)
                 if(w2[j] > w1[i])
                 {
                     flag = j;
                     break;
                 }    
            if(flag)
                for(long j = flag; j < n-i+1; j++)
                    w2[j] = w2[j+1];
            else {
                     ans++;
                     for(long j = 1; j < n-i+1; j++)
                         w2[j] = w2[j+1];
                 }
        }
        cout<<ans<<endl;
    }
    cin.close(); cout.close();
    return 0;
}
