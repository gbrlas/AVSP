#include <iostream>
#include <vector>

using namespace std;

int
count(vector<string> matrix)
{
  vector<unsigned> rightmost(matrix.size());

  for (unsigned i = 0; i < matrix.size(); i++) {
    rightmost[i] = matrix[i].find_last_of('1') + 1; 
  }

  int nswap = 0;
  for (unsigned i = 0; i < matrix.size(); i++) {
    unsigned j = i;
    while (j < rightmost.size() && rightmost[j] > i + 1) j++;
    if (j > rightmost.size()) return -1;
    nswap += j - i;
    for (unsigned k = j; k > i; k--) rightmost[k] = rightmost[k - 1];
  }
  return nswap;
}

int
main()
{
  int ncases, i;

  cin >> ncases;
  for (i = 1; i <= ncases; i++) {
    int size;
    cin >> size;
    cin.ignore(9999, '\n');
    vector<string> matrix(size);
    for (int j = 0; j < size; j++) {
      getline(cin, matrix[j]);
    }
    cout << "Case #" << i << ": " << count(matrix) << endl;
  }
  return 0;
}
