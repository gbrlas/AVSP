// welcome to code jam
// Alex Alexander <alex.alexander@gmail.com>
// trying to get back into shape :D

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const char s[] = "welcome to code jam";
const int sc = sizeof(s)/sizeof(char);
long d[500][sc];

long checkString(char *p, int pp, int ss) {
	long r = 0;
	do {
		if ( *(p + pp) == *(s + ss) )
		{
			if ( *(s+ss+1) == '\0')
			{
				r++;
			}
			else if ( d[pp][ss] >= 0 )
				r += d[pp][ss];
			else if ( *(p+pp+1) != '\0' )
			{
				d[pp][ss] = checkString(p, pp+1,ss+1);
				r += d[pp][ss];
			}
		}
	} while ( *(p + ++pp) != '\0' );
	if ( r > 9999 )
		r = r % 10000;
	return r;
}

char* format(long r) {
	char *s = new char[5];
	char tmp[5];
	sprintf(tmp, "%ld", r);
	int l = strlen(tmp);
	int d = 4-l;
	int c = -1;
	while ( ++c < 4 )
	{
		if ( c < d )
			*(s+c) = '0';
		else
			*(s+c) = *(tmp + (c-d));
	}
	return s;
}

int main(int argc, char *argv[]){
   	if ( argc != 2 )
	{
		cout << *(argv) << " data_file" << endl;
		return 1;
	}

	ifstream in(*(argv+1));
	if(!in){
		cout << "Cannot open file.";
		return 1;
	}


	int i,j;

	int lines = 0;
	in >> lines;

	char str[501];
	in.getline(str,501);
	
	int cline = 0;
	while(in && ++cline <= lines){
		in.getline(str, 501);
		for (i = 0; i < 500; i++ )
			for ( j = 0; j <= sc; j++ )
				d[i][j] = -1;
		cout << "Case #" << cline << ": "<< format(checkString(str, 0, 0)) << endl;
	}
	
	in.close();
}
