/*
 * Google Code Jam 2008
 * Americas Onsite Round - September 29, 2008
 * Problem A - large version
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
typedef long long i64;
typedef pair<int, int> ipair;
typedef set<string> sstr;
#define FOR0(VAR,UB) for (int VAR = 0; VAR <  (UB); VAR++)
#define FOR1(VAR,UB) for (int VAR = 1; VAR <= (UB); VAR++)

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}


struct Solver {
  int N;
  map< string, sstr > ingredients;

  int rec(string goal) {
    int ret = 1;
    vector<int> subs;
    for (sstr::iterator it = ingredients[goal].begin(); it != ingredients[goal].end(); it++) {
      int bowlsForSub = rec(*it);
      assert(bowlsForSub >= 1);
      subs.push_back(bowlsForSub);
    }


    sort(subs.rbegin(), subs.rend());

    /*
    cerr << "To make " << goal << " need ";
    for (int i = 0; i < subs.size(); i++)
      cerr << subs[i] << " ";
    cerr << endl;
    */

    assert(ret >= 1);


    for (int i = 0; i < subs.size(); i++) {
      ret >?= (subs[i] + i);
      ret >?= (i+1);
    }
    ret >?= (subs.size() + 1);
    
    assert(ret >= 1);

    return ret;
  }

  void run() {
    string mainRecipe;
    cin >> N;
    FOR0(i, N) {
      string mixture = scan<string>();
      if (i == 0) mainRecipe = mixture;
      int nIngredients = scan<int>();
      FOR0(j, nIngredients) {
	string ingredient = scan<string>();
	if ((ingredient[0] >= 'a') && (ingredient[0] <= 'z')) continue;
	ingredients[mixture].insert(ingredient);
      }
    }
    cout << rec(mainRecipe);
  }
};

int main()
{
  const int nCases = scan<int>();
  for (int tc = 1; tc <= nCases; tc++) {
    cerr << "Case #" << tc << endl;
    cout << "Case #" << tc << ": ";
    auto_ptr<Solver> s(new Solver);
    s->run();
    cout << endl;
  }
  return 0;
}

