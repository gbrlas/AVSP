#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// int main () {
//   string G[4], E[4];
//   char resp[50],falta[50];
//   for(int i = 0; i < 4; i++) {
//     getline(cin, G[i]);
//   }
//   for(int i = 0; i < 4; i++) {
//     getline(cin, E[i]);
//   }
//   fill(resp, resp+50, '!');
//   fill(falta, falta+50, 1);
//   for(int i = 0; i < 4; i++) {
//     for(int j = 0; j < (signed)G[i].length(); j++) {
//       if(G[i][j] == ' ') continue;
//       resp[(int)G[i][j] - 'a'] = E[i][j];
//       falta[(int)E[i][j] - 'a'] = 0;
//     }
//   }
//   for(int i = 0; i < 'z'-'a' + 1; i++) {
//     cout << resp[i] << ", ";
//   }
//   cout << endl;
//   for(int i = 0; i < 'z'-'a' + 1; i++) {
//     cout << char('a' + i) << ", ";
//   }
//   cout << endl;
//   for(int i = 0; i < 'z'-'a' + 1; i++) {
//     if(falta[i])
//       cout << "falta: " << char('a' + i) << endl;
//   }
//   return 0;
// }

int main() {
  int t, T;
  char resp[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
  string line;
  scanf("%d\n", &T);
  for(t = 1; t <= T; t++) {
    getline(cin, line);
    cout << "Case #" << t << ": ";
    for(unsigned i = 0; i < line.length(); i++) {
      if(line[i] == ' ')
	cout << ' ';
      else
	cout << resp[line[i] - 'a'];
    }
    cout << endl;
  }
  return 0;
}
