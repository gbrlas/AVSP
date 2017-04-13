#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

#define MAX 107

char Code[MAX+7][MAX+7];
long C,D,N;
vector<char> Op[MAX+7];

vector<long> Ans;
//set<long> s;

/*
bool FindOp( char Ch )
{
	long i;
	for( i=0;i<Op[Ch].size();i++){
		if( s.find( Op[Ch][i]) != s.end()) return true;
	}
	return false;
}*/

bool FindOp( char Ch )
{
	long i,j;
	for( i=0;i<Op[Ch].size();i++){
		for( j=0;j<Ans.size();j++){
			if( Ans[j]==Op[Ch][i] ) return true;
		}
	}
	return false;
}

int main( void )
{
	long i,Icase,k=0;
	char Ch1,Ch2,Ch3,Ch;

	freopen("B.in","r",stdin );
	freopen("B.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld",&C );
		for( i=1;i<=C;i++){
			scanf(" %c %c %c",&Ch1,&Ch2,&Ch3 );
			Code[Ch1][Ch2] = Code[Ch2][Ch1] = Ch3;
		}

		scanf("%ld",&D );
		for( i=1;i<=D;i++){
			scanf(" %c %c",&Ch1,&Ch2 );
			Op[Ch1].push_back( Ch2 );
			Op[Ch2].push_back( Ch1 );
		}

		scanf("%ld",&N );
		Ans.clear();
		char Last = 0;
		//s.clear();
		for( i=1;i<=N;i++){
			scanf(" %c",&Ch );
			if( Code[Last][Ch] ){
				Ans.pop_back();
				Ans.push_back( Code[Last][Ch] );
				//s.erase( Last );
				//s.insert( Code[Last][Ch]);
				Last = 0;
			}
			else if( FindOp( Ch )){
				Ans.clear();
				//s.clear();
				Last = 0;
			}
			else{
				Ans.push_back( Ch );
				//s.insert( Ch );
				Last = Ch;
			}
		}

		printf("Case #%ld: [",++k);
		//if( Ans.size()==1 ){
			//printf("%ld ",
		for( i=0;i<Ans.size();i++){
			if( i ) printf(", ");
			printf("%c",Ans[i] );
		}
		printf("]\n");

		memset( Code,0,sizeof(Code ));
		for( i=0;i<=MAX;i++){
			Op[i].clear();
		}
	}

	return 0;
}



