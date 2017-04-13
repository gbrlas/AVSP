#include<fstream>
using namespace std;

ifstream fin("cookie.in");
ofstream fout("cookie.out");
int t;
double c,f,x;

int main(){
	fin>>t;
	for(int k=1;k<=t;k++){
		fin>>c>>f>>x;
		double p=2;
		double best=1<<30;
		double time=0;
		while(time+x/p<best){
			best=time+x/p;
			time+=c/p;
			p+=f;
		}
		fout.precision(7);
		fout<<fixed;
		fout<<"Case #"<<k<<": "<<best<<'\n';
	}
}

