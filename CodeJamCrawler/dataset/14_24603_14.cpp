#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    long t;
    int count=0;
    char temp[20];
    int e1,e2, num=0;
    int row1[4],row2[4];
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin.getline(temp,20);
    t=strtol(temp,0,10);
    for(int i=0;i<t;i++)
    {
        fin.getline(temp,20);
        e1=strtol(temp,0,10);
        for(int j=1;j<=4;j++)
        {
            if(j==e1)
                for(int k=0;k<4;k++)
                {
                    if(k<3)
                        fin.getline(temp,20,' ');
                    else
                        fin.getline(temp,20);
                    row1[k]=strtol(temp,0,10);
                }
            else
            {
                fin.getline(temp,20);
            }
        }
        fin.getline(temp,20);
        e2=strtol(temp,0,10);
        for(int j=1;j<=4;j++)
        {
            if(j==e2)
                for(int k=0;k<4;k++)
                {
                    if(k<3)
                        fin.getline(temp,20,' ');
                    else
                        fin.getline(temp,20);
                    row2[k]=strtol(temp,0,10);
                }
            else
            {
                fin.getline(temp,20);
            }
        }
        num=0;count=0;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                if(row1[j]==row2[k])
                {
                    if(count==0)
                        num=row1[j];
                    count++;
                                    }
            }
        fout<<"Case #"<<i+1<<": ";
        if(num)
        {
            if(count==1)
                fout<<num<<'\n';
            else
                fout<<"Bad Magician!\n";
        }
        else
            fout<<"Volunteer Cheated!\n";
    }
}
