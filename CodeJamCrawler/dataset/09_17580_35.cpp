#include <iostream>
#include <string>
using namespace std;

int T;
int N[22];
int A[22];
int len;
int D[10];


void input()
{
    string inp;
    //cin >> T;
    int i;
    for(i = 0; i < 10; i++)
	D[i] = 0;
    //for(i = 0; i < T; i++)
    //{
	cin >> inp;
	int j;
	for(j = 0; j < inp.length(); j++)
	{
	    N[j] = (int)(inp[inp.length()-j-1])-48;
	}
	N[j] = 0;
	len = inp.length();
}

void process()
{
	int i, j;
	int brk;
		
	
	for(brk = 0; brk < len - 1; brk++)
	{
		if(N[brk] > N[brk+1])
			break;
	}
	//this point has the brk-th digit for which it is possible to do our job
	//find smallest greater than N[brk+1], then just do a bucket sort.
	
	for(i = 0; i <= brk+1; i++)
	{
		D[N[i]]++;
	}
	
	
	for(i = brk; i >= 0; i--)
	{
		if(N[i] <= N[brk+1] || N[i] == 0)
			break;
	}
	//i+1 has threshhold position
	
	D[N[i+1]]--;

	int k, l;
	for(k = 0; k < 22; k++)
	{
		A[k] = 0;
	}
	if(brk == len-1)
		len++;
	k = 0;
	l = 0;
	for(l = 9; l >= 0; l--)
	{
		while(D[l]>0)
		{
			A[k] = l;
			k++;
			D[l]--;
		}
	}
	A[k] = N[i+1];k++;
	for(; k < len; k++)
	{
		A[k] = N[k];
	}
}

void output(int tno)
{
	cout << "Case #" << tno << ": ";
	int i;
	for(i = len-1; i >=0; i--)
		cout << A[i];
	cout << endl;
}

int main()
{
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		input();
		process();
		output(i+1);
	}
}
