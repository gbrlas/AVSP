#include <iostream>
#include <vector>
using namespace std;


int search(int d, int s, int p, vector<int>& goo) {
  int ret = 0;
  if (s<0) return -999999;
  if (d<goo.size()) {
    int div3 = goo[d] / 3;
    if (div3 == 0) {
    	if (goo[d] == 0) ret = search(d+1, s, p, goo)+(0>=p?1:0);
    	else if (goo[d] == 1) ret = search(d+1, s, p, goo)+(1>=p?1:0);
    	else ret = max(search(d+1, s, p, goo)+(1>=p?1:0), search(d+1, s-1, p, goo) + (2>=p?1:0));
    } else if (goo[d] % 3 == 0) {
    	ret = max(search(d+1, s, p, goo)+(div3>=p?1:0), search(d+1, s-1, p, goo) + (div3+1>=p?1:0));
    } else if (goo[d] % 3 == 1) {
    	ret = search(d+1,s,p,goo)+ (div3+1>=p?1:0);
    } else {
    	ret = max(search(d+1, s, p, goo)+(div3+1>=p?1:0), search(d+1, s-1, p, goo) + (div3+2>=p?1:0));
    }
  } else {
    return ret;
  }
  return ret;
}


int main(){
  int t,n,s,p;
  cin >> t;
  for (int x=1; x<=t; x++) {
    cin >> n;
    cin >> s;
    cin >> p;
    vector<int> goo (n);
    for (int i=0; i<n; i++) {
    	cin >> goo[i];
    }
    printf("Case #%d: %d\n", x, search(0,s,p,goo));
  }
  return 0;
}