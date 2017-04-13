//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Bigint{
       int num[1000];
	   int len;
	   bool flag;
public:
       void Clear()
       {
	   		flag=false;
	   		len=1;
	   		num[0]=0;
       }
       Bigint()
       {
               Clear();
       }
	   friend std::istream& operator >>(istream &is,Bigint & a);
	   friend std::ostream& operator <<(ostream &os,const Bigint & a);
	   int operator <=( Bigint &b) const;
	   int operator <( Bigint &b) const; 
	   Bigint operator -(Bigint b) const;
	   Bigint operator %(Bigint b) const;  
};

Bigint zero;

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
       //cout<<a <<"%"<<b;
	   while( b<=a )
	   {
	   		  a=a-b;
       }
	   //cout<<"="<<a<<endl;
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
			  	 a.num[i]+=10;
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

std::istream& operator >>(istream &is,Bigint & a)
{
   string s;
   is>>s;
   a.Clear();
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
	           a.num[ a.len++ ]=s[i]-'0';
	      }else
		  {
		   	   a.Clear();
		   	   return is;
	      } 
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
   for(int i=a.len-1;i>=0;i--)
   {
   		   os<<a.num[i];
   }
   return os;
}

int t;
int n;

Bigint a[1000];

Bigint get_gcd(Bigint x ,Bigint y)
{
 	   Bigint z;
 	   
 	   cout<<"gcd ("<<x<<" , "<<y<<") =";
       if( x<y )
       {
	   	   z=x;
	   	   x=y;
	   	   y=z;
       }
       if( y<=zero )
       {
	   	   return x;
	   }
       z=x%y;
       while( zero<z )
       {
              x=y;
              y=z;
              z=x % y;
       }
       cout<<y<<endl;
	   return y;
       
}

Bigint get_ans()
{
       int i;
       int j;
       Bigint tmp;
       Bigint c;
       bool first=true;
       for(i=0;i<n;i++)
       {
           for(j=0;j<i;j++)
           {
	   			if( a[i]<a[j] )
                {
				 	c=a[j]-a[i];
				}else
				{
	 	            c=a[i]-a[j];
			    }
			    cout<<a[i]<<"-"<<a[j]<<"="<<c<<endl;
				if( first )
				{
				 	tmp=c;
				 	first=false;
		 	    }else
			    {	
					tmp=get_gcd(tmp,c);    
				}
           }
       }
       return tmp;    
}

int main()
{
    ifstream fin("B-small-attempt0.in");
    fin>>t;
    ofstream fout("B-small-attempt0.out");
    for(int i=1;i<=t;i++)
    {
            fin>>n;
            for(int j=0;j<n;j++)
            {
                    fin>>a[j];
                    cout<<a[j]<<endl;
            }
			cout<<endl;
            Bigint gcd=get_ans();
			Bigint ans=a[0] % gcd;
            if( zero < ans )
            {
                ans=gcd-ans;
            }
            fout<<"Case #"<<i<<": "<<ans<<endl;
    }
    fout.close();
    while (1);
    return 0;
}
 
