#include <vector>
#include <list>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;
#define mp make_pair
#define pp push_back
#define Sort(x) sort(x.begin(), x.end())
#define rep(i, x, y) for(int i = x; i < y; i++)
#define Rep(i, x, y) for(int i = x; i <= y; i++)
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long
#define all(v) v.begin(),v.end()
#define ii pair<int, int>
#define mem(x,v) memset(x,v,sizeof(x))

int main()
{
	freopen("out.o","w",stdout);
	freopen("in.i","r",stdin);
	int testC;
	cin>>testC;
	int aNum,bNum, A[4][4],B[4][4];
	rep(t,0,testC)
	{
		int chosen[17]={0};
		cin>>aNum;
		rep(i,0,4)
			rep(j,0,4)
				cin>>A[i][j];
		cin>>bNum;
		rep(i,0,4)
			rep(j,0,4)
				cin>>B[i][j];
		
		rep(i,0,4)
			chosen[A[aNum-1][i]]++,chosen[B[bNum-1][i]]++;
		printf("Case #%d: ",t+1);
		if(count(chosen,chosen+17,1)==8)
			printf("Volunteer cheated!\n");
		else if(count(chosen,chosen+17,1)<6)
			printf("Bad magician!\n");
		else 
			printf("%d\n", find(chosen,chosen+17,2)-chosen);

	}
}