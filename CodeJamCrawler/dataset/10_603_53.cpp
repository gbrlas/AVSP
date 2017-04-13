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

int getDivsior(int x,int y){
	if(y!=-1){
		while(x!=y){
			if(x>y)
				x-=y;
			else
				y-=x;
		}
	}
	return x;
}

int main(void){
	int i,j,k;
	char * inName="B-small-attempt1.in";
	char * outName="small.out";
	ifstream in(inName);
	ofstream out(outName);
	if(!in){
		cout<<"Can not open input file"<<endl;
	}
	
	if(!out){
		cout<<"Can not open output file"<<endl;
	}


	int C;
	in>>C;
	vector<int>w;
	for(i=0;i<C;i++){
		int N;
		in>>N;
		int temp=0;
		w.clear();
		for(j=0;j<N;j++){
			in>>temp;
			w.push_back(temp);
		}
		sort(w.begin(),w.end());
		int div=-1;
		vector<int>::iterator iter=w.begin();
		vector<int>::iterator end=w.end();
		if(w.size()==1){
			div=*iter;
		}else{
			int local=0;
			for(;iter+1!=end;iter++){
				local=*(iter+1)-*iter;
				if(local){
					div=getDivsior(local,div);
				}
			}
		}
		iter=w.begin();
		int res=*iter%div;
		if(res){
			GOUT(i+1)<<div-res<<endl;
		}else{
			GOUT(i+1)<<0<<endl;
		}

	}

	out.flush();
	out.close();
	in.close();
	return 0;
}