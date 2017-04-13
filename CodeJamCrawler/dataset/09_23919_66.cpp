#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define fr2(i, s, n) for(i = (s); i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define MAXD 5000

int L, D, N;
string dic[MAXD];

string word;

bool read()
{
 
 return true;
}

void proc()
{
 // Clear
 
 // Process
 
 // Output
}

bool compare(int d) {
  int i;
  int p=0;
  bool error = false;

  fr (i, L) {
    if (word[p] != '(') {
      if (word[p] != dic[d][i]) {
	error = true;
	break;
      }
    } else {
      p++;
      error = true;
      while (word[p] != ')') {
	if (word[p] == dic[d][i]) 
	  error = false;
	p++;
      }
      if (error)
	break;
    }

    p++;
  }
  return !error;
}

int main()
{
  cin >> L >> D >> N;
  int i, j;
  fr (i, D) 
    cin >> dic[i];


  fr (i, N) {
    cin >> word;
    int pos = 0;
    fr (j, D) {
      if (compare(j)) 
	pos++;
    }
  
    cout << "Case #" << i+1 << ": " << pos << endl;
  }
 
 return 0;
}
