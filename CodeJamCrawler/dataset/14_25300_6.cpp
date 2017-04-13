#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
main()
{      FILE *f1,*f2;
      int n,i,j,k,row1,row2,pos=0,count=0;
      int matrix1[4][4],matrix2[4][4],arr[4];
      char bad[]="Bad magician!";
      char cheat[]="Volunteer cheated!";
      f1=fopen("file.c.in","r");
      f2=fopen("output.txt","w");
      fscanf(f1,"%d",&n);
      printf("%d\n",n);
      if(n<1||n>100)
      {
                    printf("\n Exceeds limit!");
                    exit(0);
                    }
      for(i=1;i<=n;i++)
      {
                      fscanf(f1,"%d",&row1);
                      
                      if(row1<1||row1>4)
                      {
                                         printf("\n Invalid row number");getch();exit(0);
                                                                           }
                                        
                      for(j=0;j<4;j++)
                      {
                      for(k=0;k<4;k++)
                      {
                                      fscanf(f1,"%d",&matrix1[j][k]);
                                      if(matrix1[j][k]>16||matrix1[j][k]<1)
                                      {
                                                                           printf("\n Invalid input");getch();exit(0);
                                                                           }
                                      
                                    }  }
                      fscanf(f1,"%d",&row2);
                      
                       if(row2<1||row2>4)
                      {
                                         printf("\n Invalid row number");getch();exit(0);
                                                                           }
                      for(j=0;j<4;j++)
                      {
                      for(k=0;k<4;k++)
                      {
                                      fscanf(f1,"%d",&matrix2[j][k]);
                                        if(matrix2[j][k]>16||matrix2[j][k]<1)
                                      {
                                                                           printf("\n Invalid input");getch();exit(0);
                                                                           }
                                    }  }
                      for(j=0;j<4;j++)
                      {
                                      arr[j]=matrix1[row1-1][j];
                                      }
                                       for(j=0;j<4;j++)
                      {
                                      }
                      
                         for(j=0;j<4;j++)
                      {
                                      for(k=0;k<4;k++)
                                      {
                                                      if(arr[j]==matrix2[row2-1][k])
                                                      {
                                                       pos=k;                           
                                                       count++;
                                                       }
                                                       }
                                                       }
                                                      if(count==1)
                                                      {
                                                      fprintf(f2,"Case #%d: %d\n",i,matrix2[row2-1][pos]);count=0;
                                                     
                                                                  }
                                                                  else if(count<=4&&count>1)
                                                                  {
                                                                       fprintf(f2,"Case #%d: %s\n",i,bad);count=0;
                                                                      
                                                                       }
                                                                       else if(count==0)
                                                                       {
                                                                            fprintf(f2,"Case #%d: %s\n",i,cheat);count=0;
                                                                          
                                                                            }
                                                                           

                                                                            }getch();
                                                                            }
                                                                            
                              
