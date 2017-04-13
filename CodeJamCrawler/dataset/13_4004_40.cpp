#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   int T,i,j,count,flag;
   char a[4][4],temp;
   ifstream fin;  // declarations of streams fp_in and fp_out
   ofstream fout;
   fin.open("A.in", ios::in);    // open the streams
   fout.open("ans.txt", ios::out);
   fin>>T;
   
   for(int t=0;t<T;t++)
   {
           
           fout<<"\nCase #"<<t+1<<": ";
           flag=0;
           
           for (i=0;i<4;i++)
           {
               for (j=0;j<4;j++)
               {
                   fin>>a[i][j];
                   if(a[i][j]=='.')
                   flag=1;
                   }
               }
           
           
           for (i=0;i<4;i++)
           {
               count=1;
               temp=a[i][0];
               if (temp=='T')
               temp=a[i][1];
               if (temp=='.')
               continue;
               
               for (j=1;j<4;j++)
               {
                   if(a[i][j]==temp || a[i][j]=='T')
                   {
                                    count++;
                                    continue;
                                    }
                   else
                   break;
                   }
               if(count==4)
               {
                           fout<<temp<<" won";
                           goto start;
                           }
               }
               
           for (i=0;i<4;i++)
           {
               count=1;
               temp=a[0][i];
               if (temp=='T')
               temp=a[1][i];
               if(temp=='.')
               continue;
               
               for (j=1;j<4;j++)
               {
                   if(a[j][i]==temp || a[j][i]=='T')
                   {
                                    count++;
                                    continue;
                                    }
                   else
                   break;
                   }
               if(count==4)
               {
                           fout<<temp<<" won";
                           goto start;
                           }
               }
               
               temp=a[0][0];
               if (temp=='T')
               temp=a[1][1];
               if(temp=='.')
               goto skip1;
               if((a[1][1]==temp||a[1][1]=='T')&&(a[2][2]==temp||a[2][2]=='T')&&(a[3][3]==temp||a[3][3]=='T'))
               {
                                                                                                              fout<<temp<<" won";
                                                                                                              goto start;
                                                                                                              }
               
skip1:
               temp=a[0][3];
               if (temp=='T')
               temp=a[1][2];
               if(temp=='.')
               goto skip2;
               if((a[1][2]==temp||a[1][2]=='T')&&(a[2][1]==temp||a[2][1]=='T')&&(a[3][0]==temp||a[3][0]=='T'))
               {
                                                                                                              fout<<temp<<" won";
                                                                                                              goto start;
                                                                                                              }
               
skip2:
               if(flag==1)
               fout<<"Game has not completed";
               else
               fout<<"Draw";
             start:  ;}


return 0;}
    
