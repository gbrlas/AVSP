#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int qq=1; qq<=T; ++qq) {
        int H, W, M;
        cin >> H >> W >> M;

        cout << "Case #" << qq << ":\n";
        char c[100][100];
        memset(c,'.',sizeof(c));

        c[0][0] = 'c';
        bool good=0;
        int m = M;

        bool flip = (H > W);
        if(flip) {
            swap(H, W);
        }

        for(int i=0; i<H; ++i) c[i][W] = 0;

        if(M==0){good=1;}
        else if (H==1 || W==1 || M==H*W-1) {
            for(int i=H-1; i>=0; --i) {
                for(int j=W-1; j>=0; --j) {
                    c[i][j] = '*';
                    --m;
                    if(m==0) break;
                }
                if(m==0) break;
            }
            good=1;
        }
        else if (H==2) {
            for(int j=W-1; j>=0; --j) {
                for(int i=H-1; i>=0; --i) {
                    c[i][j] = '*';
                    --m;
                    if(m==0) break;
                }
                if(m==0) break;
            }
            good=(M<=H*W-4 && M%2==0);
        }
        else if (H==3) {
            for(int j=W-1; j>=0; --j) {
                if(m >= 3) for(int i=0; i<H; ++i){ c[i][j] = '*'; --m; }
            }
            int mm = m;
            for(int Q=0; Q<mm; ++Q){
                for(int j=W-1; j>=0; --j) {
                    if(c[2][j] == '.'){
                        c[2][j] = '*';
                        --m;
                        break;
                    }
                }
            }
            good=1;

            if(M>=H*W-3 || M==H*W-5 || M==H*W-7) good=0;
        }
        else {
            int cl=H-1;
            for(int i=H-1; i>=4; --i) {
                if(m < W) break;
                --cl;
                for(int j=0; j<W; ++j) {
                    c[i][j] = '*';
                    --m;
                }
            }

            if(m <= W) {
                for(int j=W-1; j>=0; --j) {
                    if(m==0) break;
                    if(m==1 && j==1) c[cl-1][W-1] = '*';
                    else c[cl][j] = '*';
                    --m;
                }
                good=1;
            }
            else{
                for(int i=0; i<W; ++i){
                    --m; c[3][i] = '*'; }
            for(int j=W-1; j>=0; --j) {
                if(m >= 3) for(int i=0; i<3; ++i){ c[i][j] = '*'; --m; }
            }
            int mm = m;
            for(int Q=0; Q<mm; ++Q){
                for(int j=W-1; j>=0; --j) {
                    if(c[2][j] == '.'){
                        c[2][j] = '*';
                        --m;
                        break;
                    }
                }
            }
            good=1;

            if(M>=H*W-3 || M==H*W-5 || M==H*W-7) good=0;
            }
        }

        //if(m!=0) good=0;
//good=1;
        if(good) {
            if(flip) {
                for(int j=0; j<W; ++j) {
                    for(int i=0; i<H; ++i){
                        cout << c[i][j];
                    }
                    cout << '\n';
                }
            }
            else{
                for(int i=0; i<H; ++i) {
                    cout << c[i] << '\n';
                }
            }
        }
        else cout << "Impossible\n";
    }
    return 0;
}
