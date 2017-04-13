#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

int PO,PB,RO,RB,tempo;

int main(){
	int n,t;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("saida.txt","w",stdout);
	scanf(" %d ",&t);
	int caso = 1;
	while(t--){
		scanf("%d",&n);
		char c[2];
		int d;
		PO = PB = 1;
		RO = RB = 0;
		tempo = 0;
		
		for(int i = 0; i < n; i++){
			scanf("%s %d",c,&d);
			//cout << c << endl;
			if(c[0] == 'O'){
				tempo += (max( abs(PO - d)- RO, 0 ) + 1);
				RB += (max( abs(PO - d) - RO, 0 ) + 1);
				RO = 0;
				PO = d;	
			}
			else if(c[0] == 'B'){
				tempo += ( max( abs(PB - d) - RB, 0 ) + 1);
				RO += (max( abs(PB - d) - RB, 0 ) + 1);
				RB = 0;
				PB = d;
			}
			//cout << tempo << " " << RO << " " << PO <<   endl;
		}
		
		printf("Case #%d: %d\n",caso++,tempo);
	}
	return 0;
}

