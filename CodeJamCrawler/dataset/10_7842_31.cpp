#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <conio.h>
using namespace std;
static const double EPS = 1e-5;

#define SIZE 500

int lx,ly;
bool map[SIZE][SIZE];
bool next[SIZE][SIZE];

bool get(int x,int y){
	if(x>=0 && y>=0)return map[y][x];
	else return false;
}

int main(){
	int t,u;
	int x1,x2,y1,y2,x,y,r,time;
	cin >>t;
	for(u=0;u<t;u++){
		cin >> r;
		memset(map,false,sizeof(map));
		memset(next,false,sizeof(map));
		lx=0;ly=0;
		for(;r--;){
			cin >> x1 >> y1 >> x2 >> y2;
			for(x=x1;x<=x2;x++){
				for(y=y1;y<=y2;y++){
					map[y][x]=true;
					if(ly<y)ly=y;
					if(lx<x)lx=x;
				}
			}
		}
		lx+=5;ly+=5;
		for(time=0;;time++){

			bool flag=true;
			for(y=0;y<ly && flag;y++){
				for(x=0;x<lx && flag ;x++){
					if(map[y][x]){
						flag=false;
					}
				}
			}
			if(flag)break;

			for(x=0;x<lx;x++){
				for(y=0;y<ly;y++){
					if(map[y][x]==false){
						if(get(x-1,y) && get(x,y-1)){
							next[y][x]=true;
						}
						else next[y][x]=false;
					}else{
						if(get(x-1,y) || get(x,y-1)){
							next[y][x]=true;
						}else next[y][x]=false;
					}
				}
			}

			for(x=0;x<lx;x++){
				for(y=0;y<ly;y++){
//					cout << map[y][x];
					map[y][x]=next[y][x];
				}
//				cout << endl;
			}
//			cout << endl;

			lx++;ly++;
		}
		cout << "Case #" << u+1 << ": " << time;
		cout << endl;
	}
	getch();
	return 0;
}