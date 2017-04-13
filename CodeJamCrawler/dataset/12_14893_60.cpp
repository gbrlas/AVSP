#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>;


using namespace std;

int main(void){
 map<char,char> RS;
 string A = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
 string B = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
 for (size_t i=0;i<A.length();++i){
  RS[A[i]]=B[i];
 }
 RS['q'] = 'z';
 RS['z'] = 'q';
 RS[' '] = ' ';

 int N;
 cin>>N;
  string s;
  getline(cin,s);
 for (size_t i=0;i<N;++i){
  getline(cin,s);
  cout<<"Case #"<<i+1<<": ";
  for (size_t j=0;j<s.length();++j) {
   cout<<RS[s[j]];
  }
  cout<<'\n';
 }
}