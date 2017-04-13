#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int N;
string welcome = "welcome to code jam";
string test;
int sizew, sizet;
bool letras[256];
vector<int> ind[256];
int pd[19][501];

int testar(int pw, int pt) {
	int total = 0;

	if(pw >= sizew){
		total = (total + 1) % 10000;
		pd[pw][pt] = total;
		return total;
	}
	
	if(pd[pw][pt] == -1){
	
		if(pt >= sizet) return 0;

		if(sizet - pt < sizew - pw) return 0;

		for(int i=0; i<ind[welcome[pw]].size(); i++){
			if(ind[welcome[pw]][i] >= pt){
				total = (total + testar(pw+1, ind[welcome[pw]][i]+1)) % 10000;
			}
		}

		pd[pw][pt] = total;
	}

	return pd[pw][pt];
}

int main() {
	cin >> N;
	getline(cin, test);
	sizew = welcome.size();

	memset(letras, false, sizeof(letras));
	for(int i=0; i<sizew; i++){
		letras[welcome[i]] = true;
	}
	
	int total;
	for (int i = 1; i <= N; ++i) {
		memset(pd, -1, sizeof(pd));

		for(int k=0; k<256; k++){
			if(letras[k]) ind[k].clear();
		}

		getline(cin, test);
		sizet = test.size();
		total = 0;
		
		if (sizet >= sizew) {
			for(int k=0; k<sizet; k++){
				if(letras[test[k]]) ind[test[k]].push_back(k);		
			}
			total = testar(0, 0);
		}

		printf("Case #%d: %04d\n", i, total % 10000);
	}

	return (0);
}

