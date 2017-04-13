#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <utility>
#include <map>
#include <bitset>
#include <cstdio>

using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int n,d,g,t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d>>g;
        cout<<"Case #"<<i+1<<": ";
        if((d<100 && g==100) || (d>0 && g==0))
            cout<<"Broken"<<endl;
        else{
            bool found = false;
            for(int j=n;j>0;j--){
                if((j*d)%100==0){
                    found = true;
                    break;
                }
            }
            if(found)
                cout<<"Possible"<<endl;
            else
                cout<<"Broken"<<endl;
        }
    }
    return 0;
}
