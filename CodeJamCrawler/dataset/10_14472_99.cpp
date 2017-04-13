#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, k;

bool read(){
	scanf("%d%d", &n, &k);
}

int caso = 1;
void process(){
	printf("Case #%d:", caso++);
	if(k%(1 << n) == ( (1 << n)-1)){
		printf(" ON\n");
	}else
		printf(" OFF\n");
}

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		read();
		process();
	}
	
	return 0;
}
