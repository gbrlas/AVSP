/*
 * Author: GhostBoyZone
 * Created Time:  2012/4/14 13:43:52
 * File Name: t3.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
int func(int n );
int str2num(string tmp);
bool jud(int k , int A , int B);
map<int,int> mp ;
int main() {
    int T ; 
    freopen("test3.out","w",stdout);
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i++){
        int tot = 0 ; 
        string A , B ; 
        cin>>A>>B ;
        int sta = str2num(A) ;
        int end = str2num(B) ;
        mp.clear();
        for(int j = sta ; j <= end ; j++){
            mp[j] = 0 ; 
        }
        //cout<<sta<<end<<endl;
        for(int j = sta ; j <= end ; j++){
            //cout<<"11";
            char sstr[100] ;
            memset(sstr,0 ,sizeof(sstr));
            //cout<<j<<endl;
            sprintf(sstr,"%d",j);
            //cout<<strlen(sstr)<<endl;
            //cout<<sstr<<endl;
            if(strlen(sstr) < 2) continue ;
            if(strlen(sstr) == 2){
                if(sstr[0] != sstr[1]){
                    //cout<<sstr<<endl;
                    string tmp1 = "" ;
                    string tmp2 = "" ;
                    tmp1 += sstr[0] ;
                    tmp1 += sstr[1] ;
                    tmp2 += sstr[1] ;
                    tmp2 += sstr[0] ;
                    int num1 = str2num(tmp1);
                    int num2 = str2num(tmp2);
                    //cout<<num1<<" "<<num2<<endl;
                    if(num1 != num2 && jud(num1,sta,end) && jud(num2,sta,end) && mp[num1]!=1 && mp[num2]!=1){
                        mp[num1] = 1 ;
                        mp[num2] = 1 ; 
                        tot++ ;
                    }
                }
            }
            if(strlen(sstr) == 3){
                string tmp1 = "" ;
                string tmp2 = "" ;
                string tmp3 = "" ;
                tmp1 += sstr[0];
                tmp1 += sstr[1];
                tmp1 += sstr[2];
                tmp2 += sstr[2];
                tmp2 += sstr[0];
                tmp2 += sstr[1];
                tmp3 += sstr[1];
                tmp3 += sstr[2];
                tmp3 += sstr[0];
                int num1 = str2num(tmp1);
                int num2 = str2num(tmp2);
                int num3 = str2num(tmp3);
                if(mp[num1] == 1 || mp[num2] == 1 || mp[num3] == 1)
                    continue ;
                else{
                    if(num1 == num2 || num1 == num3 || num2 == num3){
                        continue ;
                    }
                    else{
                        if(jud(num1,sta,end) && jud(num2,sta,end)){
                            tot++ ;
                        }
                        if(jud(num1,sta,end) && jud(num3,sta,end)){
                            tot++ ;
                        }
                        if(jud(num2,sta,end) && jud(num3,sta,end)){
                            tot++ ;
                        }
                        mp[num1] =1 ;
                        mp[num2] =1 ;
                        mp[num3] =1 ;
                    }
                }
            }
            if(strlen(sstr) == 4){
                if(sta <= 1)
                    tot++ ;
                if(sta <= 10)
                    tot++ ;
                if(sta <= 100)
                    tot++ ;
            }
        }
        cout<<"Case #"<<i+1<<": "<<tot<<endl;
        //break;
    }
    return 0;
}
int func(int n){
    if(n == 0) return 1 ;
    else return 10*func(n-1);
}
int str2num(string tmp){
    int len = tmp.length() ;
    int num = 0 ; 
    for(int i = 0 ; i < len ; i++){
        num += (tmp[i]-'0')*func(len-i-1);
    }
    return num ;
}
bool jud(int k , int A , int B){
    if(k >= A && k <= B) return true ;
    return false ;
}
