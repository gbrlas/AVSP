#include<iostream> 
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string sayi;

struct tutac{
  char deger;
  int opt;  
};


void artir(int from)
{
   char tut;
   int i;
   
   tut = sayi[from];
   
   if(from == 0 && tut == '9')
   {
      for(i=0;i<sayi.length();i++)
      {
	sayi[i] = '0';
      }
      sayi = '1' + sayi;
      
      return;
   }
   
   if(tut == '9')
   {
     sayi[from] = '0';
     artir(from-1);
   } 
   else
   {
     sayi[from] = tut + 1;
   }
    
}


int main()
{
  FILE *f;
  f = fopen("B-small-attempt2.in","r");
  
  rewind(f);
  
  int count,itr,temp,i,j;
  
  fscanf(f,"%d",&count);
  
  char tut;
  fgetc(f);
  
  
  for(itr=0;itr<count;itr++)
  {
      sayi.clear();
      
    while(1)
    {
      tut = fgetc(f);
      
      if(tut == '\n')break;
      if(feof(f))break;
      
      sayi += tut;
    }
    
    //-----------------------------------------------------------------------------------
    
    int boyut = sayi.length();
    
    struct tutac copy[boyut];
        
    for(i=0;i<sayi.length();i++)
    {
      copy[i].deger = sayi[i];
      copy[i].opt   = -1;
    }
    
    int check,t;
    
    while(1)
    {
      artir(sayi.length()-1);
      
      for(i=0;i<sayi.length();i++)
      {
	if(sayi[i] == '0')continue;
	for(j=0;j<boyut;j++)
	{
	  if(sayi[i] == copy[j].deger)
	  {
	    if(copy[j].opt != -1)continue;
	    
	    copy[j].opt = 0;
	    break;
	  }  
	}
      }
	
      for(j=0;j<boyut;j++)if(copy[j].deger == '0') copy[j].opt = 0;
	
      check = 0;
      
      for(j=0;j<boyut;j++)
      {
	if(copy[j].opt != 0)
	{
	  if(copy[j].deger == '0')continue;
	  check = 1;
	  break;
	}
      }
      
      for(j=0;j<boyut;j++) copy[j].opt = -1;
      
      int sc = 0;
      int cc = 0;
      
      for(i=0;i<sayi.length();i++)
      {
	if(sayi[i] == '0')continue;
	sc++;
      }
      
      for(j=0;j<boyut;j++)
      {
	if(copy[j].deger == '0')continue;
	cc++;
      }
      
      if(sc>cc)check = 1;
      
      if(check == 1)continue;
      else break;
	
      
    }
   
   cout<<"Case #"<<(itr+1)<<": "<<sayi;
   
   if(itr != (count-1))cout<<endl;

   
   
  }
 
  
  return 0;
}