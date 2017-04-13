#include<fstream>
#include<cstring>
using namespace std;

const int MAXN=5;
ifstream fin("magic.in");
ofstream fout("magic.out");
int t,a[2][MAXN][MAXN];
int num[MAXN*MAXN];
int n[2];

int main(){
	fin>>t;
	for(int k=1;k<=t;k++){
		memset(num,0,sizeof(num));
		for(int i=0;i<2;i++){
			fin>>n[i];
			for(int r=1;r<=4;r++)for(int c=1;c<=4;c++)
				fin>>a[i][r][c];
			for(int c=1;c<=4;c++)
				num[ a[i] [n[i]] [c] ]++;
		}
		int cnt=0,last;
		for(int j=1;j<=16;j++)if(num[j]>1){
			cnt++;
			last=j;
		}
		fout<<"Case #"<<k<<": ";
		if(!cnt) fout<<"Volunteer cheated!\n";
		else if(cnt==1) fout<<last<<'\n';
		else fout<<"Bad magician!\n";
	}
}

