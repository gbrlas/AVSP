
#include <iostream>
#include "BigIntegerLibrary.hh"

#include <algorithm>
using namespace std;

//class BigUnsigned comes from bigint-2010.04.30 package
struct myclass {
  bool operator() (const BigUnsigned& l, const BigUnsigned& r) { return (l < r);}
} myobject;


int main(){
    int C;
    cin >> C;
    BigUnsigned t[1000];
    for(int i = 0; i < C; ++i){
        int N;
        cin >> N;
        for(int j = 0; j < N; ++j){
		string s;
		cin >> s;
		t[j] = stringToBigUnsigned(s);
	}	
        sort(t, t + N, myobject);
        BigUnsigned g = 0;
        for(int j = 0; j < N - 1; ++j){
            if(g == 0) g = t[j + 1] - t[j];
            else{
                if(t[j + 1] == t[j]) continue;
                g = gcd(g, t[j + 1] - t[j]);
            }
        }
        BigUnsigned y;
        if(t[0] % g == 0) y = 0;
        else y = (t[0] / g + 1) * g - t[0];
		cout << "Case #" << i + 1 << ": " << y << endl;
    }

}

