#include<cstdio>
#include<algorithm>

#define MAX 32

using namespace std;
int casos, v[MAX];

int main(){
	int x, y;
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		for(int i=1;i<=16;i++) v[i] = 0;
		for(int a=0;a<2;a++){
			scanf(" %d", &x);
			for(int i=0;i<16;i++){
				scanf(" %d", &y);
				if(i/4 == x-1) v[y]++;
			}
		}
		x = 0;
		for(int i=1;i<=16;i++){
			if(v[i] == 2){
				x++;
				y = i;
			}
		}
		
		printf("Case #%d: ", inst);
		if(x == 0) printf("Volunteer cheated!\n");
		else if(x == 1) printf("%d\n", y);
		else printf("Bad magician!\n");
	}
	return 0;
}