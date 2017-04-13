#include<stdio.h>
#include<algorithm>

using namespace std;

struct dic{
	long long dist;
	long long cnt;	
};

struct dic dc[1010];

bool cmp(const struct dic &a, const struct dic &b){
	return a.dist > b.dist;	
}

int main(){
	int nt;
	long long nBooster,nStar,cDistance,tBooster;
	long long tb;
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%lld %lld %lld %lld",&nBooster,&tb,&nStar,&cDistance);
		tBooster = tb;
		//if(tb>2000000000L) tBooster = 2000000001;
		//else tBooster = (int)tb;
		long long sum = 0;
		for(int i=0;i<cDistance;i++){
			scanf("%lld",&dc[i].dist);
			dc[i].dist*=2;
			sum+=dc[i].dist;
		}
		
		long long sisa = nStar%cDistance;
		long long bagi = nStar/cDistance;
		for(int i=0;i<cDistance;i++){
			if(i<sisa){
				dc[i].cnt=bagi+1;
			}
			else{
				dc[i].cnt=bagi;	
			}
		}
		
		long long total=0;
		for(int i=0;i<cDistance;i++){
			total+=dc[i].dist*dc[i].cnt;
		}
		
		//printf("%d %d\n",tBooster,total);
		printf("Case #%d: ",t+1);

		if(total<=tBooster){
			printf("%lld\n",total);
		}
		else{
			long long hasil = total;
			
			long long p = tBooster%sum;
			long long x = tBooster/sum;
			long long posisi;
			long long cummulation = 0;
			long long kurang = 0;
			for(int i=0;i<cDistance;i++){
				dc[i].cnt-=x;
			}
			for(int i=0;i<cDistance;i++){
				cummulation+=dc[i].dist;
				if(cummulation>p) { posisi = i; kurang = (cummulation-p)/2; dc[i].cnt--; break; }
				else if(cummulation==p) { break; }
				dc[i].cnt--;
			}
			
			
			sort(dc,dc+cDistance,cmp);
			
			long long minus = 0;
			for(int i=0;i<cDistance;i++){
				if(nBooster==0) break;
				if(nBooster>dc[i].cnt){
					minus+=(dc[i].dist/2)*dc[i].cnt;
					nBooster-=dc[i].cnt;
				}	
				else{
					minus+=nBooster*(dc[i].dist/2);
					if(nBooster==0){
						if(dc[i-1].dist/2 < kurang){
							minus=minus-(dc[i-1].dist/2)+kurang;
						}
					}
					else{
						if(dc[i].dist/2 < kurang){
							minus=minus-(dc[i].dist/2)+kurang;	
						}	
					}
					nBooster=0;
				}
			}
			
			printf("%lld\n",hasil-minus);
		}
		
		
	}
	return 0;	
}