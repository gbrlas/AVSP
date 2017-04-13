#include <bits/stdc++.h>

using namespace std;

int main(){
     ifstream cin("B-large.in");
     ofstream cout("salCookiesL.txt");
    int T,casos=0;
    double c,f,x,gall=2,t1,t2,tot;
    cin>>T;
    while (T--){
        gall=2;
        cin>>c>>f>>x;
        tot = 0;
        while (true){
            t1 = x/gall;
            t2 = (c/gall) + (x/(gall+f));
            if (t2<t1){
                tot += (c/gall);
                gall += f;
            }else{
                tot += t1;
                break;
            }
        }
        cout<<"Case #"<<++casos<<": ";
        cout.precision(7);
        cout.setf(ios::fixed,ios::floatfield );
        cout << tot <<endl;
    }

    return 0;
}
