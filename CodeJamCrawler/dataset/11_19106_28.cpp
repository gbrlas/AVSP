#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

_int64 gcd( _int64, _int64);

int main () {
	ifstream fin ("C.in");
	ofstream fout ("C.out");

	int T;
	_int64 N, L, H;
	_int64* Freq;
	fin >> T;
	for( int i=1; i<= T; i++) {
		fin >> N >> L >> H;
		Freq= new _int64[N];
		bool ok =true;
		
		for(int I = 0; I< N; I++){
			fin >> Freq[I];
		}
		sort(Freq, Freq+N);
		bool valid = true;
		_int64 ctr;
		for(ctr=L; ctr<=H; ctr++) {
			valid=true;
			for(int ctr2=0; ctr2 < N; ctr2++) {
				if( Freq[ctr2] <= ctr){
					if(ctr % Freq[ctr2] != 0) {
						valid = false;
						break;
					}
				}else{
					if( Freq[ctr2] % ctr != 0){
						valid= false;
						break;
					}
				}
			}
			if(valid)
				break;
		}
		fout<<"Case #"<<i<<": ";
		if(valid) {
			fout<<ctr<<endl;
		}else {
			fout<<"NO\n";
		}
	}
	return 0;
}

_int64 gcd(_int64 a, _int64 b){
	if(a < b) {_int64 temp=b; b=a; a=temp;}
	while(b!=0){
		_int64 t=b;
		b=a%b;
		a=t;
	}
	return a;
}