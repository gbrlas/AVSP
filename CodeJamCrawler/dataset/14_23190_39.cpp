#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a[16],b[16], i =0, q, p, t, n;
	cin >> t;
	while(t--){
		 cin >> p;
		for(i=0; i<16; ++i){
			scanf("%d", &a[i]);
		}
		cin >> q;
		for(i=0; i<16; ++i){
			scanf("%d", &b[i]);
		}
		int k=0;
		for(i =4*(p-1); i<4*(p); ++i)
		{
			for(int j=4*(q-1); j<4*q; ++j)
			{
				if(a[i]==b[j]){
					++k;
					n = i;
				}
			}
		}
		if(k == 0)	cout << "Volunteer cheated!" << endl;
		else if(k == 1) cout << a[n] << endl;
		else if(k >1) cout << "Bad magician!" << endl;
	}
	return 0;
}
