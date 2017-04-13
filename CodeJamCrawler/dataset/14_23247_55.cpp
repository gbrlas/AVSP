#include <cstdio>
#include <cstring>

using namespace std;

int count[20];

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		memset(count,0,sizeof(count));
		int row;
		scanf("%d", &row);
		--row;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j){
				int t;
				scanf("%d", &t);
				if (i==row) ++count[t];
			}
		scanf("%d", &row);
		--row;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j){
				int t;
				scanf("%d", &t);
				if (i==row) ++count[t];
			}
		int ans=-1;
		for (int i=1; i<17; ++i)
			if (count[i]==2)
				if (ans==-1)
					ans=i; 
				else{
					ans=-2;
					break;
				}
		printf("Case #%d: ", T);
		if (ans==-2) printf("Bad magician!\n");
		if (ans==-1) printf("Volunteer cheated!\n");
		if (ans>0) printf("%d\n", ans);
	}
}
