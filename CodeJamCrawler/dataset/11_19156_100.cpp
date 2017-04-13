/* 
 * File:   main.cpp
 * Author: nraprolu
 *
 * Created on May 4, 2011, 9:45 AM
 */

#include <cstdlib>
#include <iostream>

//stl containers
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <climits>

#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>

#define rep(i,n) for(long long i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) cout<<"Case #"<<i<<": ";
using namespace std;

/*
 * 
 */

int main(){
    long long T,n;
    cin>>T;
    long long pcount;
    pcount=0;
    while (T--){
        pcount++;
        cin>>n;
        long long sum=0;
        long long xsum=0;
        long long minnum=INT_MAX;
        long long currnum;
        rep(i,n){
            cin>>currnum;
            sum+=currnum;
            xsum=xsum^currnum;
            minnum=min(minnum,currnum);
            
        }
        gprint(pcount);
        
        if(!xsum){
        cout<<sum-minnum<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}