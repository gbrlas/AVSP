//
//  A.cpp
//  BaseProj
//
//  Created by Pratyush Verma on 13/04/13.
//  Copyright (c) 2013 Pratyush Verma. All rights reserved.
//

#include <iostream>
using namespace std;
string grid[4];
bool checkH(char ch, int no) {
    int c = 0;
    for (int i = 0; i < 4; ++i) {
        if(grid[no][i] == ch || grid[no][i] == 'T') {
            c++;
        }
    }
    return c == 4;
}
bool checkV(char ch, int no) {
    int c = 0;
    for (int i = 0; i < 4; ++i) {
        if(grid[i][no] == ch || grid[i][no] == 'T') {
            c++;
        }
    }
    return c == 4;
}
bool checkD(char ch, int no) {
    int c = 0;
    if (no == 1) {
        for (int i = 0; i < 4; ++i) {
            if(grid[i][i] == ch || grid[i][i] == 'T') {
                c++;
            }
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            if(grid[i][3-i] == ch || grid[i][3-i] == 'T') {
                c++;
            }
        }
    }
    
    return c == 4;
}
int main() {
    int test;
    cin>>test;
    string xwon = "X won";
    string owon = "O won";
    string draw = "Draw";
    string nc = "Game has not completed";
    
    for (int i = 0; i < test; ++i) {

        for(int j = 0; j < 4; ++j) {
            cin>>grid[j];
        }
        if(checkH('X', 0)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkH('X', 1)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkH('X', 2)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkH('X', 3)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkV('X', 0)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkV('X', 1)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkV('X', 2)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkV('X', 3)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkD('X', 1)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkD('X', -1)) {
            cout<<"Case #"<<i+1<<": "<<xwon<<endl;
        }
        else if(checkH('O', 0)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkH('O', 1)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkH('O', 2)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkH('O', 3)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkV('O', 0)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkV('O', 1)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkV('O', 2)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkV('O', 3)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkD('O', 1)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else if(checkD('O', -1)) {
            cout<<"Case #"<<i+1<<": "<<owon<<endl;
        }
        else {
            bool ncFlag = false;
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if(grid[j][k] == '.') {
                        ncFlag = true;
                    }
                }
            }
            if(ncFlag) {
                cout<<"Case #"<<i+1<<": "<<nc<<endl;
            } else {
                cout<<"Case #"<<i+1<<": "<<draw<<endl;
            }
        }
    }
    return 0;
}
