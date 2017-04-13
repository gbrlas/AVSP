#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.txt", "w", stdout);
	char inb[110], outb[110], Ts[100];
	char translate[] = "yhesocvxduiglbkrztnwjpfmaq";
	int T = 0;
	gets(Ts);
	T = atoi(Ts);
	for (int k = 0; k < T; k++)
	{
	    gets(inb);
		int n = strlen(inb);
		for (char i = 0; i < n; i++)
		{
			if (inb[i] != ' ') outb[i] = translate[(char)(inb[i] - 'a')];
			else outb[i] = inb[i];
		}
		outb[n] = '\0';
		cout << "Case #" << k + 1 << ": " << outb << endl;
	}
	return 0;
}