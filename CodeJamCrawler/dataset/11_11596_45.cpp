#include<iostream>
#include<string>
#include<fstream>
using namespace std;



int main()
{
    char opp[2000][3],add[2000][4],string[10248];
    char list[1024];
    int count=0;
    int cas;
    int flag=0;
    int c2;    
    ifstream fin;
    int c=0,c1=0;
    ofstream fout;
    fout.open("output.in");
    fin.open("B-large.in");
    if(fin==NULL)
    {
                 cout<<"no such file..";
                 exit(0);
                                  
                 }
    
    fin>>cas;
    //cout<<cas<<"  ";
    
    int n,n1,stringc;;
    for(int i=0;i<cas;i++)
    {
                 fin>>n;
    //cout<<n<<"  ";             
                 for(c=0;c<n;c++)
                 {
                                 fin>>add[c];
                                                         
                                 
                                 }
                  fin>>n1;
                 for(c1=0;c1<n1;c1++)
                 {
                                 fin>>opp[c1];
                                                         
                                 
                                 }
                 fin>>stringc;
                  fin>>string;
         count=0;
         list[0]=string[0];
         count++;           
        // cout<<string<<'\n';
         for(c=1;c<strlen(string);c++)
         {                            
                                      if(count==0)
                                      list[count++]=string[c];
                                      else
                                      {
                                      flag=0;
                                      for(c1=0;c1<n;c1++)
                                      {
                                                         if(string[c]==add[c1][0])
                                                         {
                                                                                  if(list[count-1]==add[c1][1])
                                                                                  {list[count-1]=add[c1][2];
                                                                                  flag=1;  }                       
                                                                                  }
                                                         else
                                                         if(string[c]==add[c1][1])
                                                         {
                                                                                  if(list[count-1]==add[c1][0])
                                                                                  {list[count-1]=add[c1][2];
                                                                                  flag=1;
                                                                                  }
                                                                                  }
                                                         if(flag==1)
                                                         break;
                                                         
                                                         }
                                      if(flag==0)
                                      {
                                                 for(c1=0;c1<n1;c1++)
                                      {
                                                         if(string[c]==opp[c1][0])
                                                         {                       //cout<<string[c]<<"   ";
                                                                                  for(c2=0;c2<count;c2++)
                                                                                  {
                                                                                  if(list[c2]==opp[c1][1])
                                                                                  {count=0;
                                                                                  flag=1;  }                       
                                                                                  }
                                                                                  }
                                                         else
                                                         if(string[c]==opp[c1][1])
                                                         {                        //cout<<string[c]<<"  ";
                                                                                  for(c2=0;c2<count;c2++)
                                                                                  {
                                                                                  if(list[c2]==opp[c1][0])
                                                                                  {count=0;
                                                                                  flag=1;  }                       
                                                                                  }
                                                                                  
                                                                                  }
                                                         if(flag==1)
                                                         break;
                                                                                  
                                                         }
                                                 
                                                 
                                                 
                                                 }
                                                 if(flag==0)
                                                 {
                                                            list[count]=string[c];
                                                            count++;
                                                            }
                                      
                                      }
                                      }
         list[count]='\0';
    cout<<"Case #"<<i+1<<": [";
    fout<<"\nCase #"<<i+1<<": [";
    if(count==0)
    {           cout<<"]";
                fout<<"]";
}
    else
    {
    for(c=0;c<count-1;c++)
    {cout<<list[c]<<", ";
fout<<list[c]<<", ";
}
    cout<<list[c]<<"]\n";
    fout<<list[c]<<"]";
}
    c=getchar(); 
                                                     
                          }
    
    fout.close();
    fin.close();
    
    
    }
