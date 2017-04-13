
#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

int main(){
	uint nt;
	cin >> nt;
	for(uint t=0;t<nt;t++){

		string str;
		char map[4][4];
		for(uint y=0;y<4;y++){
			cin >> str;
			for(uint x=0;x<4;x++){
				map[y][x]=str[x];
			}
		}

		bool fill,xfill,ofill;
		fill=true;
		xfill=ofill=false;

		for(uint i=0;i<4;i++){
			for(uint j=0;j<4;j++){
				if(map[i][j]=='.'){
					fill=false;
				}
			}
		}

		uint cx,co,ct;

		for(uint i=0;i<4;i++){
			cx=co=ct=0;
			for(uint j=0;j<4;j++){
				if(map[i][j]=='X')cx++;
				if(map[i][j]=='O')co++;
				if(map[i][j]=='T')ct++;
			}
			if(cx==4 || (cx==3 && ct==1)){
				xfill=true;
			}
			if(co==4 || (co==3 && ct==1)){
				ofill=true;
			}
		}
		for(uint i=0;i<4;i++){
			cx=co=ct=0;
			for(uint j=0;j<4;j++){
				if(map[j][i]=='X')cx++;
				if(map[j][i]=='O')co++;
				if(map[j][i]=='T')ct++;
			}
			if(cx==4 || (cx==3 && ct==1)){
				xfill=true;
			}
			if(co==4 || (co==3 && ct==1)){
				ofill=true;
			}
		}
		cx=co=ct=0;
		for(uint i=0;i<4;i++){
			if(map[i][i]=='X')cx++;
			if(map[i][i]=='O')co++;
			if(map[i][i]=='T')ct++;
			if(cx==4 || (cx==3 && ct==1)){
				xfill=true;
			}
			if(co==4 || (co==3 && ct==1)){
				ofill=true;
			}
		}
		cx=co=ct=0;
		for(uint i=0;i<4;i++){
			if(map[3-i][i]=='X')cx++;
			if(map[3-i][i]=='O')co++;
			if(map[3-i][i]=='T')ct++;
			if(cx==4 || (cx==3 && ct==1)){
				xfill=true;
			}
			if(co==4 || (co==3 && ct==1)){
				ofill=true;
			}
		}

		cout << "Case #" << t+1 << ": ";
		if(xfill && ofill){
			cout << "Draw";
		}else if(xfill){
			cout << "X won";
		}else if(ofill){
			cout << "O won";
		}else if(fill){
			cout << "Draw";
		}else{
			cout << "Game has not completed";
		}
		cout << endl;
	}
	return 0;
}