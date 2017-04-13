#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int base_(char* buf){
	char buf2[100];
	strcpy(buf2, buf);
	int d=strlen(buf2);
	sort(buf2, buf2+d);
	int res=unique(buf2, buf2+d)-buf2;
}

main(){
	char buf[71];
	int t; scanf("%d",&t);
	map<char, int>M;
	int Case=0;
	while(t--){
		++Case;
		M.clear();
		scanf("%s",buf);
		unsigned long long res=1;
		int akt=0;
		M[ buf[0] ]=1;
		int d=strlen(buf);

		unsigned long long base=base_(buf);
		if(base==1) base=2;

		for(int i=1; i<d; i++){
			res*=base;
			if(M.count( buf[i] )==0){
				M[buf[i]]=akt;

				res+=akt;

				if(akt==0) akt=2;
				else ++akt;
			} else {
				res+=M[buf[i]];
			}
		}
		printf("Case #%d: %llu\n", Case, res);
	}
}
