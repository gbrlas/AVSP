#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
  ofstream out("output.txt");
  int nb_cas;
  cin>>nb_cas;
  for(int c=0;c<nb_cas;c++)
  {
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int c2=0;c2<n;c2++)
    {
      cin>>v[c2].first>>v[c2].second;
    }
    int act=0;
    vector<int> tab(n);
    int z=0;
    fill(tab.begin(),tab.end(),0);
    while(n*2!=act)
    {
      bool progr=false;
      for(int c2=0;c2<n;c2++)
	if(act>=v[c2].second&&tab[c2]<2){
	  act+=2-tab[c2];
	  tab[c2]=2;
	  progr=true;
	  z++;
	  cout<<c2<<endl;
	}
      if(progr)
	continue;
      int mini=-1;
      int indice=-1;
      for(int c2=0;c2<n;c2++)
	if(act>=v[c2].first&&mini<v[c2].second&&tab[c2]<=0)
	{
	  mini=v[c2].second;
	  indice=c2;
	}
	if(indice==-1)
	{
	  z=-1;
	  break;
	}
	z++;
	act++;
      cout<<indice<<endl;
      tab[indice]=1;
    }
    out<<"Case #"<<c+1<<": ";
    if(z==-1)
    out<<"Too Bad";
    else out<<z;
    out<<endl;
    cout<<endl;
  }
}