#include<iostream>
#include<fstream>

using namespace std;

int main(){
	long long T, R, k, N;
	
	ifstream fin("input.txt");
	fin >> T ;
	
	ofstream fout("output.txt");
	
	long long * g;
	for (int i = 0 ; i < T ; i++){
		fin >> R >> k >> N ;
		
		g = new long long[N];
		for (int j = 0 ; j < N ; j++)
			fin >> g[j];
			
		int nextPtr = 0;
		long long sum = 0;
		long long totalSum = 0;
		for (int j = 0 ; j < R ; j++){
			sum = 0;
			for (int l = 0 ; l < N ; l++){
				if(sum + g[nextPtr] > k)
					break;
					
				sum += g[nextPtr];
				nextPtr = (++nextPtr) % N;	
			}
			totalSum += sum;
		}
		
		fout << "Case #" << i + 1 << ": " << totalSum << endl ;
	}
	
	system("pause");
}
