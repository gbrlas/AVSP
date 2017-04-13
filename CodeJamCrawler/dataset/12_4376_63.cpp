#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int J[300], n, tot;

bool poss(int ind, double sc, double frac){
	double req=0;
	
	for(int i=0; i<n; ++i){
		
		if(i==ind) continue;
		
		double r = max(0.0, (sc - J[i])/tot);
		
		req += r;
	}
	
	return req <= frac;
}

double bs(int ind, double lo, double hi){
	while(hi-lo >= 0.00000001){
		double g = (hi+lo)/2;
		if(!poss(ind, J[ind]+tot*g, 1-g)){
			hi = g;
		}
		else{
			lo = g;
		}
	}
	
	return (hi+lo)/2;
}

int main(){
	int t;
	cin >> t;
	
	for(int qq=1; qq<=t; ++qq){
		cin >> n;
		
		tot=0;
		for(int i=0; i<n; ++i){
			cin >> J[i];
			tot += J[i];
		}
		
		printf("Case #%d:", qq);
		
		for(int i=0; i<n; ++i){
			double b = bs(i,0,1);
			printf(" %.7lf", b*100);
		}
		
		cout << '\n';
		
	}
	
	return 0;
}
