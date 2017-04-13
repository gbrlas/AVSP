#include<vector>
#include<string>
#include<iostream>
#include<cstdio>
#include<conio.h>

using namespace std;


int main(){
	int t,u;
	__int64 r,k,n,m;
	__int64 res;
	__int64 deuro,dd,repeu,rep,fst;

	vector <__int64> queue;
	vector <__int64> euro;
	vector <__int64> order;
	__int64 temp,cur;

	cin >> t;
	for(u=1;u<=t;u++){
		res=0;
		scanf("%I64d %I64d%I64d",&r,&k,&n);
		queue.clear();
		euro.clear();
		order.clear();
		for(m=0;m<n;m++){
			scanf("%I64d",&temp);
			queue.push_back(temp);
			euro.push_back(0);
			order.push_back(-1);
		}
		
		__int64 sum,turn,oe,oc;
		cur=0;
		oe=0;
		sum=0;
		turn=0;
		for(;;){
			oc=cur;
			order[cur]=turn;
			euro[cur]=oe+sum;
			oe=euro[cur];
			sum=0;

			while(1){
				if(sum+queue[cur]<=k){
					sum+=queue[cur];
					cur++;
					if(cur==queue.size())cur=0;
					if(cur==oc)break;

				}else break;
			}
			turn++;

			if(order[cur]!=-1){
				fst=order[cur];
				rep=turn-order[cur];
				repeu=oe+sum-euro[cur];
				dd=(r-fst)%rep+fst;
				for(int tt=0;tt<order.size();tt++){
					if(order[tt]==dd){
						deuro=euro[tt];
						break;
					}
				}
				break;
			}
		}

		res = repeu*((r-fst)/rep) + deuro;
		cout << "Case #" << u << ": ";
		printf("%I64d\n",res);
	}
	return 0;
}