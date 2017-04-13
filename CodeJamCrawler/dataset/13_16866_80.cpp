#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream fin,fout;
    fin.open("inp.in");
    fout.open("out.txt",ios::out);
    int n,a,b,t,i;
    fin>>n;
    t=0;
    int ans[1001];
    ans[0]=0;
    for(i=1;i<4;i++)
    {
        ans[i]=1;
    }
    for(i=4;i<9;i++)
    {
        ans[i]=2;
    }
    for(i=9;i<121;i++)
    {
        ans[i]=3;
    }
    for(i=121;i<484;i++)
    {
        ans[i]=4;
    }
    for(i=484;i<1001;i++)
    {
        ans[i]=5;
    }
    while(n--)
    {
        t++;
        fin>>a>>b;
        if(a==1)
        fout<<"Case #"<<t<<": "<<ans[b]<<"\n";
        else
        {
             fout<<"Case #"<<t<<": "<<ans[b]-ans[a]+(ans[a]-ans[a-1])<<"\n";
        }

    }
    fin.close();
    fout.close();
    return 0;
}
