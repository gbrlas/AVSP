#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main () {

  int L, D, N;
  char word[75001];
  vector<string> words;
  scanf("%d %d %d", &L, &D, &N);
  for (int i = 0; i < D; ++i) {
    scanf("%s", word);
    words.push_back(string(word));
  }
  for (int c = 1; c <= N; ++c) {
    scanf("%s", word);
    vector<map<char,bool> > sent;
    int n = 0;
    for (int i = 0; i < L; ++i) {
      map<char,bool> seen;
      if (word[n] == '(')
	while (word[++n] != ')')
	  seen[word[n]] = true;
      else
	seen[word[n]] = true;
      sent.push_back(seen);
      ++n;
    }
    n = 0;
    for (int i = 0; i < D; ++i) {
      bool ok = true;
      for (int j = 0; ok && j < L; ++j)
	if (sent[j].find(words[i][j]) == sent[j].end())
	  ok = false;
      if (ok)
	++n;
    }
    printf("Case #%d: %d\n", c, n);
  }
}
