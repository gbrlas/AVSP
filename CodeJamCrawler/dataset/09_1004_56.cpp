// B2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"
#include <set>
#include <string>

bool isDigit(char* c)
{
  if(*c < '0')
    return false;
  if(*c <= '9')
    return true;
  return false;
}

bool isAlpha(char* c)
{
  if(*c >= 'a' && *c <= 'z')
    return true;
  if(*c >= 'A' && *c <= 'Z')
    return true;
  return false;
}
class Node {
public:
  double weight;
  char feature[16];
  Node* left;
  Node* right;
  char asciiWeight[16];
  Node(char*& currPtr)
  {
    
    left=right=NULL;
    memset(feature,0,16*sizeof(char));
    weight = 0.0;
    while(*currPtr != '(')
      ++currPtr;

    while(!isDigit(currPtr) && *currPtr != '.')
      ++currPtr;

    int index=0;
    while(isDigit(currPtr) || *currPtr == '.')
    {
      asciiWeight[index] = *currPtr;
      ++currPtr;
      ++index;
    }
    asciiWeight[index]=0;
    weight = atof(asciiWeight);

    while(!isAlpha(currPtr) && *currPtr!=')')
      ++currPtr;

    if(*currPtr == ')')
    {
      ++currPtr;
      return;
    }

    index=0;
    while(isAlpha(currPtr))
    {
      feature[index] = *currPtr;
      ++currPtr;
      ++index;
    }
    feature[index] = 0;

    left = new Node(currPtr);
    right = new Node(currPtr);
    while(*currPtr!=')')
      ++currPtr;
    ++currPtr;

  }
  ~Node()
  {
    delete left;
    delete right;
  }
};

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
  Node* root;
  Node* currNode;
  int testCases = atoi(t.getToken());
  double wt;
  char buffer[10240] = {0};
  char animalName[32];
  std::set<std::string> characteristics;
  std::string singleChar;
  char* currPtr;
  for(int i=1;i<=testCases;++i)
  {
    memset(buffer,0,sizeof(buffer));
    int linesOfTree = atoi(t.getToken());
    t.setSEPS("\t\n");
    for(int j=0;j<linesOfTree;++j)
    {
      strcat(buffer,t.getToken());
    }

    currPtr = buffer;
    root = new Node(currPtr);
    fprintf(outFile,"Case #%d:\n",i);
    
    t.setSEPS(" \t\n");
    int numTests = atoi(t.getToken());
    for(int k=0;k<numTests;++k)
    {
      strcpy(animalName,t.getToken());
      characteristics.clear();
      wt=1.0;
      int numChars = atoi(t.getToken());
      for(int m=0;m<numChars;++m)
      {
        singleChar.assign(t.getToken());
        characteristics.insert(singleChar);
      }
      currNode = root;
      do{
        wt*=currNode->weight;
        if(characteristics.find(std::string(currNode->feature)) != characteristics.end())
          currNode = currNode->left;
        else
          currNode = currNode->right;
      }while(currNode!=NULL);

      fprintf(outFile,"%f\n",wt);
    }
    delete root;
  }

  //
  fclose(outFile);
  fclose(inFile);
  return 0;
}

