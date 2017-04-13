/* 
 * File:   p2.cpp
 * Author: snehasish
 *
 * Created on May 7, 2011, 11:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int T;
    cin>> T;
    for(int i=1;i<=T;i++){
        int N;
        cin >>N;
        int xorVal=0;
        int minVal=-1;
        unsigned long long int sum =0L;
        while(N--){
            int val;
            cin>>val;
            sum += (unsigned long long int)val;
            xorVal ^= val;
            if(minVal==-1 || minVal > val){
                minVal = val;
            }
        }
        cout<<"Case #"<<i<<": ";
        if(xorVal != 0){
            cout<<"NO"<<endl;
        }else{
            cout<<(sum - minVal)<<endl;
        }
    }
    return 0;
}

