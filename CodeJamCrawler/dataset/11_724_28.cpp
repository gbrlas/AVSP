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

void fmain(){
    int r,c, i, j;
    vector<string> keys;
    string str;
    in>>r>>c;
    REP(i, r){
       in>>str;
       keys.push_back(str);     
    }
    bool founded = true;
    REP(i,r - 1){
        str = keys[i];
        int len = str.length();
        REP(j, len - 1){
			str = keys[i];
            if(str[j] == '#'){
                if(keys[i][j] == '#' &&
                    keys[i][j] == '#' &&
                    keys[i + 1][j] == '#' &&
                    keys[i + 1][j + 1] == '#'){
                    keys[i][j] = keys[i + 1][j + 1] = '/';        
                    keys[i][j + 1] = keys[i + 1][j] = '\\';
                } else {
                    founded = false;
                    break;    
                }
            }
        }
        if(!founded){
            break ;
        }
    }
    if(founded){
        REP(i, r){
            if(keys[i][c-1] == '#'){
                founded = false;
                break;    
            }    
        }    
        REP(i, c){
            if(keys[r-1][i] == '#'){
                founded = false;
                break;    
            }
        }
    }
    if(founded){
        gout<<endl;
        REP(i,r){
            out<<keys[i].c_str()<<endl;    
        }
    } else {
        gout<<endl<<"Impossible"<<endl;    
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
