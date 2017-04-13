#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define ASIZE(arr,type) sizeof(arr)/sizeof(type)
#define GOUT(i) out<<"Case #"<<i<<": "

int main(void){
	int i,j,k;
	char * inName="C-small-attempt1.in";
	char * outName="small.out";
	ifstream in(inName);
	ofstream out(outName);
	if(!in){
		cout<<"Can not open input file"<<endl;
	}
	
	if(!out){
		cout<<"Can not open output file"<<endl;
	}


	int T;
	in>>T;
	vector<int>w;
	for(i=0;i<T;i++){
		int R,N,K;
		in>>R>>K>>N;
		w.clear();
		int sum=0;
		int temp=0;
		for(j=0;j<N;j++){
			in>>temp;
			w.push_back(temp);
		}
		vector<int>::iterator iter=w.begin();
		vector<int>::iterator end=w.end();
		for(j=0;j<R;j++){
			if(*iter>K){
				break;
			}
			int local=0;
			for(k=0;k<N;k++){
				int current=*iter;
				if(local+current<=K){
					local+=current;
					iter++;
					if(iter==end){
						iter=w.begin();
					}
				}else{
					break;
				}
			}
			sum+=local;
		}
		GOUT(i+1)<<sum<<endl;
	}
	out.flush();
	out.close();
	in.close();
	return 0;
}