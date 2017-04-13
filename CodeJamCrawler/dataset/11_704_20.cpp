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
typedef long long int64;
typedef unsigned long long uint64;


char * inName  = "gcj.in";
char * outName = "gcj.out";
ifstream in(inName);
ofstream out(outName);

void fmain(){
     int i, n;
     in>>n;
     vector<string> comps;
     vector<double> wp, owp, oowp;
     string temp;
     REP(i, n){
         in>>temp;
         comps.push_back(temp);   
     }
     REP(i, n){
        int win = 0, lose = 0, j = 0, len = 0;
        temp = comps[i];
        len = temp.length();
        REP(j, len){
            if(temp[j] == '1'){
                win ++;
            } else if(temp[j] == '0'){
                lose++;    
            }
        }
        wp.push_back(win / (double)(win + lose));
     }
     REP(i, n){
         int count = 0, len = 0, j = 0;
         double sum = 0;
         temp = comps[i];
         len = temp.length();
         REP(j, len){
            if(temp[j] != '.'){
                string str = comps[j];
                str[i] = '.';
                int k= 0, slen = str.length(), scount =0, swin = 0, slose = 0;
                REP(k,slen){
                    if(str[k] == '1'){
                        swin ++;
                    }  else if(str[k] == '0'){
                        slose++;    
                    }
                }
                sum += (swin/(double)(swin + slose));
                count ++;
            }    
         }
         owp.push_back(sum / count);
     }
     REP(i, n){
         int count = 0, len = 0, j = 0;
         double sum = 0;
         temp = comps[i];
         len = temp.length();
         REP(j, len){
            if(temp[j] != '.'){
               sum += owp[j];
               count ++;
            }    
         }
         oowp.push_back(sum / count);
     }
     double score = 0;
     gout<<endl;
     REP(i,n){
        score = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
        out<<score<<endl;
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
