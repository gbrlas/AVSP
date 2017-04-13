#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int t;
int h,w;

int map[100][100];
char bas[100][100];
int cld[100][100];//0

bool isvalid(int x,int y) {
	if ((x>=0)&&(x<w)&&(y>=0)&&(y<h)) {
		return true;
	}
	return false;
}
int getheight(int x,int y) {
	if (isvalid(x,y))
		return map[y][x];
	return 100001;
}
int findchild(int xp,int yp) {
	if (!isvalid(xp,yp))
		return 0;
	//North, West, East, South.
	int north = getheight(xp,yp-1);
	int west = getheight(xp-1,yp);
	int south = getheight(xp,yp+1);
	int east = getheight(xp+1,yp);
	int minheight = min(min(north,south),min(east,west));
	if (minheight >= getheight(xp,yp))
		return 0;
	if (north == minheight) {
		return 1;
	}
	if (west == minheight) {
		return 2;
	}
	if (east == minheight) {
		return 3;
	}
	if (south == minheight) {
		return 4;
	}
	return 0;
}

char floodfill(int y,int x,char ffc) {
	//cout<<"ff "<<y<<" "<<x<<" "<<ffc<<endl;
	if (!isvalid(x,y))
		return ffc;
	if (bas[y][x] == '-') {
		bas[y][x] = ffc;
		switch(cld[y][x]) {
			case 1:
				floodfill(y-1,x,ffc);
				break;
			case 2:
				floodfill(y,x-1,ffc);
				break;
			case 3:
				floodfill(y,x+1,ffc);
				break;
			case 4:
				floodfill(y+1,x,ffc);
				break;
		}
		if (isvalid(x,y-1)&&(cld[y-1][x] == 4))
			floodfill(y-1,x,ffc);
		if (isvalid(x-1,y)&&(cld[y][x-1] == 3))
			floodfill(y,x-1,ffc);
		if (isvalid(x+1,y)&&(cld[y][x+1] == 2))
			floodfill(y,x+1,ffc);
		if (isvalid(x,y+1)&&(cld[y+1][x] == 1))
			floodfill(y+1,x,ffc);
		return ffc + 1;
	}
	return ffc;
}

int main() {
	ifstream fin("watersheds.in");
	ofstream fout("watersheds.out");
	fin>>t;
	for (int ncase=0; ncase<t; ncase++) {
		fin>>h>>w;
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++) {
				fin>>map[i][j];
			}
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++) {
				bas[i][j] = '-';
			}
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++) {
				cld[i][j] = findchild(j,i);
			}
		char ffc = 'a';
		for (int i=0; i<h; i++)
			for(int j=0; j<w; j++) 
				ffc = floodfill(i,j,ffc);
		fout<<"Case #"<<ncase+1<<":"<<endl;
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				fout<<bas[i][j]<<' ';
				//cout<<cld[i][j]<<' ';
			}
			fout<<endl;
			//cout<<endl;
		}
	}
	fin.close();
	fout.close();
}
