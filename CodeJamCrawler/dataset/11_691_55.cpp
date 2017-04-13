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
int case_number = 0;
#define gout case_number++,  GOUT(case_number)


char * inName  = "gcj.in";
char * outName = "gcj.out";
ifstream in(inName);
ofstream out(outName);

int tMax = -1;
int tSum = 0;

int getMax(vector<int> & values, int index, int left, int right, int lsum, int rsum){
    if(index == values.size() - 1){
        int temp = left ^ values[index];
        if(temp == right && rsum != 0){
            tMax = max(tMax, rsum);
            tMax = max(tMax, lsum + values[index]);
        } 
        temp = right ^ values[index];
        if(temp == left && lsum != 0){
            tMax = max(tMax, rsum + values[index]);
            tMax = max(tMax, lsum);
        }
    } else {
        int temp = left ^ values[index];
        getMax(values, index + 1, temp, right, lsum + values[index], rsum);
        temp = right ^ values[index];
        getMax(values, index + 1, left, temp, lsum, rsum  + values[index]);
    }
}

void fmain(){
     int i,j,k,m,n;
     GCASE(N);
     int temp;
     tMax = -1;
     vector<int> values;
     tSum = 0;
     REP(i,N){
        in>>temp;
        tSum += temp;
        values.push_back(temp);
     }
     getMax(values, 0, 0, 0, 0, 0);
     if(-1 == tMax){
        gout<<"NO"<<endl;       
     }else{
        gout<<tMax<<endl;       
     }
}

int main(void){
	if(!in){
		cout<<"Can not open input file"<<endl;
		system("pause");
	}
	if(!out){
		cout<<"Can not open output file"<<endl;
		system("pause");
	}

        GCASE(T);
	int i;
        REP(i,T)   fmain();
	out.flush();
	out.close();
	in.close();
	return 0;
}
