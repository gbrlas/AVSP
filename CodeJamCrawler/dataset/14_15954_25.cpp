#include <iostream>

using namespace std;

int main(){

	int t;
	double c, f, x, r = 2, tm;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>c>>f>>x;
		r = 2; tm = 0;
		while(x/r > (c/r + x/(r+f))){
			tm += c/r;
			r+=f;
		}
		
		tm += x/r;
		printf("Case #%d: %0.7lf\n", i+1, tm);
	}

	return 0;
}