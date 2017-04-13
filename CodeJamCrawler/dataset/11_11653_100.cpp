#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int T; cin >>T;
	for(int t=0;t<T;++t){
		int N; cin >> N;
		vector<int> array(N,0);

		for(int n=0;n<N;++n){
			cin >>array[n];
		}
		vector<int> array1=array;
		sort(array1.begin(),array1.end());
		int fail=0;
		for(int i=0;i<array.size();++i)
			fail+=(array1[i]!=array[i]);	

		cout << "Case #" << t+1 << ": " << fail << endl;
	}

	return 0;

}
