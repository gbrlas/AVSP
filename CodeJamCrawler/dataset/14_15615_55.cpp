#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t,a[4][4],b[4][4],x,y,i,j,k,ans,cnt;
    fstream fp, fout;
    fp.open("A-small-attempt1.in", ios::in);
    fout.open("op.txt", ios::out);
    fp>>t;
    for(i=1;i<=t;i++)
    {
        cnt=0;
        fp>>x;
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                fp>>a[j][k];
        fp>>y;
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                fp>>b[j][k];

        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                if(a[x-1][j]==b[y-1][k])
                {
                    ans=a[x-1][j];
                    cnt++;
                }
        fout<<"Case #"<<i<<": ";
        if(cnt==1)
            fout<<ans<<'\n';
        else if(cnt>1)
            fout<<"Bad magician!\n";
        else
            fout<<"Volunteer cheated!\n";

    }
    fp.close();
    fout.close();
    return 0;
}
