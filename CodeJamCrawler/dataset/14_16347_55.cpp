#include<iostream>
using namespace std;
int main()
{
    int t,t1,i,j,ch1,ch2,m1[4][4],m2[4][4];
    cin>>t;
    for(t1=1;t1<=t;++t1)
    {
        cin>>ch1;
        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
                cin>>m1[i][j];
        }
        cin>>ch2;
        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
                cin>>m2[i][j];
        }
        int count=0,n;
        for(i=0;i<4;++i)
        {
            int choice=m1[ch1-1][i];
            for(j=0;j<4;++j)
            {
                if(m2[ch2-1][j]==choice)
                {
                   ++count;
                   n=choice;
                }

            }
        }
        if(count==0)
            cout<<"Case #"<<t1<<": Volunteer cheated!"<<endl;
        else if(count>1)
            cout<<"Case #"<<t1<<": Bad magician!"<<endl;
        else if(count==1)
            cout<<"Case #"<<t1<<": "<<n<<endl;
    }
    return 0;

}
