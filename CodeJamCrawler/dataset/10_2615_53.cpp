#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <iostream.h>

#include <string>

using namespace std;

int	T,
	n,
	n1;
const int	N = 1000,
			M = 52;
char* t[N];

int compare(char* s1, char* s2)
{
	int l1 = strlen(s1),
		l2 = strlen(s2);
	if ( l1 != l2 )
		return  l1 - l2;
	while ( ( l1 >= 0 ) && ( s1[--l1]== s2[--l2] ) );
	if ( l1 < 0 )
		return 0;
	else
		return s1[l1] - s2[l2];
}

void reverse( char* s)
{
	int len = strlen(s);
	int l = len / 2;
	char temp;
	for ( int i = 0; i < l; i++ )
	{
		temp = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = temp;
	}
}

void sub(char* s1, const char* s2)
{
	int l = strlen(s2);
	int i;
	for ( i = 0; i <l; i++ )
	{
		s1[i] = s1[i] - s2[i] + '0';
		if ( s1[i] < '0' ) 
		{
			s1[i] += 10;
			s1[i+1] -= 1;
		}
	}
	l = strlen(s1);
	while ( i < l && s1[i] < '0' )
	{
		s1[i] += 10;
		s1[++i] -= 1;
	}
	while ( l > 1 &&  s1[--l] == '0' ) s1[l] = 0;
}

void sort()
{
	char * temp;
	for ( int i=0; i<n1; i++ )
		for ( int j=n1; j>i; j--)
			if ( compare( t[j], t[j-1] ) > 0 )
			{
				temp = t[j];
				t[j] = t[j-1];
				t[j-1] = temp;
			}
}

bool zero(char* s)
{
	int i;
	int len = strlen(s);
	for ( i=0; i<len; i++ )
		if ( s[i] != '0' )
			break;
	return i==len;
}

int main(int argc, char ** argv)
{
	int i, j, k;

	freopen("p2is.txt", "r", stdin);
	freopen("p2os.txt", "w", stdout);
	
	cin >> T;
	for ( i=0; i<T; i++ )
	{
		cin >> n;
		for ( j=0; j<n; j++ )
		{
			t[j] = new char[M];
			cin >> t[j];
			reverse(t[j]);
		}

		n1 = n-1;
		sort();
		n1--;
		for ( j=0; j<=n1; j++)
			sub( t[j], t[j+1]);
		sort();
		do
		{
			for ( j=0; j<n1; j++)
				sub( t[j], t[j+1]);
			sort();
			while ( n1 > 0 && ( ( compare( t[n1], t[n1-1] )== 0 ) || zero(t[n1]) ) )
				n1--;
		} while ( n1 > 0 );

		while ( compare( t[n-1], t[0] ) > 0 )
			sub( t[n-1], t[0] );
		sub( t[0], t[n-1] );
		reverse(t[0]);
		
		cout << "Case #" << i+1 << ": " << t[0] << endl;
		for ( j=0; j<n; j++ )
		{
			delete t[j];
		}
	}
	
	return 0;
}