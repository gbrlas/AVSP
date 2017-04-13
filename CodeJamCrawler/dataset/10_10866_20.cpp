#include<iostream>
#include<fstream>

using namespace std;

int main(){
	long long T, K, N;
	
	ifstream fin("input.txt");
	fin >> T ;
	ofstream fout("output.txt");


	for (int i = 0 ; i < T ; i++){
		fin >> N >> K ;
		
		if ((K + 1)%(1LL << N) == 0)
			fout << "Case #" << i + 1 << ": ON\n" ;
		else	
			fout << "Case #" << i + 1 << ": OFF\n" ;
	}
	fout << endl ;	
}
