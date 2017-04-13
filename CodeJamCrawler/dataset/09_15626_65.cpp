#include<iostream>
#include<algorithm>
#include<fstream>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

int p,q;
int ar[100];
int compute(){
	bool used[100];
	memset(used, 0, sizeof(used));
	int rtn=0;
	for(int i=0; i<q; ++i){
		int r=ar[i]-1;
		used[r]=true;
		for(int j=r+1; j<p; ++j){
			if(used[j]){
				break;
			}else
				++rtn;
		}
		for(int j=r-1; j>=0; --j){
			if(used[j]){
				break;
			}
			else
				++rtn;
		}
	}
	return rtn;
}

int main(){
	ifstream fin("C.in");
	ofstream fout("C.out");
	int ca;
	fin>>ca;
	for(int cas=1; cas<=ca; ++cas){
		fin>>p>>q;
		for(int i=0; i<q; ++i)
			fin>>ar[i];
		int rtn=(1<<29);
		do{
			int c=compute();
			rtn=MIN(rtn,c);
		}while(next_permutation(ar, ar+q));
		fout<<"Case #"<<cas<<": "<<rtn<<endl;	
	}
}
