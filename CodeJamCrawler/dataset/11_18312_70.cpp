#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 110

int opposite[30][30];
char combine[30][30];
int invoke[MAXN];

int main() {
	int t,n,c,d,a,b,tam,pos,nteste=1;
	char r;
	char line[MAXN];
	scanf("%d",&t);
	while (t--) {
		for (int i=0; i<30; i++)
			for (int j=0; j<30; j++) { opposite[i][j] = 0;	combine[i][j] = '0'; }

		scanf("%d",&c);
		for (int i=0; i<c; i++) {
			scanf(" %s",line);
			a = line[0]-'A';	b = line[1]-'A';	r = line[2];
			combine[a][b] = combine[b][a] = r;
		}

		scanf("%d",&d);
		for (int i=0; i<d; i++) {
			scanf(" %s",line);
			a = line[0]-'A';	b = line[1]-'A';
			opposite[a][b] = opposite[b][a] = 1;
		}

		scanf("%d",&tam);
		scanf(" %s",line);

		pos = 0;
		for (int i=0; i<tam; i++) {
			a = line[i]-'A';
			if (!pos) { invoke[pos++] = a;	continue; }
			b = invoke[pos-1];
			if (combine[a][b] != '0') { invoke[pos-1] = combine[a][b]-'A';	continue; }
			invoke[pos++] = a;
			for (int j=pos-2; j>=0; j--) if (opposite[a][invoke[j]]) pos = 0; 
		}
		
		printf("Case #%d: [",nteste++);
		for (int i=0; i<pos; i++) {
			if (i) printf(" ");
			printf("%c",invoke[i]+'A');
			if (i != pos-1) printf(",");
		}
		printf("]\n");
		
	}

	return 0;
}
