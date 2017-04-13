#include <string>
#include <vector>
#include <iostream>
using namespace std;

int l,d,n;
vector<string> dict;
string pattern;

void tokenize(vector<string>& tokens){
	int pos=0;
	bool in=false;
	for(int i=0;i<l;i++){
		while(pos<pattern.length()){
			if(pattern[pos]=='('){
				in=true;
				pos++;
				continue;
			}
			if(pattern[pos]==')'){
				pos++;
				in=false;
				break;
			}
			tokens[i]+=pattern[pos];
			pos++;
			if(!in){
				break;
			}
		}
	}	
}

int calc(){	
	vector<string> tokens(l);
	tokenize(tokens);
	
	int cnt=0;
	for(int i=0;i<dict.size();i++){
		int j;
		for(j=0;j<l;j++){
			//cout<<"->"<<dict[i][j]<<endl;
			if(tokens[j].find(dict[i][j])==tokens[j].npos){
				break;
			}
		}
		if(j==l){
			cnt++;
 		}	
	}
	return cnt;
	
	
}

int main(){
	cin>>l>>d>>n;
	cin.get();
	dict.resize(d);
	for(int i=0;i<d;i++){
		getline(cin,dict[i]);
	}
	for(int i=0;i<n;i++){
		getline(cin,pattern);
		cout<<"Case #"<<i+1<<": "<<calc()<<endl;
	}

	return 0;
}