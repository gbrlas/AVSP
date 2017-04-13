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
			int j=1;
			while(s[0]=='0')
				swap(s[0],s[j++]);
			s.insert(1,"0");
		}

		cout << "Case #" << (i+1) << ": " << s << "\n";
	}
	return 0;
}
