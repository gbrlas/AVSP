#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;

int t,T;
char GN[30] = "yhesocvxduiglbkrztnwjpfmaq";
char c;
void testc() {
	printf("Case #%d: ",t);
	scanf("%c",&c);
	while(c!='\n') {
		if(c==' ') {
			printf(" ");
		} else {
			printf("%c",GN[c-'a']);
		}
		scanf("%c",&c);
	}
	printf("\n");
}

int main() {
	scanf("%d\n",&T);
	for(t=1;t<=T;t++) {
		testc();
	}
	return 0;
}