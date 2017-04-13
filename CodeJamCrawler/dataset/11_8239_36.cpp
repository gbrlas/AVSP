#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    int TTT; cin >> TTT;
    for (int ZZZ = 1; ZZZ <= TTT; ZZZ++) {
        long double X, S, R, t, N;
        cin >> X >> S >> R >> t >> N;
        
        long double Xo = X, to = t;
        int wtl = 0;
        vector<pair<long double, long double> > walkways;
        for (int i=0; i < N; i++) {
            int B, E, w; cin >> B >> E >> w;
            walkways.push_back(make_pair(w, E-B));
            wtl += E-B;
        }
        sort(walkways.rbegin(), walkways.rend());
                
        long double time = 0;
        for (int i=0; i < N; i++) {
            if (t > 0) {
               long double delta = min(t, walkways[i].second*1.0/(R+walkways[i].first));
               t -= delta;
               time += delta;
               if (t == 0) {
                   time += (walkways[i].second - delta*(R+walkways[i].first)) / (S+walkways[i].first);
               }
            }
            else if (t == 0) {
                time +=  walkways[i].second * 1.0 / (S+walkways[i].first);
            }
            X -= walkways[i].second;
            //cerr << "After walkway " << i << "(" << walkways[i].first << ", " << walkways[i].second << "): " << X << " " << t << " " << time << endl;
        }
        if (t > 0 && X > 0) {
            long double delta = min(t, X * 1.0/R);
            //cerr << X << " left: running for " << delta << endl;
            time += delta;
            t -= delta;
            X -= delta*R;
            //cerr << X << " " << t << " " << time << endl;
        }
        time += X * 1.0/S;
        long double t1 = time;
        
        X = Xo;
        t = to;
        time = 0;
        
        sort(walkways.begin(), walkways.end());
        
        long double delta = min(t, (X-wtl)/R);
        time += delta;
        t -= delta;
        X -= delta*R;
        for (int i=0; i < N; i++) {
            if (t > 0) {
               long double delta = min(t, walkways[i].second*1.0/(R+walkways[i].first));
               t -= delta;
               time += delta;
               if (t == 0) {
                   time += (walkways[i].second - delta*(R+walkways[i].first)) / (S+walkways[i].first);
               }
            }
            else if (t == 0) {
                time +=  walkways[i].second * 1.0 / (S+walkways[i].first);
            }
            X -= walkways[i].second;
            //cerr << "After walkway " << i << "(" << walkways[i].first << ", " << walkways[i].second << "): " << X << " " << t << " " << time << endl;
        }
        time += X*1.0/S;
     
        cout << "Case #" << ZZZ << ": " << fixed << setprecision(9) << min(t1, time) << endl;
    }
}
