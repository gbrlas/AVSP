#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 110

char mapa[] = "yhesocvxduiglbkrztnwjpfmaq";
char line[MAXN];

int main() {
	int nt,nteste=1,n;
	gets(line);
	sscanf(line,"%d",&nt);
	
	while (nt--) {
		gets(line);
		n = strlen(line);
		
		for (int i=0; i<n; i++) {
			//printf("line eh %c com mapa %c\n",line[i],mapa[line[i]-'a']);
			if (line[i] == ' ') continue;
			line[i] = mapa[line[i]-'a'];
		}
		printf("Case #%d: %s\n",nteste++,line);
	}
	
	return 0;
}
