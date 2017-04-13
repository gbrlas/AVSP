
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solver{
private:
	virtual double Foo(vector <int> s);
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
	FILE *fp;
	fopen_s(&fp,output.c_str(),"w");
	int t;
	ifs >> t;
	for(int u=0;u<t;u++){
		vector <int> s;
		s.clear();
		int i,j;
		ifs >> i;
		for(j=0;j<i;j++){
			int num;
			ifs >> num;
			s.push_back(num);
		}

		double res = Foo(s);

		fprintf(fp,"Case #%d: %.6lf\n",u+1,res);

		printf("Case #%d: %.6lf\n",u+1,res);

	}
	fclose(fp);
}

double Solver::Foo(vector <int> s){
	vector <int> t;
	unsigned int i;
	for(i=0;i<s.size();i++){
		t.push_back(s[i]);
	}
	sort(t.begin(),t.end());
	int count=0;
	for(i=0;i<s.size();i++){
		if(t[i]!=s[i])count++;
	}
	return (double)count;
}