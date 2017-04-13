#include<iostream>
#include<vector>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t=0;t<T;++t){
		int R, k, N;
		cin >> R >> k >> N;
		vector<int> g(N,0);
		for(int i=0;i<N;++i){
			int g_i; cin >> g_i;
			g[i]=g_i;
		}
		int c=1;
		vector<long long> vec(1000,0);
		vector<int> check(N,-1);
		int i=0;
		check[0]=0;

		while(true){
			long long sum=0;
			int l=i;
			while(i<N&&sum+g[i]<=k){
				sum+=g[i];
				i=(i+1)%N;
				if(i==l) break;
			}
			vec[c]=sum+vec[c-1];
			if(check[i]!=-1)
				 break;
			if(i==l){
				check[1]=0;
				break;
			}

			check[i]=c;
			++c;
		}
		cout << "Case #" << t+1 << ": ";
		long long start=check[i];
		long long r1=((R-start)/(c-check[i]))*(vec[c]-vec[start]);
		long long r2=vec[start+((R-start)%(c-check[i]))];
			cout<<r1 + r2 << endl;
	}
	return 0;
}
