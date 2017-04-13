#include<stdio.h>
#define N 10
#define T 100

int m[N+1],t,n,s,p,chk[N+1];

void main(){
	int i,j,cnt[N+1]={0,},ccnt=0;
	//int tp;
	FILE *in = fopen("B-small-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d",&t);

	while(1){
		ccnt++;
		if(ccnt == t+1)
			break;
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
		fscanf(in,"%d%d%d",&n,&s,&p);
		//printf("\n\n%d\n\n",n);
		for(i=0;i<n;i++){
			fscanf(in,"%d",&m[i]);
			if(m[i] >= (p*3)-1){
				cnt[0]++;
				chk[i] = 1;
			}else if(m[i] >= (p*3)-2){
				cnt[1]++;
				chk[i] = 2;
			}else if(m[i] <= (p*3)+4 && m[i] >= (p*3)-4 && (p*3)-4 >= 0){
				cnt[2]++;
				chk[i] = 3;
			}else{
				cnt[3]++;
				chk[i] = 4;
			}
			//printf("%d %d\n",m[i],cnt[i]);
		}

		if(s == 0){
			fprintf(out,"Case #%d: %d\n",ccnt,cnt[0]+cnt[1]);
		}else if(s == cnt[2]){
			fprintf(out,"Case #%d: %d\n",ccnt,cnt[0]+cnt[1]+cnt[2]);
		}else if(s < cnt[2]){
			fprintf(out,"Case #%d: %d\n",ccnt,cnt[0]+cnt[1]+s);
		}else
			fprintf(out,"Case #%d: %d\n",ccnt,cnt[0]+cnt[1]+cnt[2]);
	}

	fclose(in);
	fclose(out);
}