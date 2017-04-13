#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map<char,char> table;
string a,b;
int main(){
  a = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeq";
  b = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupaoz";
  int n = a.length();
  for(int i=0;i<n;++i){
    table[a[i]] = b[i];
  }
  table['z'] = 'q';
  cin>>n;
  string str;
  getline(cin,str);
  for(int t=1;t<=n;++t){
    printf("Case #%d: ",t);
    getline(cin,str);
    int m = str.length();
    for(int i=0;i<m;++i){
      if(str[i]==' ') cout << " ";
      else cout << table[str[i]];
    }
    cout << endl;
  }
  return 0;
}
