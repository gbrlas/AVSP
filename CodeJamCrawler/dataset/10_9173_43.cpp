#include <stdio.h>

long getNum(FILE *fp){
	char input[100];
	char buf[101];
	int a=0,b=0;
	long ret = 0;
	
	memset(input, 0, sizeof(input));
	fgets(input,90,fp);
	memset(buf, 0, sizeof(buf));
	strncpy(buf, input, sizeof(input));
//printf("deb buf: %s\n",buf);
	while(b = buf[a++]){
		if(b == '\n'||b == '\r') break;
		ret = 10*ret;
		ret += b-'0';
//printf("deb a,b: %d %d\n",a,b);
	};
//printf("deb ret: %ld\n",ret);
	return ret;
}

void getNum2(FILE *fp,long *R,long *k,long *N){
	int ptr = 0;
	int num = 0;
	int a;
	long zest[] = {0,0,0};
	char input[512];
	
	fgets(input,511,fp);
	
	while(a = input[ptr]){
		if(a == '\n'||a == '\r') break;
		ptr++;
		if(a == ' '){
			num++;
		}else{
			zest[num] = 10 * zest[num];
			zest[num] += a - '0';
		}
	}
	*R = zest[0];
	*k = zest[1];
	*N = zest[2];
}

void getNum3(FILE *fp,long g[],long N){
	int ptr = 0;
	int num = 0;
	int a;
	char input[512];
	
	fgets(input,511,fp);
	
	for(ptr=0;ptr<N;ptr++){
		g[ptr]=0;
	}
	ptr=0;
	while(a = input[ptr]){
		if(a == '\n'||a == '\r') break;
		ptr++;
		if(a == ' '){
			num++;
		}else{
			g[num] = 10 * g[num];
			g[num] += a - '0';
		}
	}
//	for(ptr=0;ptr<N;ptr++) printf("deb g[%d]: %ld \n",ptr,g[ptr]);
}

typedef struct {
	long long num;
	int next;
} _map;


void solve(int pref,long R,long max, long N, long g[]){
	_map map[1002];
	long long sum;
	long a;
	int i,j,k;
	for(i = 0; i<N;i++){
		map[i].num = 0LL;
		sum = 0LL;
		for(j=i;sum<=max && j<=i+N;j++){
			k=j;
			if((long)k >= N) k -= N; 
			map[i].num = sum;
			map[i].next = k;
			sum += g[k];
		}
//printf("deb g[%d]=%ld sum=%lld map[%d].num next: %lld  %d\n",k,g[k],sum,i,map[i].num,map[i].next);
	}
	
	sum=0;
	for(a=0,i=0;a<R;a++,i=map[i].next){
		sum += map[i].num;
	}
	
	printf("Case #%d: %lld\n",pref+1,sum);
}



int main(int argc , const char **argv){
	FILE *fp;
	long T;
	long R;
	long k;
	long N;
	long g[1005];
	int i,j,k;
	
	fp = fopen(argv[argc-1],"r");
	
//	printf("deb argc: %d\n",argc);
	for(i=0;i<argc;i++){
//		printf("deb argv: %s\n",argv[i]);
	}
	
	T =  getNum(fp);
	
//	printf("deb T: %ld\n",T);
	
	for(i=0;i<T;i++){
		getNum2(fp,&R,&k,&N);
//printf("deb R,k,N: %ld %ld %ld\n",R,k,N);
		getNum3(fp,g,N);
		solve(i,R,k,N,g);
	}
	
	fclose(fp);
	getch();
	return 0;
}