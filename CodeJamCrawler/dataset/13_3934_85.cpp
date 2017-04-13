#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,n,m,k,flag,full,i,j;
    char a[4][4];
    scanf("%d",&T);
    int cas=0;
    while (T--)
    {
        for(i=0;i<4;i++)
          scanf("%s",a[i]); 
        getchar();                
        flag=0; full=1;
        for(i=0;i<4;i++){
         int x=0,t=0,o=0;
         for(j=0;j<4;j++){
           if(a[i][j]=='X') x++;
           else if(a[i][j]=='O') o++;
           else if(a[i][j]=='T') t++;               
         }
         if(x==4||(x==3&&t==1)){  flag=1;     break; } 
         else if(o==4||(o==3&&t==1)) {  flag=2;    break; }
         else if(x+o+t<4&&full)  {  full=0;  }
        }
        if(!flag){
         for(i=0;i<4;i++){
           int x=0,t=0,o=0;
           for(j=0;j<4;j++){
             if(a[j][i]=='X') x++;
             else if(a[j][i]=='O') o++;
             else if(a[j][i]=='T') t++;               
           }
           if(x==4||(x==3&&t==1)){  flag=1;     break; } 
           else if(o==4||(o==3&&t==1)) {  flag=2;    break; }          
         }
         if(!flag){
           int x=0,t=0,o=0;
           for(i=0;i<4;i++){
             if(a[i][i]=='X') x++;
             else if(a[i][i]=='O') o++;
             else if(a[i][i]=='T') t++;                    
           }
           if(x==4||(x==3&&t==1)){  flag=1;     } 
           else if(o==4||(o==3&&t==1)) {  flag=2;     }  
           if(!flag){
             int x=0,t=0,o=0;
             for(i=0;i<4;i++){
               if(a[i][3-i]=='X') x++;
               else if(a[i][3-i]=='O') o++;
               else if(a[i][3-i]=='T') t++;                    
             }
             if(x==4||(x==3&&t==1)){  flag=1;     } 
             else if(o==4||(o==3&&t==1)) {  flag=2;     }           
          }         
         }
        }
        if(flag==1) printf("Case #%d: X won\n",++cas);
        else if(flag==2) printf("Case #%d: O won\n",++cas);
        else if(flag==0&&full==1) printf("Case #%d: Draw\n",++cas);
        else      printf("Case #%d: Game has not completed\n",++cas);
    }
 // system("pause");
  return 0;
}
