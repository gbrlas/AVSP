#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("output.in");
    ifstream fin ("A-small-attempt0.in");
    int t,r,s,a[4][4],b[4][4],m,c=0;
    fin>>t;
    for(int x=1;x<=t;x++)
    {
        c=0;
        fin>>r;
        r--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            fin>>a[i][j];
        }
        int h[4];
        for(int i=0;i<4;i++)
        {h[i]=a[r][i];
        //fout<<h[i]<<" ";
        }
      //  fout<<endl;
        fin>>s;
        s--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            fin>>b[i][j];
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(h[i]==b[s][j])
                {
                    m=b[s][j];
                    c++;
                }
            }
        }
   //     cout<<"C IS"<<c<<endl;
        if(c==1)
        {
            fout<<"Case #"<<x<<": "<<m<<endl;
        }
        else if(c==0)
        {
            fout<<"Case #"<<x<<": Volunteer cheated!"<<endl;
        }
        else
        fout<<"Case #"<<x<<": Bad magician!"<<endl;
    }

    return 0;
}
