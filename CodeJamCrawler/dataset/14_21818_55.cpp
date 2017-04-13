#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("abc.txt");
    ofstream fout;
    fout.open("ans.txt");
    int test;
    fin>>test;
    for(int qq=1;qq<=test;qq++)
    {
        int n;
        fin>>n;
        int c[n];
        double a[n];
        double b[n];
        for(int i=0;i<n;i++)
        {
            fin>>a[i];
            c[i]=1;
        }

        for(int i=0;i<n;i++)
            fin>>b[i];

        sort(a,a+n);
        sort(b,b+n);
        int ans=0;


        for(int i=0;i<n;i++)
        {
            double element=a[i];
            for(int j=0;j<n;j++)
            {
                if(b[j]>element && c[j]==1)
                {
                    ans++;
                    c[j]=0;
                    break;
                }
            }
        }
        int first=n-ans;
        int count=0;
        for(int i=0;i<n;i++)
        {
            double element=a[i];
            for(int j=0;j<n;j++)
            {
                if(b[j]<element)
                {
                    b[j]=1;
                    count++;
                    break;
                }
            }
        }
        fout<<"Case #"<<qq<<": "<<count<<" "<<first<<"\n";
    }
}
