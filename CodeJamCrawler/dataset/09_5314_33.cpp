//** Classes to read, write and algo

//** Parser class
class FileParser
{
public:
	int L;
	int D;
	int N;

	char **ppWords;
	char **ppTestCases;

public:
	FileParser();
	~FileParser();

	int Parse(char* iFilePath);
	
};

//** Algorithm class
class Algorithm
{
	class Token
	{
		public:
			Token();
			~Token();
			
			int SetToken(char *iToken, int iSize);
			int _IndexToken;
			int _Size;
			char *_pString;
	};
public:
	Algorithm(FileParser & iParser);
	~Algorithm();
	
	int GetMatchingWordCount (char *iWordPattern, int & oNumberOfMatchingWords);

private:
	bool IsValidWord(char *iWord);
	bool IsValidToken(int & iIndexToken);
	//int GetWords(char *iWordPattern, char** &oppWords, int & oNumberWords); //Caller will free the memory allocated for output
	int GetTokens(char *iWordPattern);
	int ValidWordsCache(int & iIndexToken);
	bool IsValidWordCache(char *ipWord);

	//Caller will allocate the memory
	//int GetWordIndicesFromTokens (int **oppIndices, int iNumberOfWords); //Number of rows will be equal to number of words possible from tokens, column length of word

	FileParser & _parser;
	Token *_pTokens;
	int _NumberTokens;
	char **_ppCache;
	int _NumberCache;
};

//** Output class
class FileWriter
{
public:
	FileWriter(int iNumberTestCases);
	~FileWriter();

	int SetResult(int iCaseId, int iPatternCount);//CaseID start with 1
	int Write();

private:
	int _N;	//Number of test cases
	int *_pResult; //Pattern count for each test cases
};

