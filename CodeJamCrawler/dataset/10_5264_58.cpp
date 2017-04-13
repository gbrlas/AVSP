//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define ten 10000


int t;
int n;

int l,p,c;
int get_ans()
{
 	int ans=0;
	int x=p/l/c;
	if( x*l*c<p )
	{
	 		 	x++;
	}
	if(x<=1)
	{
	 		return 0;
	}
	int y=1;
	int t=c;
	while( x>t )
	{
	 	   t=t*c;
	 	   y++;
 	}
 	int z=1;
 	int er=2;
 	
 	while ( y>=er )
 	{
	 	  er=er*2;
	 	  z++;
    }
    
    cout<<" x="<<x<<" y="<<y<<" z="<<z<<endl;
    
 	return z;
}
int main()
{
    ifstream fin("B-small-attempt0.in");
    //ifstream fin("A-large.in");
    fin>>t;
	//ofstream fout("A-large.out");
	ofstream fout("b.out");
    for(int i=1;i<=t;i++)
    {
     		fin>>l>>p>>c;
			//cout<<endl;
			int ans=get_ans();
            fout<<"Case #"<<i<<": "<<ans<<endl;
    }
    fout.close();
    while(1);
	return 0;
}
 
