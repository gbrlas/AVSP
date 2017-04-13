#include<iostream>
#include<vector>

using namespace std;

void print(vector<char> output){
	cout << "[";
	if(output.size()>0) cout << output[0];
	for(int i=1;i<output.size();++i)
		cout << ", " << output[i];
	cout << "]" << endl;
}

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;++t){
		vector<vector<char> > combine(256,vector<char>(256,0));
		int C; cin>>C;
		for(int c=0;c<C;++c){
			string s; cin>> s;
			combine[s[0]][s[1]]=s[2];
			combine[s[1]][s[0]]=s[2];
		}
		int D;cin>>D;
		vector<vector<bool> > opposite(256,vector<bool>(256,0));
		for(int d=0;d<D;++d){
			string s; cin>> s;
			opposite[s[0]][s[1]]=1;
			opposite[s[1]][s[0]]=1;
		}
		int size; cin >> size;
		string N; cin >> N;
		vector<char> output;
		for(int n=0;n<size;++n){
			if(!output.size())
				output.push_back(N[n]);
			else{
				int last = output.size()-1;
				if(combine[N[n]][output[last]]!=0){
					output[last]=combine[N[n]][output[last]];
					continue;
				}
				output.push_back(N[n]);
				for(int i=0;i<=last;++i){
					if(opposite[N[n]][output[i]]){
						output.clear();
						break;
					}
				}
			}
		}
		cout << "Case #" << t << ": ";
		print(output);
	}
	return 0;
}
