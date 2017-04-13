#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int num_case = 0;

int main(){
	scanf("%d", &num_case);
	for(int caseno = 0;caseno < num_case;caseno++){
		int num_move = 0;
		scanf("%d", &num_move);
		int o = 0,b = 0;
		int op = 1,bp = 1;
		for(int i = 0;i < num_move;i++){
			char bot[5];int but;
			scanf("%s %d", bot, &but);
			if(bot[0] == 'B'){
				int v = abs(but - bp) - (max(o,b)-b);
				if(v < 0)v=0;
				b=max(o,b)+v+1;
				bp = but;
			}else{
				int v = abs(but - op) - (max(o,b)-o);
				if(v < 0)v=0;
				//printf("%d %d\n",max(o,b), v);
				o=max(o,b)+v+1;
				op = but;
			}
			//printf("o:%d b:%d op:%d bp:%d\n", o, b, op, bp); 
		}
		printf("Case #%d: %d\n", caseno+1, max(o,b));
	}
}
