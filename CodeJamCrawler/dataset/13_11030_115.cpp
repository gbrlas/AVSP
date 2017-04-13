#include <stdio.h>
#include <cstring>

char s[20][20];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        for(int i=0;i<4;i++)
           scanf("%s",s[i]);
        
        int u=-1;
        for(int i=0;i<4;i++)
        {
          int o=0,x=0,t=0;      
          for(int j=0;j<4;j++)
          {
             if(u==-1&&s[i][j]=='.') u=0;
             if(s[i][j]=='T') t++;
             else if(s[i][j]=='O') o++;
             else if(s[i][j]=='X') x++;
          }
          if(x+t==4) u=2;
          else if(o+t==4) u=1;
        }
        
        for(int i=0;i<4;i++)
        {
          int o=0,x=0,t=0;      
          for(int j=0;j<4;j++)
          {
             if(u==-1&&s[j][i]=='.') u=0;
             if(s[j][i]=='T') t++;
             else if(s[j][i]=='O') o++;
             else if(s[j][i]=='X') x++;
          }
          if(x+t==4) u=2;
          else if(o+t==4) u=1;
        }       
        
        
        int o=0,x=0,t=0;
        for(int u=0;u<4;u++)
        {
           if(s[3-u][u]=='T') t++;
           else if(s[3-u][u]=='O') o++;
           else if(s[3-u][u]=='X') x++;
        }
        if(x+t==4) u=2;
        else if(o+t==4) u=1;
        
        o=0,x=0,t=0;
        for(int u=0;u<4;u++)
        {
           if(s[u][u]=='T') t++;
           else if(s[u][u]=='O') o++;
           else if(s[u][u]=='X') x++;
        }
        if(x+t==4) u=2;
        else if(o+t==4) u=1;
        
        printf("Case #%d: ",ca);
        if(u==0) printf("Game has not completed\n");
        else if(u==-1) printf("Draw\n");
        else if(u==1) printf("O won\n");
        else if(u==2) printf("X won\n");
    }
}
