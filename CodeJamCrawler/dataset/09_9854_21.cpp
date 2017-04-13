#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string s, int l){
	for(int i = s.length()-1; i>=s.length()-l;i--){
		if(s[i]!='0'){
			return false;
		}
	}
	return true;
}

int testcase(){
	int l;
	int res = 0;
	vector<string>v;
	cin >> l;
	v.resize(l);
	for(int i=0;i<l;i++){
		cin >> v[i];
	}
	for(int i=0;i<l-1;i++){
		int j = 0;
		for(vector<string>::iterator it = v.begin(); it!=v.end(); it++){
			if(check(*it,l-i-1)){
				v.erase(it);
				res+=j;
				break;
			}
			j++;
		}
	}
	return res;
}

int main(){
	int cases;
	cin >> cases;
	for(int i=0;i<cases;i++){
		printf("Case #%d: %d\n",i+1,testcase());
	}
	return 0;
}
