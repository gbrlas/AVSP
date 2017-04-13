#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, S, Q;

map<string, int> nameMap;
vector<int> querys;

int opt[1024][1024];

int solve()
{
    
    int nq = querys.size();
    if (nq == 0) return 0;
    
    memset(opt, -1, sizeof(opt));
    for (int i = 0; i < S; i++) if (i != querys[0]){
        opt[0][i] = 0;    
    }    
    for (int i = 1; i < nq; i++) {
        for (int j = 0; j < S; j++) {
            if (querys[i] == j) continue;
            for (int k = 0; k < S; k++) if (opt[i-1][k] >= 0){
                int tmp = opt[i-1][k] + (j != k);
                if (tmp < opt[i][j] || opt[i][j] == -1) opt[i][j] = tmp;    
            }    
        }    
    }
    int ret = 0xffff;
    for (int i = 0; i < S; i++) {
        if (opt[nq-1][i] < ret && opt[nq-1][i] >= 0) ret = opt[nq-1][i];    
    }
    return ret;
}

int main()
{ 
    freopen("f:\\A-small-attempt1.in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
    scanf("%d", &N);
    for (int sz=1;sz<=N;sz++) {
        nameMap.clear();
        querys.clear();
               
        scanf("%d", &S);
        char line[1024];
        gets(line);
        for (int i=0;i<S;i++) {
            gets(line);
           
            nameMap.insert(map<string, int>::value_type(line, i));                
        }    
    
        scanf("%d", &Q);
        gets(line);
        for (int i=0;i<Q;i++) {
            gets(line);
            
            querys.push_back(nameMap.find(line)->second);      
        }
        
        printf("Case #%d: %d\n", sz, solve());
    }    
  
    return 0;    
}
