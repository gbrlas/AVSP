#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;




int main()
{
  FILE *f;
  int L,D,N;
  
  
  
  f = fopen("A-large.in","r");
  rewind(f);
  
  fscanf(f,"%d",&L);
  
  fscanf(f,"%d",&D);
  
  fscanf(f,"%d",&N);
  
  fgetc(f);
  
  char temp;
  vector<char> carrier;
  
  
  while(1)
  {
    temp = fgetc(f);
  
    if(carrier.size() == (L*D))break;
    if(temp == '\n')continue;
    
    
    carrier.push_back(temp);
  }
  
 
  
  
  char temper;
  int i,j,k,th;
    
  struct harf{
    vector<char> kiskac;    
  };
  
  th = 0;
  struct harf kelime[L];
  
  int yertut[D];
  
  for(i=0;i<D;i++)yertut[i]=0;
  
  int case_ = 1;
  
  while(1)
  {
    
    
    if(th >= L)
    {
      th = 0;
      
      temp = fgetc(f);
    
      if(feof(f))break;
      
      
      
      for(i = 0;i<L;i++)
      {
	for(j = 0;j<D;j++)
	{
	  for(k = 0;k<kelime[i].kiskac.size();k++)
	  {
	    
	    if(kelime[i].kiskac[k] == carrier[j*L + i])yertut[j]++;
	  }
	
	}
      
      }
      
      int kac = 0;
      
      for(i=0;i<D;i++)if(yertut[i]>=L)kac++;
      
      for(i=0;i<D;i++)yertut[i]=0;
      
      
      
      if(case_ == 1)cout<<"Case #"<<case_<<": "<<kac;
      else cout<<endl<<"Case #"<<case_<<": "<<kac;
      
      case_++;
    }
    
    
    
    
    temp = fgetc(f);
    
    if(feof(f))break;
    
    
    
    
    if(temp == '(')
    {
      kelime[th].kiskac.clear();
      
      while(1)
      {
	temper = fgetc(f);
	
	if(temper == ')')break;
	
	kelime[th].kiskac.push_back(temper);
	
      }
      
      th++;
      
      continue;
    }
    
    kelime[th].kiskac.clear();
    kelime[th].kiskac.push_back(temp);
    
    th++;
  }
  
  
//  cout<<L<<" "<<D<<" "<<N<<endl;

  return 0;


} 
