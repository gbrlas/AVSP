#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;

int CASES;

void init() {
  scanf("%d", &CASES);
}

int fios;
int A[1001], B[1001];
int pi[1001];

int cmp(int a, int b){
  if(A[a] < A[b])
    return 1;
  else
    return 0;
}


void solve(int P) {
  int res= 0;
  scanf("%d ", &fios);
  for(int i = 0; i < fios; i++){
    scanf("%d %d ", &(A[i]), &(B[i]));
  }

  for(int i = 0; i < fios; i++)
    pi[i] = i;

  sort(pi, pi+fios, cmp);

  for(int i = 0; i < fios-1 ; i++)
    for(int j = i+1; j < fios; j++)
      if(B[pi[j]] < B[pi[i]]){
	res++;
      }

  printf("Case #%d: %d\n", P, res);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
