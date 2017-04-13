#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int D, I, M, N, values[200];

bool read(){
	
	scanf("%d%d%d%d", &D, &I, &M, &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &values[i]);
	}
		
	return true;
}
int caso = 1;

int dist[200][300];

void process(){
	priority_queue< pair<int,pair<int,int> > > heap;
	int pos, ant;
	
	heap.push( pair<int, pair<int,int> >( 0 , pair<int,int>(0, 256)));
	memset(dist,0x63,sizeof(dist));
	dist[0][256] = 0;
	
	while(!heap.empty()){
		pos = heap.top().second.first;
		ant = heap.top().second.second;
		//printf("%d %d -> %d\n", pos, ant, dist[pos][ant]);
		
		if(dist[pos][ant] < -heap.top().first){
			heap.pop();
			continue;
		}else heap.pop();
		
		if(pos == N){
			printf("Case #%d: %d\n", caso++, dist[pos][ant]);
			return;
		}
		
		if(ant != 256){
			//inserir um pixel
			for(int i = 0; i <= 255; i++){
				if(abs(ant - i) <= M && dist[pos][i] > dist[pos][ant] + I){
					dist[pos][i] = dist[pos][ant] + I;
					heap.push(make_pair(-dist[pos][i], make_pair(pos, i)));
				}
			}
			
		}
		//mudar
		for(int i = 0; i <= 255; i++){
			if((ant == 256 || abs(ant - i) <= M) && dist[pos+1][i] > dist[pos][ant] + abs(values[pos]-i)){
				dist[pos+1][i] = dist[pos][ant]  + abs(values[pos]-i);
				heap.push(make_pair(-dist[pos+1][i], make_pair(pos+1, i)));
			}
		}
		
		//deletar
		if(dist[pos+1][ant] > dist[pos][ant] + D){
			dist[pos+1][ant] = dist[pos][ant] + D;
			heap.push(make_pair(-dist[pos+1][ant], make_pair(pos+1, ant)));
		}
		
	}
	
}

int main(){
	
	int casos;
	
	scanf("%d", &casos);
	
	while(casos-- && read()){
		process();
	}
	
	return 0;
}
