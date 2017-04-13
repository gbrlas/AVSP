#include <fstream>
//#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#include <set>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main(){
	int l,d,n;
	bool b[50010];
	cin>>l>>d>>n;
	
	char dic[5010][20];
	cin.getline(dic[0], 1000);
	for(int i=0; i<d; i++){
		cin.getline(dic[i], 1000);
	}
	char str[50005];
	set <char> st;
	for(int k=0; k<n; k++){
		cin.getline(str, 50000);
		memset(b,1,sizeof(b));
		int len=strlen(str);
		int num=0;
		for(int i=0; i<len; i++){
			if(str[i]=='('){
				i++;
				while(str[i]!=')'){
					st.insert(str[i]);
					i++;
				}
			}else{
				st.insert(str[i]);
			}
			for(int j=0; j<d; j++){
				b[j]=b[j]&&(st.find(dic[j][num])!=st.end());
			}
			num++;
			st.erase(st.begin(),st.end());
		}
		int count=0;
		for(int i=0; i<d; i++) if(b[i]) count++;
		
		cout<<"Case #"<<k+1<<": "<<count<<endl;
	}
	return 0;
}