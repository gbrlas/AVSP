//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int t;
int r;
int k;
int n;
int a[1010];


int next[1010];
int f[1010];


#define ten 10

class Bigint{
       int num[40];
	   int len;
	   bool flag;
public:
       void Clear()
       {
	   		flag=false;
	   		len=1;
	   		for(int i=0;i<40;i++)
	   		{num[i]=0;}
	   		num[0]=0;
       }
       Bigint()
       {
               Clear();
       }
	   friend std::istream& operator >>(istream &is,Bigint & a);
	   friend std::ostream& operator <<(ostream &os,const Bigint & a);
	   Bigint operator + (Bigint b) const;
	   int operator <=( Bigint &b) const;
	   int operator <( Bigint &b) const; 
	   Bigint operator -(Bigint b) const;
	   Bigint operator +(int b) const;
	   Bigint operator *(int b) const;
	   Bigint operator %(Bigint b) const;  
	   Bigint move(int p)
	   {
	   		  Bigint ans;
	   		  ans.len=len+p;
	   		  for(int i=0;i<len;i++)
	   		  {
			   		  ans.num[i+p]=num[i];
	   		  }
	   		  for(int i=0;i<p;i++)
	   		  {
			   		  ans.num[i]=0;
	   		  }
	   		  return ans;
       }
};
Bigint ff[1010];
Bigint zero;
Bigint cost[1010];
Bigint Bigint::operator *(int b) const
{
 	   Bigint a = * this;
 	   int i;
 	   a.num[a.len]=0;
 	   for(i=0;i<a.len;i++)
 	   {
		   a.num[i]*=b;
       }
       for(i=0;i<a.len-1;i++)
       {
		   if( a.num[i]>=ten )
		   {
		   	     a.num[i+1]+=a.num[i]/ten;
          		 a.num[i]%=ten;
		   }
       }
      i=a.len-1;
	   while( a.num[i]>=ten )
	   {
	   		     a.num[i+1]=a.num[i]/ten;
				 a.num[i]%=ten;
				 i++;
       }
       a.len=i+1;
	   return a;
}
Bigint Bigint::operator +(int b) const
{
 	   Bigint a = * this;
 	   a.num[0]+=b;
 	   int i=0;
 	   while(i<a.len-1 && a.num[i]>=ten )
 	   {
          a.num[i+1]+=a.num[i]/ten;
          a.num[i]%=ten;
          i++;
	   }
	   i=a.len-1;
	   while( a.num[i]>=ten )
	   {
	   		     a.num[i+1]=a.num[i]/ten;
				 a.num[i]%=ten;
				 i++;
       }
       a.len=i+1;
	   return a;
}

int Bigint::operator <( Bigint &b) const
{
 	Bigint a=* this;
 	if( a.len>b.len )
 	{
	 	return false;
	}
	if( a.len<b.len )
	{
	 	return true;
	}
	for(int i=a.len-1;i>=0;i--)
	{
	 		if(a.num[i]!=b.num[i])
	 		{
  	             return a.num[i]<b.num[i];
		    }
	}
	return a.num[0]<b.num[0];
}

int Bigint::operator <=( Bigint &b) const
{
 	Bigint a=* this;
 	if( a.len>b.len )
 	{
	 	return false;
	}
	if( a.len<b.len )
	{
	 	return true;
	}
	for(int i=a.len-1;i>=0;i--)
	{
	 		if(a.num[i]!=b.num[i])
	 		{
  	             return a.num[i]<=b.num[i];
		    }
	}
	return a.num[0]<=b.num[0];
}

Bigint Bigint::operator % (Bigint b) const{
	   Bigint a=* this;
	   Bigint c;
	   for(int i=a.len-b.len;i>=1;i--)
	   {
		  c=b.move(i);
		  while (c<=a)
		  {
		   		a=a-c;
  		  }
	   }
	   while( b<=a )
	   {
	   		  a=a-b;
       }
       return a;
}

Bigint Bigint::operator - (Bigint b) const{
	   Bigint a=* this;
	   if( a<b )
	   {
	   	   a=b-a;
	   	   a.num[a.len-1]=-a.num[a.len-1];
	   	   return a;
	   }
	   int len=0;
	   if(len<a.len) len=a.len;
	   if(len<b.len) len=b.len;
	   int i;
	   for(i=a.len;i<len;i++) a.num[i]=0;
	   for(i=b.len;i<len;i++) b.num[i]=0;
	   for(i=0;i<len;i++)
	   {
			 a.num[i]-=b.num[i];
			 if( a.num[i]<0 && i<len-1 )
			 {
			  	 a.num[i]+=ten;
			  	 a.num[i+1]--;
			 }
	   }
	   while ( len>1 && a.num[len-1]==0 )
	   {
	   		 len--;
       }
       a.len=len;
       a.flag=(a.num[a.len-1]<0);
       return a;
}

Bigint Bigint::operator + (Bigint b) const{
	   Bigint a=* this;
	   int len=0;
	   if(len<a.len) len=a.len;
	   if(len<b.len) len=b.len;
	   int i;
	   for(i=a.len;i<len;i++) a.num[i]=0;
	   for(i=b.len;i<len;i++) b.num[i]=0;
	   for(i=0;i<len;i++)
	   {
			 a.num[i]+=b.num[i];
	   }
       for(i=0;i<len-1;i++)
       {
		   if( a.num[i]>=ten )
		   {
		   	     a.num[i+1]+=a.num[i]/ten;
          		 a.num[i]%=ten;
		   }
       }
       i=len-1;
	   while(   a.num[i]>=ten )
	   {
	   		     a.num[i+1]=a.num[i]/ten;
				 a.num[i]%=ten;
				 i++;
       }
       a.len=i+1;
       return a;
}

std::istream& operator >>(istream &is,Bigint & a)
{
   string s;
   is>>s;
   a.Clear();
   int tmp=0;
   int t=1;
   
   if( s.length()>0 )
   {
   	   int p=0;
   	   if( s[0]=='-' )
   	   {
	   	   a.flag=true;
	   	   p=1;
	   }
	   a.len=0;
	   
	   for(int i=s.length()-1;i>=p;i--)
	   {
	      if(s[i]<='9' && s[i]>='0' )
		  {
	         tmp=tmp+( s[i]-'0')*t ;
	      	 t=t*10;
             if( t>=ten )
	      	 {
			  	 a.num[a.len++]=tmp;
			 	 tmp=0;
			 	 t=1;
			 }
		  }else
		  {
		   	   a.Clear();
		   	   return is;
	      } 
 	   }
 	   if( tmp>0 )
 	   {
	   	   a.num[a.len++]=tmp;
	   }
 	   if( a.len>=1 && a.flag )
 	   {
	   	   a.num[a.len-1]=a.num[a.len-1]*-1;
	   }
   }
   return is;
}

std::ostream& operator <<(ostream &os, const Bigint & a)
{
 
   os<<a.num[a.len-1];
   for(int i=a.len-2;i>=0;i--)
   {
   		   int t=ten/10;
   		   while( a.num[i]<t && t>1)
   		   {
		   		  os<<"0";
		   		  t/=10;
           }
   		   os<<a.num[i];
   }
   return os;
}


void get_list()
{	
	  int i;
	  int j;
	  int p;
	  Bigint t;
	  Bigint kk;
	  kk=kk+k;
	  Bigint Zero;
 	  for(i=0;i<n;i++)
	   {
	      t.Clear();
	      p=i;
	      for(j=0;j<n;j++)
	      {
 			  if( t+a[p] <= kk )
		      {
			   	  t=t+a[p];
			   	  p++;
			   	  if( p==n )
			   	  {
				     p=0;
				  }
	  		  }else
			  {
			   	   break;
		      }  
		  }
		  cost[i]=t;
		  next[i]=p;
	   }
}

Bigint get_ans()
{
 	   get_list();
 	   Bigint ans;
 	   
	   int i;
	   int p=0;
	   for(i=0;i<n;i++) f[i]=-1;
	   f[0]=0;
	   ff[0].Clear();
	   i=1;
	   int step;
	   Bigint cost_step;
	   int rr=r;
	   while(i<=r)
	   {
           ans=ans+cost[p];
           p=next[p];
           rr--;
		   if( f[p]>=0 )
           {
		   	   step=i-f[p];
		   	   cost_step=ans-ff[p];
		   	  // cout<<ans<<"-"<<ff[p]<<"="<<cost_step<<endl;
 	   		   if( rr >=step )
		   	   {
			   	  int d=rr / step;
				//  cout<<cost_step<<"*"<<d<<"="<<cost_step*d<<endl;
                //cout<<ans<<"+"<<cost_step*d<<"=";
				  ans=ans+cost_step*d;
				//  cout<<ans<<endl;
                  rr-=d*step;
				  i+=d*step;
			   }
		   }else
		   {
		   		f[p]=i;
		   		ff[p]=ans;
		   }
   	   	   i++;
	   }  
 	   return ans;
}

int main()
{
 	ifstream fin("C-large.in");
    ofstream fout("C.out");
    fin>>t;     
	for(int i=1;i<=t;i++)
    {
        fin>>r>>k>>n;
        for(int j=0;j<n;j++)
        {
		 		fin>>a[j];
        }
	  	fout<<"Case #"<<i<<": "<<get_ans()<<endl;
    }
    fout.close();

    return 0;
}
