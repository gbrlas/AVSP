#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

int main() {
    int tc;
    string xw = "XXXX";
    string ow = "OOOO";
    
    scanf("%d", &tc);
    for(int t = 0; t < tc; ++t) {
        vector<string> vs;
        string s;
        bool adadot = false;
        bool xwin = false;
        bool owin = false;
        for(int i = 0; i < 4; ++i) {
            cin >> s;
            vs.push_back(s);
        }
        
        //T='X'
        int rt, ct;
        rt = ct = -1;
        for(int i = 0; i < 4; ++i)
            for(int j =0; j < 4; ++j) {
                if(vs[i][j] == 'T') {
                    rt = i;
                    ct = j;
                    vs[i][j] = 'X';
                }
                if(vs[i][j] == '.') {
                    adadot = true;
                }
            }
        
        //check won
        //check row
        for(int i = 0; i < 4; ++i){
            string temp = "";
            for (int j = 0; j < 4; ++j)
                temp += vs[i][j];
            if(temp == xw) {
                xwin = true;
            } else if(temp == ow) {
                owin = true;
            }
        }
        //check column
        for(int i = 0; i < 4; ++i){
            string temp = "";
            for (int j = 0; j < 4; ++j)
                temp += vs[j][i];
            if(temp == xw) {
                xwin = true;
            } else if(temp == ow) {
                owin = true;
            }
        }
        //check diag
        string lr = "";
        string rl = "";
        lr += vs[0][0]; lr += vs[1][1]; lr += vs[2][2]; lr += vs[3][3];
        rl += vs[0][3]; rl += vs[1][2]; rl += vs[2][1]; rl += vs[3][0];
        
        if(lr == xw || rl == xw) {
            xwin = true;
        } else if(lr == ow || rl == ow) {
            owin = true;
        }
        
        
        
        //T='O'
        if(rt!=-1) {
            vs[rt][ct]='O';
        }
        
        /*for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j)
                cout << vs[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << "RT = " << rt << endl;*/
        
        //check won
        //check row
        for(int i = 0; i < 4; ++i){
            string temp = "";
            for (int j = 0; j < 4; ++j)
                temp += vs[i][j];
            if(temp == xw) {
                xwin = true;
            } else if(temp == ow) {
                owin = true;
            }
        }
        //check column
        for(int i = 0; i < 4; ++i){
            string temp = "";
            for (int j = 0; j < 4; ++j)
                temp += vs[j][i];
            if(temp == xw) {
                xwin = true;
            } else if(temp == ow) {
                owin = true;
            }
        }
        //check diag
        lr = "";
        rl = "";
        lr += vs[0][0]; lr += vs[1][1]; lr += vs[2][2]; lr += vs[3][3];
        rl += vs[0][3]; rl += vs[1][2]; rl += vs[2][1]; rl += vs[3][0];
        
        //cout << "LR = " << lr << endl;
        //cout << "RL = " << rl << endl;
                
        if(lr == xw || rl == xw) {
            xwin = true;
        } else if(lr == ow || rl == ow) {
            owin = true;
        }
        
        printf("Case #%d: ", t+1);
        if(xwin) {
            printf("X won");
        } else if(owin) {
            printf("O won");
        } else if(adadot) {
            printf("Game has not completed");
        } else {
            printf("Draw");
        }
        printf("\n");
    }
    
    
    return 0;
}

