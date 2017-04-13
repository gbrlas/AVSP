#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int w,h,b;
int x0[1<<10];
int y0[1<<10];
int x1[1<<10];
int y1[1<<10];

int cost[1<<10][1<<10];
int dist[1<<10];
bool finished[1<<10];

struct mycmp
{
    bool operator()(const int& i, const int& j)
    {
        if (dist[i] == dist[j]) return i<j;
        return dist[i] < dist[j];
    }
};

void dijkstra(){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	dist[b] = 0;
	memset(finished,false,sizeof(finished));
	
	int fin_cnt = 0;
	while (fin_cnt < b+2){
		int ind = -1;
		int best = 0x3f3f3f3f;
		for (int i = 0; i <= b+1; i++)
			if (!finished[i] && dist[i] < best){
				ind = i;
				best = dist[i];
			}
			
		finished[ind] = true;
		for (int next = 0; next <= b+1; next++){
			if (finished[next]) continue;
			if (dist[next] > dist[ind] + cost[ind][next]){
				dist[next] = dist[ind] + cost[ind][next];
			}
		}
		fin_cnt++;
	}
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> w >> h >> b;
		for (int i = 0; i < b; i++){
			cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
			x1[i]++;
			y1[i]++;
		}
			
		memset(cost,0,sizeof(cost));
		for (int i = 0; i < b; i++){
			for (int j = i+1; j < b; j++){
				int c1=0, c2=0;
				if (x0[i] > x1[j])
					c1 += x0[i] - x1[j];
				if (x0[j] > x1[i])
					c1 += x0[j] - x1[i];
				if (y0[i] > y1[j])
					c2 += y0[i] - y1[j];
				if (y0[j] > y1[i])
					c2 += y0[j] - y1[i];
				cost[i][j] = max(c1,c2);
				/*
				if (x1[i] > x0[j] || x1[j] > x0[i]){
					if (y0[i] >= y1[j]) cost[i][j] = y0[i] - y1[j];
					else cost[i][j] = y0[j] - y1[i];
				}
				else if (y1[i] > y0[j] || y1[j] > y0[i]){
					if (x0[i] >= x1[j]) cost[i][j] = x0[i] - x1[j];
					else cost[i][j] = x0[j] - x1[i];
				}
				else{
					if (x0[i] >= x1[j]) cost[i][j] = x0[i] - x1[j];
					else cost[i][j] = x0[j] - x1[i];
					
					if (y0[i] >= y1[j]) cost[i][j] += y0[i] - y1[j];
					else cost[i][j] += y0[j] - y1[i];
				}
				*/
				cost[j][i] = cost[i][j];
			}
		}
		
		
		for (int i = 0; i < b; i++){
			cost[i][b] = cost[b][i] = x0[i];
			cost[i][b+1] = cost[b+1][i] = w - x1[i];
		}
		cost[b][b+1] = cost[b+1][b] = w;
		
		/*
		for (int i = 0; i <= b+1; i++){
			for (int j = 0; j <= b+1; j++)
				cout << cost[i][j] << " ";
			cout << endl;
		}
		*/
		dijkstra();
		cout << "Case #" << zz << ": " << dist[b+1] << endl;
	}
	
	return 0;
}
