#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using namespace std;

bool great (int i,int j) { return (i>j); }

class TaskA{
public:
	void run();
private:
	ifstream inFile;
	ofstream outFile;
	void search();
	int P,K,L;
	vector<int> l;
};

void TaskA::search(){
	sort(l.begin(), l.end(), great);
	if (K*P < L) {
		outFile << "Impossible" << endl;
		return;
	}
	int res = 0;
	for (int p = 0; p < P; p++){
		for (int k = 0; k < K; k++){
			if (p*K+k >= l.size()) continue;
			res+= (p+1)*l[p*K+k];
			//cout << res << " " ; 
		}
	}
	cout << "res = " << res << endl;
	outFile << res << endl;
}

void TaskA::run(){
	//inFile.open("A-test.in");
   // outFile.open("A-test.out");
	inFile.open("A-small-attempt1.in");
   outFile.open("A-small.out");
	//inFile.open("A-large.in");
   // outFile.open("A-large.out");
    
	int n,t;
	inFile >> n;
	cout << "n=" << n << endl;
	for (int i = 0; i<n; i++){

		inFile >> P >> K >>L;
		l.clear();
		for (int j = 0; j < L; j++){
			inFile >> t;
			l.push_back(t);
		}
		outFile << "Case #" << i+1 << ": ";
		search();
	}
}

int main(){
    TaskA* t = new TaskA();
    t->run();
}
