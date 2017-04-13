#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int N = 10010;
const int M = 26 * N;
const int L = 1000010;

struct node {
  node *next[26];
  int word;
  char c;
};

node a[M], *next, *root;

node *node_new(char c) {
  node *x = next++;
  x->word = -1;
  x->c = c;
  memset(x->next, 0, sizeof(node *) * 26);
  return x;
}

void init() {
  next = a;
  root = node_new('_');
}

void ins(char *key, int i) {
  node *x = root;
  for (; *key; key++) {
    int z = *key - 'a';
    if (!x->next[z]) {
      x->next[z] = node_new(z + 'a');
    }
    x = x->next[z];
  }
  if (x->word == -1) x->word = i;
}

int dp(char *permutation, node *x) {
  int k = 0, best = -1, bw = -1;
  if (x->word != -1) {
    best = 0;
    bw = x->word;
  }
  for (int z = 0; z < 26; z++) {
    int c = permutation[z] - 'a';
    if (x->next[c]) {
      int tt = dp(permutation, x->next[c]);
      int sc = tt / N + (k++);
      int w = tt % N;
      if (sc > best) {
        best = sc;
        bw = w;
      } else if (sc == best) {
        bw = min(bw, w);
      }
    }
  }
  while (best == -1 || bw == -1) puts("ooops");
//printf("%c %d %d\n", x->c, best, bw);
  return best * N + bw;
}

char str[L];
char per[27];
char key[27];
char org[N][27];
int n, m;
int len[N];
vector<int> e[N][26];
map<int, int> group;
vector<int> member[N];

int _c;
bool cmp(int i, int j) {
  return e[i][_c] < e[j][_c];
}

int solve(vector<int> ids, char *permutation) {
  if (ids.size() == 1) {
    return ids[0];
  }
  int ok = 0;
  int c = *permutation - 'a';
  for (int j = 0; j < ids.size(); j++) {
    int i = ids[j];
    if (e[i][c].size()) {
      ok = 1;
      break;
    }
  }
  if (!ok) return solve(ids, permutation + 1);

  int best = -1, bw = -1;
  _c = c;
  sort(ids.begin(), ids.end(), cmp);
  for (int i = 0, j = 0; i < ids.size(); i = j) {
    vector<int> ids2;
    while (j < ids.size() && e[ids[i]][c] == e[ids[j]][c]) ids2.push_back(ids[j++]);
    int tt = solve(ids2, permutation + 1);
    int sc = tt / N + (e[ids[i]][c].size() == 0);
    int wh = tt % N;
    if (sc > best) {
      best = sc;
      bw = wh;
    } else if (sc == best) {
      bw = min(bw, wh);
    }
  }
  return best * N + bw;
}

int main() {
  int T, cas = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int z = 0; z < 26; z++)
        e[i][z].clear();
      scanf("%s", org[i]);
      len[i] = strlen(org[i]);
      for (int j = 0; j < len[i]; j++)
        e[i][org[i][j] - 'a'].push_back(j);
    }

    group.clear();
    for (int i = 0; i < N; i++)
      member[i].clear();
    for (int i = 0; i < n; i++) {
      if (group.find(len[i]) == group.end()) {
        int gn = group.size();
        group[len[i]] = gn;
      }
      member[group[len[i]]].push_back(i);
    }

    printf("Case #%d:", ++cas);

    while (m--) {
      scanf("%s", per);
      int best = -1, bw = -1;
      for (int i = 0; i < group.size(); i++) {
        int tt = solve(member[i], per);
        int sc = tt / N;
        int wh = tt % N;
        if (sc > best) {
          best = sc;
          bw = wh;
        } else if (sc == best) {
          bw = min(bw, wh);
        }
      }
      printf(" %s", org[bw]);
    }
    puts("");
  }
  return 0;
}

