#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string genant(int*,int*);
int main()
{
    string ant[101];
    int arr1[16],arr2[16],ans[2];
    int T,i,j;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>ans[0];
        for(j=0;j<16;j++)
            cin>>arr1[j];
        cin>>ans[1];
        for(j=0;j<16;j++)
            cin>>arr2[j];
        ant[i]=genant(arr1+4*ans[0]-4,arr2+4*ans[1]-4);   
    }
    for(i=1;i<=T;i++)
        cout<<"Case #"<<i<<": "<<ant[i]<<endl; 
    return 0;    
}
string genant(int* sour,int* ent)
{
    int i,j,count=0,num;
    stringstream str;
    string ant;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(*(sour+i)==*(ent+j))
            {
                num=*(sour+i);
                count++;    
            }
        }    
    }
    if(count==0)
        ant="Volunteer cheated!";
    if(count>=2)
        ant="Bad magician!";    
    if(count==1)
    {
        str<<num;
        str>>ant;
    }
    return ant;
}
