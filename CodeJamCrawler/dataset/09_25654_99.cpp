#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits.h>
using namespace std;

typedef pair<int,int> pii;

void find_sinks(vector<vector<int> >& map, vector<vector<int> >& sinks){
	int r=map.size();
	int c=map[0].size();
	int no=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int cnt1=0;
			int cnt2=0;
			if(i-1>=0){
				cnt1++;
				if(map[i-1][j]>=map[i][j]){
					cnt2++;
				}
			}
			if(i+1<r){
				cnt1++;
				if(map[i+1][j]>=map[i][j]){
					cnt2++;
				}
			}
			if(j-1>=0){
				cnt1++;
				if(map[i][j-1]>=map[i][j]){
					cnt2++;
				}
			}
			if(j+1<c){
				cnt1++;
				if(map[i][j+1]>=map[i][j]){
					cnt2++;
				}
			}
			if(cnt1==cnt2){
				sinks[i][j]=no++;
			}
		}	
	}
}

bool in(int r,int c,int rdim,int cdim){
	return r>=0&&r<rdim&&c>=0&&c<cdim;
}

pii flows_to(int r,int c,vector<vector<int> >& map){
	int r_off[]={-1,0,0,1};
	int c_off[]={0,-1,1,0};
		
	int min=INT_MAX;
	pii ret;
	for(int i=0;i<4;i++){
		int rnext=r+r_off[i];
		int cnext=c+c_off[i];
		if(in(rnext,cnext,map.size(),map[0].size())){
			if(map[rnext][cnext]<=map[r][c]&&map[rnext][cnext]<min){
				min=map[rnext][cnext];
				ret=pii(rnext,cnext);
			}
		}
	}
	
	return ret;

}

void flood1(vector<vector<int> >& sinks,int rs,int cs,vector<vector<int> >& map){	
	queue<pii> q;
	q.push(pii(rs,cs));
	
	int r_off[]={-1,0,0,1};
	int c_off[]={0,-1,1,0};

	while(!q.empty()){
		pii curr=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int rnext=curr.first+r_off[i];
			int cnext=curr.second+c_off[i];
			if(in(rnext,cnext,map.size(),map[0].size()) and sinks[rnext][cnext]==-1 and flows_to(rnext,cnext,map)==curr){
				sinks[rnext][cnext]=sinks[rs][cs];
				q.push(pii(rnext,cnext));
			}
		}
		
	}	
}

void flood2(vector<vector<int> >& sinks,vector<vector<char> >& res){
	vector<char> letter(26,'#');
	char next_letter='a';
	for(int i=0;i<sinks.size();i++){
		for(int j=0;j<sinks[0].size();j++){
			if(letter[sinks[i][j]]=='#'){
				letter[sinks[i][j]]=next_letter;
				next_letter++;
			}		
			res[i][j]=letter[sinks[i][j]];
		}	
	}

}


int main(){
	int tcases;
	cin>>tcases;
	for(int tcase=1;tcase<=tcases;tcase++){
		int r,c;
		cin>>r>>c;
		//cout<<r<<" "<<c<<endl;
		vector<vector<int> > map(r,vector<int>(c));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>map[i][j];
			}
		}		
		//cout<<"fd";
		vector<vector<int> > sinks(r,vector<int>(c,-1));
		find_sinks(map,sinks);

	
		int curr=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(sinks[i][j]==curr){
					flood1(sinks,i,j,map);
					curr++;
				}
			}	
		}
		/*
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%3d ",sinks[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		*/
		cout<<"Case #"<<tcase<<":"<<endl;
		vector<vector<char> > res(r,vector<char>(c,'#'));
		flood2(sinks,res);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout<<res[i][j];
//				if(j<c-1){
					cout<<" ";
//				}
			}
			cout<<endl;
		}
		//cout<<endl;
	}
	
	
	return 0;
}