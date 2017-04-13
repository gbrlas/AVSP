// watersheds
// Alex Alexander <alex.alexander@gmail.com>
// trying to get back into shape :D

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int maps = 0;
int map[100][100];
int flow[100][100];
char label[100][100];
int mapd[2];

char chars[27] = "abcdefghijklmnopqrstuvwxyz";
char c = -1;

void printLabels() {
	int i,j;
	for ( i = 0; i < mapd[0]; i++ )
	{
		for ( j = 0; j < mapd[1]; j++ )
		{
			cout << label[i][j] << " ";
		}
		cout << endl;
	}
}

int getFlow(int y, int x) {
	int v[4] = {-1,-1,-1,-1};
	if ( y > 0 )
		v[0] = map[y-1][x];
	if ( x > 0 )
		v[1] = map[y][x-1];
	if ( x < mapd[1] - 1 )
		v[2] = map[y][x+1];
	if ( y < mapd[0] - 1 )
		v[3] = map[y+1][x];
	
	int l = -1;
	int lv = map[y][x];
	for ( int k = 0; k <= 3; k++ )
		if ( v[k] > -1 )
		{
			if ( v[k] < lv )
			{
				l = k;
				lv = v[k];
			}
		}

	return l+1;
}

int getLabel(int y, int x) {
	if ( flow[y][x] == -1 )
		flow[y][x] = getFlow(y,x);

	if ( flow[y][x] == 0 )
	{
		if ( label[y][x] == ' ' ) {
			label[y][x] = chars[++c];	
		}
		return label[y][x];
	}
	else if ( flow[y][x] > 0 )
	{
		int ny = y, nx = x;
		int f = flow[y][x];
		switch (f) {
			case 1:
				ny--;
			break;
			case 2:
				nx--;
			break;
			case 3:
				nx++;
			break;
			case 4:
				ny++;
			break;
		}
		label[y][x] = getLabel(ny,nx);
		return label[y][x];
	}
}

int checkMap(int i) {
	int k = 0, j = 0;
	for ( k = 0; k < mapd[0]; k++ )
		for ( j = 0; j < mapd[1]; j++ )
		{
			// get flow
			if ( flow[k][j] == -1 )
				flow[k][j] = getFlow(k,j);
			if ( label[k][j] == ' ' )
				label[k][j] = getLabel(k,j);
		}
	
	cout << "Case #" << i << ":" << endl;
	printLabels();
}

void reset() {
	int i, j;
	c = -1;
	mapd[0] = mapd[1] = 0;
	for ( i = 0; i < 100; i++ )
	{
		for ( j = 0; j < 100; j++ )
		{
			map[i][j] = -1;
			flow[i][j] = -1;
			label[i][j] = ' ';
		}
	}
}

int main(int argc, char *argv[]){
   	if ( argc != 2 )
	{
		cout << *(argv) << " data_file" << endl;
		return 1;
	}

	ifstream in(*(argv+1));
	if(!in){
		cout << "Cannot open file.";
		return 1;
	}

	int i,j, h, w;


	in >> maps;
	
	int cmap = 0;
	while(in && ++cmap <= maps){
		reset();

		in >> h >> w;
		
		mapd[0] = h;
		mapd[1] = w;
		for ( i = 0; i < h; i++ )
		{
			for ( j = 0; j < w; j++ )
			{
				in >> map[i][j];
			}
		}
		checkMap(cmap);
	}
	in.close();

}
