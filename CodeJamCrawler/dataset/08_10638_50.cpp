#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

void reset(int *arr, int n1);
void reset(int *arr,int n1)
{
  int i;
  for(i=0;i<n1;i++)
  arr[i] = -1;
}
           
main()
{
      ifstream fin;
      ofstream fout;
      char *num_cases = new char[100];
      fin.open("A-small-attempt3.in",ios::in);
      fout.open("A-small-attempt3.out",ios::out);
      if(!fin)
      {
              cout<<"\n File doe'nt exit ";
              return 0;
      }
      fin.getline(num_cases,100,'\n');
      int N = atoi(num_cases);
      
      char *num_s,*num_q;
      char **search_engine;
      char **query;
      int *temp; 
      int switches = 0;
      int i,j,k,count = 0;
       
      for(i=0;i<N;i++)
      {
        num_s = new char[100];
        fin.getline(num_s,100,'\n');                
        int S = atoi(num_s);
        delete num_s;
        search_engine = new char*[S];
        for(j=0;j<S;j++)
        {
          search_engine[j] = new char[100];
          fin.getline(search_engine[j],100,'\n');
        }
        
        num_q = new char[100];
        fin.getline(num_q,100,'\n');                
        int Q = atoi(num_q);
        delete num_q;
        query = new char*[Q];
        for(j=0;j<Q;j++)
        {
          query[j] = new char[100];
          fin.getline(query[j],100,'\n');
        }
        
        temp = new int[S];
        reset(temp,S);
        
        for(j=0;j<Q;j++)
        {
          for(k=0;k<S;k++)
          {
            if(!strcmpi(query[j],search_engine[k]))
            {
              if(temp[k]==-1)
              {
                 if (count==(S-1))
                 {
                   count = 0;
                   switches++;
                   reset(temp,S);
                 }
                 count++;
                 temp[k] = j;
              }
              break;
            }
          }
        }
      cout<<"Case #"<<(i+1)<<": "<<switches<<"\n";    
      fout<<"Case #"<<(i+1)<<": "<<switches<<"\n";
      switches = 0;
      count = 0;
      delete temp;
      delete []search_engine;
      delete []query;
      }
      
      getch();
      return 0;
}
