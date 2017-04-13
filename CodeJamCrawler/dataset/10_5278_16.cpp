#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define cin fin
ifstream cin("B-small-attempt1.in");
#define cout fout
ofstream cout("b.out");

int er[11];
int p;
int m[1100];
int s[1100][1100];
int n;
int need[1100];

void init()
{
     er[11];
 	 er[1]=2;
 	 er[0]=1;
 	 for( int i=2;i<=10;i++)
 	 {
	  	  er[i]=er[i-1]*2;
     }
 	 cin>>p;
 //	 cout<<p<<endl;
     n=er[p];
     //cout<<n<<endl;
 	 for( int i=0;i<n;i++)
 	 {
	  	  cin>>m[i];
     }
    int pp=p-1;
     memset(s,-1,sizeof(s));
    int i=0;
     while(pp>=0 )
     {
          for( int j=0;j<er[pp];j++)
	      {
		   	   cin>>s[i][j];
          //	   cout<<s[i][j];
		  }
		 // cout<<endl;
        i++;
        pp--;
	}
}

int fill(int level,int pos)
{
 	for(int i=0;i<n;i++)
 	{
	 		if( i / er[level]==pos )
	 		{
			 	need[i]--;
			}
    }
}
int get_ans()
{
 
	 for(int i=0;i<n;i++)
 	{
	 		 need[i]=p-m[i];
	}
	int sum=0;
	for( int i=0;i<n;i++)
	{
	 	 for( int k=p-1;k>=0;k--)
	 	 {
		  	  int pos=i / er[k+1];
		  	  if( s[k][pos]>=0 && need[i]>0 )
		  	  {
			   	  sum+=s[k][pos];
			   	  fill(k+1,pos);
			   	  s[k][pos]=-1;
			  }
         }
    }
    return sum;
}
int main()
{
 	int ti;
 	int t;
 	cin>>t;
 	for( ti=1;ti<=t;ti++)
 	{
	 	 init();
	 	 cout<<"Case #"<<ti<<": "<<get_ans()<<endl;
    }
 	return 0;
}
