#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream infile("B-large.in");
	ofstream outfile("output_B.txt");
	if(infile.is_open()){
		int T;
		infile >> T;
		for(int i = 1; i <= T; ++i ){
			int N, S, P;
			infile >> N >> S >> P;
			int count = 0, sCount = 0, score;
			for(int j = 0; j < N; ++j ){
				infile >> score;
				if(!score && P)
					continue;
				if(!score && !P){
					++count;
					continue;
				}
				int evenly = score / 3;
				int leftover = score - 3 * evenly;
				if( evenly >= P )
					++count;
				else if( P - evenly == 1 ){
					if(leftover == 2)
						++count;
					else if(leftover == 1){
						++count;
					}
					else if( leftover == 0 && sCount < S){
						++count; ++sCount;
					}
				}
				else if( P - evenly == 2 ){
					if(leftover == 2 && sCount < S){
						++count;
						++sCount;
					}
				}
			}
			outfile << "Case #" << i << ": " << count << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}
