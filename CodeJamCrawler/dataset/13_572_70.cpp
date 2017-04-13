#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input_small.txt");
    fout.open("out_small.txt");
    int i,j,k,l,turn,z,flag,m,n;
    bool row,col,ans;
    turn=0;
    fin>>z;
    while(z--)
    {
        ans=0;
        turn++;
        fin>>n>>m;
        int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                fin>>a[i][j];
                //cout<<a[i][j]<<" ";
            }
            //cout<<"\n";
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                row=1;
                col=1;

                        if(col)
                        for(k=0;k<n;k++)
                        {
                            if(a[k][j]>a[i][j])
                            {
                                col=0;
                                break;
                            }
                        }
                        if(row)
                        for(l=0;l<m;l++)
                        {
                            if(a[i][l]>a[i][j])
                            {
                                row=0;
                                break;
                            }
                        }
                    if(col==0&&row==0)
                    {
                        ans=1;
                        break;
                    }

            }
            if(ans)
            break;
        }
        if(ans)
        {
                            //cout<<"Case #"<<turn<<": NO\n";
                            fout<<"Case #"<<turn<<": NO\n";
        }
        if(!ans)
        {

                            //cout<<"Case #"<<turn<<": YES\n";
                            fout<<"Case #"<<turn<<": YES\n";

        }
    }
    fin.close();
    fout.close();
    return 0;

}

