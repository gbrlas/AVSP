#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
using namespace std;
int f[800],s[800],T,n;
int cmp(const void *a,const void *b)
{
    int * aa;
    int * bb;
    aa = (int*)a;
    bb = (int*)b;
    int tmp;
    if(*aa > *bb)
    {
        return 1;
    }
    else if(*aa < *bb) return -1;
    else return 0;
}
int cmp1(const void *a,const void *b)
{
    int * aa;
    int * bb;
    aa = (int*)a;
    bb = (int*)b;
    int tmp;
    if(*aa < *bb)
    {
        return 1;
    }
    else if(*aa > *bb) return -1;
    else return 0;
}
int main()
{
    ofstream out;
    out.open("a.txt");
    int ncase = 0;
    int nn;
    long long res;
    cin>>T;
    while(T)
    {
        --T;
        ++ncase;
        cin>>n;
        nn = 0;
        while(nn<n)
        {
            cin>>f[nn];
            ++nn;
        }
        nn = 0;
        while(nn<n)
        {
            cin>>s[nn];
            ++nn;
        }
        qsort(f,n,sizeof(int),cmp);
        qsort(s,n,sizeof(int),cmp1);
        res = 0;
        nn = 0;
        while(nn<n)
        {
            res += f[nn]*s[nn];
            ++nn;
        }
        cout<<"Case #"<<ncase<<": "<<res<<endl;
        out<<"Case #"<<ncase<<": "<<res<<endl;
    }
    cin>>nn;
    return 0;
}
