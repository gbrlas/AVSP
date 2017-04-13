 #include<iostream>
#include<algorithm>
#include<math.h>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;
vector< vector<bool> > tri;
int adde(int prsum,int num)
{
    bool f[50],nm[50];
    memset(f,0,sizeof(f));
    memset(nm,0,sizeof(nm));
    int t=0;
    if(prsum!=0)
    {
        while(prsum!=0)
        {
            f[t]=prsum%2;
            t++;
            prsum/=2;
        }
    }
    int t1=0;
    while(num!=0)
    {
        nm[t1]=num%2;
        t1++;
        num/=2;
    }
    int n=0;
    for(int i=0;i<max(t1,t);i++)
    {
        if(nm[i]==f[i]) continue;
        else n+=pow(2,i);
    }
    return n;
}
void rec(int beg,int sz,vector<bool> f)
{
    for(int i=beg+1;i<sz;i++)
    {
        f[i]=1;
        tri.push_back(f);
        rec(i,sz,f);
        f[i]=0;
    }
}
int main()
{
    ifstream fin;
    fin.open("input.in");
    ofstream fout;
    fout.open("output.out");
    int ts;
    fin>>ts;
    for(int k=0;k<ts;k++)
    {
        tri.clear();
        int n,x[1010];
        vector<bool> f;
        fin>>n;
        int s=0;
        int ret=-1;
        for(int i=0;i<n;i++) {fin>>x[i];s+=x[i];f.push_back(0);}
        for(int i=0;i<n;i++)
        {
            f[i]=1;
            tri.push_back(f);
            rec(i,n,f);
            f[i]=0;
        }
        for(int i=0;i<tri.size();i++)
        {
                int r=0,h=0;
                for(int u=0;u<n;u++)
                {
                    if(tri[i][u]) r=adde(r,x[u]);
                    else h=adde(h,x[u]);
                }
               //cout<<r<<' '<<h<<endl;
                if(h==r && (h!=0 && r!=0))
                {
                    r=0;
                    for(int u=0;u<n;u++)
                    {
                        if(tri[i][u]) r+=x[u];
                    }
                    ret=max(ret,max(r,s-r));
                }
            }
        if(ret==-1) fout<<"Case #"<<k+1<<": NO\n";
        else fout<<"Case #"<<k+1<<": "<<ret<<endl;
    }
    return 0;
}
