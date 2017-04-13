#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string word[5001];
const int S='z'-'a'+2;
char ok[16][S];

int nr(char c){return int(c-'a');}
int D;

int res(string pattern){
	int d=word[0].length();
	int k=0;
	for(int i=0; i<d; i++)
	for(int j=0; j<S; j++) ok[i][j]=false;

	bool open=false;
	for(int i=0; k<d; i++){
		if(pattern[i]==')'){
			open=false;
			k++;
			continue;
		} else if(pattern[i]=='('){
			open=true;
			continue;
		} else {
			ok[k][nr(pattern[i])]=true;
			if(!open) k++;
		}
	}
	int res=0;
	for(int i=0; i<D; i++){
		bool acc=true;
		for(int j=0; j<d; j++) acc &= ok[j][nr(word[i][j])];
		if(acc)++res;
	}
	return res;
}

main(){
	int l,n,d;
	cin >> l >> d >> n;
	D=d;
	for(int i=0; i<d; i++){
		cin >> word[i];
	}
	string pattern;
	for(int i=0; i<n; i++){
		cin >> pattern;
		printf("Case #%d: %d\n", i+1, res(pattern));
	}
}
