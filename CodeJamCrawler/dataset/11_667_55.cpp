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
     GCASE(N);
     vector<int> org, blue;
     vector<char> seq;
     char op; int num;
     REP(i,N){
        in >>op>>num;
        seq.push_back(op);
        if(op == 'O'){
            org.push_back(num);    
        } else {
            blue.push_back(num);  
        }
     }
     int step = 0, optr = 1, bptr = 1, oPos = 0, bPos = 0, temp = 0;
     REP(i, seq.size()){
        if(seq[i] == 'O'){
            temp = abs(org[oPos] - optr) + 1;
            step += temp;
            if(bPos < blue.size()){
                if(abs(blue[bPos] - bptr) > temp){
                    if(blue[bPos] > bptr){
                        bptr += temp;    
                    } else {
                        bptr -= temp;    
                    } 
                } else {
                    bptr = blue[bPos];     
                }    
            }
            optr = org[oPos];
            oPos ++;
        } else{
            temp = abs(blue[bPos] - bptr) + 1;
            step += temp;
            if(oPos < org.size()){
              if(abs(org[oPos] - optr) > temp){
                    if(org[oPos] > optr){
                        optr += temp;    
                    }  else {
                        optr -= temp;    
                    }
                } else {
                    optr = org[oPos];     
                }    
            }
            bptr = blue[bPos];
            bPos ++;
        }      
     }
     gout<<step<<endl;
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
