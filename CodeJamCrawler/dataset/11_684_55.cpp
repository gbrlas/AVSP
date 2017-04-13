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

void fmain(){
     int i,j,k,m,n;
     GCASE(C);
     map<string, char> cMap;
     string temp;
     REP(i,C){
         in>>temp;
         if(temp.size() != 3){
            cout<<"Change input error"<<endl;
            system("pause");       
         }
         string key = "";
         key += temp[0];
         key += temp[1];   
         cMap[key] = temp[2];
         key = "";
         key += temp[1];
         key += temp[0];
         cMap[key] = temp[2];
     }

     map<char, string> dMap;
     GCASE(D);
     REP(i,D){
        in>>temp;
        if(temp.size() != 2){
            cout<<"Delete input Error"<<endl;
            system("pause");       
        }      
        dMap[temp[0]] += temp[1];
        dMap[temp[1]] += temp[0];
     }
     GCASE(N);
     string res;
     char op; bool combined = false;
     REP(i,N){
        in>>op;
        res += op;
        combined = false;
        if(res.length() > 1){ //change
            string cmd = res.substr(res.length() - 2 , 2);
            if(cMap.count(cmd)){
                res = res.substr(0, res.length() - 2) + cMap[cmd];
            }
        }  
        if(res.length() > 1 && !combined){
            op = res[res.length() - 1];
            if(dMap.count(op)){ //delete
                int index = res.find_last_of(dMap[op]);
                if(index != -1){
//                    res.erase(index, res.length() - index);    
                    res = "";
                }
            }
        }
     }
     string outStr = "[";
     REP(i, res.length()){
        outStr = outStr + res[i] + ", ";  
     }
     if(' ' == outStr[outStr.length() -1]){
        outStr = outStr.substr(0, outStr.length() - 2);
     }
     outStr += "]";
     gout<<outStr.c_str()<<endl;
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
