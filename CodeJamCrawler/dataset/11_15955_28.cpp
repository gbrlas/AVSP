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
    bool f[55][55];
    int x[55][55];
    for(int k=0;k<t;k++)
    {
        fout<<"Case #"<<k+1<<": \n";
        memset(f,0,sizeof(f));
        memset(x,0,sizeof(x));
        int r,c;
        char t;
        fin>>r>>c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                fin>>t;
                if(t=='#') {f[i][j]=1;}
            }
        }
        int re=1;
        bool z=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(f[i][j])
                {
                    if(f[i+1][j] && f[i][j+1] && f[i+1][j+1])
                    {
                        x[i][j]=x[i+1][j]=x[i][j+1]=x[i+1][j+1]=re;
                        re++;
                        f[i][j]=0;
                        f[i+1][j]=0;
                        f[i][j+1]=0;
                        f[i+1][j+1]=0;
                    }
                    else {z=1;break;}
                }
            }
            if(z) break;
        }
        bool ret[1000];
        memset(ret,0,sizeof(ret));
        if(z) {fout<<"Impossible"<<endl;continue;}
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(x[i][j])
                {
                    if(!ret[x[i][j]])
                    {
                        fout<<"/\\";
                        ret[x[i][j]]=1;
                        j++;
                    }
                    else
                    {
                        fout<<"\\/";
                        j++;
                    }
                }
                else fout<<'.';
            }
            fout<<endl;
        }
    }
    return 0;
}
