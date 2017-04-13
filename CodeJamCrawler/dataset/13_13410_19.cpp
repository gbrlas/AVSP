
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int nt;
	cin >> nt;
	for(int t=0;t<nt;t++){
		long n,m;
		cin >> n >> m;
		vector <pair < long , long > > a;
		vector <pair <long,long> > oe;
		vector <long> oen;
		set <long> s;
		long ori=0;
		for(int i=0;i<m;i++){
			long o,e,p;
			cin >> o >> e >> p;
			oe.push_back(make_pair(o,e));
			oen.push_back(p);
			s.insert(o);
			s.insert(e);
			long d=e-o;
			ori+=p*(2*d*n-d*d+d)/2;
		}
		set<long>::iterator ite=s.begin();
		while(ite!=s.end()){
			a.push_back(make_pair(*ite,0));
			ite++;
		}
		for(int i=0;i<oe.size();i++){
			for(int j=0;j<a.size();j++){
				if(oe[i].first<=a[j].first){
					if(oe[i].second<=a[j].first)break;					
					else a[j].second+=oen[i];
				}
			}
		}

		long res=0;
		bool flag=true;
		while(flag){
			long min=0;
			long st=0;
			flag=false;
			for(int i=0;i<a.size();i++){
				if(a[i].second==0){
					if(min==0)continue;
					else{
						for(int j=st;j<i;j++){
							a[j].second-=min;
						}
						long dist=a[i].first-a[st].first;
						res+=min*(2*dist*n-dist*dist+dist)/2;
						min=0;
					}
				}else{
					flag=true;
					if(min==0){
						st=i;
						min=a[i].second;
					}else{
						min=(min>a[i].second)?a[i].second:min;
					}
				}
			}
		}

		cout << "Case #" << t+1 << ": " << ori-res << endl;
	}
	return 0;
}