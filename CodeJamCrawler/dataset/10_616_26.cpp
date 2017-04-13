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
#define GCASE(i) int i; in>>i;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ipair;
#define MP(X,Y) make_pair(X,Y)
#define REP(i,a) for(i=0;i<a;++i)
#define REP2(i,n,m) for(i=n;i<m;++i)
#define FORE(it,a) for (typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define ALL(a) (a).begin(),(a).end()

int main(void){
    int i,j,k;
    char * inName="A-small-attempt0.in";
    char * outName="small.out";
    ifstream in(inName);
    ofstream out(outName);
    if(!in){
        cout<<"Can not open input file"<<endl;
    }
   
    if(!out){
        cout<<"Can not open output file"<<endl;
    }
   
	GCASE(T);
	map<string,int>list;
	REP(i,T){
		list.clear();
		list[""]++;
		int N,M;
		in>>N>>M;
		string str;
		REP(j,N){
			in>>str;
			int index=-1;
			int start=0;
			string temp;
			list[str]++;
			while((index=str.find('/',start))!=-1){
				temp=str.substr(0,index);
				list[temp]++;
				start=index+1;
			}
		}
		int count=0;
		REP(j,M){
			in>>str;
			int index=0;
			
			int start=0;
			string temp;
			while((index=str.find('/',start))!=-1){
				temp=str.substr(0,index);
				if(!list.count(temp)){
					list[temp]++;
					count++;
				}
				start=index+1;
			}
			if(!list.count(str)){
				list[str]++;
				count++;
			}
		}
		out<<"Case #"<<i+1<<": "<<count<<endl;
		
	}
   
   
    out.flush();
    out.close();
    in.close();
    return 0;
}