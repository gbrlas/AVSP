// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d ",&T);

	 for (int t=0;t<T;t++)
	 {
		 int N,K;
		 scanf("%d %d ",&N,&K);
		 const int chkbits = (1<<N)-1;
		 if((chkbits&K)==chkbits)
		 {
			 printf("Case #%d: ON\n",t+1);
		 }
		 else
		 {
			 printf("Case #%d: OFF\n",t+1);
		 }
	 }

	return 0;
}
