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
int main(){
	freopen ("D-largo.in","r",stdin);
	freopen ("Dlargo1.out","w",stdout);
	int casos;
	scanf("%d",&casos);
	int val;
	for(int t=1;t<=casos;t++)
	{
		scanf("%d",&n);

		double res=0.0;
		for(int i=1;i<=n;i++){
			cin>>val;
			if(i!=val)
				res+=1.0;
		}
		printf("Case #%d: %.8lf\n",t,res);
	}
	return 0;
}