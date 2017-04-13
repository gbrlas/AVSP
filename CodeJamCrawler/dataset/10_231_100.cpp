#include <iostream>
using namespace std;

void solvecase(int index){
    long long l,p,c,f,g;
    cin>>l>>p>>c;
    f=0;
    while(c*l<p) ++f,l*=c;
    g=0;
    while(f) ++g,f>>=1;
    cout<<"Case #"<<index<<": "<<g<<endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
        solvecase(i);
    return 0;
}
