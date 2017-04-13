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

int main(){
	int n;
	cin>>n;
	int res[19][505];
	char str[1000];
	char wlc[]="welcome to code jam";
	cin.getline(str,1001);
	for(int p=0; p<n; p++){
		cin.getline(str,1001);
		int len=strlen(str);
		memset(res, 0, sizeof(res));
		int cnt=0;
		for(int i=0; i<len; i++){
			if(str[i]=='w'){
				//cnt++;
				res[0][i]=1;
			}
		}
		for(int i=1; i<19; i++){
			for(int j=0; j<len; j++){
				if(str[j]==wlc[i]){
					for(int k=0; k<j; k++){
						res[i][j]+=res[i-1][k];
						res[i][j]=res[i][j]%10000;
					}
				}
			}
		}
		int sum=0;
		for(int i=0; i<len; i++){
			sum=(sum+res[18][i])%10000;
		}

		cout<<"Case #"<<p+1<<": ";
		if(sum<1000) cout<<0;
		if(sum<100) cout<<0;
		if(sum<10) cout<<0;
		cout<<sum<<endl;
	}
	return 0;
}