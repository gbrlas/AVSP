#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <list> 
#include <map> 
#include <utility> 
#include <sstream> 
#include <string> 
#include <cstring> 
#include <cctype> 
#include <cmath> 
#include <queue> 
#include <stack> 
#include <set> 
 
using namespace std;
int n;
int val[1003];
int main(){
	freopen ("A-large.in","r",stdin);
	freopen ("Ares2.out","w",stdout);
	int casos;
	scanf("%d",&casos);
	//int val;
	for(int t=1;t<=casos;t++)
	{
		cin>>n;
		string cad="";
		int num;
		char c;
		for(int i=0;i<n;i++){
			cin>>c;
			cin>>val[i];
			cad+=c;
		}
		
		char ant='Y';
		int T=0;
		int rec=0;
		int res=0;
		int curO=1,curB=1;
		for(int i=0;i<cad.size();i++){
			if(cad[i]=='O'){
				if(cad[i]==ant){
					res+=abs(val[i]-curO)+1;
					T+=abs(val[i]-curO)+1;
					curO=val[i];
					continue;
				}
				rec=abs(val[i]-curO);
				rec=max(0,rec-T);
				res+=(rec+1);
				T=rec+1;
				curO=val[i];
				ant=cad[i];
			}
			else{
				if(cad[i]==ant){
					res+=abs(val[i]-curB)+1;
					T+=abs(val[i]-curB)+1;
					curB=val[i];
					continue;
				}
				rec=abs(val[i]-curB);
				rec=max(0,rec-T);
				res+=(rec+1);
				T=rec+1;
				curB=val[i];
				ant=cad[i];
			}
		}
		printf("Case #%d: %d\n",t,res);
	}
	return 0;
}