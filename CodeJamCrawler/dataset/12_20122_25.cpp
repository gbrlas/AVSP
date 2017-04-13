#include <iostream>
#include <cstdio>
using namespace std;

int tr[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
  int ntp;

  scanf("%d\n", &ntp);
  for(int tp = 0; tp < ntp; ++tp) {
    string line;
    getline(cin, line);
    for (int i = 0; i < (int)line.size(); ++i) {
      if (line[i] != ' ') {
        line[i] = tr[line[i]-'a'];
      }
    }
    printf("Case #%d: %s\n", tp+1, line.c_str()); 

  }

  return 0;
}
