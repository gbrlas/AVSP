#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cmp1(pair< int,int > a, pair< int,int > b){
	if(a.first < b.first) return 1;
	else return 0;
}

int cmp2(pair< int,int > a, pair< int,int > b){
	if(a.second < b.second) return 1;
	else	return 0;
}



int main(){
	int N,NA,NB,T,pociagb,pociaga,j,k,sa,sb;
	int t1,t2,t3,t4;
	vector< pair< int,int > >a,b;
	vector< pair< int,int > > :: iterator it;
	scanf("%d\n",&N);
	for(int i=1; i<=N; i++){
		scanf("%d\n",&T);
		scanf("%d %d\n",&NA,&NB);
		for(int z=0;z<NA; z++){
			scanf("%d:%d %d:%d\n",&t1,&t2,&t3,&t4);
			a.push_back( pair<int,int> (t1*60+t2,t3*60+t4) );
			
		}
		for(int z=0;z<NB; z++){
			scanf("%d:%d %d:%d\n",&t1,&t2,&t3,&t4);
			b.push_back( pair<int,int> (t1*60+t2,t3*60+t4) );
		}
// // 		for(it=a.begin(); it!=a.end(); it++)
// // 			cout << (*it).first.first << ":" << (*it).first.second << " " << (*it).second.first << ":" << (*it).second.second << endl;
		sort(a.begin(),a.end(),cmp2);
		sort(b.begin(),b.end(),cmp1);
		/*cout << "posortowane:" << endl;
		for(it=a.begin(); it!=a.end(); it++)
			cout << (*it).first.first << ":" << (*it).first.second << " " <<*/ /*(*it).second.first << ":" << (*it).second.second << endl;*/
		pociagb=0;j=0;k=0;sb=0;
		if(a.size()==0) {pociaga=0; pociagb=b.size();}
		else if(b.size()==0) {pociaga=a.size(); pociagb=0;}
		else{
			while(1){
				//cout << j << " " << k << " " << a[j].second << " " << b[k].first << endl;
				if(a[j].second+T<=b[k].first ) { j++; sb++;}
				else {
					//cout << k << " " << sb << " ";
					k++;
					if(sb>0) sb--;
					else pociagb++;
					//cout << sb << " " << pociagb << endl;
				}
				if(j>=NA) {
					if(NB-k-sb > 0) pociagb+=NB-k+-sb;
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
				//cout << j << " " << k << " " << b[j].second << " " << a[k].first << endl;
				if(b[j].second+T<=a[k].first) { j++; sa++;}
				else {
					//cout << k << " " << sa << " ";
					k++;
					if(sa>0) sa--;
					else pociaga++;
					//cout << sa << " " << pociaga << endl;
				}
				if(j>=NB) {
					//cout << NA << " " <<  sa << " " << 
					if(NA-sa-k> 0) pociaga+=NA-sa-k;
					break;	
				}
				if(k>=NA) break;
			}
		}
		a.clear();
		b.clear();
		cout << "Case #" << i << ": " << pociaga << " " << pociagb << endl;
		
	}
	
	return 0;
}
