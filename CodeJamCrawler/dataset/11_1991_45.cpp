#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
#define mp make_pair

int main(){
  int caseNum;
	cin>>caseNum;
	for(int ca = 0;ca < caseNum;ca++){
		int n;
		cin>>n;
		char col;
		int pos;
		vector<PII> blue,orange;
		for(int i=0;i<n;i++){
			cin>>col>>pos;
			if(col == 'B')
				blue.push_back(mp(i,pos));
			else
				orange.push_back(mp(i,pos));
		}
		blue.push_back(mp(101,1));
		orange.push_back(mp(101,1));
		int bi = 0,oi = 0,count = 0,bpos = 1,opos = 1,i = 0;
		while(i<n){
			bool sw = false;
			if(blue[bi].first == i && bpos == blue[bi].second){
				bi++;
				sw = true;
			}
			else{
				if(bpos < blue[bi].second){
					bpos++;
				}
				else if(bpos > blue[bi].second){
					bpos--;
				}
			}
			if(orange[oi].first == i && opos == orange[oi].second){
					oi++;
					sw = true;
			}
			else{
				if(opos < orange[oi].second){
					opos++;
				}
				else if(opos > orange[oi].second){
					opos--;
				}
			}
			/*
			cout<<"or: "<<orange[oi].first<<","<<orange[oi].second<<endl;
			cout<<"bl: "<<blue[bi].first<<","<<blue[bi].second<<endl;
			cout<<opos<<","<<bpos<<endl;
			*/
			if(sw){
				i++;
			}
			count++;
		}
		cout<<"Case #"<<ca+1<<": "<<count<<endl;
	}
	
  return 0;
}
