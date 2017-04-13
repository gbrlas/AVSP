#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int csize(char *c)
{
   char p='\0';
   int s=0;
   for (; *c; ++c)
      if (p!=*c) 
         p=*c, ++s;
   return s;
}
void adapt(int *per,int k,char *s,char *t)
{
   int i,j;
   for (i=0; s[i]; i+=k) 
      for (j=0; j<k; ++j)
         t[i+j]=s[i+per[j]];
   t[i]=0;
}

int main()
{
   static char rio[8192],mei[8192];
   int t,T;
   for (cin>>T,t=1;t<=T;++t) {
      int i,j,k,l,mc;
      cin>>k>>rio;

      mc=1<<30;
      
      int per[16],ori[16];
      for (i=0;i<k;++i)
         per[i]=ori[i]=i;
      do {
         adapt(per,k,rio,mei);
         mc=min(mc,csize(mei));
         next_permutation(per,per+k);
      } while (!equal(per,per+k,ori));
      cout<<"Case #"<<t<<": "<<mc<<endl;
   }
}
