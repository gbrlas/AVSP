
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef __int64 ll;

int main(){
	int nt;
	cin >> nt;
	for(int t=0;t<nt;t++){
		__int64 n,m;
		cin >> n >> m;
		vector <pair < __int64 , __int64 > > a;
		vector <pair <__int64,__int64> > oe;
		vector <__int64> oen;
		set <__int64> s;
		__int64 ori=0;
		for(int i=0;i<m;i++){
			__int64 o,e,p;
			cin >> o >> e >> p;
			oe.push_back(make_pair(o,e));
			oen.push_back(p);
			s.insert(o);
			s.insert(e);
			__int64 d=e-o;
			ori+=(p*((2*d*n-d*d+d)/2% 1000002013)) % 1000002013;
			ori%=1000002013;
		}
		set<__int64>::iterator ite=s.begin();
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

		__int64 res=0;
		bool flag=true;
		while(flag){
			__int64 min=0;
			int st=0;
			flag=false;
			for(int i=0;i<a.size();i++){
				if(a[i].second==0){
					if(min==0)continue;
					else{
						for(int j=st;j<i;j++){
							a[j].second-=min;
						}
						__int64 dist=a[i].first-a[st].first;
						res+=min*((2*dist*n-dist*dist+dist)/2 % 1000002013);
						res%=1000002013;
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
		__int64 ans=(ori+1000002013-res)% 1000002013;
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}