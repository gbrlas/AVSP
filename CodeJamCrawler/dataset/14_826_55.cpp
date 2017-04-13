#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=1005;

ifstream fin("war.in");
ofstream fout("war.out");
int t,n;
double naomi[MAXN],ken[MAXN];

int main(){
	fin>>t;
	for(int k=1;k<=t;k++){
		fin>>n;
		for(int i=0;i<n;i++) fin>>naomi[i];
		for(int i=0;i<n;i++) fin>>ken[i];
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		int best_n=0,best_k=0;
		for(int i=0;i<n;i++)if(naomi[i]>ken[best_n]) best_n++;
		for(int i=0;i<n;i++)if(ken[i]>naomi[best_k]) best_k++;
		fout<<"Case #"<<k<<": "<<best_n<<' '<<n-best_k<<'\n';
	}
}

