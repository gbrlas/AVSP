#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
  using namespace std;

int main(){
	int t, n, current, i, j;
	char bot;
	vector<int> vecta, vectb, all;
	vector<char> next;
	fscanf(stdin, "%d", &t);
	
	for(i=0; i<t; i++){
		fscanf(stdin, "%d", &n);
		
		vecta.clear();
		vectb.clear();
		all.clear();
		next.clear();
		for(j=0; j<n; j++){
			fscanf(stdin, " %c %d", &bot, &current);
			if(bot=='O'){
				vecta.push_back(current);
			} else {
				vectb.push_back(current);
			}
			
			all.push_back(current);
			next.push_back(bot);
		}
		
		//cout << vecta.size() << "\t" << vectb.size() << endl;
		int steps=0, posa=1, posb=1;
		bool movea, moveb;
		while(!next.empty()){
			movea= false;
			moveb= false;
			if(next.size()>0 && next.at(0)=='O' && vecta.at(0)==posa){
				vecta.erase(vecta.begin());
				next.erase(next.begin());
				movea= true;
				//cout << "push O" << endl;
			} else if(next.size()>0 && next.at(0)=='B' && vectb.at(0)==posb){
				vectb.erase(vectb.begin());
				next.erase(next.begin());
				moveb= true;
				//cout << "push B" << endl;
			}
			
			if(!movea){
				if(vecta.size()>0){
					if(posa< vecta.at(0)){
						posa++;
					} else if(posa> vecta.at(0)){
						posa--;
					}
				}
			}
			if(!moveb){
				if(vectb.size()>0){
					if(posb< vectb.at(0)){
						posb++;
					} else if(posb> vectb.at(0)){
						posb--;
					}
				}
			}
			
			steps++;
			//cout << "[" << posa << ", " << posb << "]\tsteps: " << steps << endl;
			
		}
		
		fprintf(stdout, "Case #%d: %d\n", (i+1), steps);
		//cout << endl << endl;
	}
	return 0;
}
