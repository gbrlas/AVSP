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

#define rep(i,n) for(int i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) cout<<"Case #"<<i<<": ";
using namespace std;

/*
 * 
 */

int main(){
    int T,n;
    cin>>T;
    int pcount;
    pcount=0;
    while (T--){
        pcount++;
        cin>>n;
        int sum=0;
        int xsum=0;
        int minnum=INT_MAX;
        int currnum;
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