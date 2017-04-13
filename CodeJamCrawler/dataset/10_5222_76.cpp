//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
string get_ans(int n,int k)
{
       if( n<=0 || k<=0 )
       {
           return "OFF";
       }
       int tmp=0;
       int i;
       for(i=1;i<=n ;i++)
       {
           tmp=k % 2;
           if( tmp==0 )
           {
		   	   return "OFF";
		   }
           k/=2;
       }
       if( tmp==1 )
       {
           return "ON";
       }else
       {
            return "OFF";
       }
}
int main()
{
    int t;
    int n;
    int k;
    
    ifstream fin("A-small-attempt3.in");
    fin>>t;
    ofstream fout("A-small-attempt3.out");
    for(int i=1;i<=t;i++)
    {
            fin>>n>>k;
            //cout<<n<<" "<<k<<endl;
            fout<<"Case #"<<i<<": "<<get_ans(n,k)<<endl;
    }
    fout.close();
    return 0;
}
