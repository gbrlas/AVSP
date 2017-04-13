//** Utility class
#include <iostream>

#include "Utility.h"

using namespace std;

#define MAX_CHAR_PER_LINE 5000

// ******************************************
// ******************************************
FileParser::FileParser()
{
	L = D = N = 0;
	ppWords = 0;
	ppTestCases = 0;
}

FileParser::~FileParser()
{
	if (ppWords) 
	{
		for(int i =0; i < D; i++)
		{
			char *pWord = ppWords[i];
			if (*pWord) { delete[] pWord; pWord = NULL;}
		}
		delete [] ppWords; ppWords = NULL;
	}
	if (ppTestCases) 
	{
		for(int i =0; i < N; i++)
		{
			char *pTestCase = ppTestCases[i];
			if (*pTestCase) { delete[] pTestCase; pTestCase = NULL;}
		}
		delete [] ppTestCases; ppTestCases = NULL;
	}
}

int FileParser::Parse(char *iFilePath)
{
	//** Read the contents and store it
	FILE *pFile = NULL;
	pFile = fopen(iFilePath, "r");
	if (NULL == pFile)
		return 1;

	char Line[MAX_CHAR_PER_LINE];
	Line[0] = 0;
	//** Read the first line, L, D, N
	fgets (Line, MAX_CHAR_PER_LINE, pFile);
	sscanf (Line,"%d %d %d",&L, &D, &N);
//cout << L << " " << D << " " << N << endl;
	
	//** Read the words
	ppWords = new char *[D];
	if (NULL == ppWords) 
		return 1;
	int i = 0;
	for(i = 0; i < D; i++)
	{
		ppWords[i] = new char [L + 1]; //** One extra char for NULL char at end
		if (NULL == ppWords[i])
			return 1;
	}
	for(i = 0; i < D; i++)
	{
		fgets (Line, MAX_CHAR_PER_LINE, pFile);
		sscanf (Line,"%s",ppWords[i]);
	}
//for(i = 0; i < D; i++)
//{
//	cout<< ppWords[i] << endl;
//}

	//** Read the test cases
	ppTestCases = new char *[N];
	if (NULL == ppTestCases)
		return 1;
	for(i = 0; i < N; i++)
	{
		ppTestCases[i] = new char [MAX_CHAR_PER_LINE + 1]; //** One extra char for NULL char at end
		if (NULL == ppTestCases[i])
			return 1;
	}
	for(i = 0; i < N; i++)
		{
			fgets (Line, MAX_CHAR_PER_LINE, pFile);
			sscanf (Line,"%s",ppTestCases[i]);
		}
//for(i = 0; i < N; i++)
//{
//	cout<< ppTestCases[i] << endl;
//}
	//** Close the file
	fclose(pFile);

	return 0;
}
// ******************************************
// ******************************************
Algorithm::Token::Token()
{
	_IndexToken = 0;
	_Size = 0;
	_pString = NULL;
}

Algorithm::Token::~Token()
{
	if (_pString)
	{
		delete [] _pString; _pString = NULL;
	}
}

int Algorithm::Token::SetToken(char *iToken, int iSize)
{
	if(_pString)
	{
		delete [] _pString; _pString = NULL;
	}
	_Size = iSize;
	_pString = new char [_Size];
	if (NULL == _pString)
		return 1;
	strncpy(_pString, iToken, iSize);

	return 0;
}

Algorithm::Algorithm(FileParser & iParser):
_parser(iParser)
{
	_NumberTokens = 0;
	_pTokens = NULL;
	_NumberCache = 0;
	_ppCache = NULL;
}

Algorithm::~Algorithm()
{
	if (_pTokens)
	{
		delete[] _pTokens; _pTokens = NULL;
	}
	_NumberTokens = 0;
	if (_ppCache)
	{
		int i = 0;
		for (i = 0; i < _NumberTokens; i++)
		{
			delete []_ppCache[i]; _ppCache[i] = NULL;
		}
		delete[] _ppCache; _ppCache = NULL;
	}
}

int Algorithm::GetMatchingWordCount(char *iWordPattern, int & oNumberOfMatchingWords)
{
	//** Set the default value of output
	oNumberOfMatchingWords = 0;

	//** Get all tokens
  	GetTokens(iWordPattern);

	//** Check
	if (_NumberTokens != _parser.L)
		return 1;

	//** Get total number of possible words
	int i = 0;
	unsigned long NumberOfWords = 1;
	for (i = 0; i < _NumberTokens; i++)
	{
		NumberOfWords *= _pTokens[i]._Size;
	}

	//** Special treament for single word
	if (NumberOfWords == 1)
	{
		//** Check if a valid word
		if(IsValidWord(iWordPattern))
			oNumberOfMatchingWords++;
		return 0;
	}
	//** Get valid words for each token
	_ppCache = new char*[_parser.D];
	if (NULL == _ppCache)
		return 1;
	_NumberCache = _parser.D;
	for (i = 0; i < _NumberCache; i++)
	{
		_ppCache[i] = new char[_NumberTokens + 1];
		if (NULL == _ppCache[i])
			return 1;
	}
	
	//** Copy the original words
	for(i = 0; i < _NumberCache; i++)
	{
		strcpy(_ppCache[i], _parser.ppWords[i]);
	}

	for (i = 0; i < _NumberTokens; i++)
	{
		if (0 == ValidWordsCache(i))
			continue;
		else
			return 0;
	}
	
	if(_NumberCache == 0)
		return 0;

	//**For each word from the cache, valid it
	char *pWord = NULL;
	int j = 0;
	for(i = 0; i < _NumberCache; i++)
	{
		pWord = _ppCache[i];
		if (IsValidWordCache(pWord))
			oNumberOfMatchingWords++;
	}

	////** Get the indices for word
	//int *pIndices = new int [_NumberTokens];
	//if (NULL == pIndices)
	//	return 1;
	//char *pWord = new char[_NumberTokens + 1];
	//if (NULL == pWord)
	//	return 1;

	//int indexToken = 0;
	//int j = 0;
	//unsigned long index = 0;
	//for(index = 0; index < NumberOfWords; index++)
	//{
	//	for(j = _NumberTokens - 1; j >=0 ; j--)
	//	{
	//		pIndices[j] = _pTokens[j]._IndexToken;
	//	}

	//	//** Get the word
	//	for(j = 0; j < _NumberTokens; j++)
	//	{
	//		indexToken = pIndices[j];
	//		pWord[j] = _pTokens[j]._pString[indexToken];
	//	}
	//	pWord[_NumberTokens] = 0;
	//	
	//	//** Check if a valid word
	//	if(IsValidWord(pWord))
	//		oNumberOfMatchingWords++;

	//	// Increment the counter
	//	for(j = _NumberTokens - 1; j >=0 ; j--)
	//	{
	//		_pTokens[j]._IndexToken++;
	//		if( _pTokens[j]._Size == _pTokens[j]._IndexToken)
	//		{
	//			_pTokens[j]._IndexToken = 0;
	//			j--;
	//			continue;
	//		}
	//	}
	//}
	//** Free memory
	//if (pIndices) {	delete [] pIndices; pIndices = NULL;}
	//if (pWord) {	delete [] pWord; pWord = NULL;}
	if (_ppCache)
	{
		for (i = 0; i < _NumberTokens; i++)
		{
			delete []_ppCache[i]; _ppCache[i] = NULL;
		}
		delete[] _ppCache; _ppCache = NULL;
	}
	return 0;
}

int Algorithm::ValidWordsCache(int & iIndexToken)
{
	//** Return 1, if a valid word is not found
	//** Check each word from cache at the given index
	int i = 0;
	int NumberCache = 0;
	char **ppCache = NULL;
	ppCache = new char*[_NumberCache];
	if (NULL == ppCache)
		return 1;
	for (i = 0; i < _NumberCache; i++)
	{
		ppCache[i] = new char[_NumberTokens + 1];
		if (NULL == _ppCache[i])
			return 1;
	}
	int j = 0;
	char *pWord = NULL;
	for(i = 0; i < _NumberCache; i++)
	{
		pWord = _ppCache[i];
		for(j = 0; j < _pTokens[iIndexToken]._Size; j++)
		{
			if(pWord[iIndexToken] == _pTokens[iIndexToken]._pString[j])
			{
				strcpy(ppCache[NumberCache++], pWord);
			}
		}
	}

	//** Update the cache
	for (i = 0; i < NumberCache; i++)
	{
		strcpy(_ppCache[i], ppCache[i]);
	}

	//** Free memory
	for (i = 0; i < _NumberCache; i++)
	{
		delete []ppCache[i]; ppCache[i] = NULL;
	}
	delete [] ppCache; ppCache = NULL;

	if (NumberCache == 0)
		return 1;

	//** Set new cache size
	_NumberCache = NumberCache;
	
	return 0;
}

bool Algorithm::IsValidWordCache(char *ipWord)
{
	if (NULL == ipWord)
		return false;

	int i = 0;
	int j = 0;
	bool fValid = false;
	for(i = 0; i < _NumberTokens; i++)
	{
		fValid = false;
		for(j = 0; j < _pTokens[i]._Size; j++)
		{
			if(ipWord[i] == _pTokens[i]._pString[j])
			{
				fValid = true;
				break;
			}
		}
		if(fValid)
			continue;
		else
			return false;
	}

	return true;
}

//int Algorithm::GetMatchingWordCount(char *iWordPattern, int & oNumberOfMatchingWords)
//{
	//** Set the default value of output
	//oNumberOfMatchingWords = -1;
	////** Get the word patterns
	//char **ppWords = NULL;
	//int NumberWords = 0;
	//GetWords(iWordPattern, ppWords, NumberWords);
	//if (NULL == ppWords)
	//	return 1;

	////** Get the count of valid words
	//int i = 0;
	//int count = 0;
	//for(i = 0; i < NumberWords; i++)
	//{
	//	if(IsValidWord(ppWords[i]))
	//		count++;
	//}

	////** Set the output
	//oNumberOfMatchingWords = count;

	////** Free the memory
	//for(i = 0; i < NumberWords; i++)
	//{
	//	if (ppWords[i])
	//	{
	//		delete [] ppWords[i]; ppWords[i] = NULL;
	//	}
	//}
//
//	return 0;
//}

bool Algorithm::IsValidWord(char *iWord)
{
	int i = 0;
	for(i = 0; i < _parser.D; i++)
	{
		char *pWord = _parser.ppWords[i];
		if (0 == strcmp(iWord, pWord))
			return true;
	}

	return false;
}

bool Algorithm::IsValidToken(int & iIndexToken)
{
	//if (iIndexToken < 0 || iIndexToken >= _NumberTokens)
	//	return false;

	//** Check each word from dictionary at the given index
	int i = 0;
	int j = 0;
	char *pWord = NULL;
	for(i = 0; i < _parser.D; i++)
	{
		pWord = _parser.ppWords[i];
		for(j = 0; j < _pTokens[iIndexToken]._Size; j++)
		{
			if(pWord[iIndexToken] == _pTokens[iIndexToken]._pString[j])
			{
				return true;	//** Token is valid
			}
		}
	}
	return false;
}

//int Algorithm::GetWords(char *iWordPattern, char** &oppWords, int & oNumberWords)
//{
//	if (NULL == iWordPattern)
//		return 1;
//
//	//** Get all possible words from the input wordpattern
//
//	//** Get all tokens
//	GetTokens(iWordPattern);
//
//	//** Get total number of possible words
//	int NumberOfWords = 1;
//	int i = 0;
//	for (i = 0; i < _NumberTokens; i++)
//	{
//		NumberOfWords *= _pTokens[i]._Size;
//	}
//	oNumberWords = NumberOfWords;
//
//	//** Get the indices from each token for forming words
//	int **ppIndices = NULL;
//	ppIndices = new int*[oNumberWords];
//	if (NULL == ppIndices)
//		return 1;
//	for(i = 0; i < oNumberWords; i++)
//	{
//		ppIndices[i] = new int [_NumberTokens];
//		if (NULL == ppIndices[i])
//			return 1;
//	}
//	GetWordIndicesFromTokens (ppIndices, oNumberWords);
//	
//	//** Form the words using indices
//	oppWords = new char*[oNumberWords];
//	if (NULL == oppWords)
//		return 1;
//	for(i = 0; i < oNumberWords; i++)
//	{
//		oppWords[i] = new char [_NumberTokens + 1]; //One extra char for null char
//		if (NULL == oppWords[i])
//			return 1;
//	}
//	int j = 0;
//	int indexToken = 0;
//	char Line[MAX_CHAR_PER_LINE];
//	Line[0] = 0;
//	for(i = 0; i < oNumberWords; i++)
//	{
//		for(j = 0; j < _NumberTokens; j++)
//		{
//			indexToken = ppIndices[i][j];
//			Line[j] = _pTokens[j]._pString[indexToken];
//		}
//		Line[_NumberTokens] = 0;
//		strcpy(oppWords[i], Line);
//	}
////for(i = 0; i < oNumberWords; i++)
////{
////	cout << oppWords[i] << endl;
////}
//	//** Free the memory
//	for(i = 0; i < oNumberWords; i++)
//	{
//		if (ppIndices[i])
//		{
//			delete [] ppIndices[i]; ppIndices[i] = NULL;
//		}
//	}
//	return 0;
//}

int Algorithm::GetTokens(char *iWordPattern)
{
	//** Initialize data members
	if (_pTokens)
	{
		delete[] _pTokens; _pTokens = NULL;
	}
	_NumberTokens = 0;

	if (NULL == iWordPattern)
		return 1;
	int size = strlen(iWordPattern);
	if (size <= 0)
		return 1;
	
	//** Get token counts
	int i = 0;
	int count = 0;
	bool fParenthesisOpen = false;
	for(i = 0; i < size; i++)
	{
		char ch = iWordPattern[i];
		switch(ch)
		{
			case '(':
				fParenthesisOpen = true;
				count++;
				break;
			case ')':
				fParenthesisOpen = false;
				break;
			default:
				if(fParenthesisOpen == false)
					count++;
				break;
		}
	}
	
	//** Set the token count
	if(count == 0)
		return 1;
	_NumberTokens = count;
	_pTokens = new Token [_NumberTokens];
	if (NULL == _pTokens)
		return 1;
	
	//** Read the tokens
	count = 0;
	int sizeToken = 0;
	char Line[MAX_CHAR_PER_LINE];
	Line[0] = 0;
	fParenthesisOpen = false;
	for(i = 0; i < size; i++)
	{
		char ch = iWordPattern[i];
		switch(ch)
		{
			case '(':
				fParenthesisOpen = true;
				break;
			case ')':
				fParenthesisOpen = false;
				_pTokens[count++].SetToken(Line, sizeToken);
				sizeToken = 0;
				break;
			default:
				if(fParenthesisOpen == false)
				{
					Line[sizeToken++] = ch;
					_pTokens[count++].SetToken(Line, sizeToken);
					sizeToken = 0;
				}
				else
				{
					Line[sizeToken++] = ch;
				}
				break;
		}
	}

	return 0;
}

//int Algorithm::GetWordIndicesFromTokens(int **ppIndices, int iNumberOfWords)
//{
//	if (NULL == ppIndices)
//		return 1;
//
//	int i = 0;
//	int j = 0;
//	int indexToken = 0;
//	for(i = 0; i < iNumberOfWords; i++)
//	{
//		for(j = _NumberTokens - 1; j >=0 ; j--)
//		{
//			ppIndices[i][j] = _pTokens[j]._IndexToken;
//		}
//		// Increment the counter
//		for(j = _NumberTokens - 1; j >=0 ; j--)
//		{
//			_pTokens[j]._IndexToken++;
//			if( _pTokens[j]._Size == _pTokens[j]._IndexToken)
//			{
//				_pTokens[j]._IndexToken = 0;
//				j--;
//				continue;
//			}
//		}
//	}
//
//for(i = 0; i < iNumberOfWords; i++)
//{
//	for(indexToken = 0; indexToken < _NumberTokens; indexToken++)
//	{
//		cout << ppIndices[i][indexToken] << " " ;
//	}
//	cout << endl;
//}
//	return 0;
//}

// ******************************************
// ******************************************
FileWriter::FileWriter(int iNumberTestCases)
{
	_N = iNumberTestCases;
	_pResult = new int [iNumberTestCases];
}

FileWriter::~FileWriter()
{
	if (_pResult)
	{
		delete [] _pResult; _pResult = NULL;
	}
}

int FileWriter::SetResult(int iCaseId, int iPatternCount)
{
	if (NULL != _pResult && iCaseId <= _N && iCaseId > 0)
	{
		_pResult[iCaseId - 1] = iPatternCount;
	}
	else
	{
		return 1;
	}

	return 0;
}

int FileWriter::Write()
{
	char FileName[] = "output_sample.txt";
	FILE *pFile = NULL;
	char Line[MAX_CHAR_PER_LINE];
	Line[0] = 0;

	pFile = fopen(FileName, "w");
	if (NULL == pFile)
		return 1;

	int i = 0;
	for (i = 0; i < _N; i++)
	{
		sprintf(Line, "Case #%d: %d \n", i + 1, _pResult[i]);
		fputs(Line, pFile);
//cout << Line;
	}

	//** Close the file
	fclose(pFile);

	return 0;
}



// ******************************************
// ******************************************


// ******************************************
// ******************************************

