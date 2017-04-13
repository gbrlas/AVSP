//
//  QualifA.cpp
//  CodeJam2013
//
//  Created by Eric Prévost-Dansereau on 2013-04-12.
//  Copyright (c) 2013 Eric Prévost-Dansereau. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

char lineComplete(char** board,int x, int y,bool *isComplete)
{
    char winner='.';
    char currentPlayer='.';
    
    
    if (y==0) {
        //top line, look for vertical
        int line=0;
        for (line=0; line<4; ++line) {
            if (board[x][line]=='.' ) {
                *isComplete=false;
                break;
            }
            else if (currentPlayer=='.' && board[x][line]!='T')
                currentPlayer=board[x][line];
            else if (currentPlayer != board[x][line] && board[x][line]!='T') {
                break;
            }
        }
        if(line==4)
        {
            winner=currentPlayer;
        }
    }
    if (x==0 && winner=='.') {
        //first column, look for horizontal
        int column=0;
        for (column=0; column<4; ++column) {
            if (board[column][y]=='.' ) {
                *isComplete=false;
                break;
            }
            else if (currentPlayer=='.' && board[column][y]!='T')
                currentPlayer=board[column][y];
            else if (currentPlayer != board[column][y] && board[column][y]!='T') {
                break;
            }
        }
        if(column==4)
        {
            winner=currentPlayer;
        }
    }
    if (y==0 && winner=='.' && (x==0 || x==3)) {
        //Check for diagonal if one of top corners
        
        int incrementX=1;
        if (x==3)
            incrementX=-1;
        
        
        int column=0;
        int line=0;
        for (line=0,column=x; line<4; ++line,column+=incrementX) {
            if (board[column][line]=='.' ) {
                *isComplete=false;
                break;
            }
            else if (currentPlayer=='.' && board[column][line]!='T')
                currentPlayer=board[column][line];
            else if (currentPlayer != board[column][line] && board[column][line]!='T') {
                break;
            }
        }
        if(line==4)
        {
            winner=currentPlayer;
        }
    }
    
    return winner;
}

int main(int argc, const char * argv[])
{
    int nbCases;
    char** board;
    
    board= new char*[4];
    for(int i=0;i<4;++i){
        board[i]= new char[5];
    }
    ifstream file;

    //file.open("/Users/eric/Documents/Xcode/CodeJam2013/QualifA/example.txt");
    cin >> nbCases;
    
    for (int currentCase=1; currentCase<=nbCases; ++currentCase) {
        
        //load board for current case
        for (int i=0; i<4; ++i) {
            cin >> board[i];
        }
        
        bool isComplete=true;
        char winner='.';
        
        for (int i=0; i<4 && winner=='.'; ++i) {
            winner = lineComplete(board, i, 0, &isComplete);
            if (winner =='.') {
                winner = lineComplete(board, 0, i, &isComplete);
            }
        }
        
        if (winner!='.')
            cout << "Case #" << currentCase << ": "<< winner << " won" << endl;
        else if (isComplete)
            cout << "Case #" << currentCase << ": Draw" << endl;
        else
            cout << "Case #" << currentCase << ": Game has not completed" << endl;
    }
    
    for(int i=0;i<4;++i){
        delete[] board[i];
    }
    delete[] board;
    
    
    
}