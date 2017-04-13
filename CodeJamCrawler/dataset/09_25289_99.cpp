#include <fstream>
//#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");
char str[1000];
int len;
char obr[]="welcome to code jam";
//int 
int now;
int cnt;

void proc(int ind){
	if(now==19){
		cnt++;
		cnt%=10000;
		return;
	}
	if(ind==len) return;
	for(int i=ind; i<len; i++){
		if(str[i]==obr[now]){
			now++;
			proc(i+1);
			now--;
		}
	}
}

int main(){
	int n;
	cin>>n;
	cin.getline(str,1001);
	for(int i=0; i<n; i++){
		now=0;
		cin.getline(str,1001);
		len=strlen(str);
		cnt=0;
		proc(0);
		cout<<"Case #"<<i+1<<": ";
		if(cnt<1000) cout<<0;
		if(cnt<100) cout<<0;
		if(cnt<10) cout<<0;
		cout<<cnt<<endl;
	}
	return 0;
}