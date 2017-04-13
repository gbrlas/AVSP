#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N 300
#define inf 0x7fffffff
#define eps 1e-8

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/gcj/b.out","w",stdout);
    int com[N][N],opp[N][N],vis[N];
    string s,res;
    char tmp;
    int i,j,n,l,T,cas=0;
    scanf("%d",&T);
    while (T--){
        cas++;
        memset(com,-1,sizeof(com));
        memset(opp,0,sizeof(opp));
        memset(vis,0,sizeof(vis));
        cin >> n;
        for (i=1;i<=n;++i){
            cin >> s;
            com[s[0]-'A'][s[1]-'A']=com[s[1]-'A'][s[0]-'A']=s[2]-'A';
        }
        cin >> n;
        for (i=1;i<=n;++i){
            cin >> s;
            opp[s[0]-'A'][s[1]-'A']=opp[s[1]-'A'][s[0]-'A']=1;
        }
        cin >> n;
        cin >> s;
        res="";
        for (i=0;i<s.length();++i){
            res=res+s[i];
            //cout << res << endl;
            vis[s[i]-'A']++;
            l=res.length();
            if (l>1 && com[res[l-1]-'A'][res[l-2]-'A'] != -1){
                tmp = 'A' + com[res[l-1]-'A'][res[l-2]-'A'];
                vis[res[res.length()-1]-'A']--;
                res.erase(res.length()-1);
                vis[res[res.length()-1]-'A']--;
                res.erase(res.length()-1);
                res+=tmp;
                //cout << res << endl;
                continue;
            }
            for (j=0;j<res.length()-1;++j){
                if (opp[s[i]-'A'][res[j]-'A']){
                    res.clear();
                    memset(vis,0,sizeof(vis));
                    break;
                }
            }
            //cout << res << endl;
        }
        cout << "Case #" << cas << ": ";
        cout << "[" ;
        if (res.length()) cout << res[0] ;
        for (i=1;i<res.length();++i){
            cout << ", " << res[i];
        }
        cout << "]" << endl;
    }
    return 0;
}
