#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int n;
	scanf("%d",&n);
	string field[4];
	for(int q=1;q<=n;q++){
		int x=0,o=0;
		bool all=1;
		for(int i=0;i<4;i++) cin >> field[i];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(field[i][j]=='.'){
					all=0;
				}
			}
		}
		for(int i=0;i<4;i++){
			map<char,int>ma;
			ma.clear();
			for(int j=0;j<4;j++) ma[field[i][j]]++;
			if(ma['X']==4 || ma['O']==4 || (ma['T']==1 && (ma['X']==3 || ma['O']==3))){
				if(ma['X']>=3) x=1;
				if(ma['O']>=3) o=1;
			}
		}
		for(int i=0;i<4;i++){
			map<char,int>ma;
			ma.clear();
			for(int j=0;j<4;j++) ma[field[j][i]]++;
			if(ma['X']==4 || ma['O']==4 || (ma['T']==1 && (ma['X']==3 || ma['O']==3))){
				if(ma['X']>=3) x=1;
				if(ma['O']>=3) o=1;
			}
		}
		map<char,int>ma;
		ma.clear();
		for(int i=0;i<4;i++){
			ma[field[i][i]]++;
		}
		if(ma['X']==4 || ma['O']==4 || (ma['T']==1 && (ma['X']==3 || ma['O']==3))){
			if(ma['X']>=3) x=1;
			if(ma['O']>=3) o=1;
		}
		ma.clear();
		for(int i=0;i<4;i++){
			ma[field[i][3-i]]++;
		}
		if(ma['X']==4 || ma['O']==4 || (ma['T']==1 && (ma['X']==3 || ma['O']==3))){
			if(ma['X']>=3) x=1;
			if(ma['O']>=3) o=1;
		}
		printf("Case #%d: ",q);
		if(x) puts("X won");
		else if(o) puts("O won");
		else if(!x && !o && all) puts("Draw");
		else puts("Game has not completed");
	}
}