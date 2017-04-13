#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int A,B;
bool check(int i){
 int z; if(i<10) return true;
 string S="";

 while(i>0){
  z = i%10;
  i/=10;
  S+=char(z+'0');
 }
 for(int i=0;i<S.size();i++) if(S[i]!=S[S.length()-1-i])return false; return true;
}
int main()
{
	int ans=0,T;
 freopen("A.in","r",stdin);freopen("C.out","w",stdout);
 scanf("%d",&T);
 for(int j = 0; j < T; j++){
ans = 0; 
scanf("%d %d",&A,&B);
 for(int i=A;i<=B;i++){
  if(int (sqrt(i))*int (sqrt(i))==i && check(i)) if(check(sqrt(i))) {
//  cout << i << endl; 
ans++;
  }
 }
 printf("Case #%d: %d\n",j+1,ans);
}
}
