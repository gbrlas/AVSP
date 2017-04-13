#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>
using namespace std;

typedef __int64 ll;
typedef pair<int,int> P;

int a[4][4];
int b[4][4];
int t,l,r;
int main(void){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&l);
		for(int j=0;j<4;j++)for(int k=0;k<4;k++)scanf("%d",&a[k][j]);
		scanf("%d",&r);
		for(int j=0;j<4;j++)for(int k=0;k<4;k++)scanf("%d",&b[k][j]);
		l--,r--;
		int cnt=0,res;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(a[k][l]==b[j][r])cnt++,res=b[j][r];
			}
		}
		printf("Case #%d: ",i);
		if(cnt==1)printf("%d\n",res);
		if(cnt>=2)printf("Bad magician!\n");
		if(cnt==0)printf("Volunteer cheated!\n");
	}
	return 0;
}