//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define ten 10000


int t;
int n;

int a[2000];
int b[2000];

bool f(int x1,int y1,int x2,int y2)
{
 	 return (not (x1<x2 && y1<y2 || x1>x2 && y1>y2 ));
}

int get_ans()
{
 	int ans=0;
 
	for( int i=0;i<n;i++)
	{
	 	 for(int j=i+1;j<n;j++)
		 {
		  		 if( f(a[i],b[i],a[j],b[j]))
		  		 {
				  	 ans++;
				 }
 		 }	 	 
    }
 	return ans;
}
int main()
{
 	//ifstream fin("a.in");
    ifstream fin("A-large.in");
    fin>>t;
	ofstream fout("A-large.out");
	//ofstream fout("a.out");
    for(int i=1;i<=t;i++)
    {
            fin>>n;
            for(int j=0;j<n;j++)
            {
                    fin>>a[j];
                    fin>>b[j];
					//cout<<a[j]<<endl;
            }
			//cout<<endl;
			int ans=get_ans();
            fout<<"Case #"<<i<<": "<<ans<<endl;
    }
    fout.close();
    return 0;
}
 
