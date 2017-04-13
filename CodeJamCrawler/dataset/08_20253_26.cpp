/*
 * Google Code Jam 2008
 * Americas Onsite Round - September 29, 2008
 * Problem A
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <algorithm>
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
  vector< string > mixtures;
  string mainRecipe;

  int bowls() {

    int curBowlsUsed = 0;
    int maxBowlsUsed = 0;
    set<string> mixturesAvailable;

    FOR0(i, mixtures.size()) {
      string mixture = mixtures[i];
      int nSubMixtures = 0;
      // if needs a mixture not yet available, return immediately
      for (sstr::iterator it = ingredients[mixture].begin(); it != ingredients[mixture].end(); it++) {
	string ingredient = *it;
	//	if ((ingredient[0] >= 'a') && (ingredient[0] <= 'z')) continue;
	nSubMixtures++;
	if (mixturesAvailable.count(ingredient) == 0) return 99999999;
      }
      curBowlsUsed ++;
      maxBowlsUsed >?= curBowlsUsed;
      curBowlsUsed -= nSubMixtures;
      mixturesAvailable.insert(mixture);
    }

    /*
    cerr << "Need " << maxBowlsUsed << " bowls for order: ";
    for (int i = 0; i < mixtures.size(); i++) {
      cerr << mixtures[i] << ","; 
    }
    cerr << endl;
    */

    return maxBowlsUsed;
  }

  void run() {
    cin >> N;
    FOR0(i, N) {
      string mixture = scan<string>();
      mixtures.push_back(mixture);
      if (i == 0) mainRecipe = mixture;
      int nIngredients = scan<int>();
      FOR0(j, nIngredients) {
	string ingredient = scan<string>();
	if ((ingredient[0] >= 'a') && (ingredient[0] <= 'z')) continue;
	ingredients[mixture].insert(ingredient);
      }
    }
    sort(mixtures.begin(), mixtures.end());
    int ret = 99999999;
    do {
      if (mixtures[N-1] != mainRecipe) continue;
      ret <?= bowls();
    } while (next_permutation(mixtures.begin(), mixtures.end()));
    cout << ret;
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

