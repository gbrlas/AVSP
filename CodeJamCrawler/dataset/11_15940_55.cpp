 #include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.in");
    ofstream fout;
    fout.open("output.out");
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        string x,y,u,ret;
        char c;
        int n,m,h;
        fin>>n;
        if(n==1) fin>>x;
        fin>>m;
        if(m==1) fin>>y;
        fin>>h>>u;
        ret+=u[0];
        if(n){c=x[2];
        x.erase(2,1);}
        for(int i=1;i<h;i++)
        {
            string tt,ll;
            tt+=u[i];
            tt+=ret[ret.size()-1];
            ll=tt;
            reverse(ll.begin(),ll.end());
            if(tt==x || ll==x) {ret.erase(ret.size()-1,1);ret+=c;/*cout<<ret<<endl;*/}
            else ret+=u[i];
            tt.clear();
            for(int j=0;j<ret.size();j++)
            {
                for(int k=1;k<ret.size();k++)
                {
                    if(j==k) continue;
                    if((ret[j]==y[0] && ret[k]==y[1]) || (ret[j]==y[1] && ret[k]==y[0])) ret.clear();
                }
            }
        }
      fout<<"Case #"<<i+1<<": ";
      if(ret.size()==0) fout<<"[]\n";
      else fout<<'[';
      for(int j=0;j<ret.size();j++)
      {
          if(j==ret.size()-1) fout<<ret[j]<<"]\n";
          else fout<<ret[j]<<", ";
      }
    }
    return 0;
}
