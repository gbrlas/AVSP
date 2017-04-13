#include<stdio.h>
#include<algorithm>

using namespace std;

struct dt{
	double begin,end,length,speed;	
};

struct dt data[1010];

bool comp(const struct dt &a, const struct dt &b){
	return a.speed < b.speed;	
}

int main(){
	int nt,n;
	double x,s,r,t;
	
	scanf("%d",&nt);
	for(int z=0;z<nt;z++){
		scanf("%lf %lf %lf %lf %d",&x,&s,&r,&t,&n);
		double total = 0;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf",&data[i].begin,&data[i].end,&data[i].speed);	
			data[i].length = data[i].end-data[i].begin;
			total+=data[i].length;
		}		
		data[n].speed = 0;
		data[n].length = x-total;
		n++;
		
		sort(data,data+n,comp);
		
		double time = (double) t;
		double result = 0;
		for(int i=0;i<n;i++){
			double v = data[i].speed+r;
			double w = data[i].speed+s;
			double l = (double)data[i].length;
			
			if(l/v > t){
				double sp = v*t;
				double sisa = l-sp;
				//printf("%lf %lf %lf %lf\n",sp,sisa,v,w);
				result+=sp/v;
				result+=sisa/w;
				t=0;
			}
			else{
				t-=l/v;
				result+=l/v;
			}
		}
		
		printf("Case #%d: %.10lf\n",z+1,result);
	}
	return 0;	
}