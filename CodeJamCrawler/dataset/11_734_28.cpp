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
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;


int case_number = 0;
#define gout case_number++,  GOUT(case_number)
#define GOUT(i) out<<"Case #"<<i<<": "
#define GCASE(i) int i; in>>i;
#define REP(i,a) for(i=0;i<a;++i)
#define REP2(i,n,m) for(i=n;i<m;++i)
#define MP(X,Y) make_pair(X,Y)
typedef long long int64;
typedef unsigned long long uint64;


char * inName  = "gcj.in";
char * outName = "gcj.out";
ifstream in(inName);
ofstream out(outName);

int64 gcd(int64 a, int64 b){
   return b ? gcd(b, a % b) : a;
}

int64 lcm(int64 a, int64 b){
    return a * b / gcd(a, b);
}

void fmain(){
    int n, l, h,i,k, j;
    int64  key;
    in>>n>>l>>h;
    vector<int64> keys;
    REP(i, n){
        in>>key;
        keys.push_back(key);
    }
    bool founded = false;
    for(int i = l; i<=h ; i++){
        founded = true;
        REP(j, n){
            if(i % keys[j] != 0
                && keys[j] % i != 0){
                founded = false;
                break ;
            }
        }    
        if(founded){
            gout<<i<<endl;   
            return; 
        }
    } 
    gout<<"NO"<<endl;
    
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
