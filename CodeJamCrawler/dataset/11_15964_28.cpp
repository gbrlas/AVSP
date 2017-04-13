#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.in");
    ofstream fout;
    fout.open("output.out");
    int t;
    fin>>t;
    for(int k=0;k<t;k++)
    {
        fout<<"Case #"<<k+1<<": ";
        int n,l,h,x[110];
        fin>>n>>l>>h;
        for(int i=0;i<n;i++) fin>>x[i];
        if(l==1) {fout<<1<<endl;continue;}
        bool f=0;
        for(int i=l;i<=h;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(!(x[j]%i) || !(i%x[j])) c++;
            }
            if(c==n) {f=1;fout<<i<<endl;break;}
        }
        if(!f) fout<<"NO"<<endl;
    }
    return 0;
}
