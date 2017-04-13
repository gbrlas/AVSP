#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string genant(double*,double*,int);
int main()
{
    string  ant[51];
    double arr1[1001]={0.0},arr2[1001]={0.0};
    int T,N,i,j;
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>N;
        for(j=0;j<N;j++)
            cin>>arr1[j];
        for(j=0;j<N;j++)
            cin>>arr2[j];
        ant[i]=genant(arr1,arr2,N);  
    }
    for(i=1;i<=T;i++)
        cout<<"Case #"<<i<<": "<<ant[i]<<endl; 
    return 0;    
}
string genant(double* sour,double* ent,int n)
{
    int i=n-1,j=n-1,count=0;
    string ant,tmp;
    stringstream str1,str2;
    sort(sour,sour+n);
    sort(ent,ent+n);
    count=0;
    while(i>=0&&j>=0)
    {
        if(sour[i]>ent[j])
        {
            i--;
            j--;
            count++;    
        }
        else
            j--;
    }  
    str1<<count;
    str1>>tmp;
    ant=tmp+" ";
    i=0;
    j=0;
    count=0;
    while(i<n&&j<n)
    {
        if(sour[i]<ent[j])
        {
            i++;
            j++;
            count++;    
        }
        else
            j++;    
    }
    str2<<n-count;
    str2>>tmp;
    ant+=tmp;
    return ant;
}
