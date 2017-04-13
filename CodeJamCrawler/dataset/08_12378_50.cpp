#include<iostream>
#include<algorithm>
using namespace std;

int as[510];
int ae[510];
int bs[510];
int be[510];


int main()
{
	int N,na,nb,i,m,t,h,j;
	int mm = 1;

	scanf("%d",&N);
	while(N--){
		scanf("%d",&t);
		scanf("%d%d",&na,&nb);

		for(i =0; i < na; i ++){
			scanf("%d:%d",&h,&m);
			as[i] = h*60+m;

			scanf("%d:%d",&h,&m);
			ae[i] = h*60+m + t;
		}

		for(i =0; i < nb; i ++){
			scanf("%d:%d",&h,&m);
			bs[i] = h*60+m;

			scanf("%d:%d",&h,&m);
			be[i] = h*60+m + t;
		}

		sort(as,as+na);	
		sort(ae,ae+na);

		sort(bs,bs+nb);
		sort(be,be+nb);
		
		int ca = 0,cb =0;

		j = 0;
		for(i =0; i < na; i ++){
			if(j >= nb || be[j] > as[i])	ca ++;
			else j ++;
		}

		j = 0;
		for(i =0; i < nb; i ++){
			if(j >= na || ae[j] > bs[i])	cb ++;
			else j ++;
		}

		printf("Case #%d: %d %d\n",mm++,ca,cb);
	}
	return 0;
}
