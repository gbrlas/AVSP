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

void getNum2(FILE *fp,long *R,long *k){
	int ptr = 0;
	int num = 0;
	int a;
	long zest[] = {0,0};
	char input[51200];
	
	fgets(input,51100,fp);
	
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
}

void solve(int pref,long N,long K){
	static char ans[][] = {"OFF","ON"};
	long a = (1<<N)-1; 
	printf("Case #%d: ",pref+1 );
	puts(ans[a==(K & a)]);
}


int main(int argc , const char **argv){
	FILE *fp;
	long T;
	long N;
	long K;
	int i,j,k;
	
	fp = fopen(argv[1],"r");
	
//	printf("deb argc: %d\n",argc);
	
	T =  getNum(fp);
	
//	printf("deb T: %ld\n",T);
	
	for(i=0;i<T;i++){
		getNum2(fp,&N,&K);
//printf("deb R,k,N: %ld %ld %ld\n",R,k,N);
		solve(i,N,K);
	}
	
	fclose(fp);
//	getch();
	return 0;
}