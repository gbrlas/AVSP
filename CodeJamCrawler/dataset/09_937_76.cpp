// GCJ1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"
#include <set>

int _tmain(int argc, _TCHAR* argv[])
{
    if(argc!=2)
    {
        fprintf(stderr,"usage: %s infile\n",argv[0]);
        exit(0);
    }
    FILE* inFile = fopen(argv[1],"rt");
    if(!inFile)
    {
        fprintf(stderr,"Could not open %s\n",argv[1]);
        exit(0);
    }
    char outFileName[256] = {0};
    sprintf(outFileName,"%s.out.txt",argv[1]);
    FILE* outFile = fopen(outFileName,"wt");
    if(!outFile)
    {
        fprintf(stderr,"Could not open %s\n",outFileName);
        exit(0);
    }

    tokenizer t(inFile);
    int word_length = atoi(t.getToken());
    int num_words = atoi(t.getToken());
    int test_cases = atoi(t.getToken());

    std::set<char*> words;

    char* currWord;

    for(int i = 0; i < num_words; ++i)
    {
        currWord = new char[word_length+1];
        strcpy(currWord,t.getToken());
        currWord[word_length]=0;
        words.insert(currWord);
    }

    std::set<char*> matches;
    std::set<char> currLetter;

    char currTestCase[500];
    char* currTestCaseChar;
    std::set<char>::iterator found;

    for(int i=1; i<=test_cases;++i)
    {
        memset(currTestCase,0,500);
        matches.clear();
        for(std::set<char*>::iterator itr = words.begin(); itr!=words.end(); itr++)
        {
            matches.insert(*itr);
        }
        strcpy(currTestCase,t.getToken());
        currTestCaseChar = currTestCase;
        
        for(int j = 0; j < word_length; ++j)
        {
            currLetter.clear();
            if(*currTestCaseChar=='(')
            {
                ++currTestCaseChar;
                while (*currTestCaseChar != ')')
                {
                    currLetter.insert(*currTestCaseChar);
                    ++currTestCaseChar;
                }
            }
            else
            {
                currLetter.insert(*currTestCaseChar);
            }
            ++currTestCaseChar;

            for(std::set<char*>::iterator itr = matches.begin(); itr!=matches.end();)
            {
                found = currLetter.find((*itr)[j]);
                if(found==currLetter.end())
                {
                    itr=matches.erase(itr);
                }
                else
                {
                    itr++;
                }
            }
            
        }

        fprintf(outFile,"Case #%d: %d\n",i,matches.size());
    }



    fclose(inFile);
    fclose(outFile);

    return 0;
}

