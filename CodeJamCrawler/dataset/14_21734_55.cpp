#include <bits/stdc++.h>
#define         Z       1004
using namespace std;
int b1[Z], b2[Z];
double a1[Z], a2[Z];
int n;

bool WAR( double x){
    double m1,m2;
    int r1,r2,i;
    m1 = 1.0;
    m2 = 1.0;
    for(i = 0; i < n; i++){
        if(b2[i] == 1) continue;
        if(a2[i] < m1){
            m1 = a2[i];
            r1 = i;
        }
        if(a2[i] > x ){
            if( a2[i] < m2){
                m2 = a2[i];
                r2 = i;
            }
        }
    }


    if(m2 < 1.0){
        b2[r2] = 1;
        return false;
    }
    else{
        b2[r1] = 1;
        return true;
    }
}
bool THEIF(double x){
    double m1,m2;
    int r1,r2,i;

    m1 = 1.0; m2 = 1.0;
    for(i = 0; i < n ; i++){
        if(b1[i] == 1) continue;
        if(a1[i] > x){
            if(a1[i] < m2){
                m2 = a1[i];
                r2 = i;
            }
        }
        if(a1[i] < m1){
            m1 = a1[i];
            r1 = i;
        }
    }

    if(m2 < 1.0){
        b1[r2] = 1;
        return true;
    }
    else{
        b1[r1] = 1;
        return false;

    }
}
int main()
{
    int T,tc,i,fair, theif;

    freopen("D-small-attempt0.in","r",stdin);
    freopen("DSmallAns.out","w",stdout);

    cin >> T;
    tc = 0;
    while(tc < T){
        tc++;
        cin >> n;

        for(i = 0; i < n ; i++)
            cin >> a1[i];

        for(i = 0; i < n ; i++)
            cin >> a2[i];

        sort(a1, a1 + n);
        sort(a2, a2 + n);
        memset(b1, 0, sizeof(b1));
        memset(b2, 0, sizeof(b2));

        fair = 0;
        for(i = n-1; i >= 0; i--){
            if(WAR(a1[i])== true) fair++;
        }

        theif = 0;

        for(i = 0; i < n ; i++){
            if(THEIF(a2[i]) == true) theif++;
        }

        printf("Case #%d: %d %d\n",tc,theif, fair);
    }

    return 0;
}
