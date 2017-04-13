#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#define cin in

using namespace std;

int main()
{
  ifstream in ("input.txt");
  ofstream out("output.txt");
  int nb_cas;
  in>>nb_cas;
  out.precision(6);
  for(int c=0;c<nb_cas;c++)
  {
    int n,m;
    in>>m>>n;
    vector<double> v(m);
    for(int c2=0;c2<m;c2++)
      in>>v[c2];
    double mini=(double)(2+n);
    for(int c2=0;c2<=m;c2++)
    {
      double probacorrect=1.0;
      for(int c3=0;c3<c2;c3++)
	probacorrect*=v[c3];
      double tmp=probacorrect*(double)((n-c2)+m-c2+1)+(1.0-probacorrect)*(double)((n-c2)+m-c2+2+n);
      mini=min(mini,tmp);
    }
    out<<fixed<<"Case #"<<c+1<<": "<<mini<<endl;
  }
}