#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t=0;t<T;++t){
		int N;cin >> N;
		int check, sum = 0;
		vector<int> C(N,0);
		for(int i=0;i<N;++i)
			cin >> C[i];
		sort(C.begin(),C.end());
		check=C[0];
		for(int i=1;i<N;++i){
			check = (check ^ C[i]);
			sum+=C[i];
		}
		cout << "Case #" << t+1 << ": ";
		if(check)
			cout << "NO";
		else
			cout << sum;
		cout << endl;

	}
	return 0;

}
