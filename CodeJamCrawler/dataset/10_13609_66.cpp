#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define pii pair<int,int>

int tc, R, k, N, a;
vector <long long> cost;
map <int,int> m;
set <int> S;

int main(){
    freopen("C-large.in", "r",stdin);
    freopen("output.txt","w",stdout);
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++){
        cost.clear(); S.clear(); m.clear();
        cout << "Case #" << TC << ": ";
        cin >> R >> k >> N;
        queue <pii> Q, q;
        for (int i = 0; i < N; i++){
            cin >> a;
            Q.push(pii(a, i));
        }
        long long num = 0, total = 0;
        int ii = 0;
        while (true){
            int F = Q.front().second;
            num = 0;
            while (!Q.empty()){
                pii tmp = Q.front();
                if (tmp.first + num> k) break;
                //cout << tmp.first << endl;
                Q.pop();
                num += tmp.first;
                total += tmp.first;
                q.push(tmp);
            }
            if (Q.empty()){
                long long ans = R * num;
                cout << ans << endl;
                break;
            }
            //cout << "DEBUG " << Q.front().second << " F " << F << endl;
            if (S.find(F) != S.end()){
                map <int,int>::iterator it = m.find(F);
                int t = it->second;
                long long cyclecost = total;
                long long cyclelen = ii-t;
                //for (int i = 0; i < cost.size(); i ++) cout << cost[i] << endl;
                cyclecost -= cost[t];
                if (R <= t + cyclelen){
                    cout << cost[R-1] << endl; break;
                }else{
                    long long ans = 0;
                    if (t != 0) ans += cost[t-1];
                    R -= t+1;
                    ans += cyclecost * (R/cyclelen);
                    int mod = R % cyclelen;
                    //cout << R<< " mod "<<mod << endl;
                    ans += cost[mod + t];
                    if (t != 0) ans -= cost[t-1];
                    cout << ans <<endl;
                }

                //cout << "cyclelen " << cyclelen << " cyclecost " << cyclecost << endl;
                //long long ans = R
                //do stuff here
                break;
            }
            m.insert(pii(F, ii++));
            S.insert(F);
            cost.push_back(total);
            while (!q.empty()){
                Q.push(q.front()); q.pop();
            }
        }
        /*while (!Q.empty()){
            pii tmp = Q.front(); 
            if (tmp.first + num> k) break;
            Q.pop();
            num += tmp.first;
            q.push(tmp);
        }
        total = num;
        if (Q.empty()){
        }else{
            cost.push_back(num);
            S.insert(Q.front().second);
            m.insert(pii(Q.front().second, 1));
            int t;
            while (true){
                while (!q.empty()){
                    Q.push(q.front()); q.pop();
                }
                if (S.find(Q.front().second) != S.end()){
                    map <int,int>::iterator it = m.find(Q.front().second);
                    t = it->second;
                    break;
                }
                num = 0;
                while (!Q.empty()){
                    pii tmp = Q.front();
                    if (tmp.first + num> k){ cout << "DEBUG " << tmp.second << endl;break;}
                    Q.pop();
                    num += tmp.first;
                    q.push(tmp);
                }
                total += num;
                cost.push_back(total);
            }
            //if (!cost.empty()) cost.pop_back();
            int mod = R % (cost.size()-t);
            cout << "cost.size " << cost.size()-t <<" "<<mod << " " << R/(cost.size()-t) << endl;
            long long ans = cost[mod + t-1];
            ans += total * (R / (cost.size()-t));
            cout << ans << endl;
        }*/
    }
    return 0;
}
