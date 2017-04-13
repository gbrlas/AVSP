#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long ulong;

int numCases;
int d[10];

int main (int argc, char * const argv[]) 
{
	if ( argc != 2 ) return -1;
	
	ifstream fileIn(argv[1], ifstream::in);
	
	if ( fileIn.good() == false ) return -1;
	
	fileIn >> numCases;
	
	for ( int caseIndex = 0; caseIndex < numCases; caseIndex++ )
	{
		cout << "Case #" << caseIndex + 1 << ": ";
		char s[64];
		fileIn >> s;
		memset(d, 0, 10 * sizeof(int));
		int slen = strlen(s);
		for ( int i = 0; i < slen; i++ )
		{
			d[s[i] - '0']++;
		}
		
		bool largest = true;
		for ( int i = 0; i < slen - 1; i++ )
		{
			if ( s[i] < s[i+1] )
			{
				largest = false;
				break;
			}
		}
		
		if ( largest )
		{
			int d2[10];
			memcpy(d2, d, sizeof(int) * 10);
			char small[64];
			char * psmall = small;
			int i = 1;
			while ( d2[i] == 0 )
			{
				i++;
			}
			*psmall = i + '0';
			psmall++;
			d2[i]--;
			
			d2[0]++;
			
			for ( int j = 0; j < 10; j++ )
			{
				while ( d2[j] > 0 )
				{
					*psmall = j + '0';
					psmall++;
					d2[j]--;
				}
			}
			
			*psmall = 0;
			cout << small;
		} else
		{
			//cout << "here";
			next_permutation(s, s + slen);
			cout << s;
		}
		cout << endl;
	}
	
	fileIn.close();
	return 0;
}


