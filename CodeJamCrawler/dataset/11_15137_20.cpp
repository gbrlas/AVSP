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

int n;
char a[111][111];

double wp(int x){
	int total = 0, won = 0;
	for(int i=0; i<n; i++){
		if(a[x][i]!='.') total++;
		if(a[x][i]=='1') won++;
	}
	return double(won)/double(total);
}

double owp(int x){
	double rez = 0.0;
	int total = 0;
	char ch1, ch2;
	for(int i=0; i<n; i++){
		if(a[i][x]=='.') continue;
		total++;
		ch1 = a[i][x];
		ch2 = a[x][i];
		a[i][x] = '.';
		rez+=wp(i);
		a[i][x] = ch1;
		a[x][i] = ch2;
	}
	rez/=total;
	return rez;
}

double oowp(int x){
	double rez = 0.0;
	int total = 0;
	for(int i=0; i<n; i++){
		if(a[i][x]!='.'){
			total++;
			rez+=owp(i);
		}
	}
	rez/=total;
	return rez;
}

double rpi(int x){
	return 0.25 * wp(x) + 0.50 * owp(x) + 0.25 * oowp(x);
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		cout<<"Case #"<<testnum+1<<":"<<endl;
		for(int i=0; i<n; i++){
			cout<<setiosflags(ios::showpoint|ios::fixed)<<setprecision(7)<<rpi(i)<<endl;
		}
	}
	return 0;
}
