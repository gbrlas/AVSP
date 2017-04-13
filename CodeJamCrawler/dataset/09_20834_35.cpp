#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
int tests;
cin>>tests;
int count=1;
while(tests){
string s;
cin>>s;
vector<char>a;
for(int i=0;i<s.length();i++){
  a.push_back(s[i]);
}
bool found=false;
string ans;
while(next_permutation(a.begin(),a.end())){
found=true;
for(int i=0;i<a.size();i++){
ans+=a[i];
}
break;
}
if(found){
cout<<"Case #"<<count<<": ";
cout<<ans<<endl;
}
else{
a.push_back('0');
sort(a.begin(),a.end());
for(int i=0;i<a.size();i++){
if(a[i]!='0'){
swap(a[i],a[0]);
break;
}
}
cout<<"Case #"<<count<<": ";
for(int i=0;i<a.size();i++){
cout<<a[i];
}
cout<<endl;
}
count++;
tests--;
}
}
