#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

void sort(long int *arr,int n)
{
  int i,j,index;
  long int small;
  for(i=n-1;i>0;i--)
  {
     small = arr[0];
     index = 0;
     for(j=1;j<=i;j++)
     if(arr[j]<small)
     {
        small = arr[j];
        index = j;
     }
     arr[index] = arr[i];
     arr[i] = small;
  }     
}

main()
{
      ifstream fin;
      ofstream fout;
      char *num_cases = new char[10];
      fin.open("input1.in",ios::in);
      fout.open("output1.out",ios::out);
      if(!fin)
      {
              cout<<"\n File doe'nt exit ";
              return 0;
      }
      fin.getline(num_cases,10,'\n');
      int N = atoi(num_cases);
      //cout<<" "<<N;
      
      char *p,*k,*l,*fq;
      long int *freq;
      int P,K,L,j,len,a,count;
      
      for(int i=0;i<N;i++)
      {
        p = new char[10];
        fin.getline(p,10,' ');
        P = atoi(p);
        //cout<<" "<<P;
        
        k = new char[10];
        fin.getline(k,10,' ');
        K = atoi(k);
        //cout<<" "<<K;
        
        l = new char[10];
        fin.getline(l,10,'\n');
        L = atoi(l);
        //cout<<" "<<L;
        
        freq = new long int[L];
        for(j=0;j<(L-1);j++)
        {
          fq = new char[10];
          fin.getline(fq,10,' ');
          freq[j] = atoi(fq);
          //cout<<" "<<freq[j];
          delete fq;
        }
        fq = new char[10];
        fin.getline(fq,10,'\n');
        freq[L-1] = atoi(fq);
        //cout<<" "<<freq[L-1]<<"\n";
        delete fq;
        
        sort(freq,L);
        
        for(j=0;j<L;j++)
        //cout<<" "<<freq[j];
        
        len = L;
        //a = 0;
        count = 0;
        //cout<<"\n";
        for(a=0;a<P && len;a++)
        {
           for(j=0;j<K && len;j++)
           {
             count += ((freq[a*K + j])*(a+1));
             len--;
             //cout<<" "<<count;
           }
        }
        
        //cout<<"\n "<<count;
        cout<<"Case #"<<(i+1)<<": "<<count<<"\n";    
        fout<<"Case #"<<(i+1)<<": "<<count<<"\n";              
        
        delete p;
        delete k;
        delete l;
        delete freq;
      }
      
      getch();
      return 0;
}

      
