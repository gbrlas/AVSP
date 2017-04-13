#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define eps 0.000001
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		cnt++;
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		double now=0;
		double rate=0;
		double time=0;
		rate=2.0;
		while(1){
			if(fabs(now-x)<eps)
			   	break;
			double need_time0=0,need_time1=0,tt=0;
			need_time0 = (x-now)/rate;
			if(now>c){
				now -= c;
				rate += f;
				need_time1 = (x-now)/rate;
			}else{
				need_time1 += (c-now)/rate;
				tt = (c-now)/rate;
				now = 0;
				rate += f;
				need_time1 += (x-now)/rate;
			}
	//		cout<<"time0="<<need_time0<<"  time1="<<need_time1<<endl;
			if(need_time0<=need_time1){
				time += need_time0;
				now = x;
			}else{
				time += tt;
			}
		}
		printf("Case #%d: %.7lf\n",cnt,time);
	}
	return 0;
}
