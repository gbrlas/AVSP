#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

bool isPossible(int** lawn,int n, int m, int x, int y);

int main(int argc, const char * argv[])
{
    int nbCases;
    
    
    cin >> nbCases;
    
    for (int currentCase=1; currentCase<=nbCases; ++currentCase) {
        int n=0;
        int m=0;
        
        //load lawn size
        cin >> n >> m;
        
        //init array && load lawn pattern
        int ** lawn = new int*[n];
        for (int x=0; x<n; ++x) {
            lawn[x] = new int[m];
            
            for (int y=0; y<m; ++y) {
                cin >> lawn[x][y];
            }
        }
        
        //check if pattern possible. if a square is shorter than any edge, it's impossible
        bool patternPossible=true;
        for (int x=0; x<n && patternPossible; ++x) {
            for (int y=0; y<m && patternPossible; ++y) {
                patternPossible=isPossible(lawn, n, m, x, y);
            }
        }
        
        if (patternPossible )
            cout << "Case #" << currentCase << ": YES"<< endl;
        else
            cout << "Case #" << currentCase << ": NO" << endl;
        
        for (int x=0; x<n; ++x) {
            delete[] lawn[x];
            
        }
        delete[] lawn;
    }
    
}

bool isPossible(int** lawn,int n, int m, int x, int y)
{
    bool patternPossible=true;
    
    for (int i=0; i<n && patternPossible; ++i) {
        if(lawn[i][y]>lawn[x][y])
            patternPossible=false;
    }
    if(!patternPossible){
        patternPossible=true;
        for (int i=0; i<m && patternPossible; ++i) {
            if(lawn[x][i]>lawn[x][y])
                patternPossible=false;
        }
    }
    return patternPossible;
    
}
