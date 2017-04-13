#include "iostream"
#include "math.h"
#include "fstream"

using namespace std;

int main()
{
 
 ifstream fin;
 ofstream fout;
 fin.open("A-small.in",ios::in);
 fout.open("A-small.out",ios::out);
 
 int t,n,k;
 fin>>t;
 for ( int i=1;i<=t;i++)
 {
       fin>>n>>k;
       k++;
       int flag=0;
//       for ( int j=0;j<n;j++)
       {
             int temp = pow(2,n);
           flag = k%(int)pow(2,n);
//           if ( flag )
//              break;
       }
       if ( flag!=0  )
       {
            fout<<"Case #"<<i<<": OFF"<<endl;
        }
        else
        {
            fout<<"Case #"<<i<<": ON"<<endl;
        }
 }
 
}
