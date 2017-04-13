#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream fin ("B-small-attempt0.in");
ofstream fout ("B-small-attempt0.out");

int main(){
	int T; fin >> T;
	for(int t = 0; t < T; t++){
		fout << "Case #" << t+1  << ": ";
		int A, B, K; fin >> A >> B >> K;
		int total= 0;
		for(int a = 0; a < A; a++){
			for(int b = 0; b < B; b++){
				int res = a & b;
				if(res < K) total++;
			}
		}
		fout << total << endl;
	}
	return 0;
}