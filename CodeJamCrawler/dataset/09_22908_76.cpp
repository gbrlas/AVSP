#include <cstdio>
#include <cstdlib>
#include <cstring>

char code[]="welcome to code jam";
const int MAXL=1000;
const int COD=19;

int main() {
	int n;
	scanf("%d",&n); getchar();
	for(int ii=0;ii<n;++ii) {
		char s[MAXL];
		int tab[COD][MAXL];
		for(int j=0;j<COD;++j) for(int i=0;i<MAXL;++i) tab[j][i]=0;
		gets(s);
		int len=strlen(s);
		if(s[0]==code[0]) tab[0][0]=1;
		for(int i=1;i<len;++i) {
			tab[0][i]=tab[0][i-1];
			if(s[i]==code[0]) ++tab[0][i];
		}
		for(int j=1;j<COD;++j) {
			for(int i=1;i<len;++i) {
				tab[j][i]=tab[j][i-1];
				if(s[i]==code[j]) tab[j][i]+=tab[j-1][i-1];
			}
		}
		int res=tab[COD-1][len-1]%1000;
		printf("Case #%d: %04d\n",1+ii,res);
	}
	return 0;
}

