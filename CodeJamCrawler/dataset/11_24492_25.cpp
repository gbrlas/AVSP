#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <ctime>
#include <climits>
using namespace std;

#define maxCandy 20
int ans,num;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C_small.out","w",stdout);
	int i,j;
	int cases,no,tmp,minN,sum = 0;
	scanf("%d",&cases);
	for (no = 1;no<=cases;no++)
	{
		scanf("%d",&num);
		ans = 0;
		minN = 10000000;
		sum = 0;
		for (i=0;i<num;i++)
		{
			scanf("%d",&tmp);
			ans ^= tmp;
			minN = min(minN,tmp);
			sum += tmp;
		}
		if (ans==0)
		{
			printf("Case #%d: %d\n",no,sum-minN);
		} 
		else
		{
			printf("Case #%d: NO\n",no);
		}
	}
}