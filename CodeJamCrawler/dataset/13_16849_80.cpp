#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    int n,t,chk=0,flag=0;
    string a[4],inp;
    ifstream fin;
    ofstream fout;
    fin.open("a.in");
    fout.open("tic.txt");
    char nl;
    fin>>n;
    t=0;

    while(fin&&n--)
    {
        //cout<<n<<endl;
        //getchar();
        chk=0;
        flag=0;                 //INDICATES DRAW
        for(int i=0;i<4;i++)
        {
            fin>>inp;
            a[i]=inp;
            //cin>>nl;

        }
        //fin>>nl;
        for(int i=0;i<4;i++)                                        //checking row
        {
            chk=0;
            for(int j=0;j<4;j++)
            chk+=(a[i][j]);
            if(chk==352||chk==348)
            {
                fout<<"Case #"<<t+1<<": X won\n";
                flag=1;
                break;
            }
            else if(chk==316||chk==321)
            {
                fout<<"Case #"<<t+1<<": O won\n";
                flag=1;
                break;
            }
        }
        if(!flag)
        {


        for(int i=0;i<4;i++)                                        //checking column
        {
            chk=0;
            for(int j=0;j<4;j++)
            chk+=a[j][i];
            if(chk==352||chk==348)
            {
                fout<<"Case #"<<t+1<<": X won\n";
                flag=1;
                break;
            }
            else if(chk==316||chk==321)
            {
                fout<<"Case #"<<t+1<<": O won\n";
                flag=1;
                break;
            }
        }
        }
        if(!flag)
        {

        chk=0;
        for(int i=0;i<4;i++)                                        //checking 1st diagonal
        {
            //chk=0;
            //for(int j=0;j<4;j++)
            chk+=a[i][i];
        }
        //cout<<chk<<endl;
            if(chk==352||chk==348)
            {
                fout<<"Case #"<<t+1<<": X won\n";
                flag=1;
                //break;
            }
            else if(chk==316||chk==321)
            {
                fout<<"Case #"<<t+1<<": O won\n";
                flag=1;
               // break;
            }

        }
        if(!flag)
        {
            chk=0;
        for(int i=0;i<4;i++)                                        //checking 2nd diagonal
        {
            //chk=0;
            //for(int j=0;j<4;j++)
            chk+=a[i][(3-i)];
        }
            if(chk==352||chk==348)
            {
                fout<<"Case #"<<t+1<<": X won\n";
                flag=1;
                //break;
            }
            else if(chk==316||chk==321)
            {
                fout<<"Case #"<<t+1<<": O won\n";
                flag=1;
                //break;
            }

        }
        t++;
        if(flag)
        continue;
        else
        {
            chk=0;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    chk+=a[i][j];
                }
            }
            if(chk>=1336)
            {
                fout<<"Case #"<<t<<": Draw\n";
            }
            else
            {
                fout<<"Case #"<<t<<": Game has not completed\n";
            }
        }


    }
   // cout<<n<<endl;
    fin.close();
    fout.close();
    return 0;

}
