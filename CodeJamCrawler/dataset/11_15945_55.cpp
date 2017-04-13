 #include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.in");
    ofstream fout;
    fout.open("output.out");
    int ts;
    fin>>ts;
    for(int i=0;i<ts;i++)
    {
        vector<string> x,y;
        string u,ret,t;
        char c[100];
        int n,m,h;
        fin>>n;
        if(n) {for(int j=0;j<n;j++) {fin>>t;x.push_back(t);}}
        fin>>m;
        if(m) {for(int j=0;j<m;j++) {fin>>t;y.push_back(t);}}
        fin>>h>>u;
        ret+=u[0];
        if(n)
        {
            for(int j=0;j<n;j++)
            {
                c[j]=x[j][2];
                x[j].erase(2,1);
            }
        }
        for(int i=1;i<h;i++)
        {
            string tt,ll;
            bool f=0;
            tt+=u[i];
            tt+=ret[ret.size()-1];
            ll=tt;
            reverse(ll.begin(),ll.end());
            for(int j=0;j<n;j++){
            if(tt==x[j] || ll==x[j]) {ret.erase(ret.size()-1,1);ret+=c[j];f=1;}
            }
            if(!f) ret+=u[i];
            tt.clear();
            for(int j=0;j<ret.size();j++)
            {
                for(int k=1;k<ret.size();k++)
                {
                    if(j==k) continue;
                    for(int r=0;r<m;r++){
                    if((ret[j]==y[r][0] && ret[k]==y[r][1]) || (ret[j]==y[r][1] && ret[k]==y[r][0])) ret.clear();}
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
