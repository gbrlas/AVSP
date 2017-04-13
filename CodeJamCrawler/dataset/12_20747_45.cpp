#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ifstream myfile;
	ofstream out;
	myfile.open("input.txt");
	out.open("output.txt");
	int T;
	myfile >> T;
	cout << T << endl;
	for(int i=0; i<T; i++){
		int N, S, P;
		myfile >> N >> S >> P;
		cout << N << " "<< S << " "<< P << endl;
		vector<int>ti;
		int answer =0;
		for(int j=0; j<N; j++){
			int tin;
			myfile >> tin;
			ti.push_back(tin);
			if(tin>=max(3*P-2,0)){
				answer++;
				continue;
			}
			if(tin>max(3*P-5,0) && S>0){
				answer++; 
				S--;
			}
		}
		
		out << "Case #" << i+1 << ": " << answer << endl;
	}
	//system("PAUSE");
	return 0;
}