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
#define rrep(i,low,high) for(int i=low;i<=high;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) fout<<"Case #"<<i<<": ";
#define init(T) int T;fin>>T; rep(i,T)
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b 
using namespace std;


ifstream fin;
ofstream fout;




int main(int argc, char** argv) {

    fin.open("in.txt",ifstream::in);
    fout.open("out.txt");
    int N,L,H;
    int * p;
    init(T){
        gprint(i+1);
        bool flag=false;
        fin>>N>>L>>H;
        p= new int[N];
        rep(j,N){
            fin>>p[j];
            //cout<<"here"<<endl;
        }
        rrep(j,L,H){
            bool flag2=true;
           
            rep(k,N){
                if(!(p[k]%j==0 || j%p[k]==0)){
                    flag2=false;
                    break;
                }
                
            }
            if(flag2){
                fout<<j<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            fout<<"NO"<<endl;
        }
        
    }
   



    fin.close();
    fout.close();
    return 0;
}
