#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

string get_line_s () {
  string temp;
  getline (cin, temp);
  return temp;
}

unsigned int get_line_u () {
  string temp = get_line_s ();
  unsigned int N;
  istringstream (temp) >> N;
  return N;
}

void do_test (unsigned int no) {
  string s1 = get_line_s ();
  string s2 = "welcome to code jam";

  int l1 = s1.size (), l2 = s2.size ();
  vector<unsigned long long> temp (l2, 0);
  vector<vector<unsigned long long> > M (l1, temp);

  int total = 0;
  for (int i = 0; i < l1; ++i) {
    if (s1[i] == s2[0]) {
      ++total;
    }
    M[i][0] = total;
  }

  for (int i = 1; i < l2; ++i)
    M[0][i] = 0;

  for (int i = 1; i < l1; ++i)
    for (int j = 1; j < l2; ++j) {
      if (s1[i] != s2[j])
        M[i][j] = M[i-1][j];
      else
        M[i][j] = M[i-1][j] + M[i-1][j-1];
    }
  
  unsigned long long t = M[l1-1][l2-1]%10000;
  string res;
  stringstream ss;
  ss << t;
  ss >> res;
  while (res.size () < 4)
    res = "0" + res;
  cout << "Case #" << no<<": " << res << endl;

  
  

}


int main () {
  unsigned int N = get_line_u ();
  for (unsigned int i = 1; i <= N; ++i)
    do_test (i);

}
