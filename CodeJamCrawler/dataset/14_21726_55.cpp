/*
    Date : 12 April, 2014
    Google CodeJam!
    Qualification Round
*/
#include <stdio.h>
#include <bits/stdc++.h>
#define     eps         1e-9
using namespace std;

int main()
{

   freopen("B-small-attempt2.in","r",stdin);
   freopen("Bans2.out","w",stdout);

    int T,tc;
    double C,F,X,ans;
    cin >> T;
    tc = 0;

    while(tc < T){
        tc++;

        cin >> C>> F>> X;

        double tym,rate, need,k;


        tym = 0.0;
        rate = 2.0;
        ans = X/rate;
        k = 0.0;
        while(1){

            tym += C/rate;
            rate += F;
            need = X/rate;
            ans = min(ans, tym+need);
            k =  k + 1.0;
            if(k > X + 5.0) break;
            if(tym > ans) break;
            //cout<<tym <<" "<<rate<<" " << need <<" "<<ans << endl;
        }

        printf("Case #%d: %.7lf\n",tc,ans);

    }

    return 0;
}
