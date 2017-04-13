#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int numcase, p, k, l;
int fre[2000];
int comp(const void *a1, const void *b1)
{
    const int *a;
    const int *b;
    a = (const int *)a1;
    b = (const int *)b1;
    if(*a<*b) return 1;
    else return -1;
}
int main()
{
    ofstream out("a.txt");
    int ca, i, res, tk,tp;
    cin>>numcase;
    ca  = 0;
    while(ca<numcase)
    {
        ++ca;
        cin>>p>>k>>l;
        
        for(i=0;i<l;i++)
            cin>>fre[i];
        qsort(fre, l, sizeof(int), comp);
        //for(i=0;i<l;i++)
        //    cout<<fre[i]<<' ';
        cout<<p*k<<' '<<l<<endl;
        if((p*k) <l) 
        {
            cout<<"Case #"<<ca<<": Impossible"<<endl;
            out<<"Case #"<<ca<<": Impossible"<<endl;
        }
        else{
            i=0,res=0;
            for(i=0;i<l;i++)
            {
                res+=(i/k+1)*fre[i];
            }
            cout<<"Case #"<<ca<<": "<<res<<endl;
            out<<"Case #"<<ca<<": "<<res<<endl;
        }
    }
    cin>>i;
    return 0;
}
