#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

priority_queue< pair<int, int> > heap;
map<int,int> mapa;

void read(){
	int c;	
	scanf("%d", &c);
	mapa.clear();
	for(int i = 0; i < c; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(b > 1)heap.push(make_pair(b,a));
		mapa[a] = b;
	}
}

int caso = 1;
void process(){
	printf("Case #%d: ", caso++);

	int total = 0;
	
	while(!heap.empty()){
		int atual = heap.top().second;
		int value = heap.top().first;
		heap.pop();
		if(mapa[atual] != value)continue;
		if(value == 1)continue;
		if(value%2 == 1){
			mapa[atual] = 1;
		}else{
			mapa[atual] = 0;
		}
		total += value/2;
		mapa[atual-1] += value/2;
		mapa[atual+1] += value/2;
		if(mapa[atual-1] > 1)	
			heap.push(make_pair(mapa[atual-1], atual-1));
		if(mapa[atual+1] > 1)
			heap.push(make_pair(mapa[atual+1], atual+1));
	}
	printf("%d\n", total);	
}

int main(){

	int casos;
	scanf("%d", &casos);

	for(int i = 1; i <= casos; i++){
		read();
		process();	
	}
	
	return 0;
}

