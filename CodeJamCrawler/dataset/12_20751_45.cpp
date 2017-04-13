#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int permutations[8] = {0,0,1,3,12,60,360, 2520};
int p[8] = {0,0,1,2,6,24,120,720};
int*cc, *mm, *nn;

int ascending(int d, int a){
	int answer=d;
	bool nontrivial = 0;
	int c, cmm;
	cmm = a%10;
	for(int b=0; b<d; b++){
		c = a%10;
		cc[b]=c;
		a/=10;
		if(c!=cmm) nontrivial=true;
	}
	if(!nontrivial) return 0;
	for(int b=0; b<d; b++){
		bool bad = false;
		for(int x=d-1; x>=0; x--){
			if(cc[(b+x)%d]>mm[x]){
				bad=true;
				break;
			}else if(cc[(b+x)%d]<mm[x]){
				break;
			}
		}
		if(!bad){
			for(int x=d-1; x>=0; x--){
				if(cc[(b+x)%d]<nn[x]){
					bad=true;
					break;
				}else if(cc[(b+x)%d]>nn[x]){
					break;
				}
			}
		}
		if(bad) answer--;
	}

	//if(answer==0) return 0;
	//return permutations[answer]/(double)answer;
	return p[answer];
}
inline int pow10(int d){
	int i=1; 
	for(int x=0; x<d; x++){
		i*=10;
	}
	return i;
}
inline int zzz(int n, int m){
	int d = log10f(m)+1;
	cc = new int[d];
	mm = new int[d];
	nn = new int[d];
	int mmm = m;
	for(int b=0; b<d; b++){
		mm[b] = mmm%10;
		mmm/=10;
	}
	int nnn = n;
	for(int b=0; b<d; b++){
		nn[b] = nnn%10;
		nnn/=10;
	}
	double answer = 0;
	//cout << "NEW PROBLEM" << endl;
	for(int a=n; a<=m; a++){
		//if(ascending(d,a)!=0)cout << a << " " << ascending(d,a) << endl;
		answer+=ascending(d,a);
	}
	delete[]cc;
	return answer/2;
}

int main(){
	ifstream myfile;
	ofstream out;
	//myfile.open("input.txt");
	myfile.open("C-small-attempt1.in");
	out.open("output.txt");
	//while(1){int asdf;cin>>asdf;int dd=log10f(asdf)+1;mm = new int[dd];for(int z=0;z<dd;z++)mm[z]=3;cc = new int[dd];cout<<" "<<ascending(log10f(asdf)+1,asdf)<<endl;delete[]mm;}
	int T;
	myfile >> T;
	//cout << T << endl;
	for(int i=0; i<T; i++){
		int n, m;
		myfile >> n >> m;
		out << "Case #" << i+1 << ": " << zzz(n,m) << endl;
		//system("PAUSE");
	}
	//system("PAUSE");
	return 0;
}