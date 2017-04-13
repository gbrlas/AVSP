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

unsigned int N;
//ifstream fin("A-small-attempt1.in.txt");
//ofstream fout("A-small-attempt1.out.txt");
//ifstream fin("A-small-practice.in.txt");
//ofstream fout("A-small-attempt0.out.txt");
string object="welcome to code jam";
__int64 analyzeAmbiguousWord(string source)
{
    int LEN;
	int i=0;
    int j=0;
	int l=0;
    int indexFirst;
    int indexSecond;
    int indexThree;
    int INDEXOBJECT[19];
    for(i=0;i<19;i++)
        INDEXOBJECT[i] =0;
    int INDEXSOURCE[501];
    for(i=0;i<501;i++)
        INDEXSOURCE[i] =0;
    __int64 COUNTING[4][501];
    for (i=0;i<4;i++)
    for (j=0;j<501;j++)
        COUNTING[i][j] =0;
    int count=0;
    __int64 NUM=0;
    for(i=0,LEN=source.length();i<LEN; i++)
    {//????substring???
		 
        indexFirst = object.find_first_of(source.at(i),0);

        if (indexFirst<0)
        {//?????????
            continue;
            }
            else{

                //???????????????????????????
                  COUNTING[0][count]=source.at(i);
                  if(0 == count)
                  {
                      if(COUNTING[0][count] == 'w')
                        COUNTING[1][count]=1;
                      }

                  for(int j=count-1;j>=0;j--)
                  {
                      if(indexFirst>0)
                      {
                          if(COUNTING[0][j] == object[indexFirst-1])
                          {
                              if(' ' == COUNTING[0][count])
                                COUNTING[1][count]+=COUNTING[2][j]; //???????????????
                              else if('d' == COUNTING[0][count] || 'j' == COUNTING[0][count])
                                COUNTING[1][count]+=COUNTING[3][j]; //???????????????
                              else
                                COUNTING[1][count]+=COUNTING[1][j];

                             //   break;
							  	for(l=1;l<4;l++)
								 {
									if(COUNTING[l][count]>10000)
										COUNTING[l][count] -= 10000;
								 }

                              }

                      }
                      else //indexFirst==0
                      {
                            COUNTING[1][count]=1;
                          }
                  }

                //?????????????????????,?????????????,????e o space c m;
                //?????,???????????????????
                indexSecond = object.find_first_of(source.at(i),indexFirst+1);
                if (indexSecond>0)
                {
                    for(j=count-1;j>=0;j--)
                    {
                        if(COUNTING[0][j] == object[indexSecond-1])
                        {
                        //????,????????????????????
                        //??????????????????????
                          if('e' == COUNTING[0][count] || 'o' == COUNTING[0][count]
                            ||'m' == COUNTING[0][count]
                            )
                            COUNTING[2][count]+= COUNTING[1][j]; //???????????????
                        if(' ' == COUNTING[0][count] ||'c' == COUNTING[0][count]) //
                            COUNTING[2][count]+= COUNTING[2][j];

                          //  break;
								for(l=1;l<4;l++)
								 {
									if(COUNTING[l][count]>10000)
										COUNTING[l][count] -= 10000;
								 }

                        }
                        }

                    //?????????????????????,????o e space
                    indexThree = object.find_first_of(source.at(i),indexSecond+1);
                    if (indexThree>0)
                    {
                        for(j=count-1;j>=0;j--)
                        {
                            if(COUNTING[0][j] == object[indexThree-1])
                            {
                                if('o' == COUNTING[0][count])
                                    COUNTING[3][count]+=COUNTING[2][j]; //??????????????c??
                                if('e' == COUNTING[0][count])
                                    COUNTING[3][count]+=COUNTING[1][j]; //??????????????d??
                                if(' ' == COUNTING[0][count])
                                    COUNTING[3][count]+=COUNTING[3][j]; //?????????????e??
                               // break;
                                }
								for(l=1;l<4;l++)
								 {
									if(COUNTING[l][count]>10000)
										COUNTING[l][count] -= 10000;
								 }

                            }

                    }
                }
                //???
                 
				 for(l=1;l<4;l++)
				 {
					if(COUNTING[l][count]>10000)
						COUNTING[l][count] -= 10000;
				 }
				 count++;
                }

     }
     //?????,?COUNTING[0][j]=m,?COUNTING[2][j]????;
     for(j=0;j<count;j++)
     {
         if(COUNTING[0][j] == 'm')
		 {
            NUM+=COUNTING[2][j];
			if(NUM>=10000)
				NUM-=10000;
		 }

         }
//	NUM = NUM%10000;
    return NUM;

    }

    void main(int argc, char **argv)
    {
    __int64 K;
    char buf[501];
    cin>>N;
	cin.get();
    for(int C=1; C<=N; C++) {
        string ambiguousWord;		
        cin.getline(buf, sizeof(buf));
        ambiguousWord = buf;
        K = analyzeAmbiguousWord(ambiguousWord);
        printf("Case #%ld: %04I64d\n",C,K);

    }
    }

