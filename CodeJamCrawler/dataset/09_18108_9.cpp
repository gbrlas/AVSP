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
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	int i,j,k,t,gg=0;
	scanf("%d",&t);
	string s1,s,s2,s3;
	while(t--){
		gg++;
		char ch;		
		//cout<<"amit"<<endl;
		printf("Case #%d: ",gg);
		cin>>s;
		s1=s;
		s2=s;
		int f=atoi(s1.c_str());
		sort(s.begin(),s.end());
		string s4=s;
		for(i=1;i<s1.size();i++){
			s3=s3+s[i];
		}	
		int flag=0;
		while(next_permutation(s.begin(),s.end())){
			int tt=atoi(s.c_str());
			if(tt>f){
				flag=1;
				cout<<tt<<endl;
				//cout<<"hhhh";
				break;
			}
		}
		string ans;
		if(flag==0){
			for(i=0;i<s4.size();i++){
				if(s4[i]!='0'){
					ch=s4[i];
					break;
				}
			}
			string s6;
			int flag1=0;
			for(i=0;i<s4.size();i++){
				if(s4[i]==ch && flag1==0){
					flag1=1;
					continue;
				}else{
					s6=s6+s4[i];
				}
			}			

			//cout<<ch<<endl;
			//cout<<s3<<endl;
			ans=ans+ch+'0'+s6;
			cout<<ans<<endl;		
		}
		s.clear();
		s1.clear();
		s2.clear();
		s3.clear();
		ans.clear();
				
	}
	return 0;
}		
