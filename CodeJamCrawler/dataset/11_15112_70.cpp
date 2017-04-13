#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//int a[111], b[111];
//int orda[111], ordb[111];
vector< pair<char, int> > sec;

int getNextDst(int z, char ch){
	for(int i=z+1; i<sec.size(); i++)
		if(sec[i].first==ch) return i;
	return -1;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n, na=0, nb=0;
		cin>>n;
		sec.resize(n);
		for(int i=0; i<n; i++){
			cin>>sec[i].first>>sec[i].second;
		}
		int cura=1, curb=1;
		int rez = 0;
		for(int i=0; i<n; i++){
			if(sec[i].first=='O'){
				int tm = abs(cura-sec[i].second)+1;
				int dstIdx = getNextDst(i,'B');
				if(dstIdx>-1){
					if(curb>sec[dstIdx].second) curb-=min(tm,curb-sec[dstIdx].second);
					else if(curb<sec[dstIdx].second) curb+=min(tm,sec[dstIdx].second-curb);
				}
				cura = sec[i].second;
				rez+=tm;
			}else{
				int tm = abs(curb-sec[i].second)+1;
				int dstIdx = getNextDst(i,'O');
				if(dstIdx>-1){
					if(cura>sec[dstIdx].second) cura-=min(tm,cura-sec[dstIdx].second);
					else if(cura<sec[dstIdx].second) cura+=min(tm,sec[dstIdx].second-cura);
				}
				curb = sec[i].second;
				rez+=tm;
			}
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
