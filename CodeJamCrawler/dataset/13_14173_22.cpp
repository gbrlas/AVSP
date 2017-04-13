#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minOperations(int a, vector<int>& motes, int position) {
	// cerr << "motes.size = " << motes.size() <<  " a = " << a << "position = " << position << " motes[position] = " << motes[position] << endl;
	while (position < motes.size()  and a > motes[position]) {
		//cerr << "motes[position] = " << motes[position] << " position = " << position << " a = " << a << endl;
		a += motes[position];
		++position;
		// cerr << " position = " << position << endl;
	}

	if (position == motes.size()) {
		return 0;
	}

	int firstMin = minOperations(a, motes, position + 1) + 1;
	// cerr << "first Min = " << firstMin << endl;
	//return 0;
	//calculate num of operations and a increment
	int numDuplications = 0;
	int incrementedA = a;
	while (incrementedA <= motes[position] and numDuplications < firstMin) {
		++numDuplications;
		incrementedA = incrementedA*2 - 1;
	}
	
	if (numDuplications >= firstMin) {
		return firstMin;
	}
	// cerr << "incrementedA = " << incrementedA << " position = " << position << endl;
	return min(firstMin, numDuplications + minOperations(incrementedA, motes, position));
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		int numMotes;
		cin >> numMotes;
		// cerr << "waiting for segFault" << endl;
		vector<int> motes(numMotes);
		// cerr << "still waiting " << endl;
		for (int j = 0; j < numMotes; ++j) {
			cin >> motes[j];
		}
		// cerr << "not segfault" << endl;
		sort(motes.begin(), motes.end());
		// cerr << "a = " << a << endl;
		for (int j = 0; j < motes.size(); ++j) {
			// cerr << motes[j] << ", ";
		}
		// cerr << endl;
		cout << "Case #" << i << ": " << minOperations(a, motes, 0) << endl;
	}
}
