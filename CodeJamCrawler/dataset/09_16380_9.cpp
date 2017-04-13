#include<iostream>
#include<list>
#include<algorithm>
#include<windows.h>
#include<string>
#include<dos.h>
#include "math.h"
using namespace std;


int next(int num)
{
	int mainarray[10]={0};
	int num1;
	num1=num;
	int index;
	while(num1 != 0)	
	{
		index = num1%10;
		mainarray[index]++;
		num1 /= 10;
	}
	while(1)
	{
		num++;
		int num2 = num;
		int checkarray[10] ={0};
		while(num2!=0)
		{
			int index = num2%10;
			checkarray[index]++;
			num2/=10;
		}	
		int flag=0;
		for(int i=1;i<=9;i++)
		{	
			if(mainarray[i]!=checkarray[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return num;
	}
}

		
		


int main(){
	int nofinputs;
	cin>>nofinputs;
	for(int i=0;i<nofinputs;i++)
	{
		int num;
		cin>>num;
		int x= next(num);	
		cout<<"Case #"<<i+1<<": "<<x<<endl;
	}
	return 0;
}

