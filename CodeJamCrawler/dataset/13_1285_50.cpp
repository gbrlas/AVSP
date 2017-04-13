#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream f("a.txt");
	int a[5];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 11;
	a[4] = 22;
	int b[5];
	b[0] = 1;
	b[1] = 4;
	b[2] = 9;
	b[3] = 121;
	b[4] = 484;
	int t;
	cin >> t;
	int k = 0;
	while (t--) {
		int c;
		int d;
		cin >> c;
		cin >> d;
		int i1 = 0;
		
		for (int i = 0; i < 5; i++) {
			if (b[i] >= c && b[i] <= d) {
				i1++;
			}
		}
		cout << "Case #" << ++k << ": " << i1 << endl; 
		f <<  "Case #" << k << ": " << i1 << endl; 
	}
}