#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define cin fin
ifstream cin("C-small-attempt0.in");
#define cout fout
ofstream cout("c.out");
bool map[110][110];
int s=0;
void init()
{
 	 int r;
 	 int x1,y1,x2,y2;
 	 int i,j,k;
 	 
	 cin>>r;
 	 memset(map,false,sizeof(map));
 	 s=0;

     for( i=0;i<r;i++)
 	 {
	  	  cin>>x1>>y1>>x2>>y2;
	  	  for( j=y1;j<=y2;j++)
	  	  {
		   	   for(k=x1;k<=x2;k++)
		   	   {
			     if( ! map[j][k])
			      s++;
			   	  map[j][k]=true;			   					  
			   					  
									 }
          }
     }
}

void show()
{
 	 cout<<s<<endl;
 	  for(int y=1;y<6;y++)
 	  {
	   		  for(int x=1;x<6;x++)
	   		  {
			   		  if( map[y][x] )
			   		  {
					   	  cout<<"1";
					  }else
					  cout<<"0";
					 
			   		  } cout<<endl;
	   		  }
	   		  cout<<endl;

}

int get_ans()
{
 	int ans=0;
 	int a=0;
 	int b=1;
 	int x=0;
 	int y=0;

 	while( s>0 )
 	{
	 	   ans++;
	 	   for( x=100;x>=1;x--)
	 	   {
		   		for(y=100;y>=1;y--)
		   		{
				   if( map[y][x] )
				   {
				   	   if( !map[y-1][x] && ! map[y][x-1] )
				   	   {
					   	   map[y][x]=false;
					   	   s--;
					   }
				   } else
				   {
				   	 	 if( map[y-1][x] && map[y][x-1] )
				   	 	 {
						  	 map[y][x]=true;
						  	 s++;
						 }
		   	       }	
 	            }
		   	}
		  // 	show();
    }
    return ans;
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
    //while(1);
 	return 0;
}
