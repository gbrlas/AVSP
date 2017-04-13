#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
#include <cctype>
using namespace std;

char line[501];
int currID = 10001;

int flow(const int h, const int w, vector<vector<int>> &map, vector<vector<int>> &result);

int main(void){
	FILE* fi = freopen("input_small.txt", "r", stdin);
	FILE* fo = freopen("output_small.txt", "w", stdout);


	int T = 0;
	scanf("%d\n", &T);
	
	for(int i = 0; i < T; ++i){
		currID = 10001;
		int H =0, W=0;
		int _h = 0, _w = 0;
		scanf("%d %d\n", &H, &W);

		vector<vector<int>> map(H, vector<int>(W, 0));
		
		//read
		for(_h = 0; _h < H; ++_h){
			for(_w = 0; _w < W; ++_w){
				int a = 0; fscanf(stdin, "%d", &a); getchar();
				if(a != '\n' && a != ' ')
					map[_h][_w] = a;
			}
		}

		//calc
		vector<vector<int>> result(map.begin(), map.end());
		for(_h = 0; _h < H; ++_h){
			for(_w = 0; _w < W; ++_w){
				if(result[_h][_w] <= 10000)
					flow(_h, _w, map, result);
			}
		}

		
		//output
		printf("Case #%d:\n", i+1);
		for(_h = 0; _h < H; ++_h){
			for(_w = 0; _w < W; ++_w){
				if(_w != W-1)
					printf("%c ", result[_h][_w]-9904);
				else
					printf("%c\n", result[_h][_w]-9904);
			}
		}
	}

	return 0;
}


int flow(const int h, const int w, vector<vector<int>> &map, vector<vector<int>> &result){
	if(result[h][w] > 10000)
		return result[h][w];
	
	int dir[2][4] = {{-1, 0, 0, +1}, {0, -1, +1, 0}};
	int w_low = 0, h_low = 0;
	int lowest = map[h][w];

	for(int d = 0; d < 4; ++d){
		int hn = h+dir[0][d];
		int wn = w+dir[1][d];
		if(hn < 0 || hn >= map.size() || wn < 0 || wn >= map[h].size())
			continue;
		int cur = map[hn][wn];
		if(cur < lowest){
			lowest = cur;
			w_low = wn;
			h_low = hn;
		}
	}

	if(lowest != map[h][w]){
		result[h][w] = flow(h_low, w_low, map, result);
		return result[h][w];
	}
	else{
		result[h][w] = currID;
		return currID++;
	}
}