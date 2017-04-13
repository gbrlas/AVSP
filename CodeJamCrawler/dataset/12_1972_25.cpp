#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(){
  int t;
  cin>>t;
  string transfer = "yhesocvxduiglbkrztnwjpfmaq";
  string line;
  getline(cin,line);
  for(int i=0;i<t;i++){


    getline(cin,line);
    for(int j=0;j<line.size();j++){

      if(line[j] == ' ')continue;
      line[j] = transfer[line[j]-'a'];

    }

    printf("Case #%d: ",i+1);
    cout<<line<<endl;

  }
  return 0;
}
