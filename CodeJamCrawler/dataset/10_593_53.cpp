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
	char * inName="A-small-attempt2.in";
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
	for(i=0;i<T;i++){
		int K;
		long long N;
		long long res;
		in>>N>>K;
		long long num=1<<N;
		res=num-1;
		if(K%num==res){
			GOUT(i+1)<<"ON"<<endl;
		}else{
			GOUT(i+1)<<"OFF"<<endl;
		}
	}
	
	out.flush();
	out.close();
	in.close();
	return 0;
}