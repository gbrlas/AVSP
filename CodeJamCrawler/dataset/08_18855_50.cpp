#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


class PairComparatorMore: 
       public std::binary_function<
	          const pair<int, int>&,
	          const pair<int, int>&,
	          bool> 
{
public:
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
		return p1.first < p2.first;
	}
};

class TaskB{
public:
	void run();
private:
	ifstream inputFile;
	ofstream outFile;
	vector<pair<int, int> > A;
	vector<pair<int, int> > B;		
	void TimeTable();
	
};

void TaskB::TimeTable(){
	bool isFreeTrain = false;
	int trainNeededA = 0;
	int trainNeededB = 0;
	for (int na = 0; na < A.size(); na++){
		int aDep = A[na].first;
		isFreeTrain = false;
		for (int nb = 0; nb < B.size(); nb++){
			if (aDep >= B[nb].second && B[nb].second != -1){
				B[nb].second = -1;
				isFreeTrain = true;
				break;
			}
		}
		if (isFreeTrain == false){
			trainNeededA++;
		}
	}
	cout << "trainNeededA = " << trainNeededA << endl;
	
	for (int nb = 0; nb < B.size(); nb++){
		int bDep = B[nb].first;
		isFreeTrain = false;
		for (int na = 0; na < A.size(); na++){
			if (bDep >= A[na].second && A[na].second != -1){
				A[na].second = -1;
				isFreeTrain = true;
				break;
			}
		}
		if (isFreeTrain == false){
			trainNeededB++;
		}
	}
	cout << "trainNeededB = " << trainNeededB << endl;
	
	outFile << trainNeededA << " " << trainNeededB << endl;
	
}

void TaskB::run(){
	//inputFile.open("B-test.in");
  //  outFile.open("B-test.out");
	inputFile.open("B-small-attempt0.in");
    outFile.open("B-small.out");
	int n;
	string st;
	int T, NA, NB;
	inputFile >> n;
	cout << "n=" << n << endl;
	for (int i = 0; i<n; i++){
		cout << "case = " << i+1 << endl;
		A.clear();
		B.clear();
		inputFile >> T;
		inputFile >> NA >> NB;
		int h1,m1,h2,m2;
		char c;
		
		for (int na = 0; na < NA; na++){
			inputFile>>h1>>c>>m1>>h2>>c>>m2;
			cout << h1 <<":"<< m1 << "  " << h2 << ":" << m2 << endl;
			A.push_back(pair<int ,int>(h1*60+m1, h2*60+m2 + T));
		}
		for (int nb = 0; nb < NB; nb++){
			inputFile>>h1>>c>>m1>>h2>>c>>m2;
			cout << h1 <<":"<< m1 << "  " << h2 << ":" << m2 << endl;
			B.push_back(pair<int ,int>(h1*60+m1, h2*60+m2 + T));
		}
		
		std::sort(A.begin(), A.end(), PairComparatorMore());
		std::sort(B.begin(), B.end(), PairComparatorMore());
		
		for (int na = 0; na < NA; na++){
			cout << A[na].first << " " << A[na].second<< endl;
		}
		for (int nb = 0; nb < NB; nb++){
			cout << B[nb].first << " " << A[nb].second<<endl;
		}
		outFile << "Case #" << i+1 << ": ";
		TimeTable();
	}
}

int main(){
    TaskB* t = new TaskB();
    t->run();
}
