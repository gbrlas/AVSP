#include <iostream>
#include <fstream>
//#include <string>
//#include <map>
//#include <utility>

using namespace std;
typedef struct POS {
	int h;
	int w;
	bool operator == (POS &p) {
		return (h==p.h && w==p.w);
	}
	bool operator != (POS &p) {
		return !(*this==p);
	}
} Pos;
ifstream fin("B-small.in");
const int MAX=100;
const int MAX_AT=10000;
int N,H,W;
int at[MAX][MAX];
Pos to[MAX][MAX];
char g[MAX][MAX];
Pos offset[4]={{-1,0},{0,-1},{0,1},{1,0}};

Pos get_to(int h, int w)
{
	Pos p;
	p.h=h;p.w=w;
	int lowest=MAX_AT;
	for(int i=0;i<4;i++) {
		Pos &o=offset[i];
		int h0=h+o.h, w0=w+o.w;
		if(h0<0 || h0>H-1 || w0<0 || w0>W-1) continue;
		if(at[h0][w0]<lowest && at[h0][w0]<at[h][w]) p.h=h0,p.w=w0,lowest=at[h0][w0];
	}
	return p;
}

void closure()
{
	bool changed;
	do {
		changed = false;
		for(int h=0;h<H;h++)
			for(int w=0;w<W;w++) {
				Pos &p1 = to[h][w];
				Pos p2 = to[p1.h][p1.w];
				if(p1!=p2) changed = true;
				p1 = p2;
			}
	}while(changed);
}
void fillchar(int h0, int w0, char c)
{
	Pos p = to[h0][w0];
	for(int h=h0;h<H;h++)
		for(int w=(h==h0?w0:0);w<W;w++)
			if(to[h][w]==p) g[h][w]=c;
}
void draw()
{
	memset(&g[0][0],0,sizeof(char)*MAX*MAX);
	char c='a';
	for(int h=0;h<H;h++) {
		for(int w=0;w<W;w++) {
			if(g[h][w]==0) {
				fillchar(h,w,c++);
			}
		}
	}
}

int main()
{
	fin>>N;
	for(int i=1;i<=N;i++)
	{
		fin>>H>>W;
		for(int h=0;h<H;h++)
			for(int w=0;w<W;w++)
				fin>>at[h][w];
		for(int h=0;h<H;h++)
			for(int w=0;w<W;w++)
				to[h][w]=get_to(h,w);
		closure();
		draw();
		printf("Case #%d:\n",i);
		for(int h=0;h<H;h++)
			for(int w=0;w<W;w++)
				cout<<g[h][w]<<((w==W-1)?"\n":" ");
	}
	return 0;
}