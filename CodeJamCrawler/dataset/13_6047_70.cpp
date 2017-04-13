//
//  B.cpp
//  BaseProj
//
//  Created by Pratyush Verma on 13/04/13.
//  Copyright (c) 2013 Pratyush Verma. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int grid[101][101];
int main() {
    int test;
    cin>>test;
    for (int i = 0; i < test; ++i) {
        int n,m;
        cin>>n>>m;
        memset(grid, 0, sizeof(grid));
        for (int nn = 0; nn < n; ++nn) {
            for (int mm = 0; mm < m; ++mm) {
                cin>>grid[nn][mm];
                grid[nn][m] = max(grid[nn][mm], grid[nn][m]);
                grid[n][mm] = max(grid[nn][mm], grid[n][mm]);
            }
        }
        //pick horiz check verti
        bool poss = true;
        for (int nn = 0; nn < n; ++nn) {
            for (int mm = 0; mm < m; ++mm) {
                if(grid[nn][mm] < grid[nn][m] && grid[nn][mm] != grid[n][mm]) {
                    poss = false;
                }
            }
        }
        if(poss) {
            cout<<"Case #"<<i+1<<": YES"<<endl;
        } else {
            cout<<"Case #"<<i+1<<": NO"<<endl;
        }

    }
    return 0;
}