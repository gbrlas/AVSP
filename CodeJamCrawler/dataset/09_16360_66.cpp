// try.cpp : Defines the entry point for the console application.
//

#include<math.h>
#include<stdio.h>
#include<iostream> 
#include<string>

using namespace std;
enum
{
	open,
	closed
}bracket;

char array[300][300];
int row=0,col=0;
	

int totalwords;
string dictionary[5000]; 
int wordlength;
int num =0;


void formtwoDarray(string str)
{
	bracket = closed;
	bool flag = false;
	for(unsigned int i=0;i<str.length();i++)
	{
		if(str[i] == '(')
		{
			bracket = open;
			flag = false;
			if(i==0)
				continue;
			row++;
			col =0;
		}
		else if(str[i] == ')')
		{	
			bracket = closed;
			flag = true;
		}
		
		else 
		{
			if(bracket==open && col==0)
			{
				array[row][col++] =  '*';
				array[row][col++] = str[i];
			}
			else if(flag == true)
			{	row++;col=0;flag=false;array[row][col++] = str[i]; }
			else
				array[row][col++] = str[i];
		}
	}
	row++;
}

void checkforwords(int currow,string dictionarystring,int index)
{
	
	if(index>wordlength) 
		return;
	if(index == wordlength && currow == row)
	{ 
		num++;
		return;
	}
	if(currow >= row) return;

	char mark = array[currow][0];
	if(mark == '*')
	{	
		int col=1;
		char dvalue = dictionarystring[index];
		while(array[currow][col]!='-')
		{
			char value = array[currow][col];
			if(value==dvalue)
			{
				checkforwords(currow+1,dictionarystring,index+1);
				break;
			}
			col++;
		}
	}
	else
	{
		int col=0;
		string str;
		while(array[currow][col]!='-')
		{
			str.append(1,array[currow][col]);
			col++;
		}
		string subdictionarystr = dictionarystring.substr(index,col);
		if(subdictionarystr.length()<col)
			return;
		if(subdictionarystr.compare(str)==0)
			checkforwords(currow+1,dictionarystring,index+col);
	}
}








//void checkforwords(int currow,string str)
//{
//	if(currow > row)
//		return;
//	if(str.length() == wordlength)
//	{
//		for(int i=0;i<totalwords;i++)
//		{
//			if(str.compare(dictionary[i])==0)
//				num++;
//		}
//		return;
//	}
//	char mark = array[currow][0];
//	if(mark == '*')
//	{	
//		int col=1;
//		string str1=str;
//		while(array[currow][col]!='-')
//		{
//			string newstr = str.append(1,array[currow][col]);
//			checkforwords(currow+1,newstr);
//			str=str1;
//			col++;
//		}
//	}
//	else
//	{
//		int col=0;
//		string newstr=str;
//		while(array[currow][col]!='-')
//		{
//			newstr.append(1,array[currow][col]);
//			col++;
//		}
//		checkforwords(currow+1,newstr);
//	}
//}




int main(int argc,char* argv[])
{
	int noofinputs;
	cin>>wordlength;
	cin>>totalwords;
	cin>>noofinputs;
	for(int i=0;i<totalwords;i++)
	{		
		string str;
		cin>>str;
		dictionary[i]=str;
	}
	for(int i=0;i<noofinputs;i++)
	{
		string str;
		cin>>str;

		num =0;row=0;col=0;
		for(int k=0;k<300;k++)
		for(int j=0;j<300;j++)
			array[k][j] = '-';
		formtwoDarray(str);
			
		for(int p=0;p<totalwords;p++)
			checkforwords(0,dictionary[p],0);
		cout<<"Case #"<<(i+1)<<": "<<num<<endl; 
	}		
	return 0;
}


