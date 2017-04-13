#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void Solve(){
	int t = 0;
	cin >> t;
	
	char s[50];
	gets(s);
	for(int i=0;i<t;i++){
		cout <<"Case #" << i+1 << ": ";
		gets(s);
		int n = strlen(s);
		vector<int> v;
		for(int j=0;j<n;j++){
			v.push_back(s[j]-'0');
		}
		if (next_permutation(v.begin(),v.end())){
			for(int j=0;j<n;j++){
				cout << v[j];
			}
		}
		else{
			v.push_back(0);
			sort(v.begin(),v.end());
			int j = 0;
			while(v[j]==0) j++;
			int c = v[0];
			v[0] = v[j];
			v[j] = c;

			for(int j=0;j<n+1;j++){
				cout << v[j];
			}
		}
		cout <<"\n";
	}
}

int main(){
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}