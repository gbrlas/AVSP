#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 200

char mat[MAXN][MAXN];
int win[MAXN], qtde[MAXN];
double wp[MAXN], owp[MAXN], oowp[MAXN];

int main() {
	int nt,n,cont,d,nteste=1;
	double aux;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++) scanf(" %s",mat[i]);

		for (int i=0;	i<n;	i++) {
			win[i]=qtde[i]=0;
			for (int j=0;	j<n;	j++) {
				if (mat[i][j] != '.') qtde[i]++;
				if (mat[i][j] == '1') win[i]++;
			}
		}

		for (int i=0;	i<n;	i++) {
			wp[i] = double(win[i])/double(qtde[i]);
			
			aux = 0.0;	d=0;
			for (int j=0;	j<n;	j++) {
				if (mat[i][j] == '.')	continue;
				if (mat[i][j] == '1')	aux += double(win[j])/double(qtde[j]-1);
				else aux += double(win[j]-1)/double(qtde[j]-1);
				d++;
			}

			owp[i] = aux/double(d);

		}

		for (int i=0;	i<n;	i++) {
			aux = 0.0;	d=0;

			for (int j=0;	j<n;	j++) {
				if (mat[i][j] == '.') continue;
				aux += owp[j];
				d++;
			}			

			oowp[i]	=	aux/double(d);

		}

		printf("Case #%d:\n",nteste++);
		for (int i=0;	i<n;	i++) {
			aux = 0.25*wp[i] + 0.50*owp[i] + 0.25*oowp[i];
			printf("%.12f\n",aux);
		}

	}

	return 0;
}
