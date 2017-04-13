#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main (){
	//freopen 
	int Test, n, pd, pg;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++){
		scanf ("%d%d%d", &n, &pd, &pg);
		if (pg == 0 && pd > 0 || pg == 100 && pd < 100){
			printf ("Case #%d: Broken\n", Cas);
			continue;
		}
		bool flag = false;
		for (int i = 1; i <= n; i ++){
			//printf ("%f %d\n", pd*1.0/100*i, (int)(pd*1.0/100*i));
			//printf ("%f %d\n", pg*1.0/100*i, (int)(pg*1.0/100*i));
			if (pd*1.0/100*i == (int)(pd*1.0/100*i)){
				flag = true;
				break;
			}
		}
		if (flag) printf ("Case #%d: Possible\n", Cas);
		else printf ("Case #%d: Broken\n", Cas);
	}
	return 0;
}
