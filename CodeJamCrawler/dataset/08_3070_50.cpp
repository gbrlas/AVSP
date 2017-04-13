#include <algorithm>
#include <vector>

using namespace std;

int N, NA, NB, T, tot;

struct Trip
{
    int leave, arrive;
};

const int MAXN = 256;

Trip A[MAXN], B[MAXN];
bool flag[MAXN];
int match[MAXN];
vector<int> adj[MAXN];

int change(char *s)
{
    s[2] = 0;
    return atoi(s) * 60 + atoi(&s[3]);
}

int get(Trip &tmp) 
{
    char a[16], b[16];
    scanf("%s %s", a, b);
    tmp.leave = change(a);
    tmp.arrive = change(b);
    return 1;
}

int add(int x, int y)
{
    adj[x].push_back(y);
}

int find(int u)
{
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (flag[v]) continue;
        flag[v] = 1;
        if (match[v] == -1 || find(match[v])) {
            match[v] = u;
            return 1;    
        }    
    }    
    return 0;
}

int maxMatch()
{
    int ret = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < tot; i++) {
        memset(flag, 0, sizeof(flag));
        if (find(i)) ret ++;     
    }    
    return ret;
}

int main()
{
    freopen("f:\\B-small-attempt2.in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
    scanf("%d", &N);
    for (int cs = 1; cs <= N; cs++) {
        scanf("%d %d %d", &T, &NA, &NB);
        for (int i = 0; i < NA; i++) {
            get(A[i]);    
        }    
        for (int i= 0; i < NB; i++) {
            get(B[i]);    
        }
        tot = NA + NB;
        for (int i=0;i<tot;i++) {
            adj[i].clear();    
        }
        for (int i= 0; i < NA; i++) {
            for (int j = 0; j < NB; j++) {
                if (A[i].arrive + T <= B[j].leave) {
                    add(i, NA+j);    
                }    
                if (B[j].arrive + T <= A[i].leave) {
                    add(NA+j, i);            
                }
            }    
        }         
        int M = maxMatch();
        int RA = NA, RB = NB;
        for (int i = 0; i < tot; i++) {
            int u;
            if ((u = match[i]) >= 0) {
                if (u < NA) RB --;
                else RA --;    
            }     
        } 
        printf("Case #%d: %d %d\n", cs, RA, RB);
    }    
    return 0;    
}
