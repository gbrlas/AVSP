#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

#define mkstr(a) # a
#define in_between(a) mkstr(a)

#define PROBLEM A
#define SMALL 0
#define ATTEMPT -1

#if (SMALL)
    #define SIZE small
#else
    #define SIZE large
#endif

int main() {
    
    //freopen(in_between(PROBLEM) "-" in_between(SIZE) "-attempt" in_between(ATTEMPT) ".in", "r", stdin);
    freopen(in_between(PROBLEM) "-" in_between(SIZE) ".in", "r", stdin);
    freopen(in_between(PROBLEM) "-" in_between(SIZE) ".out", "w", stdout);
 
    long long n, N, K;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        cin >> N >> K;
        string text;
        if ((K & ((1<<N)-1)) == ((1<<N)-1))
        text = "ON";
        else text="OFF";
        printf("Case #%d: %s\n", i+1, text.c_str());
    }
 
    return 0;   
}
