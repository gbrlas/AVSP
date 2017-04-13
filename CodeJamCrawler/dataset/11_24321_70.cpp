#include<iostream>

using namespace std;

int main()
{
    int T,N,n;
    cin>>T;
    for(int i=0;i<T;i++) {
        cin>>N;
        int asum=0,xsum=0,min=1000000;
        for(int j=0;j<N;j++) {
            cin>>n;
            asum+=n;
            xsum=xsum^n;
            if(n<min)
                min=n;
        }
        cout<<"Case #"<<i+1<<": ";
        if(xsum)
            cout<<"NO\n";
        else
            cout<<asum-min<<endl;
        //cout<<"asum:"<<asum<<" min:"<<min<<" xsum:"<<xsum<<endl;
    }
    return 0;
}