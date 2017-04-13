
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

int main(){
	int t,u;
	cin >> t;
	for(u=0;u<t;u++){
		int n,m;
		cin >> n;
		vector<int>rorder[2];
		vector<pair<int,int> > order;
		rorder[0].clear();
		rorder[1].clear();
		for(m=0;m<n;m++){
			int r,p;
			string str;
			cin >> str >> p;
			if(str[0]=='O'){
				r=0;
			}else if(str[0]=='B'){
				r=1;
			}else{
				assert(false);
			}
			rorder[r].push_back(p);
			order.push_back(make_pair(r,p));
		}

		unsigned int order_c=0;
		unsigned int rorder_c[2]={0,0};
		int pos[2]={1,1};
		int time=0;
		for(;order_c<order.size();){
			int cur_robot=order[order_c].first;
			int cur_pos=pos[cur_robot];
			int dest_pos=order[order_c].second;

			int must_move = abs(cur_pos-dest_pos);
			int dtime=must_move+1;

			pos[cur_robot]=dest_pos;
			rorder_c[cur_robot]++;
			order_c++;
//			printf("robot %d move from %d to %d with %d time\n",cur_robot,cur_pos,dest_pos,dtime);

			int sub_robot=cur_robot==0?1:0;
			if(rorder_c[sub_robot]<rorder[sub_robot].size()){
				int sub_pos=pos[sub_robot];
				int sub_dest_pos=rorder[sub_robot][rorder_c[sub_robot]];
				int sub_must_move = abs(sub_dest_pos-sub_pos);
				if(dtime>=sub_must_move){
					pos[sub_robot]=sub_dest_pos;
				}else{
					if(sub_dest_pos>sub_pos){
						pos[sub_robot]+=dtime;
					}else{
						pos[sub_robot]-=dtime;
					}
				}
//				printf("robot %d move from %d to %d\n",sub_robot,sub_pos,pos[sub_robot]);
			}

			time+=dtime;
		}

		cout << "Case #" << u+1 << ": " << time << endl;
	}
	return 0;
}