#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#define llu unsigned long long int
#define REP(i , a) for(i = 0 ; i < (a) ; i ++)
#define FOR(i , a , b) for(i = a ; i <= (b) ; i ++)
using namespace std;


int main()
{
	unsigned int i , t , size , j , idx;
	const char dec[] = "yhesocvxduiglbkrztnwjpfmaq";
	char buff[102];
	cin >> t;
	cin.getline(buff , 101);
	FOR(i , 1 , t)
	{
		cin.getline(buff , 101);
		size = strlen(buff);
		REP(j , size)
		{
			if(buff[j] == ' ')
				continue;
			idx = buff[j] - 'a';
			buff[j] = dec[idx];
		}
		cout << "Case #" << i << ": " << buff << endl;
	}
	return 0;
}