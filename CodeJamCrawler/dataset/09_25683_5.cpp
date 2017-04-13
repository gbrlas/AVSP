/* 
 * File:   code.cpp
 * Author: dzaric
 *
 */

#include <cmath>
#include <cstdlib>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;

struct F{
    double x,y,r;
   
};

double solve(vector<F> fl){
    double min=999999999;
    pii minp;
    for(int i=0;i<fl.size()-1;i++){
        for(int j=i+1;j<fl.size();j++){
            double d=fl[i].r+fl[j].r+sqrt(pow((fl[i].x-fl[j].x),2)+pow(fl[i].y-fl[j].y,2));
            if(d<min){
                min=d;
                minp=pii(i,j);
            }            
        }
    }

    for(int i=0;i<fl.size();i++){
        if(minp.first!=i&&minp.second!=i){
            return max(min/2,fl[i].r);
        }
    }


}


int main(int argc, char** argv) {

    int tcases;
    cin>>tcases;

    for(int tcase=1;tcase<=tcases;tcase++){
        int n;
        cin>>n;
        vector<F> fl;
        for(int i=0;i<n;i++){
            F t;
            cin>>t.x>>t.y>>t.r;
            fl.push_back(t);
        }

        double sol;
        if(n==1){
            sol=fl[0].r;
        }
        if(n==2){
            sol=max(fl[0].r,fl[1].r);
        }
        if(n==3){
            sol=solve(fl);
        }
        cout<<"Case #"<<tcase<<": "<<sol<<endl;

    }

    return (EXIT_SUCCESS);
}

