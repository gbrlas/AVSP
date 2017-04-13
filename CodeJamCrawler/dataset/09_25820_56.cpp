#include <cstdio>
#include <cstring>
#include <set>
#include <string>
using namespace std;
#define maxn 100 * 128

set<string>SET;
char str[maxn];
int stk[maxn];
int rightP[maxn];

bool isSpace(char p){
    return p == ' ' || p == '\n';
}

struct Node {
    Node *lc, *rc;
    double weight;
    char name[12];
    Node() {
        lc = rc = NULL;
        weight = 0.0;
        strcpy(name, "dummy");
    }
}*root;

Node *build(int l, int r) {
    char tmp[20];
    int top = 0;
    int i;
    for (i = l; i <= r; ++i) {
        if (str[i] == '.' || (str[i] <= '9' && str[i] >= '0')) {
            tmp[top++] = str[i]; 
        } else {
            break; 
        }
    }    
    tmp[top] = '\0';
    Node *node = new Node();
    sscanf(tmp, "%lf", &node->weight);
    if (i <= r) {
       top = 0;
       for (; i <= r; ++i) {
            if (str[i] == '(') break;
            tmp[top++] = str[i];
       }
       tmp[top] = '\0';
       sscanf(tmp, "%s", node->name);
       node->lc = build(i + 1, rightP[i] - 1);
       node->rc = build(rightP[i] + 2, r - 1);
    }
    return node;
}
double ans;
void dfs(Node *root) {
    if (root == NULL) return;
    ans *= root->weight;
   // puts(root->name);
    if (root->lc != NULL) {
        if (SET.find(root->name) != SET.end()) {
            dfs(root->lc);
        } else {
            dfs(root->rc);
        }
    }
}
int main() {
//	freopen("a.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int nline;
		int i;
        scanf("%d", &nline);
        char line[128];
        gets(line);
        str[0] = '\0';
        while (nline--) {
            gets(line);
            strcat(str, line);
        }
        int j = 0;
        for ( i = 0; str[i]; ++i) {
            if (isSpace(str[i])) {
                continue; 
            }
            str[j++] = str[i];
        }
        str[j] = '\0';
        //puts(str);
        printf("Case #%d:\n", kase);
        int m;
        scanf("%d", &m);
        int nstr = strlen(str);
        int top = 0; 
        memset(rightP, 0, sizeof(rightP));
        for ( i = 0; i < nstr; ++i) {
            if (str[i] == '(') {
                stk[top++] = i; 
            } else if (str[i] == ')') {
                rightP[stk[top - 1]] = i;
                top--;
            }
        }

//        for (int i = 0; i <nstr; ++i) {
  //          printf("%d ", rightP[i]);
    //    }
      //  puts("");
        root = build(1, nstr - 2);
        dfs(root);
        while (m--) {
            scanf("%s", line);
            int n;
            scanf("%d", &n);
            SET.clear();
            for (int i = 0; i < n; ++i) {
                scanf("%s", line);
                SET.insert(line);
            }
            ans = 1.0;
            dfs(root);
            printf("%.8lf\n", ans);
        }
    }
    return 0;
}
