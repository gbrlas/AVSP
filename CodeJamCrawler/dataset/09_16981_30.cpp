#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
  int t,k;
  scanf(" %d",&t);
  for(int c=1;c<=t;c++) {
    scanf(" %d",&k); 
    int orig = k;
    vector<int> v;
    while (k > 0) {
      v.push_back(k%10);
      k/=10;
    }
    v.push_back(0);
    next_permutation(v.rbegin(),v.rend());
    
    
    char s[22];
    int n = (int) v.size();
    for(int i=0;i<n;i++) {
      s[n-i-1] = (char) (v[i] + '0');
    }
    s[n] = 0;
    //fprintf(stderr," DEBUG: %s\n",s);
    sscanf(s,"%d",&k);
    
    printf("Case #%d: %d\n",c,k);
  }
  return 0;
}
