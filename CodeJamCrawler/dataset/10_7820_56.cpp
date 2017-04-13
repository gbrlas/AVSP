#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define EPS 1E-10

struct chick{
	double mytime;
	int x;
	int v;
	bool out;
	bool goal;
	bool need;
};

int main(){
	int c,d;
	int rtn;
	cin >> c;
	for(d=1;d<=c;d++){
		int n,k,b,t;
		int w;
		vector <chick> f;
		rtn=0;
		f.clear();
		cin >> n >> k >> b >> t;
		for(w=0;w<n;w++){
			chick temp;
			cin >> temp.x;
			f.push_back(temp);
		}
		for(w=0;w<n;w++){
			cin >> f[w].v;
			f[w].mytime=(double)(b-f[w].x)/(double)f[w].v;
			f[w].out=false;
			f[w].goal=( EPS >= f[w].mytime - (double)t);
			f[w].need=false;
		}
		int cc=0;
		for(w=n-1;w>=0 && cc<k;w--){
			if(f[w].goal){
				f[w].need=true;
				cc++;
			}
		}
		if(cc<k){
			cout << "Case #" << d << ": " << "IMPOSSIBLE" << endl;
		}else{
			int cn=0;
			for(w=0;w<n;w++){
				if(f[w].need==false){
					rtn+=cn;
				}
				if(f[w].need==true){
					cn++;
				}
			}
			cout << "Case #" << d << ": " << rtn << endl;
		}
	}
	return 0;
}
