#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

template<class T> inline T sqr(T x) {return x*x;}	//square
#define FOR(i,a,b) for(int i=(a);i<(b);i++)			//for loop
#define REP(i,n) FOR(i,0,n)							//repeat
#define SORT(n) sort((n).begin(),(n).end());		//sort

//デバッグ用
#define dump(x) cout << #x << ":" << (x) << " (L:" << __LINE__ << ")" << endl;

bool column_search(char data[4][5], char mark, bool* complete)
{
    bool flag = true;
    bool dot = false;

    for(int i=0; i<4; i++)
    {
        flag = true; dot = false;
        for(int j=0; j<4; j++)
        {
            if(data[i][j] == '.')   dot = true;
            if(flag && (data[i][j] != mark && data[i][j] != 'T'))
            {
                flag = false;
            }
        }
        if(dot)    *complete = false;
        if(flag)    return true;
    }

    return false;
}

bool row_search(char data[4][5], char mark, bool* complete)
{
    bool flag = true;
    bool dot = false;

    for(int i=0; i<4; i++)
    {
        flag = true; dot = false;
        for(int j=0; j<4; j++)
        {
            if(data[j][i] == '.')   dot = true;
            if(flag && (data[j][i] != mark && data[j][i] != 'T'))
            {
                flag = false;
            }
        }
        if(dot)    *complete = false;
        if(flag)    return true;
    }

    return false;
}

bool diag_search(char data[4][5], char mark, bool* complete)
{
    bool flag = true;
    bool dot = false;
    
    for(int i=0; i<4; i++)
    {
        if(data[i][i] == '.')   dot = true;
        if(flag && (data[i][i] != mark && data[i][i] != 'T'))
        {
            flag = false;
        }
    }
    if(dot)    *complete = false;
    if(flag)    return true;
   
    flag = true;    dot = false;
    for(int i=3; i>=0; i--)
    {
        if(data[3-i][i] == '.') dot = true;
        if(flag && (data[3-i][i] != mark && data[3-i][i] != 'T'))
        {
            flag = false;
        }
    }
    if(dot)    *complete = false;
    
    return flag;
}

int main(int argc, char* argv[])
{
    int loop;
    char data[4][5];
    bool x = false, o = false, complete = false;

    cin >> loop;

    for(int i=0; i<loop; i++)
    {
        complete = true;

        //data input
        for(int j=0; j<4; j++)  cin >> data[j];

        //is_complete

        //column search
        x = column_search(data, 'X', &complete);
        o = column_search(data, 'O', &complete);
        
        //row search
        if(!x)  x = row_search(data, 'X', &complete);
        if(!o)  o = row_search(data, 'O', &complete);

        //diagonal search
        if(!x)  x = diag_search(data, 'X', &complete);
        if(!o)  o = diag_search(data, 'O', &complete);
        
        //result
        cout << "Case #" << i+1 << ": ";
        if(x){
            cout << "X won";
        } else if(o) {
            cout << "O won";
        } else if(!complete)  {
            cout << "Game has not completed";
        } else {
            cout << "Draw";
        }
        cout << endl;

    }

    return 0;
}
