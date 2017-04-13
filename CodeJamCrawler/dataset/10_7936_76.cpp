#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a,long long b){
	return (b==0)?a:gcd(b,a%b);
}

int main(){
	int C; cin >> C;
	for(int c=0;c<C;++c){
		int T; cin >> T;
		vector<long long> time(T,0);
		for(int i=0;i<T;++i){
			long long t;
			cin >> t;
			time[i]=t;
		}
		sort(time.begin(),time.end());
		long long GCD=(time[1]-time[0]);
		for(int i=2;i<T;++i)
			GCD=gcd((time[i]-time[i-1]),GCD);
		long long y=-time[0];
		while(y<0)
			y+=GCD;
		cout << "Case #" << c+1 << ": " << y << endl;
	}


}


