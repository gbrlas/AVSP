#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct Node {
    int x,y,h;
};

struct cmp {
    bool operator () (Node a, Node b) {
        return a.h<b.h;
    }
};

priority_queue <Node, vector<Node>, cmp> heap;

int map[120][120];
int belong[120][120];
int n,m,kase,sum;
Node temp;

int way[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char key[30];

int dfs(int x,int y)
{
    int mx,my,low=map[x][y];
    bool pd=false;
    for (int i=0;i<4;i++) {
        int tx=x+way[i][0],ty=y+way[i][1];
        if (tx>=0&&tx<n&&ty>=0&&ty<m) {
            if (map[tx][ty]<low) {
                low=map[tx][ty];
                mx=tx;my=ty;pd=true;
            }
        }
    }
    if (!pd) {
        if (belong[x][y]==-1) return belong[x][y]=++sum;
        else return belong[x][y];
    }
    else return belong[x][y]=dfs(mx,my);
}


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&kase);
    for (int i=0;i<kase;i++) {
        scanf("%d %d",&n,&m);
        for (int j=0;j<n;j++)
            for (int k=0;k<m;k++)
            {
                scanf("%d",&map[j][k]);
                temp.x=j,temp.y=k;temp.h=map[j][k];
                heap.push(temp);
            }
        memset(belong,-1,sizeof(belong));
        sum=0;
        while (!heap.empty()) {
            temp=heap.top();heap.pop();
            if (belong[temp.x][temp.y]!=-1) continue;
            belong[temp.x][temp.y]=dfs(temp.x,temp.y);
        }
        sum=0;
        memset(key,0,sizeof(key));
        for (int j=0;j<n;j++)
            for (int k=0;k<m;k++)
                if (key[belong[j][k]]==0) key[belong[j][k]]='a'+sum++;
        printf("Case #%d:\n",i+1);
        for (int j=0;j<n;j++)
        {
            printf("%c",key[belong[j][0]]);
            for (int k=1;k<m;k++) printf(" %c",key[belong[j][k]]);
            printf("\n");
        }
    }
    return 0;
}
