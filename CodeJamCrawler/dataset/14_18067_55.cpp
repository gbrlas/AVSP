#include<iostream>
#include<fstream>
using namespace std;

main()
{
    int t,counter=1,a[4][4],r1,i,s1[4],s2[4],j,flag,ans;
    ofstream outputfile("out.txt");
    cin>>t;
    while(counter!=(t+1))
    {
        flag=0;
        cin>>r1;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cin>>a[i][j];

        for(i=0;i<4;i++)
           s1[i]=a[r1-1][i];

        cin>>r1;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cin>>a[i][j];

        for(i=0;i<4;i++)
        {
            s2[i]=a[r1-1][i];
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                {
                    if(s1[i]==s2[j])
                    {
                        flag++;
                        ans=s1[i];
                    }
                }
        }

        if(flag==0)
        {
            outputfile<<"Case #"<<counter<<": "<<"Volunteer cheated!"<<endl;
        }
        if(flag==1)
        {
            outputfile<<"Case #"<<counter<<": "<<ans<<endl;
        }
        if(flag>1)
        {
            outputfile<<"Case #"<<counter<<": "<<"Bad magician!"<<endl;
        }
        counter++;
    }
}
