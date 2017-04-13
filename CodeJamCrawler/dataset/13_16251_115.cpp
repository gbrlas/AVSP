#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

string a[5];

bool check_win(char c){
	for(int i=0; i<4; i++){
		if((a[i][0]==c || a[i][0]=='T')
		&& (a[i][1]==c || a[i][1]=='T')
		&& (a[i][2]==c || a[i][2]=='T')
		&& (a[i][3]==c || a[i][3]=='T'))
			return true;
		if((a[0][i]==c || a[0][i]=='T')
		&& (a[1][i]==c || a[1][i]=='T')
		&& (a[2][i]==c || a[2][i]=='T')
		&& (a[3][i]==c || a[3][i]=='T'))
			return true;
	}
	if((a[0][0]==c || a[0][0]=='T')
	&& (a[1][1]==c || a[1][1]=='T')
	&& (a[2][2]==c || a[2][2]=='T')
	&& (a[3][3]==c || a[3][3]=='T'))
		return true;
	if((a[0][3]==c || a[0][3]=='T')
	&& (a[1][2]==c || a[1][2]=='T')
	&& (a[2][1]==c || a[2][1]=='T')
	&& (a[3][0]==c || a[3][0]=='T'))
		return true;

	return false;
}

bool has_empty(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(a[i][j]=='.') return true;
		}
	}
	return false;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		for(int i=0; i<4; i++) cin>>a[i];
		string result;
		if(check_win('X')) result = "X won";
		else if(check_win('O')) result = "O won";
		else if(has_empty()) result = "Game has not completed";
		else result = "Draw";
		cout<<"Case #"<<testnum+1<<": "<<result<<endl;
	}
	return 0;
}
