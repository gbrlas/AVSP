#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
char instr[10][10];      
      
int checkvarrow(int row,char var)
{if( (instr[row][0]==var||instr[row][0]=='T') && (instr[row][1]==var||instr[row][1]=='T') && (instr[row][2]==var||instr[row][2]=='T') && (instr[row][3]==var||instr[row][3]=='T') )
     return 1;
else return 0;
}
 
     
int checkvarcol(int col,char var)
{if( (instr[0][col]==var||instr[0][col]=='T') && (instr[1][col]==var||instr[1][col]=='T') && (instr[2][col]==var||instr[2][col]=='T') && (instr[3][col]==var||instr[3][col]=='T') )
     return 1;
else return 0;
}    
 
int checkdaigonal1(char var)
{
   if( (instr[0][0]==var||instr[0][0]=='T') && (instr[1][1]==var||instr[1][1]=='T') && (instr[2][2]==var||instr[2][2]=='T') && (instr[3][3]==var||instr[3][3]=='T')  ) 
    return 1;
    else return 0;
    }  
    
int checkdiagonal2(char var)
{
    if    ( (instr[0][3]==var||instr[0][3]=='T') && (instr[1][2]==var||instr[1][2]=='T') && (instr[2][1]==var||instr[2][1]=='T') && (instr[3][0]==var||instr[3][0]=='T')  ) 
    return 1;
    else return 0;    
}
 
int main()
{
freopen("input","r",stdin);
freopen("output","w",stdout);

int  T,flag=0,count=0;
char req,ntreq;
scanf("%d%*c",&T);
 int casenumber=0;
while(T--)
 
{       casenumber++;
        // scanf("%c",&ntreq);
          flag=0;count =0;
          //Take in the input
          for(int i=0;i<4;i++)
               {
                      scanf("%s",instr[i]);      
                              
               }    
               
          
          
           req='X';
           
           for(int i=0;i<4;i++)
           {
                   
              flag= checkvarrow(i,req);
              //printf("X horizontal row %d %d\n",i,flag);
              
              if(flag) 
              {        
                    break;
              }
                  
           } 
           
           if(flag) 
           {        printf("Case #%d: X won\n",casenumber);
                    continue;
           }
             
            
           for(int i=0;i<4;i++)
           {
                   
              flag= checkvarcol(i,req);
               //printf("vertical col %d %d\n",i,flag);
              if(flag) 
              {        
                    break;
              }
                  
           } 
           if(flag) 
           {printf("Case #%d: X won\n",casenumber);
          continue;
           }
           
           flag=checkdaigonal1(req);
           if(flag) 
           {printf("Case #%d: X won\n",casenumber);
           continue;
           }
           
           
           flag=checkdiagonal2(req);
           if(flag) 
           {printf("Case #%d: X won\n",casenumber);
            continue;
           }           
           
           
           
           
           req='O';
           
           for(int i=0;i<4;i++)
           {
                   
              flag= checkvarrow(i,req);
              //printf("O horizontal row %d %d\n",i,flag);
                if(flag) 
              {        
                    break;
              }  
           } 
           
           if(flag) 
           {        printf("Case #%d: O won\n",casenumber);
            continue;
           }
             
            
           for(int i=0;i<4;i++)
           {
                   
              flag= checkvarcol(i,req);
             // printf("O horizontal row %d %d\n",i,flag);
              if(flag) 
              {        
                    break;
              }
                  
           } 
           if(flag) 
           {printf("Case #%d: O won\n",casenumber);
            continue;
           }
           
           flag=checkdaigonal1(req);
           if(flag) 
           {printf("Case #%d: O won\n",casenumber);
            continue;
           }
           
           
           flag=checkdiagonal2(req);
           if(flag) 
           {printf("Case #%d: O won\n",casenumber);
            continue;
           }          
           
           
           for(int i=0;i<4;i++)
           {
                   for (int j=0;j<4;j++)
                   {
                          if(instr[i][j]=='.')count++;
                          if(count)break; 
                   }
                   if(count)break;
           }
	//printf("\ncount=%d\n",count);
           if(count>0&&flag==0)
           printf("Case #%d: Game has not completed\n",casenumber);
           
           
           
           else  printf("Case #%d: Draw\n",casenumber);
          /* for(int i=0;i<4;i++)
           {for(int j=0;j<4;j++)
           {
           print("")
           }cout<<endl;}   */
            char Temp[10];      
            gets(Temp);         
          
}
 
    
    
// system("pause");  
return 0;
}
