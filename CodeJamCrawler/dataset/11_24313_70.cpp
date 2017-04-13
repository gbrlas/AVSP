#include<iostream>
using namespace std;

int abs(int x);
int max(int x, int y);
int main()
{
    int T,N;//N button push in the sequence
    int Pi, OTk=0, OPk=1, BTk=0, BPk=1, Ti, prevT=0;
    char Ri;
    //cout<<"#Test Cases? ";
    cin>>T;
    for(int j=1;j<=T;j++) {
        cin>>N;
        OTk=0, OPk=1, BTk=0, BPk=1, Ti, prevT=0;
        for(int i=1;i<=N;i++) {
            //cout<<"Ri,Pi? ";
            cin>>Ri>>Pi;
            if(Ri=='O') {
                Ti=max(OTk+abs(Pi-OPk),prevT)+1;
                OTk=Ti;
                OPk=Pi;
                prevT=Ti;
            }
            else {
                Ti=max(BTk+abs(Pi-BPk),prevT)+1;
                BTk=Ti;
                BPk=Pi;
                prevT=Ti;
            }
            //cout<<"iteration"<<i<<": "<<Ti<<endl<<"OTk: "<<OTk<<", OPk: "<<OPk<<", BTk: "<<BTk<<", BPk: "<<BPk<<", prevT: "<<prevT<<endl;
        }
        cout<<"Case #"<<j<<": "<<Ti<<endl;
    }

    return 0;
}

inline int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

inline int max(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}