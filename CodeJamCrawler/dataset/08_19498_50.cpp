#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cmp1(pair< pair<int,int>, pair<int,int> > a, pair< pair<int,int>, pair<int,int> > b){
	if(a.first.first < b.first.first) return 1;
	else if(a.first.first == b.first.first) if(a.first.second < b.first.second) return 1;
	return 0;
}

int cmp2(pair< pair<int,int>, pair<int,int> > a, pair< pair<int,int>, pair<int,int> > b){
	if(a.second.first < b.second.first) return 1;
	else if(a.second.first == b.second.first) if(a.second.second < b.second.second) return 1;
	return 0;
}



int main(){
	int N,NA,NB,T,pociagb,pociaga,j,k,sa,sb;
	int t1,t2,t3,t4;
	vector< pair< pair<int,int>, pair<int,int> > > a,b;
	vector< pair< pair<int,int>, pair<int,int> > > :: iterator it;
	scanf("%d\n",&N);
	for(int i=1; i<=N; i++){
		scanf("%d\n",&T);
		scanf("%d %d\n",&NA,&NB);
		while(NA--){
			scanf("%d:%d %d:%d\n",&t1,&t2,&t3,&t4);
			//pair <int, int> p1(t1,t2,p2;
			a.push_back( pair< pair<int,int>, pair<int,int> > ( pair<int,int>(t1,t2), pair<int,int> (t3,t4) ));
			
		}
		while(NB--){
			scanf("%d:%d %d:%d\n",&t1,&t2,&t3,&t4);
			b.push_back( pair< pair<int,int>, pair<int,int> > ( pair<int,int>(t1,t2), pair<int,int> (t3,t4) ));
		}
// // 		for(it=a.begin(); it!=a.end(); it++)
// // 			cout << (*it).first.first << ":" << (*it).first.second << " " << (*it).second.first << ":" << (*it).second.second << endl;
		sort(a.begin(),a.end(),cmp2);
		sort(b.begin(),b.end(),cmp1);
		/*cout << "posortowane:" << endl;
		for(it=a.begin(); it!=a.end(); it++)
			cout << (*it).first.first << ":" << (*it).first.second << " " <<*/ /*(*it).second.first << ":" << (*it).second.second << endl;*/
		pociagb=0;j=0;k=0;sb=0;
		while(1){
			if(a[j].second.first<b[k].first.first or (a[j].second.first==b[k].first.first and a[j].second.second<b[k].first.second)) { j++; sb++;}
			else {
				k++;
				if(sb>0) sb--;
				else pociagb++;
			}
			if(j>=NA) {
				if(NB-sb > 0) pociagb+=NB-sb;
				break;	
			}
			if(k>=NB) break;
		}
		
		sort(a.begin(),a.end(),cmp1);
		sort(b.begin(),b.end(),cmp2);
// 		cout << "posortowane:" << endl;
// 		for(it=a.begin(); it!=a.end(); it++)
// 			cout << (*it).first.first << ":" << (*it).first.second << " " << (*it).second.first << ":" << (*it).second.second << endl;
		pociaga=0;j=0;k=0;sa=0;
		while(1){
			if(b[j].second.first<a[k].first.first or (b[j].second.first==a[k].first.first and b[j].second.second<a[k].first.second)) { j++; sa++;}
			else {
				k++;
				if(sa>0) sa--;
				else pociaga++;
			}
			if(j>=NB) {
				if(NA-sa > 0) pociaga+=NA-sa;
				break;	
			}
			if(k>=NA) break;
		}
		
		a.clear();
		b.clear();
		cout << "case #" << i << ": " << pociaga << " " << pociagb << endl;
		
	}
	
	return 0;
}
