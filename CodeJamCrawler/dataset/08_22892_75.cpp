#include <cstdlib>
//#include <iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;
ofstream fout("A-small.out");
ifstream cin("A-small.in");
int solve (int &s,int qarr[],int &q)
{
     /*for(int i=0;i<q;i++)
     {
             cout<<qarr[i]<<" ";
     }
     cout<<endl;*/
     if(q<s) return 0;
     int i,j;
     int currmax=0,curri=qarr[0];
     for(i=0;i<s;i++)
     {
      for(j=0;j<q;j++)
      {
       if(qarr[j]==i)
       {
        if(currmax<j) {currmax=j; curri =i;}
        break;
       }
      }
      if(j==q) return 0;
     }
     int q1= q-currmax;
     return 1+solve(s,qarr+currmax,q1);
     
}
int main()
{
    int n;
    cin>>n;
    int i,j,s,q;
    string temp;
    for(i=0;i<n;i++)
    {
     cin>>s;
     string sarr[s];
     getline(cin,temp,'\n');
     map <string,int> marr;
     for(j=0;j<s;j++)
     {
      getline(cin,sarr[j],'\n');
    //  cout<<sarr[j]<<"-"<<j<<endl;
      marr[sarr[j]]=j;
     }
     cin>>q;
     int qarr[q];
     getline(cin,temp,'\n');
     for(j=0;j<q;j++)
     {
      getline(cin,temp,'\n');
      qarr[j]=marr[temp];
     }              
     /*for(j=0;j<s;j++)
     {
      cout<<sarr[j]<<"-"<<j<<endl;
     }
     for(j=0;j<q;j++)
     {
      cout<<qarr[j]<<endl;
     }*/
     fout <<"Case #"<<i+1<<": "<< solve(s,qarr,q)<<endl;
    
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
