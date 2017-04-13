//Coded by Vasu Jain Google Profile available at:- https://plus.google.com/109831871181042742891
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char replaceChar(char i);

int main()
{
ifstream inputFile;
inputFile.open("A-small-attempt0.in");
inputFile.open("small.in");

if(!inputFile.is_open()) {cerr<<"Path can not be opened\n";exit(-1);};

if(inputFile.is_open())
	{
	string currentLine;
	int numLines;
	bool lineNumberCount=false;
	int getLineCount=1;
	while(!inputFile.eof())
		while(getline(inputFile,currentLine))
			{
				
				if(lineNumberCount==false)
					{
					numLines =atoi(currentLine.c_str());
					lineNumberCount=true;					
					}
				else
					{
					//cout<<"Encoded: \n"<<currentLine<<endl;
					for(int i=0;i<currentLine.length()-1;i++)
						{
							currentLine[i]=replaceChar(currentLine[i]);							
						}
					cout<<"Case #"<<getLineCount<<": "<<currentLine<<endl;
					getLineCount++;	
					}
			}
	}
}


char replaceChar(char j)
{
	switch (j)
	{
	case 'y': return('a'); break;
	case 'n': return('b'); break;
	case 'f': return('c'); break;
	case 'i': return('d'); break;
	case 'c': return('e'); break;
	case 'w': return('f'); break;
	case 'l': return('g'); break;
	case 'b': return('h'); break;
	case 'k': return('i'); break;
	case 'u': return('j'); break;
	case 'o': return('k'); break;
	case 'm': return('l'); break;
	case 'x': return('m'); break;
	case 's': return('n'); break;
	case 'e': return('o'); break;
	case 'v': return('p'); break;
	case 'p': return('r'); break;
	case 'd': return('s'); break;
	case 'r': return('t'); break;
	case 'j': return('u'); break;
	case 'g': return('v'); break;
	case 't': return('w'); break;
	case 'h': return('x'); break;
	case 'a': return('y'); break;
	case ' ': return(' '); break;
	case 'q': return('z'); break;
	case 'z': return('q'); break;
	
	}
}
