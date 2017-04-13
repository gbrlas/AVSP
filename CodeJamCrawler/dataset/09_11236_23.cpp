#include<iostream> 
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

long long int yap(int base, string ss)
{
  long long int carp = 1;
  int j;
  long long int sonuc = 0;
  
  for(j=ss.length()-1;j>-1;j--)
  {
    sonuc += (ss[j] - 48)*carp;
    carp *= base;
  }
  
  return sonuc;
  
}


int main()
{
  FILE *f;
  f = fopen("A-small-attempt0.in","r");
  
  rewind(f);
  
  int count,itr,temp,i,j;
  
  fscanf(f,"%d",&count);
  fgetc(f);
  
  string sayi;
  char tut;
  
  vector<char> types;
  
  for(itr=0;itr<count;itr++)
  {
    sayi.clear();
    types.clear();
    
     while(1)
    {
      tut = fgetc(f);
      
      if(tut == '\n')break;
      if(feof(f))break;
      
      sayi += tut;
    }
    
    int check = 0;
    
    for(i=0;i<sayi.length();i++)
    {
      check = 0;
      
      for(j=0;j<types.size();j++)
      {
	if(types[j] == sayi[i])
	{
	  check = 1;
	  break;
	}
		
      }
      
      if(check != 1)types.push_back(sayi[i]);
      
    }
    
    int base = types.size();
    int baser = '0';
    char cur;
    int dd[sayi.length()];
    
    for(j = 0;j<sayi.length();j++)dd[j]=-1;
    
    cur = sayi[0];  
    
    for(i=0;i<sayi.length();i++)
    {
      if(cur == sayi[i])
      {
	sayi[i] = '1';
	dd[i]   =  0;
      }
    }
    
    for(i=0;i<sayi.length();i++)
    {
      if(dd[i] == 0)continue;
      
      cur = sayi[i];
      
       for(j=i;j<sayi.length();j++)
	{
	  if(dd[j] == 0)continue;
	  
	  if(cur == sayi[j])
	  {
	   sayi[j] = baser;
	   dd[j] = 0;
	  }
	  
	}
      
      if(baser == '0')baser = '2';
      else baser++;
      
    }
    
    long long int don = yap(base,sayi);
    
    cout<<"Case #"<<itr+1<<": "<<don;
    if(itr != count-1)cout<<endl;
    
  }
 
  
  return 0;
}