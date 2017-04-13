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
    int T;
    cin>>T;
    int n,k,num;
    int pcount=0;
    while(T--){
        cin>>n;
        num=0;
        rep(i,n){
            cin>>k;
           if(k!=i+1){
               num++;
           } 
        }
        pcount++;
        gprint(pcount);
        cout<<num<<".000000"<<endl;
    }
}