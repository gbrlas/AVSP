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

double minT=0;

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>C>>F>>X;
        minT = 0.0;
        
        int n=0;
        while(X/(n*F+2.0)>C/(n*F+2.0)+X/((n+1)*F+2.0)){
            minT += C/(n*F+2.0);
            n++;
        }
        minT += X/(n*F+2.0);
        
        printf("Case #%d: %.7f\n", i+1, minT);
    }
}
