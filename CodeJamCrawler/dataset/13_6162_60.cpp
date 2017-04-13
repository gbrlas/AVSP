#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ifstream in("C-small-attempt0.in");
	ofstream out("C-sample-attempt0.out");
	int t = 0;
	in >> t;
	cout << t << endl;	
	
	for (int i = 1; i <= t; i++) {
		int a, b;
		in >> a;
		in >> b;
		cout << a << "\t" << b << endl;
		
		int low = 1, high = a, aroot = 0, broot = 0;
		while (low <= high) {
			aroot = low + (high-low) / 2;
			if (aroot > INT_MAX / aroot || aroot*aroot > a) {
				high = aroot-1;	
			}else if (aroot*aroot < a) {
				low = aroot+1;	
			}else if (aroot*aroot == a) {
				break;	
			}
		}
		if (aroot*aroot != a) {
			aroot = low;	
		}
		low = 1, high = b, broot = 0;
		while (low <= high) {
			broot = low + (high-low) / 2;
			if (broot > INT_MAX / broot || broot*broot > b) {
				high = broot-1;	
			}else if (broot*broot < b) {
				low = broot+1;	
			}else if (broot*broot == b) {
				break;	
			}				
		}
		if (broot*broot != b) {
			broot = low-1;	
		}
		
		int res = 0;
		if (aroot >= 1) {
			for (int root = aroot; root <= broot; root++) {
				bool palindrome = true;
				
				int c = root*root;
				int x = c, d = 1;
				while (x > 9) {
					d *= 10;
					x /= 10;
				}				
				x = c;
				while (x > 0) {
					if (x/d != x%10) {
						palindrome = false;
						break;	
					}
					x %= d;
					x /= 10;
					d /= 100;
				}
				
				x = root, d = 1;
				while (x > 9) {
					d *= 10;
					x /= 10;	
				}
				x = root;
				while (x > 0) {
					if (x/d != x%10) {
						palindrome = false;
						break;
					}
					x %= d;
					x /= 10;
					d /= 100;
				}
				
				if (palindrome) {
					res++;
					cout << "c = " << c << endl;
					cout << "root = " << root << endl;	
				}
			}
		}
		out << "Case #" << i << ": " << res << endl;
		cout << "Case #" << i << ": " << res << endl;
	}
	
	return 0;	
}
