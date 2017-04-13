#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int tc;
    string line;
    
    cin >> tc;
    getline(cin, line);
    for(int x = 1; x <= tc; x++) {
	cout << "Case #" << x << ": ";
	string line;
	getline(cin, line);
	list<int> sz, sz2;
	sz.clear();
	for(int a = 0; a <  line.length(); a++) {
	    sz.push_back(line[a] - '0');
	    sz2.push_back(line[a] - '0');
	}
	if(next_permutation<list<int>::iterator>(sz.begin(), sz.end())) {
	    for(list<int>::iterator i = sz.begin(); i != sz.end(); i++)
		cout << *i;
	    cout << endl;
	} else {
	    sz2.push_front(0);
	    if(next_permutation<list<int>::iterator>(sz2.begin(), sz2.end())) {
		for(list<int>::iterator i = sz2.begin(); i != sz2.end(); i++)
		    cout << *i;
		cout << endl;
	    }
	}
    }
}