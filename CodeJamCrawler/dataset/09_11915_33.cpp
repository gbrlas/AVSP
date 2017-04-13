//This problem is submitted by Jitesh
#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);//selecting input file
    freopen("output.txt","w",stdout);// selection output file
    int L,D,N,i,j,k,l,m,flag=0,token,count,result,totalcount,flag1;
    char s[5001][20],input[20000],test,tokenlist[20][1000];
    scanf("%d%d%d",&L,&D,&N);
    for(i=0;i<D;i++)
    {
                    scanf("%s",s[i]);
    }
    for(i=0;i<N;i++)
    {
                    result=0;
                    scanf("%s",input);
                    j=0;
                    token=0;
                    count=0;
                    while(input[j]!='\0')
                    {                
                       count=0;
                       if(input[j]=='(')
                       {
                           do {
                              j++;
                              for(k=0;k<D;k++)
                              {
                                if(s[k][token]==input[j])
                                {
                                     tokenlist[token][count]=input[j];
                                     count++;
                                     break;
                                }        
                              }
                           }while(input[j]!=')');
                       } 
                       else 
                       {
                           for(k=0;k<D;k++)
                           {
                                if(s[k][token]==input[j])
                                {
                                    tokenlist[token][count]=input[j];                                                         
                                     count++;
                                     break;
                                }
                           } 
                       }
                       j++;
                       tokenlist[token][count]=0;
                       token++;
                       if(count==0)
                       break;                      
                       }
                       for(k=0;k<D;k++)
                       {               flag1=0;
                                       for(l=0;l<L;l++)
                                       {
                                          flag=0;
                                          m=0;
                                          while(tokenlist[l][m]!=0)
                                          {
                                              if(s[k][l]==tokenlist[l][m])
                                              {
                                                  flag=1;
                                                  break;
                                              }
                                              m++;
                                          }
                                          if(flag==1)
                                          {
                                                 flag1++;          
                                          }
                                          else
                                          break;                                     
                                       }
                                       if(flag1==L)
                                       result++;
                      }
                      printf("Case #%d: %d\n",i+1,result);
                    }
//while(1);           
//getch();
    return 0;
}


