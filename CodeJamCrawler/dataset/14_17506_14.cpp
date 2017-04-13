#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>  //for C++
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <sstream>
//#include <string> for C

using namespace std;

double C, F, X;

double minT=1000000.0;

double findTime(int n, double C, double F, double X){
    double sum=0.0;
    for(int i=1; i<=n; i++){
        sum+=C/((i-1)*F+2.0);
    }

    return  X/(n*F+2.0)+sum;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>C>>F>>X;
        int n=0;
        minT = 1000000.0;
//        while(n*F+2.0<=X+2.0){
//            double time = findTime(n, C, F, X);
//            if(minT>time){
//                minT = time;
//            }
//            n++;
//        }

        double preT = findTime(n, C, F, X);
        while(true){
            minT = findTime(n, C, F, X);
            if(minT>preT)
                break;
            else
            preT = minT;
            n++;
        }

        printf("Case #%d: %.7f\n", i+1, preT);
    }
}
