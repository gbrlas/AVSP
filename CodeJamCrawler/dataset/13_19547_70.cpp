#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
#define iss istringstream
#define pb push_back
#define cs c_str()
#define frr(i,a,b) for(i=(a); i<(b); i++)
#define fr(i,n) frr(i,0,(n))
#define rrf(i,b,a) for(i=(b)-1; i>=(a); i--)
#define rf(i,n) rrf(i,(n),0)
#define sq(x,y,z) sqrt((x)*(x)+(y)*(y)+(z)*(z))
#define in(x,s) (s.find(x)!=s.end())
#define sv(x) sort(x.begin(),x.end())

int main()
{
   int T, t, i, j, f;
   char s[8][8];
   string ans;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      ans="";
      fr(i,4) scanf("%s", s[i]);
      fr(i,4)
      {
         fr(j,4) if(s[i][j]!='X' && s[i][j]!='T') break;
         if(j==4) ans="X won";
         fr(j,4) if(s[j][i]!='X' && s[j][i]!='T') break;
         if(j==4) ans="X won";
         fr(j,4) if(s[i][j]!='O' && s[i][j]!='T') break;
         if(j==4) ans="O won";
         fr(j,4) if(s[j][i]!='O' && s[j][i]!='T') break;
         if(j==4) ans="O won";
      }
      fr(i,4) if(s[i][i]!='X' && s[i][i]!='T') break;
      if(i==4) ans="X won";
      fr(i,4) if(s[i][3-i]!='X' && s[i][3-i]!='T') break;
      if(i==4) ans="X won";
      fr(i,4) if(s[i][i]!='O' && s[i][i]!='T') break;
      if(i==4) ans="O won";
      fr(i,4) if(s[i][3-i]!='O' && s[i][3-i]!='T') break;
      if(i==4) ans="O won";
      f=0;
      fr(i,4) fr(j,4) f=f || s[i][j]=='.';
      if(ans=="") ans=f?"Game has not completed":"Draw";
      printf("Case #%d: %s\n", t, ans.c_str());
   }
   
   return 0;
}
