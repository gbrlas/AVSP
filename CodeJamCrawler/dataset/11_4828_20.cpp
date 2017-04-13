#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T, N;
	char c;
	int b;
	
	vector < map<char,int> > v;
	map<char,int> m;
	cin>>T;
	
	for(int i=1;i<=T;i++){
		cin>>N;
		for(int j=1;j<=N;j++){
			cin>>c>>b;
			m[c]=b;
			v.push_back(m);
			m.clear();
		}
		int y=0;
		int po=1,pb=1,O=1,B=1;
		
		while(!v.empty()){
			m.clear();
			m=v[0];
			if(m.begin()->first=='O'){
				O=m['O'];
				m.clear();
				for(int j=1;j<v.size();j++){
					m=v[j];
					if(m.begin()->first=='B'){
						B=m['B'];
						m.clear();
						break;
					}
					m.clear();
				}
				y+=abs(O-po)+1;
				if( abs(B-pb)<=abs(O-po) + 1 )
					pb=B;
				else{
					if(pb<=B)
						pb+=abs(O-po)+1;
					else
						pb-=abs(O-po)+1;
				}
				po=O;
				v.erase(v.begin());
			}
			else{
				B=m['B'];
				m.clear();
				for(int j=1;j<v.size();j++){
					m=v[j];
					if(m.begin()->first=='O'){
						O=m['O'];
						m.clear();
						break;
					}
					m.clear();
				}
				y+=abs(B-pb)+1;
				if( abs(O-po)<=abs(B-pb) + 1)
					po=O;
				else{
					if(po<=O)
						po+=abs(B-pb)+1;
					else
						po-=abs(B-pb)+1;
				}
				pb=B;
				v.erase(v.begin());
			}
			
		}		
		cout<<"Case #"<<i<<": "<<y<<endl;
		v.clear();
	}
}
