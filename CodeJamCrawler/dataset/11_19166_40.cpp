#include <cstdlib>
#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <fstream>
#include <climits>

#define rep(i,n) for(int i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) fout<<"Case #"<<i<<": ";
#define init(T) int T;fin>>T; rep(i,T)
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b 
using namespace std;


ifstream fin;
ofstream fout;


string *p;

int main(int argc, char** argv) {

    fin.open("in.txt",ifstream::in);
    fout.open("out.txt");
    
    init(T){
        gprint(i+1);
        fout<<endl;
        
        int m,n;
        fin>>m>>n;
        string s;
        p=new string[m];
        rep(j,m){
           fin>>p[j]; 
        }
        bool flag=true;
        rep(j,m){
            rep(k,n){
                if(p[j][k]=='#'){
                    if(j!=m-1 && k!=n-1&& p[j+1][k]=='#' && p[j][k+1]=='#' && p[j+1][k+1]=='#' ){
                        p[j][k]='/'; p[j+1][k]='\\' ; p[j][k+1]='\\' ; p[j+1][k+1]='/';
                    }
                    else{
                        flag=false;
                    }
                }
            }
        }
        
        if(flag){
            rep(j,m){
                fout<<p[j]<<endl;
            }
        }
        else{
            fout<<"Impossible"<<endl;
        }
        
    }
   



    fin.close();
    fout.close();
    return 0;
}
