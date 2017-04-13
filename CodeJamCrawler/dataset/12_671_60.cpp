#include <iostream>
#include <cassert>
#include <list>

using namespace std;


bool needs_no_surprise(int total, int p) {
	 return total >= p*3-2;
}

bool not_possible(int total, int p) {
	 return total < p || total < p*3-4;
}

int get_max(list<int>& totals, int surprises_left, int p) {
	 if (totals.empty()) {
		  return 0;
	 }

	 else {
		  int total = totals.front();
		  totals.pop_front();

		  if (needs_no_surprise(total, p)) {
				return 1 + get_max(totals, surprises_left, p);
		  }
		  else if (not_possible(total, p)) {
				return get_max(totals, surprises_left, p);
		  }
		  else {
				int use_surprise = surprises_left > 0 ? 1 : 0;
				return use_surprise + get_max(totals, surprises_left-use_surprise, p);
		  }
	 }
}

void handle_case(int case_nbr) {
	 cout << "Case #" << case_nbr << ": ";

	 int nbr_googlers;
	 cin >> nbr_googlers;

	 int surprises_left;
	 cin >> surprises_left;

	 int p;
	 cin >> p;

	 list<int> totals;

	 for (int i = 0; i < nbr_googlers; i++) {
		  int total;
		  cin >> total;
		  totals.push_back(total);
	 }

	 cout << get_max(totals, surprises_left, p) << endl;
}

int main(void) {
	 int T;

	 cin >> T;

	 for (int i = 0; i < T; i++) {
		  handle_case(i+1);
	 }

	 return 0;
}
