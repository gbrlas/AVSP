#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char str[1000] ;
string ans[10000]; 
map<string,int>ID ;
string res[10000] ;
int code[1111][111] ;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("shark.out","w",stdout);
	int text , Case ; 
	while ( 1 == scanf("%d",&text))
	{
		for (Case = 0 ; Case < text ; Case ++)
		{
			int n ;
			scanf("%d",&n) ;
			gets(str) ; 
			int length , i , j , k , Q;
			ID.clear() ;
			for ( i = 0 ; i < n ; i ++)
			{
				ans[i] = "";
				gets(str) ;
				length = strlen(str) ;
				for ( j = 0 ; j < length ; j ++)
					ans[i] += str[j] ;
				ID[ans[i]] = i ;
			}
			scanf("%d",&Q) ;
			gets(str);
			for ( i = 0 ; i < Q ; i ++)
			{
				res[i] = "" ; 
				gets(str) ;
				length = strlen(str) ;
				for ( j = 0 ; j < length ; j ++)
					res[i] += str[j] ;
			}
			for ( i = 0 ; i < Q ; i ++)
				for ( j = 0 ; j < n ; j ++)
					code[i][j] = 1000000 ; 
			for ( i = 0 ; i < n ; i ++)
			{
				if( ID[res[0]] == i)
					code[0][i] = 1000000 ;
				else 
					code[0][i] = 0 ;
			}
			int Max , temp;
			for ( i = 1 ; i < Q ; i ++)
			{
				for ( k = 0 ; k < n ; k ++)
				{
					if(ID[res[i]] == k)
					{
						code[i][k] = 1000000;
						continue;
					}
					Max = 1000000 , temp; 
					for ( j = 0 ; j < n ; j ++)
					{
						if( k == j)
							temp = code[i-1][j] ;
						else 
							temp = code[i-1][j] + 1;
						if(Max > temp )
							Max = temp ;	
					}
					code[i][k] = Max ;
				}
			}
			Max = 1000000;
			for ( i = 0 ; i < n ; i ++)
				if(Max > code[Q-1][i])
					Max = code[Q-1][i] ;
			printf("Case #%d: %d\n",Case+1,Max);
		}
	}
	return 0 ;
}