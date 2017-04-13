#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

bool cmp( int a, int b )
{
	return a > b ;
	
};

int main()
{
ifstream cin("A-small-attempt0.in");
//ifstream cin("data.in");
ofstream cout("data.out");

int notc=0;
cin>>notc;

long long ans=0;
long temp=0;
int noe=0, i=0;


for( int z=1; z<= notc; z++ )
{
ans=0;
noe=0;


cin>>noe;
vector<int> v1 ;
vector<int> v2 ;


for( i=0; i<noe;i++ )
{ 
	cin>>temp;
	v1.push_back(temp);
}


for( i=0; i<noe;i++ )
{ 
	cin>>temp;
	v2.push_back(temp);
}

sort( v1.begin(), v1.end() );
sort( v2.begin(), v2.end() , cmp );


for( i=0; i< v1.size(); i++ )
	ans = ans + ( long long )(v1[i] * v2[i]);  
		

cout<<"Case #"<<z<<": "<<ans<<"\n";
}

return 0;
}
