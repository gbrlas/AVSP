#include <iostream>
#include <queue>
using namespace std;
int main() {
    int T, N, Opos, Bpos, Odest, Bdest, Odir = 1, Bdir = 1;
    queue<char> q;
    bool bdone = false, odone = false;
    cin >> T;
    for(int k = 0; k < T; k++) {
        queue<int> qo;
        queue<int> qb;
        cin >> N;
        Opos = 1, Bpos = 1, Odest = 0, Bdest = 0, Odir = 1, Bdir = 1;
        char c;
        int in;
        for(int i = 0; i < N; i++) {
            cin >> c;
            cin >> in;
            q.push(c);
            if(c == 'O') qo.push(in);
            else qb.push(in);
        }
        int w = 0;
        if(!qo.empty()) Odest = qo.front();
        if(!qb.empty()) Bdest = qb.front();
        qo.pop();
        qb.pop();
        while(!q.empty()) {
            char c = q.front();
            if(Opos > Odest) Odir = -1;
            if(Bpos > Bdest) Bdir = -1;
            if(Opos < Odest) Odir = 1;
            if(Bpos < Bdest) Bdir = 1;
            if(c == 'O') {
                while(Opos != Odest) {
                    if(Bpos != Bdest) Bpos += Bdir;
                    Opos += Odir;
                    w++;
                }
                if(Bpos != Bdest) Bpos += Bdir;
                w++;
                Odest = qo.front();
                qo.pop();
            } else {
                while(Bpos != Bdest) {
                    if(Opos != Odest) Opos += Odir;
                    Bpos += Bdir;
                    w++;
                }
                if(Opos != Odest) Opos += Odir;
                w++;
                Bdest = qb.front();
                qb.pop();
            }
            q.pop();
        }
        cout << "Case #" << k + 1 << ": " << w << endl;
    }
    return 0;
}
