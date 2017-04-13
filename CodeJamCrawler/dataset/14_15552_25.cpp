#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**){
	int t, x, n, i, k, found, card;
	string str;
	vector<int> cards;
	cin >> t;
	for(x = 1; x <= t; x ++){
		cin >> n;
		i = 1;
		while(i < n){
			for(k = 0; k < 4; k++)
				cin >> card;
			i ++;
		}
		k = 0;
		cards.clear();
		while(k < 4){
			cin >> n;
			cards.push_back(n);
			k++;
		}
		while(i < 4){
			for(k = 0; k < 4; k++)
				cin >> card;
			i ++;
		}

		cin >> n;
		i = 1;
		while(i < n){
			for(k = 0; k < 4; k++)
				cin >> card;
			i ++;
		}

		k = found = card = 0;
		while(k < 4){
			cin >> n;
			if(find(cards.begin(), cards.end(), n) != cards.end()){
				card = n;
				found ++;
			}
			k++;
		}
		
		if(found == 0){
			cout << "Case #" << x << ": Volunteer cheated!" << endl;
		}else if(found == 1){
			cout << "Case #" << x << ": " << card << endl;
		}else {
			cout << "Case #" << x << ": Bad magician!" << endl;
		}

		while(i < 4){
			for(k = 0; k < 4; k++)
				cin >> card;
			i ++;
		}

	}
	return 0;
}