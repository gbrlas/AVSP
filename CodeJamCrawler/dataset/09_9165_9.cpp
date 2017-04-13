#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
  using namespace std;

int main(){
	//cout << "suerte eCasas" << endl;
	string line;
	int tope, caso=1;
	cin >>tope;
	getline(cin,line,'\n');
	for(int i=0; i<tope; i++){
		getline(cin,line,'\n');
		//cout << "\t" << line << endl;
		if(next_permutation(line.begin(), line.end())){
			cout << "Case #" << caso++ << ": " << line << endl;
		} else {
			//cout << line << endl;
			line = "0" + line;
			//cout << "Case #" << caso++ << ": " << line << endl;
			while(line.at(0)=='0'){
				next_permutation(line.begin(), line.end());
			}
			cout << "Case #" << caso++ << ": " << line << endl;
		}
	}
	return 0;
}
