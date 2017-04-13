#include<iostream>
#include<map>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int i,j,row,count;
    string a[4][4],pos;
    map<string,int> data;
    map<string,int>::iterator it;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>row;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cin>>a[i][j];
        row=row-1;
        for(j=0;j<4;j++)
        data[a[row][j]]+=1;

        cin>>row;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cin>>a[i][j];
        row=row-1;
        for(j=0;j<4;j++)
        data[a[row][j]]+=1;
        count=0;
        for(it=data.begin();it!=data.end();++it)
        {
         if(it->second==2)
         {
         	count++;
         	pos = it->first;
         }
        }

        if(count==1)
        {cout<<"Case #"<<k<<": "<<pos<<"\n";}
        else if(count>1)
        {
            cout<<"Case #"<<k<<": Bad magician!\n";
        }
        else
        {
            cout<<"Case #"<<k<<": Volunteer cheated!\n";
        }

        data.clear();
    }

    return 0;
}
