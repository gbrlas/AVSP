/* Problem : Codejam Prome A
 * Author  : Ivan Cachicatari <ivancp@latindevelopers.com>
 * Date    : sat may  8 16:29:53 PET 2010
 * */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const char* state[2] = {"OFF","ON"};

void dec2bin(long decimal, char *binary)
{
	int k = 0, n = 0;
	int neg_flag = 0;
	int remain;
	int old_decimal; // for test
	char temp[80];
	 
	// take care of negative input
	if (decimal < 0)
	{
		decimal = -decimal;
		neg_flag = 1;
	}
	do
	{
		old_decimal = decimal; // for test
		remain = decimal % 2;
		// whittle down the decimal number
		decimal = decimal / 2;
		// this is a test to show the action
		//printf("%d/2 = %d remainder = %d\n", old_decimal, decimal, remain);
		// converts digit 0 or 1 to character '0' or '1'
		temp[k++] = remain + '0';
	} while (decimal > 0);
	 
	if (neg_flag)
		temp[k++] = '-'; // add - sign
	//else
	//	temp[k++] = ' '; // space
	 
	// reverse the spelling
	while (k >= 0)
		binary[n++] = temp[--k];
	 
	binary[n-1] = 0; // end with NULL
}

int getState(int pos, string num)
{
	bool connected = true;
	int i = 0;
	for(i = pos ; i >= 0 ;i--)
	{
		if(num[i] == '0')
		{
			connected = false;
			return 0;
		}
	}
	if(num[pos] == '1')
		return 1;
	else
		return 0;
}
int main(int argc, char *argv[])
{
	
	long t = 0,n,k,Case=1;
	cin>>t;
	char binary[40];
	while(t>0)
	{
		cin>>n;
		cin>>k;
		dec2bin(k,binary);
		string bin = binary;

		if(bin.size() <= n )
		{
			
			int z = n - bin.size();
			//cout<<"tam =" <<z<<endl;
			for(int i = 0 ;i < z ;i++)
				bin.insert(0,"0");
		}
		else
		{
			cout<<"[ old "<<bin<<"]\n";
			bin = bin.substr(bin.size()-n,bin.size());
			
		}

		cout<<"Case #"<<Case++<<": "<<state[getState(n-1,bin)]<<endl;
		//cout<<n<<":\""<<bin.c_str()<<"\""<<endl;
		t--;
	}
	return 0;
}


