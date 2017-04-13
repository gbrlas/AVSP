// SLEEP DEPRIVATION

#include <iostream>
#include <cstring>
#include <cstdio>

#define MOD 1000000007
#define ll long long

using namespace std;

ll Fac[1000] = {1,1};

bool bad_inside(string S) {
    for(int i=0; i<S.size(); ++i) {
        char c = S[i];
        string Sc = S;

        for(int j=0; j<S.size(); ++j) {
            if(Sc[j] != c) Sc[j] = ' ';
        }

        int a=0;
        if(Sc[0]!=' ') a=1;
        for(int j=1; j<Sc.size(); ++j) {
            if(Sc[j-1]==' ' && Sc[j]!=' ') ++a;
        }

        if(a>1) return 1;
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int Cases;

    cin >> Cases;

    for(int i=2; i<1000; ++i) {
        Fac[i] = i * Fac[i-1];
        Fac[i] %= MOD;
    }

    for(int Case=1; Case<=Cases; ++Case) {
    //    cerr << Case << '\n';

        int T;
        string s[110];
        int indeg[26] = {0}, outdeg[26] = {0};
        int att[26][26] = {{0}};
        int mult[26] = {0};
        int self[26] = {0};
        bool involved[26] = {0};

        cin >> T;

        for(int i=0; i<T; ++i) {
            cin >> s[i];
            int X = s[i][0]-'a', Y = s[i][s[i].size()-1]-'a';
            if(X==Y) ++self[X];
            else {
                ++indeg[X]; ++outdeg[Y];
                att[X][Y] = 1;
                involved[X] = involved[Y] = 1;
            }
        }

        for(int i=0; i<26; ++i) {
            for(int j=0; j<T; ++j) {
                for(int k=0; k<s[j].size(); ++k) {
                    if(s[j][k] == 'a'+i) {
                        ++mult[i];
                        break;
                    }
                }
            }
        }

        // check trapped sandwiched char
        int bad=0;
        for(int i=0; i<T; ++i) {
            if(s[i].size() <= 2) continue;
            for(int j=1; j<s[i].size()-1; ++j) {
                if(s[i][j] != s[i][0] && s[i][j] != s[i][s[i].size()-1]
                    && mult[s[i][j]-'a'] >= 2) {
                    // hopeless
                    bad=1;
                    break;
                }
            }
            if(bad) break;
        }

        // check first/last consec
        for(int i=0; i<T; ++i) {
            if(bad_inside(s[i])) {
                bad=2; break;
            }
        }

        // check deg problem
        for(int i=0; i<26; ++i) {
            if(indeg[i] > 1 || outdeg[i] > 1) {
                bad=3; break;
            }
        }

        // check cycle up
        for(int i=0; i<26; ++i) {
            if(bad) break;
            if(!involved[i]) continue;

            int head = i;
            while(1) {
                bool got=0;
                for(int j=0; j<26; ++j){
                    if(att[head][j]){
                        head=j; got=1;
                        break;
                    }
                }
                if(!got) break;
                        if(head==i) {
                            // cycle
                            bad=4; break;
                        }
                if(bad) break;
            }
        }

        if(bad) {
        //    cout << "BAD " << bad << ' ';
            cout << "Case #" << Case << ": 0\n";
            continue;
        }

       // find components
        int nc=0;
        bool found[26] = {0};

        for(int i=0; i<26; ++i) {
            if(!involved[i]) continue;
            if(found[i]) continue;

            // move to head of chain
            int head=i;
            while(1) {
                bool got=0;
                for(int j=0; j<26; ++j){
                    if(att[j][head]){
                        head=j; got=1;
                        break;
                    }
                }
                if(!got) break;
            }

            if(found[head]) continue;

            ++nc;
            // go to tail
            while(1) {
                found[head] = 1;
                //cout << char('a'+head) << ' ';

                bool got=0;
                for(int j=0; j<26; ++j){
                    if(att[head][j]){
                        head=j; got=1;
                        break;
                    }
                }
                if(!got) break;
            } //cout << '\n';
        }

        ll ways = 1;


        for(int i=0; i<26; ++i) {
            ways *= Fac[self[i]];
            ways %= MOD;

            if(found[i]) continue;

            // find singleton components
            if(self[i] != 0){
                ++nc;
            }
        }

            ways *= Fac[nc];
            ways %= MOD;

      //  cout << nc << ' ';

        cout << "Case #" << Case << ": " << ways << '\n';
    }

    return 0;
}