#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("b.out");
ifstream fin ("b.in");
char str[101];
int T,N, surprising, maxScore;

int main () {
	fin >> T;
	for(int j=1; j<= T; j++){
		int overMax = 0;
		int overMaxWithSpecial = 0;
		fin >> N >> surprising >> maxScore;
		for(int i=0;i<N;i++){
			int sum;
			fin >> sum;
			if(sum %3 == 0){
				if(sum/3 >= maxScore){
					overMax++;
				}
				else if((sum/3) + 1 >= maxScore && sum/3 - 1 >= 0){
					overMaxWithSpecial++;
				}
			}
			if(sum %3 == 1){
				if((sum+2)/3 >= maxScore){
					overMax++;
				}
			}
			if(sum %3 == 2){
				if((sum+1)/3 >= maxScore){
					overMax++;
				}
				else if(((sum+1)/3) + 1 >= maxScore && ((sum+1)/3) - 1 >= 0){
					overMaxWithSpecial++;
				}
			}
		}
		fout << "Case #" << j << ": " << overMax + min(overMaxWithSpecial, surprising) << endl;
	}
}