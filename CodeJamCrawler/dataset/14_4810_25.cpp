#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;
int main()
{

    int t;
    int s1, s2;
    int row[4];
    int i,j;
    int x;

    ifstream filin;

    ofstream fout;


    filin.open("ip.in");
    fout.open("ans1.txt");



    filin>>t;


    for(int c =1;c<=t;++c)
    {

        filin>>s1;
        for(i=0;i<4;++i)
            for(j=0;j<4;++j)
            {
                if(i==s1-1)
                filin>>row[j];

                else
                filin>>x;
            }


        filin>>s2;
        int cnt = 0, card;
        for(i=0;i<4;++i)
            for(j=0;j<4;++j)
            {
            filin>>x;
            if(i==s2-1)
            {
                for(int k=0;k<4;++k)
                if(x==row[k])
                {
                    cnt++;
                    card = x;

                }
            }

            }

            if(cnt>1)
            fout<<"Case #"<<c<<":"<<" Bad magician!\n";

            else if(cnt==1)
            fout<<"Case #"<<c<<": "<<card<<endl;

            else
            fout<<"Case #"<<c<<": "<<"Volunteer cheated!\n";
    }



}
