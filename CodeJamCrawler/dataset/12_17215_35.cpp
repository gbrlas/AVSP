#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >>t;
	int N,S,p;
	for(int i=1;i<=t;i++){
		int count=0;
		cin >> N>>S>>p;
		vector <int> val(N);
		for(int j=0;j<N;j++)
			cin >> val[j];
		sort(val.begin(),val.end());
		for(int j=N-1;j>=0;j--){
			if(p==0) count++;
			else if(val[j]==0) ;	
			else if(val[j]>=3*p-2) count++;
			else if(val[j]>=3*p-4 && S>0 ) {count++; S--;}
//			cout << val[j]<<endl;
		}
		cout << "Case #"<<i<<": "<<count<<endl;
		
	}
	return 0;
}
