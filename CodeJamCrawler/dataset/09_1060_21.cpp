#include "libfns.h"

bool isDigit(char c)
{
  if(c < '0')
    return false;
  if(c <= '9')
    return true;
  return false;
}

bool isAlpha(char c)
{
  if(c >= 'a' && c <= 'z')
    return true;
  else if(c >= 'A' && c <= 'Z')
    return true;
  return false;
}


tokenizer::tokenizer()
{
    setFile(NULL);
}

tokenizer::tokenizer( FILE* fp )
{
    setFile(fp);
}

void tokenizer::setFile( FILE* fp )
{
    dataFile = fp;
    memset(line,0,sizeof(line));
    retval = NULL;
    strcpy(MOD_SEPS,"\t\n");
}

void tokenizer::setSEPS(const char* SEPS)
{
  strcpy(MOD_SEPS,SEPS);
}

char* tokenizer::getToken()
{
    char* tokens = 0;
    while(1)
    {
        if(retval==NULL)    //reached end of line
        {
            if(fgets(line,1023,dataFile)==NULL)
                return NULL;
            tokens = line;
        }
        retval = strtok(tokens,MOD_SEPS);
        if(retval)
            return retval;
    }
    return retval;
}
tokenizer::~tokenizer(){}

Node::Node()
{
  left=right=NULL;
}

Node::~Node()
{
  delete left;
  delete right;
}