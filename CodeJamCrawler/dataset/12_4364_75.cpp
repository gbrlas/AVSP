#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b?gcd(b,a%b):a;
}

pair<int,int> nor(int a, int b){
	int g = gcd(abs(a), abs(b));
	
//	cout << a << ',' << b << " -> " << a/g << ',' << b/g << '\n';
	return make_pair(a/g, b/g);
}

bool dist(int a, int b, int d){
	if(!a && !b) return 0;
	return a*a + b*b <= d*d;
}

int main(){
	int t;
	cin >> t;
	
	for(int q=1; q<=t; ++q){
		cout << "Case #" << q << ": ";
		int h, w, d;
		int x, y;
		
		cin >> h >> w >> d;
		
		string s[30];
		for(int i=0; i<h; ++i){
			cin >> s[i];
			for(int j=0; j<w; ++j){
				if(s[i][j] == 'X'){
					x=i;
					y=j;
				}
			}
		}
		
		int A = 2*x - 1, B = 2*h - 2*x - 3;
		int C = 2*y - 1, D = 2*w - 2*y - 3;
		
//		cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';
		
		int P=0, Q=0;
		while(P <= d) P += (A+B);
		while(Q <= d) Q += (C+D);
		
		P = -P; Q = -Q;
		
		vector<pair<int,int> > v;
		
		for(int pp=P; pp<=d; pp+=(A+B)){
			for(int qq=Q; qq<=d; qq+=(C+D)){
				v.push_back(make_pair(pp,qq));
				v.push_back(make_pair(pp+B,qq));
				v.push_back(make_pair(pp,qq+C));
				v.push_back(make_pair(pp+B,qq+C));
				
//				cout << pp << ' ' << Q << '\n';
			}
		}
		
		set<pair<int,int> > pts;
		for(int i=0; i<v.size(); ++i){
			if(dist(v[i].first, v[i].second, d)) pts.insert(nor(v[i].first, v[i].second));
		}
		
		cout << pts.size() << '\n';
	}
	
	return 0;
}
