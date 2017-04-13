#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		long long N,K;
		cin >> N >> K;
		cout << "Case #"<<t+1<<": ";
		if((1<<N)-1 == (K%(1<<N)))
			cout << "ON";
		else cout << "OFF";
		cout << endl;
	}
	return 0;
}
