#include <iostream>
#include <queue>
using namespace std;
int n, a, b, x, il, ek;
bool t[20];
queue <int> jo;
int main () {
    cin >> n;
    for (int i=1 ; i<=n ; i++) {
        il=0;
        cin >>a;
        for (int j=1 ; j<=4 ; j++) {
            for (int k=1 ; k<=4 ; k++) {
                cin >> x;
                if (j==a) {
                    t[x]=1;
                    jo.push(x);
        }}}
        cin >> b;
        for (int j=1 ; j<=4 ; j++) {
            for (int k=1 ; k<=4 ; k++) {
                cin >> x;
                if (j==b) {
                    if (t[x]==1) {
                        il++;
                        ek=x;
                    }
        }}}
        while (!jo.empty()) {
            t[jo.front()]=0;
            jo.pop();
        }
        if (il==0)
            cout << "Case #" << i << ": Volunteer cheated!" << endl;
        else if (il==1)
            cout << "Case #" << i << ": " << ek << endl;
        else
            cout << "Case #" << i << ": Bad magician!" << endl;
    }
return 0;
}
