#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("a.out");
ifstream fin ("a.in");
int T;

int nVines;
int len[10000];
int dist[10000];
int lowest[10000];
int D;


int main () {
	fin >> T;
	for(int k=1; k<= T; k++){
		fin >> nVines;
		for(int i=0;i<nVines;i++){
			fin >> dist[i];
			fin >> len[i];
			lowest[i] = -1;
		}
		fin >> D;
		//fout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		//fout.precision(6);
		lowest[0] = dist[0];
		for(int i=1;i<nVines;i++){
			for(int j=0;j<i;j++){
				if(lowest[j] + dist[j] >= dist[i]){
					lowest[i] = max(lowest[i],min(dist[i] - dist[j],len[i]));
				}
			}
		}
		bool reach = false;
		for(int i=0;i<nVines;i++){
			reach = reach || (D-dist[i] <= lowest[i]);
		}
		if(reach)
			fout << "Case #" << k << ": " << "YES" << endl;
		else
			fout << "Case #" << k << ": " << "NO" << endl;
	}
}