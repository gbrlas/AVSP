#include <cstdio>
#include <cstring>

using namespace std;

int nt,r,cl,b,k;
char mat[100][100];

int f(int i, int j) {
	int k;
	char a,b,c,d;
	if (i>r-1 || j>cl-1) return 1;
	
	if (mat[i][j] != '#') {
		if (j == cl-1) return f(i+1,0);
		return f(i,j+1);
	}

	if (j == cl-1 || i == r-1) return 0;
	
	if (mat[i+1][j] != '#' && mat[i+1][j] != '.') return 0;
	if (mat[i][j+1] != '#' && mat[i][j+1] != '.') return 0;
	if (mat[i+1][j+1] != '#' && mat[i+1][j+1] != '.') return 0;

	a = mat[i][j];	b = mat[i][j+1];	c = mat[i+1][j];	d = mat[i+1][j+1];
	mat[i][j] = '/';	mat[i][j+1] = '\\';	mat[i+1][j] = '\\';	mat[i+1][j+1] = '/';	
	k = f(i,j+1);	if (k) return k;
	k = f(i+1,j);	if (k) return k;
	k = f(i-1,j);	if(k) return k;
	k = f(i-1,j-1);	if (k) return k;

	mat[i][j] = a;	mat[i][j+1] = b;	mat[i+1][j] = c;	mat[i+1][j+1] = d;
	return 0;		

}

int main() {
	int nteste=1;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d %d",&r,&cl);
		for (int i=0; i<r; i++) scanf(" %s",mat[i]);

		b=0;
		for (int i=0; i<r; i++)
			for (int j=0; j<cl; j++)
				if (mat[i][j] == '#') b++;

		if (b%4) k = 0;
		else k = f(0,0);

		printf("Case #%d:\n",nteste++);
		if (k) {
			for (int i=0; i<r; i++) printf("%s\n",mat[i]);
		}
		else printf("Impossible\n");
		
	}

	return 0;
}
