#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream iFile;
  ofstream oFile;
  iFile.open(argv[1]);
  oFile.open("result.out");
  
  int iCase, nCase;
  iFile >> nCase;
  for( iCase = 0; iCase != nCase; ++iCase) {
    oFile << "Case #" << iCase+1 << ": ";

    // Solve the problem
    int i, n;
    vector<long long> C;
    iFile >> n;
    for (i = 0; i != n; ++i){
      long long c;
      iFile >> c;
      C.push_back(c);
    }

    vector<long long>::iterator it;
    long long not_solvable = 0;
    for(it = C.begin(); it != C.end(); ++it)
      not_solvable ^= *it;

    if (not_solvable)
      oFile << "NO" << endl;
    else {
      sort(C.begin(), C.end());
      long long sum = 0;
      it = C.begin();
      for(++it; it != C.end(); ++it)
        sum += *it;

    oFile << sum << endl;
    }
  }
  
  iFile.close();
  oFile.close();
  
  return 0;
}
