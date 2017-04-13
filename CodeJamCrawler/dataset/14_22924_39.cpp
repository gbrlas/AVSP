#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t, i=1;
    int a1[4][4], a2[4][4];
    cin>>t;
    ofstream myfile;
    myfile.open ("example.txt");
    while(i<=t)
    {
        int s1,s2,cary, x, j, k, c;
        cin>>s1;
        for(j=0 ; j<4 ; j++)
        {
            for(k=0 ; k<4 ; k++)
            {
                cin>>a1[j][k];
            }
        }
        cin>>s2;
        for(j=0 ; j<4 ; j++)
        {
            for(k=0 ; k<4 ; k++)
            {
                cin>>a2[j][k];
            }
        }

        cary=0;
        for(j=0 ; j<4 ; j++)
        {
            for(k=0 ; k<4 ; k++)
            {
                if(a1[s1-1][j]==a2[s2-1][k])
                {
                    cary++;
                    c=a1[s1-1][j];
                }
            }
        }

        cout<<"Case #"<<i<<": ";
        myfile<<"Case #"<<i<<": ";
        i++;
        if(cary==1)
        {
            cout<<c;
            myfile<<c<<"\n";
        }
        else if(cary>1)
        {
            cout<<"Bad magician!";
            myfile << "Bad magician!\n";
        }
        else
        {
            cout<<"Volunteer cheated!";
            myfile << "Volunteer cheated!\n";
        }
        cout<<endl;
    }
     myfile.close();
}
