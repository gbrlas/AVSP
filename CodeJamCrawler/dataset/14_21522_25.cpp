#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define fr(a,b,c) for(int a=b; a<c; a++)
#define sc(a) scanf("%d",&a)
typedef vector<int> vi;



int main()
{
	int t,caso=1;
	scanf("%d",&t);
	while(t--){
		vi v;
		v.assign(17,0);
		int pos;
		fr(i,0,2){
			scanf("%d",&pos);
			pos--;
			for(int i=1; i<=16; i++){
				int aux;
				sc(aux);
				if(i>= pos*4 +1 && i<= pos*4 +4)v[aux]++;
			}
		}
		int achou = 0,ans;
		for(int i=1; i<=16; i++){
			if(v[i]==2){
				achou++;
				ans = i;				
			}
		}
		
		if(achou==1) printf("Case #%d: %d\n",caso++,ans);
		else if(achou>1) printf("Case #%d: Bad magician!\n",caso++);
		else printf("Case #%d: Volunteer cheated!\n",caso++);
		
	}

    return 0;
}
