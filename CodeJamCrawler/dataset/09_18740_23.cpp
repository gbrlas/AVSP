#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
  int nt,base;
  char s[100];
  scanf("%d",&nt);
  for(int t=1;t<=nt;t++)
    {
      scanf("%s\n",s);
      map<char,int> mapa;
      mapa[s[0]]=1;
      for(int i=1;s[i];i++)
	{
	  if(mapa.find(s[i])==mapa.end())//se nao existe
	    {
	      if(mapa.size()==1)
		mapa[s[i]]=0;
	      else
		mapa[s[i]]=mapa.size()-1;
	    }
	}
      
      /*
      for(typeof(mapa.begin()) it=mapa.begin();it!=mapa.end();it++)
	printf("%c %d\n",it->first,it->second);
      */

      if(mapa.size()==1)
	base=2;
      else
	base=mapa.size();
      unsigned long long int resp=0;
      //char r[100];
      for(int i=0;s[i];i++)
	{
	  //r[i]=mapa[s[i]]+'0';
	  resp=resp*base+mapa[s[i]];
	  //cout<<i<<"--"<<resp<<endl;
	}
      //r[strlen(s)]='\0';
      //cout<<"rrrr="<<r<<endl;
      //printf("Case #%d: %L\n",t,resp);
      cout<<"Case #"<<t<<": "<<resp<<endl;
      //char *fim;
      //strtoull(r,&fim,base);
      //cout<<"fim="<<fim<<endl;
      //cout<<"Case #"<<t<<": "<<r<<endl;
      
      
    }
  return 0;
}
