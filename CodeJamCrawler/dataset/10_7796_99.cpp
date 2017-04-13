#include<vector>
#include<string>
#include<iostream>
#include<cstdio>
#include<conio.h>

using namespace std;

int main(){
	int t,u;
	long r,k,n,m;
	long res;
	long deuro,dd,repeu,rep,fst;

	vector <long> queue;
	vector <long> euro;
	vector <long> order;
	long temp,cur;

	cin >> t;
	for(u=1;u<=t;u++){
		res=0;
		cin >> r >> k >> n;
		queue.clear();
		euro.clear();
		order.clear();
		for(m=0;m<n;m++){
			cin >> temp;
			queue.push_back(temp);
			euro.push_back(0);
			order.push_back(-1);
		}
		
		long sum,turn,oe,oc;
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
		cout << "Case #" << u << ": " << res <<endl;
	}
	return 0;
}