#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(){
  int t;
  cin>>t;

  int a,b;
  for(int i=0;i<t;i++){
    cin>>a>>b;

    string strA,strB;
    stringstream ssa,ssb;
    ssa << a;
    ssb << b;
    strA = ssa.str();
    strB = ssb.str();

    int cnt = 0;
    for(int j = a;j <= b;j++){
      stringstream sstr;
      sstr << j;
      string str = sstr.str();
      string strn = str;
      for(int k=0;k<str.size();k++){
        str = str.substr(str.size()-1) + str.substr(0,str.size()-1);
        if(str[0] == '0')continue;
        if(strn < str && str <= strB) cnt++;
      }
    }

    printf("Case #%d: %d\n",i+1,cnt);


  }
  return 0;
}
