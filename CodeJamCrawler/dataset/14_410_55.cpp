#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("B-small-attempt0.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf()); 

	int cases;
	cin >> cases;
	double req;
	double add;
	double win;
	double initial = 2;
	int caseNo = 0;

	for (int i = 0; i < cases; i++) {
		caseNo++;
		cin >> req;
		cin >> add;
		cin >> win;
		double ans1 = 0;
		double toadd = 0;
		double temp = 0;
		double ans2 = 0;
		// cout << req << " " << add << " " << win << endl;
		initial = 2;

		while (true) {
			temp = toadd;
			toadd =  temp + (req)/(initial);

			ans1 = toadd + (win)/(initial+add);
			
			ans2 = temp + (win)/(initial);

			// cout << "answers: " << initial << " " << ans1 << " " << ans2 << endl;
			if (ans1 < ans2) {
				initial = static_cast<double>(initial) + static_cast<double>(add);
			} else {
				cout << fixed;
    			cout << setprecision(7);				
				cout << "Case #" << caseNo << ": " << ans2 << endl;
				break;
			}
		}


	}

	return 0;
}