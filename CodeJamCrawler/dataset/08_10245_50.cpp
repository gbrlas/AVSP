#include<stdio.h>
#include<string.h>

int numn,i,j,n,s,q,countswitch=0;
char engine[100][100],query[100];
int countengine[100]={0};

void reallycleararray() {
	int index;
	for(index=0; index<s; index++)
		countengine[index] = 0;
}

void cleararray() {
	int index;
	for(index=0; index<s; index++)
		countengine[index] = 0;
	countengine[j]++;		
}

void checkarray() {
	int index,zerocount=0;
	for(index=0; index<s; index++)
		if(!countengine[index]) zerocount++;
	if(zerocount == 0) { 
		countswitch++;
		cleararray();
	}
}

int main() {
	scanf("%d",&n);
	for(numn=0; numn<n; numn++) {
		scanf("%d",&s);
		getchar();
		for(i=0; i<s; i++) {
			gets(engine[i]);
		}
		scanf("%d",&q);
		getchar();
		for(i=0; i<q; i++) {
			gets(query);
			for(j=0; j<s; j++) {
				if(!strcmp(query,engine[j])) {
					countengine[j] += !strcmp(query,engine[j]);
					break;
				}	
			}
			checkarray();
		}	
		reallycleararray();
		printf("Case #%d: %d\n",numn+1,countswitch);
		countswitch = 0;
	}
	return 0;
}
