#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using namespace std;

class TaskA{
public:
	void run();
private:
	ifstream inputFile;
	ofstream outFile;
	vector<string> engines;
	vector<string> query;
	void searchQ();
	
};

void TaskA::searchQ(){
	bool isEnd = false;
	int curQ = 0;
	int curQ2 = 0;
	int nofSwitch = 0;
	int bestEngine = 0;
	int it = 0;
	if (query.size() ==0 || query.size() ==1){
		outFile << 0 << endl;
		return;
	}

	while (!isEnd){
		curQ = curQ2;
		int maxQ = 0;
		//cout << "it = " << it++ << endl;
		for (int s = 0; s < engines.size(); s++){
			string engine = engines[s];
			if (engine == query[curQ]) continue;
			for (int q = curQ + 1; q < query.size(); q++){
				//cout << engine << " " << query[q] << endl;
				if (engine == query[q]){
					if ( q - curQ > maxQ){
						maxQ = q -  curQ;
						curQ2 = q;
						bestEngine = s;
						break;
					}
					break;
				}
				if (q == query.size() -1 && engine != query[q]){
					curQ2 = q;
					maxQ = 10000000;
					bestEngine = s;
				}
			}// for q			
		}// for s
		cout << "curQ2 = " << curQ2 << " " << engines[bestEngine] <<  "maxQ = " << maxQ << endl;
		
		if ((curQ2 ==query.size()-1)&& engines[bestEngine] == query[query.size()-1]){
			nofSwitch++;
		}
		
		if (curQ2 !=query.size()-1 ){
			nofSwitch++;
		}else {
			isEnd = true;
		}
		
	}
	
	//cout << "nofSwitch = " << nofSwitch << endl;
	outFile << nofSwitch << endl;
}

void TaskA::run(){
	//inputFile.open("A-test.in");
    //outFile.open("A-test.out");
	inputFile.open("A-small-attempt4.in");
    outFile.open("A-small.out");
	int n;
	string st;
	inputFile >> n;
	int S;
	int Q;
	cout << "n=" << n << endl;
	for (int i = 0; i<n; i++){
		cout << "case = " << i+1 << endl;
		query.clear();
		engines.clear();
		inputFile >> S;
		cout << "S=" << S << endl;
		getline(inputFile,st);
		for (int s = 0; s < S; s++){
			getline(inputFile,st);
			engines.push_back(st);
		}
		inputFile >> Q;
		getline(inputFile,st);
		cout << "Q=" << Q <<endl;
		for (int q = 0; q < Q; q++){
			getline(inputFile, st);
			query.push_back(st);
		}
	
		for (int j = 0; j < engines.size(); j++){
			cout << engines[j]<< "   ";
		}
		cout << endl;
		for (int j = 0; j < query.size(); j++){
			cout << query[j]<< "   ";
		}
		cout << endl;
		outFile << "Case #" << i+1 << ": ";
		searchQ();
	}
}

int main(){
    TaskA* t = new TaskA();
    t->run();
}
