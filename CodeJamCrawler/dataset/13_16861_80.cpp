#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("inp.in");
    fout.open("out.txt");
    int i,j,k,l,t,z,flag,m,n;
    bool row,col,ans;
    t=0;
    fin>>z;
    while(z--)
    {
        ans=0;
        t++;
        fin>>n>>m;
        int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                fin>>a[i][j];
            }
        }
        for(i=0;i<n&&!ans;i++)
        {
            for(j=0;j<m&&!ans;j++)
            {
                row=1;
                col=1;

                    //if(a[i][j]==1)

                        for(k=0;k<n&&col;k++)
                        {
                            if(a[k][j]>a[i][j])
                            {
                                col=0;
                                //break;
                            }
                        }
                        for(l=0;l<m&&row;l++)
                        {
                            if(a[i][l]>a[i][j])
                            {
                                row=0;
                                //break;
                            }
                        }

                    ans=(!col)&&(!row);
                    /*{
                            cout<<"Case #"<<t<<" :NO\n";
                            flag=1;
                            break;
                    }*/
            }
            /*if(flag)
                break;*/
        }
        if(ans)
        {
                            fout<<"Case #"<<t<<": NO\n";
                            flag=1;
                            //break;
                    }
        if(!ans)
        {
             fout<<"Case #"<<t<<": YES\n";

        }
    }
    fin.close();
    fout.close();
    return 0;

}
