#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int t;
	int n;
	int temp;
	int rec;
	int sum;
	int min;

	ifstream ifs;
	ofstream ofs;

	ifs.open("3.in");
	ofs.open("3.out");

	ifs >> t;
	for(int i = 1; i <= t; i++){
		ifs >> n;
		ifs >> rec;
		min = sum = rec;
		for(int j = 1; j < n; j++){
			ifs >> temp;
			if(temp < min)
				min = temp;
			sum += temp;
			rec = rec ^ temp;
		}
		if(rec != 0)
			ofs << "Case #" << i << ": NO" << endl;
		else{
			ofs << "Case #" << i << ": " << sum - min << endl;
		}
	}

	return 0;
}

