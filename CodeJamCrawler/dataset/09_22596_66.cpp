#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <memory.h>

using namespace std;

unsigned int L,D,N;
ifstream fin("A-small-attempt0.in.txt");
ofstream fout("A-small-attempt0.out.txt");
//ifstream fin("A-small-practice.in.txt");
//ofstream fout("A-small-attempt0.out.txt");
char** array;
int** Index;

long long int analyzeAmbiguousWord(string source)
{
    vector<string> vs;
    vector<string>::iterator l=vs.begin();
    unsigned int LEN;
    long long int i;
    long long int k; //ÓÃÓÚÍ³¼ÆºÏºõÒªÇóµÄÅÅÁÐ
//	long long int multi=1;
    long long int totalNums=0;
   // int* index=(int*)malloc(L*sizeof(int));
   // memset(index,0,L*sizeof(int));
   // char* lookupChar = (char*)malloc(L*sizeof(char));
   // memset(lookupChar,0,L*sizeof(char))
    string tempString;

    for(i=0,LEN = source.length();i<LEN;i++)
    {
        tempString.clear();
        char temp = source[i];
        if (temp!='(' && temp!=')')
        {
            tempString+=temp;
            vs.push_back(tempString);
            }
            else //meet the ( character
            {
                k = source.find_first_of(")",i);
                tempString.insert(tempString.begin(),source.begin()+i+1,source.begin()+k);
                vs.push_back(tempString);
                i = k;
                }

        }
    if (L!=vs.size())
    {
        fout<<"sth wrong!"<<endl;
        }
    tempString.clear();
    k=0;
   for(i=0;i<L;i++)
   {
	    k=0;
		for(int j=0;j<vs[i].size();j++)
		{
			//k += Index[i][vs[i].at(j)-97];
			for(int l=0;l<D;l++)
			{
                if(vs[i].at(j)==array[i][l])
                    Index[i][l] =1;

			}


		}

   }
    for(int j=0;j<D;j++)
    {
    for(i=0;i<L;i++)
    {
        if (Index[i][j]==0)
            break;

        }
    if(i==L)
        totalNums++;
    }
        return totalNums;


    }
int main(int argc, char **argv){
  string word;
  int K;
  int j;
  int i;
  fin>>L>>D>>N;

  array = (char**)malloc(L*sizeof(char*)); //L rows
  for(i=0;i<L;i++)
  {
	array[i] = (char*)malloc(D*sizeof(char));
  }

  Index = (int**)malloc(L*sizeof(int*));
  for(i=0;i<L;i++)
  {
	Index[i]=(int*)malloc(D*sizeof(int));
  }
  for(i=0;i<L;i++)
  {
      for(j=0;j<D;j++)
      Index[i][j]=0;
      }

  for(j=0; j<D; j++) //construct the dictionary
    {
        fin>>word;
        for(int i=0;i<L;i++)
		{
			array[i][j] = word.at(i);
		}
	}

  for(int C=1; C<=N; C++) {

  for(i=0;i<L;i++)
  {
      for(j=0;j<D;j++)
      Index[i][j]=0;
      }
    string ambiguousWord;
    fin>>ambiguousWord;
    K = analyzeAmbiguousWord(ambiguousWord);
    fout << "Case #"<<C<<": "<<K<<endl;

  }
}

