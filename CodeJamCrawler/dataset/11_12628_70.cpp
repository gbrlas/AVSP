#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<memory.h>
using namespace std;
vector<char> st;
int kol[1000],koll,kol1,t,asdas;
bool ff;
char x1[1000],y1[1000],z1[1000],x[1000],y[1000];
string s;         

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (int tt=0;tt<t;tt++){ 
		cin>>koll;
		st.clear();
		memset(kol,0,sizeof(kol));
		for (int i=0;i<koll;i++) 
			cin>>x1[i]>>y1[i]>>z1[i];
		cin>>kol1;
	
		for (int i=0;i<kol1;i++) cin>>x[i]>>y[i];
		cin>>s;
	        cin>>s;
		for (int i=0;i<s.size();i++) {
			ff=false;
			st.push_back(s[i]);
			kol[st[st.size()-1]]++;
			
			if (st.size()>1) {
				for (int j=0;j<koll;j++) if ((st[st.size()-1]==x1[j]&&st[st.size()-2]==y1[j])||(st[st.size()-2]==x1[j]&&st[st.size()-1]==y1[j])) {
		                                asdas=st.size()-1;
		
						kol[st[asdas]]--;
						
						st.pop_back();
		                                asdas=st.size()-1;
		
						kol[st[asdas]]--;
						st.pop_back();
						
						st.push_back(z1[j]);
						asdas=st.size()-1;
		
						kol[z1[j]]++;
						ff=true;
		
						break;
				}
			}
			if (ff==false) 
			for (int j=0;j<kol1;j++) if (kol[x[j]]!=0&&kol[y[j]]!=0) {
				st.clear();
				memset(kol,0,sizeof(kol));
			}
			
		}
		cout<<"Case #"<<tt+1<<": [";
		asdas=st.size()-1;
		for (int i=0;i<asdas;i++) cout<<st[i]<<", ";
		if (st.size()>0) cout<<st[st.size()-1]<<']'<<endl; else cout<<']'<<endl;
	}
 	return 0;
}	



				 
