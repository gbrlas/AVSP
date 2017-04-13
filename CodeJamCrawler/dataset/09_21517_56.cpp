#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void do_test (int no)
{
  string current;
  cin >> current;

  int A[10];
  memset (A, 0, sizeof A);
  for (int i = 0; i < current.size (); ++i)
    A[current[i] - '0']++;

  if (current.size () == 1)
  {
    cout << "Case #" << no << ": " << current + "0\n";
    return;
  }

  int i;
  for (i = current.size () - 2; i >= 0; --i)
  {
    if (current[i] < current[i+1])
      break;
  }

  if (i == -1)
  {
    A[0]++;
    cout << "Case #" << no << ": ";
    int j = 1;
    while (A[j] == 0)
      ++j;
    cout << j;
    A[j]--;
    for (int k1 = 0; k1 < 10; ++k1)
      for (int k2 = 0; k2 < A[k1]; ++k2)
        cout << k1;
    cout << "\n";
  } else
  {
    int j = i + 1;
    int min = 10, minj = -1;
    while (j < current.size ())
    {
      if (current[j] > current[i])
      {
        if (current[j] - current[i] < min)
        {
          min = current[j] - current[i];
          minj = j;
        }
      }
      ++j;
    }
    vector<int> v;
    for (int k = i; k < current.size (); ++k)
      if (k != minj)
        v.push_back (current[k]-'0');
    sort (v.begin (), v.end ());

    cout << "Case #" << no << ": ";
    cout << current.substr (0, i);
    cout << current[minj];
    for (int k = 0; k < v.size (); ++k)
      cout << v[k];
    cout << endl;
  }

}

int main ()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
    do_test (i);
}
