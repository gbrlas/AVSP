#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

int main(){
  int t;
	cin>>t;
	for(int cases = 0;cases<t;cases++){
		int w,h;
		cin>>h>>w;
		vector<string> picture;
		for(int i=0;i<h;i++){
			string line;
			cin>>line;
			picture.push_back(line);
		}
		bool solve = true;
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				if(picture[y][x] == '#'){
					if(y+1<h && x+1<w){
						if(picture[y+1][x] == '#' && picture[y][x+1] == '#' && picture[y+1][x+1] == '#'){
							picture[y][x] = '/';
							picture[y+1][x] = '\\';
							picture[y][x+1] = '\\';
							picture[y+1][x+1] = '/';
						}
						else{
							solve = false;
							break;
						}
					}
					else{
						solve = false;
						break;
					}
				}
			}
			if(!solve)break;
		}
		printf("Case #%d: \n",cases+1);
		if(solve){
			for(int i = 0;i<h;i++){
				cout<<picture[i]<<endl;
			}
		}
		else{
			printf("Impossible\n");
		}
	}
  return 0;
}
