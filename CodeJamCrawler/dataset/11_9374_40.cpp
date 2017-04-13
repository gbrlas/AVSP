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
int arr[103];

int N,H,L;
bool es(int num){
	bool res=true;
	for(int i=0;i<N&&res;i++){
		if(num>=arr[i]){
			if(num%arr[i])
				res=false;
		}
		else if(arr[i]%num)
			res=false;
	}
	return res;
}
int main(){
	freopen ("C:\\Documents and Settings\\jpenam\\Mis documentos\\Downloads\\C1.in","r",stdin);
	freopen ("C11.out","w",stdout);
	int cases;
	cin>>cases;
	
	for(int t=1;t<=cases;t++){
		/*cin>>r>>c;
		
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
		}*/
		//cin>>N>>H>>L;
		scanf("%d %d %d",&N,&H,&L);
		for(int i=0;i<N;i++)
			//cin>>arr[i];
			scanf("%d",&arr[i]);

		bool po=false;
		int res=0;
		for(int i=H;i<=L && !po;i++){
			if(es(i)){
				po=true;
				res=i;
			}
		}
		printf("Case #%d: ",t);
		if(!po)
			printf("NO\n");
		else
			printf("%d\n",res);
	}
	return 0;
}
//Case #1:3