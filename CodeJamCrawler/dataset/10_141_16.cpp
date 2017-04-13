#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int p;

int tc[1025];
int pr[520][11] = {0};

int main()
{
	//freopen("b.in","r",stdin);
	freopen("b-small-attempt0.in","r",stdin);freopen("b-small-attempt0.out","w",stdout);
//	freopen("b-small-attempt1.in","r",stdin);freopen("b-small-attempt1.out","w",stdout);
//	freopen("b-large.in","r",stdin);freopen("b-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		memset(tc, 0, sizeof(tc));
		memset(pr, 0, sizeof(pr));
		scanf("%d",&p);
		int p2 = (1 << p);
		for(int i = 0; i < p2; ++i)
			scanf("%d", &(tc[i]));
		int pp = p2 >> 1;
		int temp[12] = {0};
		temp[1] = pp;
		for(int i = 2; i < p; ++i){
			pp = pp >> 1;
			temp[i] = temp[i-1] + pp; 
		}
		int noi = 0;
		for(int i = 0; i < p2-1; ++i){
			if (i < temp[noi+1]){
				int noj = i - temp[noi];
			  scanf("%d", &(pr[noi][noj]));
			}else{
				++noi;
				scanf("%d", &(pr[noi][0]));
			}
		}
		for(int i = 0; i < p2; ++i)
			tc[i]  = p - tc[i];
		int ret  = 0;
		for(int i = 0; i < p; ++i){
			int nm = (1 << i);
			int ns = (1 << (p - i));
			for(int j = 0; j < nm; ++j){
				bool need = false;
				for(int k = j * ns; k < (j+1) * ns; ++k){
					if (tc[k] > 0){
						need = true;
						break;
					}
				}
				if (need){
					++ret;
					for(int k = j * ns; k < (j+1) * ns; ++k){
						if (tc[k] > 0)
							--tc[k];
					}
				}
			}
		}

		printf("Case #%d: %d\n",caseId, ret);
	}
}