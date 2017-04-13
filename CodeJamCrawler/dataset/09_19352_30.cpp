#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <list>

using namespace std;


typedef map<char,void*> Word;
typedef pair<char,void*> Letter;

/*
bool operator<(const POINT& s1, const POINT& s2)
{
	if(s1.x < s2.x)
		return true;
	else if(s1.x == s2.x)
		return (s1.y < s2.y);
	else
		return false;
}
*/

int getNumWords(list<string> pattern_tokens,Word *dictionary)
{
	int i,num_words = 0;
	string token_s;
	map<char,void*>::iterator it;

	if(pattern_tokens.size() == 0)
		return 1;

	token_s = pattern_tokens.front();

	pattern_tokens.pop_front();

	for(i=0;i<token_s.length();i++)
	{
		it = dictionary->find(token_s[i]);
		
		if(it != dictionary->end())
			num_words = num_words + getNumWords(pattern_tokens,(Word*) it->second);
	}

	return num_words;
}

int main()
{
	int i,j,k;
	int valL,valD,valN,num_words;
	
	char L[100],D[100],N[100],word[10000],pattern[10000];
	string L_s,D_s,N_s,word_s,pattern_s,token_s;
	list<string> pattern_tokens;
	Word dictionary,*dictEntry;
	Letter *letter;
	bool bracketOpen;
	map<char,void*>::iterator it,itLetter;
		
	FILE *inFile,*outFile;
	
	if( (inFile  = fopen( "A-small.in", "r" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );
	
	if( (outFile  = fopen( "A-small.out", "w" )) == NULL )
	  printf( "The file 'data' was not opened\n" );
	else
	  printf( "The file 'data' was opened\n" );

	//fscanf(inFile,"%d",&num_total_cases);
	//printf("%d Num Cases \n",num_total_cases);

	fscanf(inFile,"%s %s %s",&L,&D,&N);

	L_s = L;
	D_s = D;
	N_s = N;

	valL = 0;
	for(j=0;j<L_s.length();j++)
	{
		valL = valL + (L[L_s.length()-1-j]-48)*pow(10,double(j));
	}

	valD = 0;
	for(j=0;j<D_s.length();j++)
	{
		valD = valD + (D[D_s.length()-1-j]-48)*pow(10,double(j));
	}

	valN = 0;
	for(j=0;j<N_s.length();j++)
	{
		valN = valN + (N[N_s.length()-1-j]-48)*pow(10,double(j));
	}
	
	
	for(i=0;i<valD;i++)
	{
		fscanf(inFile,"%s",&word);
		word_s = word;
		dictEntry = &dictionary;

		for(j=0;j<word_s.length();j++)
		{
			if((itLetter = dictEntry->find(word_s[j])) != dictEntry->end())
			{
				dictEntry = (Word*)itLetter->second;
			}
			else
			{
				letter = new Letter(char(word_s[j]),new Word);
				dictEntry->insert(*letter);
				dictEntry = (Word*)(letter->second);
			}
		}
	}
	
	for(i=0;i<valN;i++)
	{
		num_words = 0;
		fscanf(inFile,"%s",&pattern);
		pattern_s = pattern;
		dictEntry = &dictionary;
		token_s.clear();
		pattern_tokens.clear();
		bracketOpen = false;
		
		for(j=0;j<pattern_s.length();j++)
		{ 
			if(pattern_s[j] == '(')
			{
				bracketOpen = true;
			}
			else if(pattern_s[j] == ')')
			{
				bracketOpen = false;
				pattern_tokens.push_back(token_s);
				token_s.clear();
			}
			else
			{
				token_s += pattern_s[j];
				if(!bracketOpen)
				{
					pattern_tokens.push_back(token_s);
					token_s.clear();
				}
			}
		}

		num_words = getNumWords(pattern_tokens,&dictionary);

		fprintf(outFile,"Case #%d: %d \n",i+1,num_words);
	}

	//TODO delete dictionary 

	fclose(inFile);
	fclose(outFile);
	
	return 1;
}
