#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int u[2200][2];

//set<int> group[2200];

struct Region {
    vector<int> vertex_id, region_to;
};
Region reg[2200];

int res;
int color[2200], visited[2200];
int tmp[2200];
void dfs(int rid) {
    if (visited[rid]) return;
    visited[rid] = 1;

    MEMSET(tmp, 0);
    REP(j, SZ(reg[rid].vertex_id)) {
        int c = color[reg[rid].vertex_id[j]];
        if (c != -1) tmp[c] = 1;
    }
    //REP(j, res) cout<<"#"<<tmp[j]<<endl;

    int cur=0;
    REP(j, SZ(reg[rid].vertex_id)) {
        int vid = reg[rid].vertex_id[j];
        if (color[vid] != -1) continue;

        int lim=0;
        for (; lim<2*res && tmp[cur]; cur=(cur+1)%res, lim++);
        if (lim == 2*res) {
            int s=SZ(reg[rid].vertex_id);
            cur=-1;
            REP(cand, res) if (cand != color[reg[rid].vertex_id[(j+1)%s]] && cand != color[reg[rid].vertex_id[(j+s-1)%s]]) { cur=cand; break; }
            assert(cur!=-1);
        }
        //assert(tmp[cur] == 0);
        color[vid] = cur;
        tmp[cur]=1;
        cur = (cur+1)%res;
    }

    FORIT(it, reg[rid].region_to) dfs(*it);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);

        int N, M; scanf("%d%d", &N, &M);
        REP(j, M) scanf("%d", &u[j][0]), u[j][0]--;
        REP(j, M) scanf("%d", &u[j][1]), u[j][1]--;

        /*
        cout<<"!"<<N<<" "<<M<<endl;
        REP(j, M) cout<<u[j][0]+1<<" "<<u[j][1]+1<<endl;
        */

        REP(j, 2200) reg[j].vertex_id.clear(), reg[j].region_to.clear();
        REP(i, N) reg[0].vertex_id.push_back(i);

            // split the regions
        REP(j, M) {
            int a=u[j][0], b=u[j][1];
            int rid=-1;
            REP(k, j+1) {
                int cnt=0;
                REP(l, SZ(reg[k].vertex_id)) if (reg[k].vertex_id[l] == a || reg[k].vertex_id[l] == b) cnt++;
                if (cnt==2) { rid=k; break; }
            }
            assert(rid != -1);

            Region tmp1, tmp2;
            REP(k, SZ(reg[rid].vertex_id)) {
                int vid=reg[rid].vertex_id[k];
                if (a<=vid && vid<=b) tmp1.vertex_id.push_back(vid);
                if (vid<=a || b<=vid) tmp2.vertex_id.push_back(vid);
            }
            tmp1.region_to.push_back(j+1);
            tmp2.region_to.push_back(rid);

            REP(l, SZ(reg[rid].region_to)) {
                int to = reg[rid].region_to[l];
                int vid = -1;
                for (int k=0; ; ++k) {
                    vid = reg[to].vertex_id[k];
                    if (vid != a && vid != b) break;
                }
                if (a<vid && vid<b) tmp1.region_to.push_back(to);
                else {
                    tmp2.region_to.push_back(to);
                    FORIT(it, reg[to].region_to) if (*it == rid) { *it = j+1; break; }
                }
            }

            reg[rid] = tmp1;
            reg[j+1] = tmp2;

        }
        /*
            cout<<"----"<<endl;
        REP(j, M+1) {
            cout<<"#"<<endl;
            FORIT(it, reg[j].vertex_id) cout<<(*it)+1<<" ";
            cout<<endl;
            FORIT(it, reg[j].region_to) cout<<*it<<" ";
            cout<<endl;
        }
        */

            // dfs + greeeeeeeeeeeeedy
        res=666*666;
        int init=-1;
        REP(j, M+1) res = min(res, SZ(reg[j].vertex_id));
        REP(j, M+1) if (SZ(reg[j].region_to) == 1) init = j;
        MEMSET(color, -1);
        MEMSET(visited, 0);
        dfs(init);

        printf("%d\n", res);
        REP(j, N) {
            if (j) printf(" ");
            printf("%d", color[j]+1);
        }
        puts("");


        REP(j, M+1) {
            set<int> st;
            FORIT(it, reg[j].vertex_id) st.insert(color[*it]);
            assert(SZ(st) == res);
        }
        /*
        REP(j, 2200) group.clear(), group.insert(0);

        REP(j, M) {
            int a=u[j][0], b=u[j][1];
            int cid=-1;
            FORIT(it, group[b]) if (FIND(group[a], *it)) { cid=*it; break; }
            REP(k, N) if (FIND(group[k], cid)) {
                if (j==k || k==b) group[k].insert(j+1);
                else if (a<k && k<b) group[k].erase( group[k].find(cid) ), group[k].insert(j+1);
            }
        }
        */
    }
}
