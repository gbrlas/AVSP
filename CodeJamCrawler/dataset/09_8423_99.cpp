#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

void ccn(int x1, int y1, int x2, int y2);

int res[100][100] = {0};
int h = 0;
int w = 0;
int mark = 'a';

int main()
{
	ifstream ifs;
	ofstream ofs;
	string buf;
	char b[1000] = {0};
	int map[100][100] = {0};
	ifs.open("B-large.in", ios::in);
	ofs.open("B-large.out", ios::out);
	getline(ifs, buf);
	int t = atoi(buf.c_str());
	for(int i = 0; i < t; i++)
	{
		getline(ifs, buf);
		sprintf(b, "%s", buf.c_str());
		h = atoi(strtok(b, " "));
		w = atoi(strtok(NULL, " "));
		mark = 'a';
		
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++)
			{
				res[j][k] = 0;
				map[i][k] = 0;
			}
		for(int j = 0; j < h; j++)
		{
			getline(ifs, buf);
			sprintf(b, "%s", buf.c_str());
			map[j][0] = atoi(strtok(b, " "));
			for(int k = 1; k < w; k++)
				map[j][k] = atoi(strtok(NULL, " "));
		}
		for(int j = 0; j < h; j++)
			for(int k = 0; k < w; k++)
			{
				int lowest = map[j][k];
				int jj = j;
				int kk = k;
				
				bool flow = false;
				//flow to North
				if(j > 0 && map[j - 1][k] < lowest)
				{
					lowest = map[j - 1][k];
					flow = true;
					jj = j - 1;
					kk = k;
				}
				//flow to West
				if(k > 0 && map[j][k - 1] < lowest)
				{
					lowest = map[j][k - 1];
					flow = true;
					jj = j;
					kk = k - 1;
				}
				//flow to East
				if(k < (w - 1) && map[j][k + 1] < lowest)
				{
					lowest = map[j][k + 1];
					flow = true;
					jj = j;
					kk = k + 1;
				}
				//flow to South
				if(j < (h - 1) && map[j + 1][k] < lowest)
				{
					lowest = map[j + 1][k];
					flow = true;
					jj = j + 1;
					kk = k;
				}
				
				if(flow)
				{
					if(res[j][k] == 0 && res[jj][kk] == 0)
					{
						res[j][k] = mark;
						res[jj][kk] = mark;
						mark++;
					}
					else if(res[j][k] == 0 && res[jj][kk] > 0)
					{
						res[j][k] = res[jj][kk];
					}
					else if(res[j][k] > 0 && res[jj][kk] == 0)
					{
						res[jj][kk] = res[j][k];
					}
					else if(res[j][k] > 0 && res[jj][kk] > 0 && res[j][k] != res[jj][kk])
					{
						ccn(j, k, jj, kk);
					}
				}
				else if(res[j][k] == 0) res[j][k] = mark++;
			}
		ofs << "Case #" << i + 1 << ": " << endl;
		for(int j = 0; j < h; j++)
		{
			ofs << (char) res[j][0];
			for(int k = 1; k < w; k++)
				ofs << " " << (char) res[j][k];
			ofs << endl;
		}
	}
	return 0;
}

void ccn(int x1, int y1, int x2, int y2)
{
	int cmax = max((int) res[x1][y1], (int) res[x2][y2]);
	int cmin = min((int) res[x1][y1], (int) res[x2][y2]);
	if(cmax == cmin) return;
	mark--;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(res[i][j] == cmax) res[i][j] = cmin;
			else if(res[i][j] > cmax) res[i][j]--;
		}
	}
}

