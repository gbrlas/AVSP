#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <numeric>

#define pii pair<int,int>
#define FOR(i,a,n) for (int i = a, _n = n; i <= _n; i++)
#define FOD(i,a,b) for (int i = a; i >= b; i--)
#define MAXINT 1000000000

using namespace std;

struct nodeT{
    int end;
    map <string, int> mymap;
    nodeT(){end = 0; mymap.clear();}
};

int tc,n,m, ans, np;
char s[105],S[105];
nodeT root;
nodeT nodes[10000];

void addWord(struct nodeT *p, char *word){
    int ii, id,len = strlen(word);
    struct nodeT *v;
    char *pch = strtok(word, " /");
    while (pch!= NULL){
        strcpy(S, pch);
        map<string,int>::iterator it = p->mymap.find(string(S));
        if (it == p->mymap.end()){
            nodes[np] = nodeT();
            p->mymap.insert(make_pair(string(pch),(int)&nodes[np]));
            p = &nodes[np];
            np++;
        }else{
            int num = it->second;
            p = (nodeT*) num;
        }
        pch = strtok(0, "/");
    }
    return;
}

void addWord2(struct nodeT *p, char *word){
    int ii, id,len = strlen(word);
    struct nodeT *v;
    char *pch = strtok(word, " /");
    while (pch!= NULL){
        strcpy(S, pch);
        map<string,int>::iterator it = p->mymap.find(string(S));
        if (it == p->mymap.end()){
            nodes[np] = nodeT();
            p->mymap.insert(make_pair(string(S),(int)&nodes[np]));
            p = &nodes[np];
            np++;
            ans++;
        }else{
            int num = it->second;
            p = (nodeT*) num;
        }
        pch = strtok(0, "/");
    }
    return;
}

int main(){
    freopen("A-large.in","r",stdin);
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    FOR(TC,1,tc){
        ans = 0;
        np = 0;
        root = nodeT();
        scanf("%d %d ",&n,&m);
        for (int i = 0; i < n; i++){
            scanf("%s ",s);
            addWord(&root, s);
        }
        for (int i = 0; i < m; i++){
            scanf("%s ",s);
            addWord2(&root, s);
        }
        printf("Case #%d: %d\n",TC,ans);
    }
    return 0;
}
