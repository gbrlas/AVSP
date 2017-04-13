//
//  A.cpp
//  BaseProj
//
//  Created by Pratyush Verma on 04/05/13.
//  Copyright (c) 2013 Pratyush Verma. All rights reserved.
//

#include<iostream>
#include<string>
#include<map>
using namespace std;
map<pair<int, int>, bool> m;
bool func(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
        return true;
    }
    return false;
}
int main()
{
    int test;
    cin>>test;
    for (int i = 0; i < test; ++i) {
        string s;
        cin>>s;
        int n;
        cin>>n;
        int res = 0;
        int prev = -1;
        int k;
        for (int j = 0; j <= s.length() - n; ++j) {
            for (k = 0; k < n; k++) {
                if(!func(s[j + k])) {
                    continue;
                }
                break;
            }
            if(k == n) {
                if(j == 0) {
                    res = s.length() - n + 1;
                } else if(prev == -1) {
                    res += (j + 1) * (s.length() - (j + n) + 1);
                    if(prev == 0) {
                        res--;
                    }
                }
                else {
                    res += (j -  prev) * (s.length() - (j + n) + 1);
                }
                prev = j;
            }
                   
        }
        cout<<"Case #"<<(i+1)<<": "<<res<<endl;
    }
    return 0;
}
