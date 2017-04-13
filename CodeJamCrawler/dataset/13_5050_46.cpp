#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#define LL long long

using namespace std;

int R, N, M, K;
int p[100];
long long fac[100] = {1,1,2,6,24,120};

vector<int> s;

map<int, vector<vector<int> > > factor;
vector<vector<int> > F[100];

long long binom(int n, int k){
	if(n==k) return 1;
	if(k<0 || k>n) return 0;
	return fac[n]/fac[k]/fac[n-k];
}

void build(int val, int left, long long prod){
	if(val == M+1){
//		for(int i=2; i<=M; ++i)  cout << s[i-2] << ' ';
//		cout << " = " << prod << '\n';
		
		factor[prod].push_back(s);
		
		return;
	}
	
	long long pwr = 1;
	for(int i=0; i<=left; ++i){
		s[val-2] = i;
		build(val+1, left-i, prod*pwr);
		pwr *= val;
	}
}

long long bestwp;
string bestdisp;

long long Pow(long long a, long long b){
	long long ans=1;
	for(int i=0; i<b; ++i) ans *= a;
	return ans;
}

void seq(int val, int left, long long rep, string disp){
	if(val == M){
		s[val-2] = left;
		rep *= fac[left];
		for(int i=0; i<left; ++i) disp += char('0'+val);
		
		long long wtprod=fac[N]/rep;
		
		for(int i=0; i<K; ++i){
			// prob that this set produces p[i]
			long long wt=0;
			for(int j=0; j<F[i].size(); ++j){
				bool good=1;
				for(int k=2; k<=M; ++k){
					if(F[i][j][k-2] > s[k-2]) good=0;
			//		else{
			//			wt += Pow();
			//		}
				}
				if(good) wt=1;
			}
			wtprod *= wt;
		}
		
		if(wtprod > bestwp){
			bestwp = wtprod;
			bestdisp = disp;
		}
//		cout << disp << ' ' << wtprod << '\n';
		
		return;
	}
	
	for(int i=0; i<=left; ++i){
		s[val-2] = i;
		seq(val+1, left-i, rep*fac[i], disp);
		disp += char('0'+val);
	}
}

int main(){
	int cases;
	
	for(int i=3; i<15; ++i) fac[i] = fac[i-1]*i;
	
	cin >> cases;
	for(int q=1; q<=cases; ++q){
		cin >> R >> N >> M >> K;
		cout << "Case #" << q << ":\n";
		
		s.resize(M-1);
		build(2,N,1);
		
		for(int i=0; i<R; ++i){
			for(int j=0; j<K; ++j){
				cin >> p[j];
				F[j] = factor[p[j]];
			}
			
			bestwp = -1;
			seq(2,N,1,"");
			cout << bestdisp << "\n";
		}
	}
	
	return 0;
}
