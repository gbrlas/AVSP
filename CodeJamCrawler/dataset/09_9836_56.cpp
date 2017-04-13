#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >>s;
		if(!next_permutation(s.begin(),s.end())){
			sort(s.begin(),s.end());
			while(s[0]=='0')
				next_permutation(s.begin(),s.end());
			s.insert(1,"0");
		}

		cout << "Case #" << (i+1) << ": " << s << "\n";
	}
	return 0;
}
