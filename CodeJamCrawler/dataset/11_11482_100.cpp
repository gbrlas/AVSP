
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solver{
private:
	virtual int Foo(vector <int> bag);
public:
	virtual void Solve(string input,string output);
};

int main(int argc,char* argv[]){
	string input,output;
	if(argc==1){
		input="sample.txt";
	}else{
		input=argv[1];
	}
	output="out.txt";
	Solver solver;
	solver.Solve(input,output);
}

void Solver::Solve(string input,string output){
	ifstream ifs(input.c_str());
	ofstream ofs(output.c_str());
	int t;
	ifs >> t;
	for(int u=0;u<t;u++){
		vector <int> bag;
		bag.clear();
		int i,j;
		ifs >> i;
		for(j=0;j<i;j++){
			int num;
			ifs >> num;
			bag.push_back(num);
		}

		int res = Foo(bag);

		ofs << "Case #"<<u+1<<": ";
		if(res>0)ofs<<res;
		else ofs<<"NO";
		ofs <<endl;

		cout << "Case #"<<u+1<<": ";
		if(res>0)cout<<res;
		else cout<<"NO";
		cout <<endl;
	}
}

int Solver::Foo(vector <int> bag){
	sort(bag.begin(),bag.end());
	long sum,xsum;
	sum=xsum=0;
	for(unsigned int i=0;i<bag.size();i++){
		xsum^=bag[i];
		sum+=bag[i];
	}
	if(xsum==0){
		return sum-bag[0];
	}else{
		return 0;
	}
}