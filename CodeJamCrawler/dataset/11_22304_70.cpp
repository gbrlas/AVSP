#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;

int main(){
	short int T, N, temp, op, bp;
	unsigned int time;
	char r;
	bool change;
	FILE * pf;
	pf = fopen("out.txt", "w");
	queue<short int> O;
	queue<short int> B;
	queue<char> C;
	scanf("%hi", &T);
	for(int z=1; z<=T; z++){
		scanf("%hi", &N);
		for(int i=0; i<N; i++){
			scanf(" %c %hi", &r, &temp);
			if(r == 'O')
				O.push(temp);
			else
				B.push(temp);
			C.push(r);
		}
		time = 0;
		op = 1;
		bp = 1;
		r=C.front();
		while(true){
			if(O.empty() && B.empty())
				break;
			change = false;
			time++;
			if(!O.empty()){
				if(O.front() == op){
					if(r=='O'){
						change = true;
						O.pop();
						C.pop();
						if(C.empty())
							break;
						r=C.front();
					}
					/*else if(!B.empty() && bp != B.front()){
						time += (abs(bp-B.front())-1);
						bp = B.front();
					}*/
				}
				else if(O.front() > op){
					op++;
				}
				else{
					op--;
				}
			}
			if(!B.empty()){
				if(B.front() == bp){
					if(r=='B' && !change){
						B.pop();
						C.pop();
						if(C.empty())
							break;
						r=C.front();
					}
					/*else if(!O.empty() && op != O.front()){
						time += (abs(op-O.front())-1);
						op = O.front();
					}*/
				}
				else if(B.front() > bp){
					bp++;
				}
				else{
					bp--;
				}
			}
		}
		fprintf(pf, "Case #%hi: %u\n", z, time);
	}
	fclose(pf);
	return 0;
}
