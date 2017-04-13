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
 
 int t,n,k,r;
 fin>>t;
 for ( int i=1;i<=t;i++)
 {
       fin>>r>>k>>n;
       int *g = new int[n];
       for ( int j=0;j<n;j++)
           fin>>g[j];
       
       int pos=0,tot=0;
       for ( int j=0;j<r;j++)
       {
           int ppl=0,gc=0;
           while ( ppl+g[pos%n] <= k && gc<n )
           {
                 ppl+=g[pos%n];
                 pos++;
                 gc++;
           }
           tot+=ppl;
       }
       fout<<"Case #"<<i<<": "<<tot<<endl;
 }

}
