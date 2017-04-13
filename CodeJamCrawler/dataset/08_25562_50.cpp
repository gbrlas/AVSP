#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char*argv[])
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    string str;
    getline(cin, str);
    vector<string> es;
    for(int j = 0; j < s; j++) {
      getline(cin, str);
      es.push_back(str);
    }
    int q;
    cin >> q;
    getline(cin, str);
    int cs[s];
    for(int j = 0; j < s; j++) {
      cs[j] = 0;
    }
    for(int j = 0; j < q; j++) {
      getline(cin, str);
      for(int k = 0; k < s; k++) {
	if(es[k]==str) {
	  for(int l = 0; l < s; l++) {
	    if(l==k) {
	      continue;
	    }
	    if(cs[l] > cs[k]+1) cs[l] = cs[k]+1;
	  }
	  cs[k] = q;
	}
      }
    }
    int m = cs[0];
    for(int l = 0; l < s; l++) {
      if(m > cs[l]) m = cs[l];
    }
    cout << "Case #" << i << ": " << m << endl;
  }
  return 0;
}
