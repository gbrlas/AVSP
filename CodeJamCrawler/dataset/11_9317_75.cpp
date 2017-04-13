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
long long A[1003];
int main(){
	freopen ("Cchico.in","r",stdin);
	freopen ("Cchico1.out","w",stdout);
	int casos;
	scanf("%d",&casos);
	int val;
	for(int t=1;t<=casos;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>A[i];
			
		long long valid=0;
		long long todo=0;
		for(int i=0;i<n;i++){
			valid^=A[i];
			todo+=A[i];
		}
		long long res=0;
		for(int i=0;i<n;i++){
			long long ans=0;
			for(int j=0;j<n;j++){
				if(i==j)
					continue;
				ans^=A[j];
			}
			res=max(res,max(ans,todo-A[i]));
		}
		if(valid)
		printf("Case #%d: NO\n",t);
		else
		printf("Case #%d: %lld\n",t,res);
	}
	return 0;
}