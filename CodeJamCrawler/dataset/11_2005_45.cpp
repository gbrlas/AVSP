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
  string invoke;
	int caseNum;
	cin>>caseNum;
	
	for(int ca = 0;ca < caseNum;ca++){
		int c,d,n;
		string co,er;
		vector<string> combine;
		vector<string> erase;
		cin>>c;
		for(int i=0;i<c;i++){
			cin>>co;
			combine.push_back(co);
			char ch;
			ch = co[0];
			co[0] = co[1];
			co[1] = ch;
			combine.push_back(co);
		}
		cin>>d;
		for(int i=0;i<d;i++){
			cin>>er;
			erase.push_back(er);
		}
		cin>>n;
		cin>>invoke;
		string ans = "";
		for(int i=0;i<n;i++){
			ans = ans + invoke.substr(i,1);
			//combine
			for(int j = 0;j < 2*c;j++){
				int se = ans.find(combine[j].substr(0,2));
				if(se != -1){
					ans = ans.substr(0,se)+combine[j][2]+ans.substr(se+2);
				}
			}
			//erase
			for(int j = 0;j < d;j++){
				if(erase[j][0] == erase[j][1]){
					if(ans.find(erase[j].substr(0,1)) != -1
						 && ans.find(erase[j].substr(0,1)) != ans.rfind( erase[j].substr(1) )){
						ans = "";
					}
				}
				else{
					if(ans.find(erase[j].substr(0,1)) != -1
						 && ans.find(erase[j].substr(1)) != -1){
						ans = "";
					}
				}
			}
		}
		cout<<"Case #"<<ca+1<<": [";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];				
			if(i<ans.size()-1)
				cout<<", ";
		}
		cout<<"]"<<endl;
	}
  return 0;
}
