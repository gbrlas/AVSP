
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solver{
private:
	virtual string Foo(vector <string> comb,vector<string> opp,string word);
public:
	virtual void Solve(string input,string output);
};

int main(int argc,char* argv[]){
	string input,output;
	if(argc==1){
		input="sample.in";
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
		vector <string> comb;
		vector <string> opp;
		string str;
		int i,j;
		ifs >> i;
		for(j=0;j<i;j++){
			ifs >> str;
			comb.push_back(str);
		}
		ifs >> i;
		for(j=0;j<i;j++){
			ifs >> str;
			opp.push_back(str);
		}
		ifs >> i;
		ifs >> str;

		string res = Foo(comb,opp,str);

		ofs << "Case #"<<u+1<<": [";
		for(i=0;i<(signed)res.length();i++){
			ofs << res[i];
			if(i+1<(signed)res.length()){
				ofs << ", ";
			}
		}
		ofs << "]"<<endl;

		cout << "Case #"<<u+1<<": [";
		for(i=0;i<(signed)res.length();i++){
			cout << res[i];
			if(i+1<(signed)res.length()){
				cout << ", ";
			}
		}
		cout << "]"<<endl;
	}
}

string Solver::Foo(vector <string> comb,vector<string> opp,string word){
	string res="";
	int wc=0;
	for(;;){
		if(wc==word.length())break;
		res+=word[wc];
		wc++;
retry:
		if(res.length()<=1)continue;
		int i;
		for(i=0;i<comb.size();i++){
			if( (comb[i][0]==res[res.length()-1] && comb[i][1]==res[res.length()-2])
			||  (comb[i][0]==res[res.length()-2] && comb[i][1]==res[res.length()-1])){
				res.erase(res.end()-1);
				res.erase(res.end()-1);
				res+=comb[i][2];
				goto retry;
			}
		}
		for(i=0;i<opp.size();i++){
			int p1=res.find(opp[i][0],0);
			int p2=res.find(opp[i][1],0);
			if(p1!=string::npos && p2!=string::npos){
				if(p1==res.length()-1 || p2==res.length()-1){
					res.erase();
					goto retry;
				}
			}
		}
	}
	return res;
}