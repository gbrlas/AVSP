#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int toMinute(int h, int m)
{
    return (h*60 + m);
}

void sort(int *arr,int n)
{
  int i,j,large,index;
  for(i=n-1;i>0;i--)
  {
     large = arr[0];
     index = 0;
     for(j=1;j<=i;j++)
     if(arr[j]>large)
     {
        large = arr[j];
        index = j;
     }
     arr[index] = arr[i];
     arr[i] = large;
  }     
}
           
main()
{
      ifstream fin;
      ofstream fout;
      char *num_cases = new char[100];
      fin.open("B-large.in",ios::in);
      fout.open("B-large.out",ios::out);
      if(!fin)
      {
              cout<<"\n File doe'nt exit ";
              return 0;
      }
      fin.getline(num_cases,10,'\n');
      int N = atoi(num_cases);
      
      char *tat,*numA,*numB;
      char *dh,*dm,*ah,*am;
      int *dA,*aA,*dB,*aB;
      int i,j,k;
      int A,B;
      
     for(k=0;k<N;k++) 
     {
      tat = new char[10];
      fin.getline(tat,10,'\n');
      int T = atoi(tat);
      delete tat;
      
      numA = new char[10];
      fin.getline(numA,10,' ');
      int NA = atoi(numA);
      delete numA;
      
      numB = new char[10];
      fin.getline(numB,10,'\n');
      int NB = atoi(numB);
      delete numB;
      
      if(NA==0 || NB==0)
      {
        A = NA;
        B = NB;
        goto lb;
      }
      
      dA = new int[NA];
      aA = new int[NA];
      dB = new int[NB];
      aB = new int[NB];
      
      for(i=0;i<NA;i++)
      { 
      dh = new char[10];
      fin.getline(dh,10,':');
      dm = new char[10];
      fin.getline(dm,10,' ');
      dA[i] = toMinute(atoi(dh),atoi(dm));
      delete dh;
      delete dm;
      
      ah = new char[10];
      fin.getline(ah,10,':');
      am = new char[10];
      fin.getline(am,10,'\n');
      aA[i] = toMinute(atoi(ah),atoi(am)) + T;
      delete ah;
      delete am;
      }
      
      for(i=0;i<NB;i++)
      { 
      dh = new char[10];
      fin.getline(dh,10,':');
      dm = new char[10];
      fin.getline(dm,10,' ');
      dB[i] = toMinute(atoi(dh),atoi(dm));
      delete dh;
      delete dm;
      
      ah = new char[10];
      fin.getline(ah,10,':');
      am = new char[10];
      fin.getline(am,10,'\n');
      aB[i] = toMinute(atoi(ah),atoi(am)) + T;
      delete ah;
      delete am;
      }
      
      sort(dA,NA);
      sort(aA,NA);
      sort(dB,NB);
      sort(aB,NB);
      
      A = NA, B = NB;
      
      j=NB-1;
      for(i=NA-1;(i>=0&&j>=0);i--)
      {                
           if(aA[i] <= dB[j])
           {
             B--;
             j--;
           }                
      }
      
      j=NA-1;
      for(i=NB-1;(i>=0&&j>=0);i--)
      {                
           if(aB[i] <= dA[j])
           {
             A--;
             j--;
           }              
      }
      
      delete dA;
      delete aA;
      delete dB;
      delete aB;
      
      lb:
      cout<<"Case #"<<(k+1)<<": "<<A<<" "<<B<<"\n";
      fout<<"Case #"<<(k+1)<<": "<<A<<" "<<B<<"\n";
     }
      getch();
      return 0;
}
