#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (int)b; ++i)

void calc(string s){
    vector<int> z;
    for(int i = s.size() - 1; i >= 0; --i){
	z.push_back(s[i] - '0');
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

    for(int i = z.size() - 1; i >= 0; --i){
	cout << z[i];
    }
    cout << endl;
}

int main(void){
    int T;
    cin >> T;
    rep(c, 1, T+1){
	string s;
	cin >> s;
	cout << "Case #" << c << ": ";
	calc(s);
    }
    return 0;
}
