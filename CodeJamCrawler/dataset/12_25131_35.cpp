#include<iostream>
#include<fstream>
using namespace std;
static const char T[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main(){
	string line;
	ifstream infile("A-small-attempt0.in");
	ofstream outfile("output.txt");
	if(infile.is_open()){
		int N;
		infile >> N;
		cout << N << endl;
		N++;
		for(int i = 0; i < N; ++i ){
			if(!infile.good())
				break;
			getline(infile, line);
			if(! line.length() ){
				--i;
				continue;
			}
			outfile << "Case #" << i+1 << ": ";
			cout << line << endl;
			int len = line.length();
			for(int i=0; i<len; ++i){
				if(line[i] >= 'a' && line[i] <= 'z')
					outfile << T[line[i] - 'a'];
				else
					outfile << line[i];
			}
			outfile << "\n";
		}
	}
	infile.close();
	outfile.close();
	return 0;
}
