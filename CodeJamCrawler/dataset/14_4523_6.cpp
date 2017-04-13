#include <cstdio>
#include <iostream>

using namespace std;

int ar[5][5],er[5][5],N,M,a,b;

int main(){
	
	//~ freopen("girdi.in","r",stdin);
	//~ freopen("girdi.out","w",stdout);
	
	cin>>N;
	
	for( int i=1 ; i<=N ; i++ ){
		
		cin>>a;
		
		for( int j=1 ; j<=4 ; j++ )
			for( int k=1 ; k<=4 ; k++ )
				cin>>ar[j][k];
		
		cin>>b;
		
		for( int j=1 ; j<=4 ; j++ )
			for( int k=1 ; k<=4 ; k++ )
				cin>>er[j][k];
		
		int say=0,kup=0;
		
		for( int j=1 ; j<=4 ; j++ )
			for( int k=1 ; k<=4 ; k++ )
				if( ar[a][j] == er[b][k] ){
					say++;
					kup=ar[a][j];
				}
		if( say==0 )
			cout<<"Case #"<<i<<": Volunteer cheated!"<<endl;
		if( say>1 )
			cout<<"Case #"<<i<<": Bad magician!"<<endl;
		if( say==1 )
			cout<<"Case #"<<i<<": "<<kup<<endl;
	}
	
	return 0;
	
}
