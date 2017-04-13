#include <iostream>
#include <vector>
using namespace std;

void calc (vector<char> & vec, int * type, int & res) {

  long long p = vec[0]-'0';
  size_t k = 0;
  for (++k; k < vec.size(); ++k) {
    if (type[k-1] == 0)
      p = 10*p+vec[k]-'0';
    else
      break;
  }
  while (k < vec.size()) {
    int tt = type[k-1];
    long long t = vec[k]-'0';
    for (++k; k < vec.size(); ++k) {
      if (type[k-1] == 0)
	t = 10*t+vec[k]-'0';
      else
	break;
    }
    if (tt == 1)
      p += t;
    else
      p -= t;
  }
  if ((p%2) == 0 || (p%3) == 0 || (p%5) == 0 || (p%7) == 0)
    ++res;
}

void solve (vector<char> & vec, int * type, int & res, size_t t) {

  if (t+1 == vec.size()) {
    calc(vec, type, res);
    return;
  }
  type[t] = 0;
  solve(vec, type, res, t+1);
  type[t] = 1;
  solve(vec, type, res, t+1);
  type[t] = 2;
  solve(vec, type, res, t+1);
}

int main () {

  char data[14];
  int N, c = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%s", data);
    vector<char> vec;
    for (int i = 0; data[i]; ++i)
      vec.push_back(data[i]);
    int type[vec.size()-1];
    int res = 0;
    solve(vec, type, res, 0);
    printf("Case #%d: %d\n", ++c, res);
  }
}
