#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void manger(int &A, list<int>& tab)
{
	list<int>::iterator it = tab.begin();
	while ( it != tab.end() && *it < A) {
		A += *it++;
	}
	tab.erase(tab.begin(), it);
}

int reduire(int &A, list<int>& tab, int &reponse)
{
	while ( (tab.front() - A) != 0 && (tab.front() - 2 * A + 1) && tab.front() - A < A ) {
		A += A - 1;
		reponse++;
		manger(A, tab);
	}
	return reponse + tab.size();
}

int main()
{
	int T;
	cin >> T;
	for (int C = 1; C <= T; C++) {
		int A,n;
		cin >> A >> n;
		list<int> tab;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			tab.push_back(tmp);
		}
		tab.sort();

		manger(A, tab);
		int reponse = tab.size();
		int decalage = 0;
		while ( tab.size() != 0 ) {
			manger(A, tab);
			reponse = min( reponse, reduire(A,tab, decalage));
			if ( A == 1 )
				break;
			A += A - 1;
			decalage++;
		}

		cout << "Case #" << C << ": " << reponse << endl;
	}
}
