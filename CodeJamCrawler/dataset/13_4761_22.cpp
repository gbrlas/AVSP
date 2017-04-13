#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int tries(long int A, long int B){
	if (A <= B) return 1+tries(A+(A-1),B);
	return 0;
}

long int calc(long int A,int count){
	while (count > 0){
		A=2*A-1;
		count -= 1;
	}
	return A;
}

int main() {
	ifstream fin;
	fin.open("A-large.in",std::ios_base::in);
	ofstream myfile; 
	myfile.open ("a.out");
  long int T,A;
  int N;
  int prob = 1;
  for (fin >> T; T--;) {
    fin >> A >>N;
	vector<long int> p(N);
	for (int i = 0;i < N;i++){
		fin >> p[i];
	}
	std::sort(p.begin(),p.end());
	int i=0;
	int result = 0;
	while (i< N){
		if (A <= p[i]){
			if (A != 1){
				int x = tries(A,p[i]);
				if (x < N-i){
					A = calc(A,x);
					result += x;
					A += p[i];
					i++;
				}
				else {
					result ++;
					i++;
				}
			}
			else {result = N;break;}
		}
		else if (A > p[i]){
			A += p[i];
			i++;
		}
	}
	if (result > N) result = N;
	myfile << "Case #" << prob++ << ": " << result << endl;
  }
  myfile.close(); 
  fin.close();
  cin.get();
  return 0;
}