#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
	int T, N, S, p, score[100],c = 0, i, count, mod, qu;
	
	freopen("B-big-output.txt","w",stdout);
	scanf("%d", &T);
	while(c < T){
		scanf("%d %d %d",&N ,&S, &p);
		count = 0; 

		for(i = 0; i < N; i++){
			scanf("%d", &score[i]);
		}

		for(i = 0; i < N; i++){
			mod = score[i]%3;
			qu = score[i]/3;
			if(score[i] == 0 && p == 0) {count++;continue;}
			else if(score[i] == 1 && p <= 1) {count++;continue;}
			else if(score[i] == 2){
				if(p <= 1){ count++;}
				else if(p == 2 && S > 0){ count++; S--;}
				continue;
			}else if(p - qu == 1){
				if(mod == 0 && score[i]>= 2 && score[i] <=28 && S > 0) { qu++; S--;}
				else if(mod == 1 || mod == 2) qu++;
				else { }
			}else if(p - qu == 2){
				if(mod == 0 || mod == 1) { }
				else if(mod == 2 && score[i]>= 2 && score[i] <=28 && S > 0) {qu = qu + 2; S--;}
				else{ }
			}
			if(qu >= p) count++;
		}
		printf("Case #%d: %d\n",c+1, count);
		c++;
	}
	return 0;
}