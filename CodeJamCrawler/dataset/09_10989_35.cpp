#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (int)b; ++i)

int calc(int n){
    vector<int> z;
    while(n > 0){
	z.push_back(n % 10);
	n /= 10;
    }
//    rep(i,0,z.size()) cout << z[i] << " "; cout << endl;
    int k;
    for(k = 1; k < z.size(); ++k){
	if(z[k-1] > z[k]) break;
    }
    if(k == z.size()){
	z.push_back(0);
	k = z.size() - 1; 
    }
    int l;
    for(l = 0; z[l] <= z[k]; ++l) ;
    swap(z[k], z[l]);
    --k; l = 0;
    while(k > l){
	swap(z[k], z[l]);
	--k; ++l;
    }
//    rep(i,0,z.size()) cout << z[i] << " "; cout << endl;

    int r = 0, m = 1;
    rep(i,0,z.size()){
	r += m * z[i];
	m *= 10;
    }
    return r;
}

int main(void){
    int T;
    cin >> T;
    rep(c, 1, T+1){
	int n;
	cin >> n;
	cout << "Case #" << c << ": " << calc(n) << endl;
    }
    return 0;
}
