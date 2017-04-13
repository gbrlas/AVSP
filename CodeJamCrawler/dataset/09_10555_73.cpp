#include <iostream>
#include <string>
#include <map>

using namespace std;


unsigned long long process(string s)
{
  int maxdigit = 0;
  bool nonzero = true;
  unsigned long long result = 0;
  map<char, int> m;
  int base = 1;

  m[s[0]] = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (m.find(s[i]) == m.end()) {
      m[s[i]] = maxdigit++;
      base += 1;
      if (maxdigit == 1) 
	++maxdigit;
    }
  }

  if (base == 1) 
    base = 2;
  
  for (int i = 0; i < s.size(); ++i)
    result = result * base + m[s[i]];

  return result;
}

int main() 
{
  int n = 0;
  string s;
  cin >> n;
  getline(cin ,s);

  for (int i = 0; i < n; ++i)
    {
      getline(cin, s);
      cout << "Case #" << i + 1 << ": " << process(s) << endl;
    }
  return 0;
}
