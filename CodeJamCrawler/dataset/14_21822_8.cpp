#include<iostream>
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
    for(int u=1;u<=test;u++)
    {
        int n,a,b;
        fin>>a>>b>>n;
        int count=0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                int result=i&j;
                if(result<n)
                    count++;
            }
        }
        fout<<"Case #"<<u<<": "<<count<<"\n";
    }
    return 0;
}
