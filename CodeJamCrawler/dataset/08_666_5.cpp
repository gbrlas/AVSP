#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t, tt = 0;
  for (cin>>t; t > tt; ++tt)
  {
    cout<<"Case #"<<(tt + 1)<<": ";
    int s, q;
    cin>>s;
//    cout<<endl<<s<<endl;
    vector< string > se(s);
    {
      char cs[200];
      cin.getline(cs, 195);
    }
    for (int i = 0; i < s; ++i)
    {
      char cs[200];
      cin.getline(cs, 195);
      se[i] = cs;
//      cout<<se[i]<<endl;
    }
    cin>>q;
//    cout<<s<<endl;
    vector< int > w(s);
    {
      char cs[200];
      cin.getline(cs, 195);
    }
    for (int qi = 0; qi < q; ++qi)
    {
      string cse;
      char cs[200];
      cin.getline(cs, 195);
      cse = cs;
//      cout<<cse<<endl;
      vector< int > cw(w);
      for (int i = 0; i < s; ++i)
        if (se[i] == cse)
        {
          w[i] = 10000;
          for (int j = 0; j < s; ++j)
          {
            if (j == i)
              continue;
            if (w[j] > (cw[i] + 1))
            {
              w[j] = (cw[i] + 1);
            }
          }
        }
/*      for (int i = 0; i < s; ++i)
        cout<<w[i]<<" ";
      cout<<endl;*/
    }
    int min = 10001;
    for (int i = 0; i < s; ++i)
      if (min > w[i])
        min = w[i];
    cout<<min<<endl;
  }
  return 0;
}
