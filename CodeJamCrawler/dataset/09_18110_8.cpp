#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include<math.h>
using namespace std;

int main(){
	int t,gg=0;
	scanf("%d",&t);
	while(t--){
		gg++;
		string s,ss;
		int i,j,k;
		map<char,int>m;
		cout<<"Case #"<<gg<<": ";
		map<char,int>m2;
		cin>>s;
		for(i=0;i<s.size();i++){
			if(m[s[i]]==0){
				m[s[i]]=1;
			}
		}
		int base=m.size();
		m2[s[0]]=1+48;
		string ss1;
		ss1=ss1+'1';
		for(i=0,j=1;j<s.size();j++){
			if(m2[s[j]]==0){
				m2[s[j]]=(i+48);
				i++;
				if(i==1){
					i=2;
				}	
				ss1=ss1+char(m2[s[j]]);
			}else{
				ss1=ss1+char(m2[s[j]]);
			}	
		}
		if(base==1){
			base=2;
		}	
		string ans;
		int sum=0;
		for(k=0,i=ss1.size()-1;k<ss1.size(),i>=0;k++,i--){
			sum+=int(ss1[i]-48)*int(pow(base,k));
		}
		cout<<sum<<endl;	
		
				
	}
	return 0;
}		
