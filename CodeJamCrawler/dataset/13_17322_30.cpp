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

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define foreach(itr, cont) for (typeof(cont.begin()) itr = cont.begin(); itr != cont.end(); itr++)

using namespace std;

char Board[16];

bool checkDraw(){
    int i;
    REP(i, 16){
        if(Board[i] == '.')
            return false;
    }
    return true;
}

bool checkXO(char C){
    int i;
    //check row
    REP(i,4){
        int j;
        bool win = true;
        REP(j,4){
            if(Board[4*i+j] != C && Board[4*i+j] != 'T'){
                win = false;
                break;
            }
        }
        if(win)
            return true;
    }
    
    //check colume
    REP(i,4){
        int j;
        bool win = true;
        REP(j,4){
            if(Board[i+4*j] != C && Board[i+4*j] != 'T'){
                win = false;
                break;
            }
        }
        if(win)
            return true;
    }
    
    //check diagonal
    bool win = true;
    REP(i,4){
        if(Board[4*i+i] != C && Board[4*i+i] != 'T'){
            win = false;
            break;
        }
    }
    if(win)
        return true;
    
    win = true;
    REP(i,4){
        if(Board[4*i+(3-i)] != C && Board[4*i+(3-i)] != 'T'){
            win = false;
            break;
        }
    }
    if(win)
        return true;
    
    return false;
}

int main()
{
    int T, i, j;
    cin>>T;
    REP(i,T){
        cout<<"Case #"<<i+1<<": ";
        REP(j,16){
            cin>>Board[j];
        }
        
        if(checkXO('X'))
            cout<<"X won";
        else if(checkXO('O'))
            cout<<"O won";
        else if(checkDraw())
            cout<<"Draw";
        else
            cout<<"Game has not completed";
        
        cout<<endl;
    }
}
