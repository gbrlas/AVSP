#include <iostream>
#include <list>
using namespace std;

struct DAW {
    int all, won;
};

int main() {
    int T, N, PD, PG;
    bool ok;
    list<DAW> lista;
    list<DAW>::iterator it;
    struct DAW temp;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> PD >> PG;
        ok = false;
        for(int j = 1; j <= N; j++) {
            for(int k = 0; k <= j; k++) {
                if((double)((double)((double)k * (double)100) / j) == PD) {
                    //cout << (double)((double)((double)k * (double)100) / j) << "  PD > " << PD << endl;
                    temp.all = j;
                    temp.won = k;
                    lista.push_back(temp);
                }
            }
        }
        //cout << PD << " " << PG << " <" << endl;
        if((PG == 100 && PD != 100) || (PG == 0 && PD != 0)) {
            ok = false;
        } else {
            ok = false;
            if(!lista.empty()) {
                int tempa, tempw;
                for(it = lista.begin(); it != lista.end(); it++) {
                    tempa = it->all;
                    tempw = it->won;

                    //cout << tempw << " " << tempa << endl;

                    for(int h = 0; h < 10000000000; h++) {
                        for(int hk = 0; hk <= h; hk++) {
                            if((((tempw + hk) * 100) / (tempa + h)) == PG) {
                                ok = true;
                                break;
                            }
                        }
                        if(ok) break;
                    }
                }


            } else ok = false;
        }

        if(!lista.empty()) lista.clear();

        if(!ok) {
            cout << "Case #" << (i + 1) << ": Broken" << endl;
        } else {
            cout << "Case #" << (i + 1) << ": Possible" << endl;
        }
    }
    return 0;
}
