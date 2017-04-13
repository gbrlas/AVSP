#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
int L,D,N;

int evaluate(const vector<string>& keys, const vector<vector<bool> >& p){
	
	int count=0;
	for(int i=0;i<keys.size();++i){
		bool language=true;
		for(int l=0;l<L;++l){
			if(!p[l][keys[i][l]-'a'])
				 language=false;
			if(!language) break; 

		}
		if(language) ++count;
		}
	return count;
}




int main(){
	ofstream fout("alien.out");
	cin >> L >> D >> N;
	vector<string> keys(D,"");
	for(int d=0;d<D;++d)
		cin >> keys[d];
	
	vector< vector<bool> > p(L,vector<bool>(27,false));

	for(int n=0;n<N;++n){
		for(int a=0;a<L;++a)
			for(int b=0;b<27;++b)
				p[a][b]=false;

		string S;
		cin >> S;
		int k=0;
		
		for(int i=0;i<S.size();++i){
			if(S[i]=='('){
				while(S[++i]!=')')
					p[k][S[i]-'a']=true;
			}
			else p[k][S[i]-'a']=true;

			++k;
		}
		fout << "Case #"<< n+1 << ": "	<< evaluate(keys,p) << endl;
	}

	return 0;


}
