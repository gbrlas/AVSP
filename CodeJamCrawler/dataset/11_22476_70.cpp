#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char com[500][500];
bool del[500][500];
int task, CS=0, t, top;
char opt[1000], stack[1000];

bool check( char o ){
	for (int i=1; i<=top; i++)
	if ( del[stack[i]][o] )
		return true;
	return false;
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		memset( com, 0, sizeof(com) );
		memset( del, 0, sizeof(del) );
		for( scanf("%d", &t);t--; ){
			scanf("%s", opt);
			com[opt[0]][opt[1]] = opt[2];
			com[opt[1]][opt[0]] = opt[2];
		}
		for( scanf("%d", &t);t--; ){
			scanf("%s", opt);
			del[opt[0]][opt[1]] = true;
			del[opt[1]][opt[0]] = true;
		}
		scanf("%d %s", &t, opt);
		top = 0;
		for (int i=0; opt[i]; i++)
		if ( top>=1 && com[stack[top]][opt[i]]!=0 ){
			stack[top] = com[stack[top]][opt[i]];
		}else
		if ( check( opt[i] ) ){
			top = 0;
		}else stack[++top] = opt[i];

		printf("Case #%d: [", ++CS);
		for (int i=1; i<=top; i++){
			if ( i!=1 ) printf(", ");
			printf("%c", stack[i]);
		}
		printf("]\n");
	}
	return 0;
}
