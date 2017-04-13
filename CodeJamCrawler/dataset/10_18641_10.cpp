#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main(void) {
    int T;
    cin>>T;
    vector<int> vM, vP;
    int buy[1024];
    for (int t=1; t<=T; t++) {
        int P, M;
        cin>>P;
        vM.clear();
        vP.clear();
        for (int i=0; i<(1<<P); i++) {
            int m;
            cin>>m;
            vM.push_back(m);
        }
        for (int i=0; i<(1<<P)-1; i++) {
            int p;
            cin>>p;
            vP.push_back(p);
        }
        memset(buy, 0, sizeof(buy));
        int N = (1<<P);
        for (int i=0; i<vM.size(); i++) {
            int fac = 2;
            int idx = 0;
            for (int j=0; j<P; j++) {
                if (j >= vM[i])
                    buy[idx+i/fac] = 1;
                idx += N/fac;
                fac *= 2;
            }
        }
        int res = 0;
        for (int i=0; i<vM.size()-1; i++)
            if (buy[i]) res++;
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
}
