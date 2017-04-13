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

#define rep(i,n) for(long long i=0;i<n;i++)
#define rrep(i,low,high) for(long long i=low;i<=high;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) fout<<"Case #"<<i<<": ";
#define init(T) long long T;fin>>T; rep(pcount,T) 
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b 
using namespace std;


ifstream fin;
ofstream fout, dout;


struct cs_ {
    double b;
    double e;
    double w;
};


vector<cs_> cs;

double x, s, r, t, n,drem_;

bool sf(cs_ a,cs_ b){
    return a.w<b.w;
}

double process() {
    sort(cs.begin(),cs.end(),sf);
    double time=0;
    double runleft=t;
    
    {
            double tmp=(drem_)/(r);
            if(tmp>runleft){
                tmp=runleft+(((drem_-runleft*(r)))/s);
                runleft=0;
                 
            }
            else{
                runleft-=tmp;
            }
            time+=tmp;
    }
    irep(it,cs){
        if(runleft>0){
            double tmp=(it->e-it->b)/(it->w+r);
            if(tmp>runleft){
                tmp=runleft+((it->e-it->b)-runleft*(it->w+r))/(it->w+s);
                 runleft=0;   
            }
            else{
                runleft=runleft-tmp;
                
            }
            time+=tmp;
            
             
        }
        else{
            time+=(it->e-it->b)/(it->w+s);
        }
    }
    
    
    
    return time;
    
}

int main(int argc, char** argv) {

    fin.open("in.txt", ifstream::in);
    fout.open("out.txt");

    init(T) {
        gprint(pcount + 1);
        fin >> x >> s >> r >> t >> n;
        drem_=x;
        rep(i, n) {
            
          cs_ temp;            
          fin >> temp.b >> temp.e >> temp.w;
          drem_+=(temp.b - temp.e);
          cs.push_back(temp);
          
        }
        fout<<setprecision(12)<<process()<<endl;
        cs.clear();
        

    }




    fin.close();
    fout.close();
    return 0;
}
