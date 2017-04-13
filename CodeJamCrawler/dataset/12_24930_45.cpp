#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (){

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n, s, p, b, B;
        cin >> n >> s >> p;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.rbegin(), v.rend());
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 0)
                b = B = 0;
            else {
                switch(v[i]%3){
                case 0:
                    b = v[i]/3;
                    B = b+1;
                    break;
                case 1:
                    b = v[i]/3+1;
                    B = b;
                    break;
                case 2:
                    b = v[i]/3+1;
                    B = b+1;
                }
            }
            if(b >= p) cnt++;
            else if(s > 0 && B >= p){
                s--;
                cnt++;
            }
            else break;
        }
        printf("Case #%d: %d\n", t+1, cnt);
    }

    return 0;
}
