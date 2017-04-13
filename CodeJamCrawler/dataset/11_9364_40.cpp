#line 3 "main.cpp"
#include  "iostream" 
#include  "vector"
#include  "string"
#include  "string.h"
#include  "algorithm" 
#include  "sstream"
#include  "set"
#include  "map"
#include  "queue"
#include  "deque"
#include  "stack"
#include "list"
#include  "bitset"
#include  "cstdio"
#include  "assert.h"
#include  "cmath"
#include  "cstdlib"
#include  "ctime"
#include  "cfloat"
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define INF 1<<28
string cad[53];
int r,c;
bool dentro(int a,int b){
	if(a <0 || b<0 ||a>=r ||b>=c)
		return false;
	return true;
}
int main(){
	freopen ("C:\\Documents and Settings\\jpenam\\Mis documentos\\Downloads\\AClargo.in","r",stdin);
	freopen ("A1Clargo.out","w",stdout);
	int cases;
	cin>>cases;
	
	for(int t=1;t<=cases;t++){
		cin>>r>>c;
		
		char cc='\\';
		for(int i=0;i<r;i++)
			cin>>cad[i];
		
		bool es=true;
		for(int i=0;i<r && es;i++){
			for(int j=0;j<c&&es;j++){
				if(cad[i][j]!='#')
					continue;
				else{
					if(dentro(i,j+1) &&dentro(i+1,j) &&dentro(i+1,j+1) ){
						if(cad[i][j]=='#'&&cad[i][j+1]=='#'&&cad[i+1][j]=='#'&&cad[i+1][j+1]=='#'){
						cad[i][j]='/';
						cad[i+1][j]='\\';
						cad[i][j+1]='\\';
						cad[i+1][j+1]='/';
						}
						else
							es=false;
					}
					else
						es=false;
				}
			}
		}
		printf("Case #%d:\n",t);
		if(!es)
			printf("Impossible\n");
		else
			for(int i=0;i<r;i++)
				cout<<cad[i]<<endl;;
	}
	return 0;
}
//Case #1:3