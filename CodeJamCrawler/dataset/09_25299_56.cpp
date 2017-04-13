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
	int n, t;
	cin>>t;
	char ch[1000];
	cin.getline(ch, 1000);
	for(int l=0; l<t; l++){
		cin.getline(ch, 1000);
		n=strlen(ch);
		bool flag=false;
		for(int i=0; i<n-1; i++){
			if(ch[i]<ch[i+1]) flag=true;
		}
		if(flag){
			int k=n-2;
			while(ch[k]>=ch[k+1]){
				k--;
			}
			int p=k+1;
			while((p<n-1)&&(ch[p+1]>ch[k])){
				p++;
			}
			swap(ch[k],ch[p]);
			sort(ch+k+1,ch+n);
		}else{
			ch[n++]='0';
			ch[n]=0;
			sort(ch,ch+n);
			int p=0;
			while(ch[p]=='0'){
				p++;
			}
			ch[0]=ch[p];
			if(p!=0) ch[p]='0';
		}
		cout<<"Case #"<<l+1<<": "<<ch<<endl;
		
	

	}
	return 0;
}	