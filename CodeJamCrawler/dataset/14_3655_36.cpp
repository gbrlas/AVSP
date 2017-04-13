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

int t;
double c,f,x;

int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		scanf("%lf%lf%lf",&c,&f,&x);
		printf("Case #%d: ",test);
		double res=1145141919;
		double nk=2.0,time=0.0;
		for(int i=0;i<=1000000;i++){
			res=min(res,time+x/nk);
			time+=c/nk;
			nk+=f;
		}
		printf("%0.9f\n",res);
	}
	return 0;
}