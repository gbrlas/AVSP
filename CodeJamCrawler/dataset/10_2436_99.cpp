//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int i,j,k,l,o,p,n,m;

int main(){
	scanf("%d",&o);
	for (i=0;i<o;i++){
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",i+1);
		j=(1<<n)-1;
		if ((m&j)==j) printf("ON\n");
		else printf("OFF\n");
	}
    return 0;
}
