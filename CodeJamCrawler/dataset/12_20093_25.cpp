/*
 * Author: GhostBoyZone
 * Created Time:  2012/4/14 9:32:54
 * File Name: t1.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int main() {
    int T ; 
    scanf("%d\n",&T);
    string tem = "yhesocvxduiglbkrztnwjpfmaq";
    freopen("test.out","w",stdout);
    for(int i = 0 ; i < T ; i++){
        string tmp ; 
        getline(cin,tmp);
        int len = tmp.length();
        for(int j = 0 ; j < len ; j++){
            if(tmp[j] >= 'a' && tmp[j] <= 'z'){
                tmp[j] = tem[(tmp[j]-'a')];
            }
        }
        cout<<"Case #"<<i+1<<": "<<tmp<<endl;
    }
    return 0;
}

