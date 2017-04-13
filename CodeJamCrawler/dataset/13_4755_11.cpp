#include <cstdio>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


int main() {
	ifstream fin;
	fin.open("A-small-attempt0.in",std::ios_base::in);
	ofstream myfile; 
	myfile.open ("a.out"); 
  int T, prob = 1;
  long double A,B = 1;
  for (fin >> T; T--;) {
    fin >> A >> B;
	int result = 0;
	while (B >= 0){
		long double area = pow(A+1,2)-pow(A,2);
		if (B-area >= 0){
			result ++;
			A +=2;
			B -=area;
		}
		else {
			break;
		}
	}
	myfile << "Case #" << prob++ << ": " << result << endl;
  }
  myfile.close(); 
  fin.close();
  cin.get();
  return 0;
}