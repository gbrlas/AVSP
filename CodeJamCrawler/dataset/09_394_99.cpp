#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int N=110;
int t, h, w;
int x, y;
int a[N][N], par[10100];
char b[N][N];
char used[10100];
bool ok(int i, int j)
{
    if (i<=0 || i>h) return false;
    if (j<=0 || j>w) return false;
    
    return true;
}
void find(int i, int j)
{
    int temp;
    
    temp=a[i][j];
    x=i, y=j;
    if (ok(i-1, j))
    {
        if (temp>a[i-1][j])
        {
            temp=a[i-1][j];
            x=i-1;
            y=j;
        }
    }
    if (ok(i, j-1))
    {
        if (temp>a[i][j-1])
        {
            temp=a[i][j-1];
            x=i;
            y=j-1;
        }
    }
    if (ok(i, j+1))
    {
        if (temp>a[i][j+1])
        {
            temp=a[i][j+1];
            x=i;
            y=j+1;
        }
    }
    if (ok(i+1, j))
    {
        if (temp>a[i+1][j])
        {
            temp=a[i+1][j];
            x=i+1;
            y=j;
        }
    }
    
    
}
void makeset()
{
    int p=w*h;
   
    for (int i=1; i<=p; i++)
        par[i]=i;
}
int findset(int x)
{
    if (x==par[x])
    {
        return x;
    }
    else
    {
        par[x]=findset(par[x]);
        return par[x];
    }
}
void Union(int x, int y)
{
    int rx, ry;
    
    rx=findset(x);
    ry=findset(y);
    par[rx]=ry;
}
int main(void)
{   
    FILE *fin, *fout;
    
    int k;
    char e;
    
    fin=fopen("B-large.in", "r");
    fout=fopen("B-large.out", "w");
    fscanf(fin, "%d", &t);
    for (int ca=1; ca<=t; ca++)
    {
        
        fscanf(fin, "%d%d", &h, &w);
        makeset();
        memset(used, 0, sizeof(used));
        e='a';
        
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                fscanf(fin, "%d", &a[i][j]);
            }
        }
        
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                find(i, j);
         //       cout<<x<<' '<<y<<endl;
                if(x!=i || j!=y)
                    Union((x-1)*w+y, (i-1)*w+j);
            }
    //        cout<<endl;
        }
        k=w*h;
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                findset((i-1)*w+j);
            //    cout<<par[(i-1)*w+j]<<endl;
            }
        }
        
        fprintf(fout, "Case #%d:\n", ca);
        
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<=w; j++)
            {
                if (used[par[(i-1)*w+j]]==0) used[par[(i-1)*w+j]]=e++;
                else used[par[(i-1)*w+j]];
                b[i][j]= used[par[(i-1)*w+j]];
            }
        }
        
        for (int i=1; i<=h; i++)
        {
            for (int j=1; j<w; j++)
            {
                fprintf(fout, "%c ", b[i][j]);
            }
            fprintf(fout, "%c\n", b[i][w]);
        }
    }
    
   
    return 0;
}
