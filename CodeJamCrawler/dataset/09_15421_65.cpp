/*
ID: nilsmolin2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>

#define inf 99999

using namespace std;

ifstream fin ("5.in");
ofstream fout ("5.out");

int n, p, q;
int guy[10];
bool used[10];
int recur[10];
bool prison[101];

int depth;

int coins(int x) {
    if(used[x]) return inf;
  //  cout << "Removing " << guy[x];
    used[x] = 1;
    recur[depth] = x;
    depth++;
    prison[guy[x]] = 0;
    
    int needed;
    int left = 0;
    for(int i = 1; i < guy[x]; i++)
        if(!prison[i])
            left = i;
    int right = p+1;
    for(int i = p; i > guy[x]; i--)
        if(!prison[i])
            right = i;
    needed = (right-left)-2;
   // cout << " took " << needed << " coins." << endl;
   // system("PAUSE");
    
    
    if(depth == q) {
    //  cout << " ... Reached depth" << endl;
    //    system("PAUSE");
        prison[guy[x]] = 1;
        depth--;
        used[x] = 0;
        return needed;
    }
    int min = inf+1;
    for(int i = 0; i < q; i++) {
        int temp = coins(i);
        if(temp<min) min = temp;
    }
    prison[guy[x]] = 1;
    depth--;
    used[x] = 0;
    return needed+min;
}

int main() {
    fin >> n;
    for(int i = 0; i < n; i++) {
        
        fin >> p >> q;
        for(int i = 0; i < q; i++) fin >> guy[i];
        for(int i = 0; i < 10; i++) used[i] = false;
        for(int i = 0; i < 101; i++) prison[i] = true;
        
        depth = 0;
        int min = inf+1;
        for(int i = 0; i < q; i++) {
            int temp = coins(i);
            if(temp<min) min = temp;
        }
        fout << "Case #" << i+1 << ": " << min << "\n";
    }
    system("PAUSE");
    return 0;
}
