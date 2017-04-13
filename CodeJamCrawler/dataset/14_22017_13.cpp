#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool cmp(uint64_t a, uint64_t b) {
  if(a>b) return 1;
  return 0;
}

int main() {
  std::ifstream input;
  std::ofstream output;
  std::vector <uint64_t> S;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    uint64_t N, X, A, Discs = 0;
    S.clear();
    input >> N;
    input >> X;
    for(uint16_t i=0; i<N; i++) {
      input >> A;
      S.push_back(A);
    }
    std::sort (S.begin(), S.end());
    while(!S.empty()) {
      A = X+1;
      while(A>X && !S.empty()) {
        A = S.back();
        S.pop_back();
      }
      if(A>X) Discs--;
      if(!S.empty()) {
        for(int64_t i=S.size()-1; i>=0 ;i--) {
          if(X-A>=S[i]) {
            S[i] = X+1;
            i = -1;
          }
        }
      }
      Discs++;
    }

    output << "Case #" << count << ": ";
    output << Discs;
    output << '\n';
  }
}
