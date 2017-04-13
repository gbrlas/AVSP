#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    double ant[101]={0.0};
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i;
    double C, F, X, cs, csm, ret;
    cin>>T;
    for(i = 1; i <= T; i++){
        ret = 0;
        cs = 2.0;
        csm = 0.0;
        cin>>C>>F>>X;
        if(X <=C)
        {
            ret = X/cs;
        }
        else 
        {
            while((X - C)/cs > X/(cs+ F))
            {
                ret += C/cs;
                cs += F;
            }
            ret += X/cs;
        }
        ant[i]=ret;
    }
    for(i=1;i<=T;i++)
        cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(7)<<ant[i]<<endl; 
    return 0; 
}

