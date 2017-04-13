#include <iostream>
#include <cstdio>
using namespace std;
int T;
char map[4][4];
bool check(char x){
 int z=0; for(int i=0;i<4;i++) if(map[i][i]==x || map[i][i]=='T')z++;
 if(z==4)return true; z=0;
 for(int i=0;i<4;i++) if(map[i][3-i]==x || map[i][3-i]=='T')z++;
 if(z==4) return true; z=0;
 for(int j=0;j<4;j++){
 
 for(int i=0;i<4;i++) 
 if(map[j][i]==x || map[j][i]=='T')z++;
  if(z==4) return true; z = 0;
 }
for(int j=0;j<4;j++){
 for(int i=0;i<4;i++) 
 if(map[i][j]==x || map[i][j]=='T')z++;
  if(z==4) return true; z = 0;
 }return false;
}
int main()
{
 freopen("A.in","r",stdin);freopen("A.out","w",stdout);
 scanf("%d",&T); 
 bool dot = false;
 for(int i=0;i<T;i++){
 for(int j=0;j<4;j++)scanf("%s",map[j]);  
 for(int j=0;j<4;j++) for(int k=0;k<4;k++){
  if(map[j][k]=='.')dot=true;}
  	if(check('X')) printf("Case #%d: X won\n",i+1);
    else if(check('O')) printf("Case #%d: O won\n",i+1);
    else if(dot) printf("Case #%d: Game has not completed\n",i+1);
    else { printf("Case #%d: Draw\n",i+1);
    }
 dot = false;
 }
}
