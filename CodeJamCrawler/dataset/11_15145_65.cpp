#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

char a[55][55];
int n, m;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		cin>>n>>m;
		for(int i=0; i<n; i++) cin>>a[i];
		bool ok = true;
		for(int i=0; i<n && ok; i++){
			for(int j=0; j<m && ok; j++){
				if(a[i][j]=='#'){
					if(j+1>=m || a[i][j+1]!='#' || i+1>=n || a[i+1][j]!='#' || a[i+1][j+1]!='#'){
						ok = false;
						break;
					}
					a[i][j] = '/';	a[i][j+1] = '\\';
					a[i+1][j] = '\\';  a[i+1][j+1] = '/';
				}
			}
		}
		cout<<"Case #"<<testnum+1<<":"<<endl;
		if(!ok){
			cout<<"Impossible"<<endl;
		}else{
			for(int i=0; i<n; i++) cout<<a[i]<<endl;
		}
	}
	return 0;
}