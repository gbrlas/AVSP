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

#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <fstream>


#define rep(i,n) for(int i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) fout<<"Case #"<<i<<": ";
using namespace std;

/*
 * 
 */
ifstream fin;
ofstream fout;

float **mat;

float *WP;
float *OWP;
float *OOWP;
float *NP;
void allocate(int n) {
    mat = new float*[n];

    rep(i, n) {
        mat[i] = new float[n];
    }
}

void deallocate(int n) {

    rep(i, n) {
        delete[] mat[i];
    }
    delete[] mat;
}

float conv(char a) {
    if (a == '1') return 1;
    if (a == '0') return 0;
    if (a == '.') return 2;
}

float wins(int row, int n) {
    float count = 0;

    rep(i, n) {
        if (mat[row][i] == 1) {
            count++;
        }
    }
    return count;
}

float wins(int row, int buff, int n) {
    float count = 0;

    rep(i, n) {
        if (mat[row][i] == 1) {
            count++;
        }
    }
    if (mat[row][buff] == 1) {
        return count - 1;
    }
    return count;
}

float ops(int row,int n){
    float count=0;
    rep(i,n){
        if(mat[row][i]!=2){
            count++;
        }
    }
    return count;
}
int main(int argc, char** argv) {
    mat = NULL;
    fin.open("in.txt", ifstream::in);
    fout.open("out.txt");


    int T;
    cin >> T;
    int cmx=0;
    while (T--) {
        int n;
        string s;
        cin >> n;
        allocate(n);
        
        WP=new float[n];
        OWP=new float[n];
        OOWP=new float[n];
        NP=new float[n];
        rep(i, n) {
            cin >> s;

            rep(j, n) {
                mat[i][j] = conv(s[j]);
            }
        }
        rep(i,n){
            NP[i]=ops(i,n);
            WP[i]=wins(i,n)/NP[i];
            cout<<i<<" "<<WP[i]<<endl;
        }
        float sumWP;
        rep(i,n){
            sumWP=0;
            rep(j,n){
              if(mat[i][j]!=2){
                  sumWP+=wins(j,i,n)/(NP[j]-1);
              }  
            }
            OWP[i]=sumWP/NP[i];
            cout<<i<<" "<<OWP[i]<<endl;
            
        }
        rep(i,n){
            sumWP=0;
            rep(j,n){
              if(mat[i][j]!=2){
                  sumWP+=OWP[j];
              }  
            }
            OOWP[i]=sumWP/NP[i];
            cout<<i<<" "<<OOWP[i]<<endl;
            
        }
        cmx++;
        gprint(cmx);
        fout<<endl;
        rep(i,n){
            
            fout<<WP[i]*0.25 + OWP[i]*0.50 +OOWP[i]*0.25<<endl;
            
        }
        
    }



    fin.close();
    fout.close();
    return 0;
}