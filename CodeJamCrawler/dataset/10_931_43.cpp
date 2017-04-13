#include "libfns.h"

double dist(double x1, double y1, double x2, double y2)
{
  double retval = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  retval = sqrt(retval);
  return retval;
}

Point::Point()
{
  x=y=0;
}
Point::~Point()
{
}

bool Point::operator==( const Point& rhs )
{
  return (x==rhs.x && y==rhs.y);
}

bool Point::operator!=( const Point& rhs )
{
  return (x!=rhs.x || y!=rhs.y);
}

Point& Point::operator=( const Point& rhs )
{
  x = rhs.x;
  y = rhs.y;
  return *this;
}
Circle::Circle()
{
  r=0;
}
Circle::~Circle()
{
}

int Circle::findIntersection( Circle& C2, Point& P1, Point& P2 )
{
  double d = dist(center.x,center.y,C2.center.x,C2.center.y);
  if(d > r+C2.r)  // too far, no intersection
    return 0;
  if(d < r-C2.r)  // C2 inside this one
    return 0;
  if(d < C2.r-r)  // this one inside C2
    return 0;
  double a = (r*r - C2.r*C2.r + d*d)/(2.0*d);
  double h = sqrt(r*r - a*a);
  P1.x = center.x + a*(C2.center.x - center.x)/d + h*(C2.center.y - center.y)/d;
  P1.y = center.y + a*(C2.center.y - center.y)/d - h*(C2.center.x - center.x)/d;

  P2.x = center.x + a*(C2.center.x - center.x)/d - h*(C2.center.y - center.y)/d;
  P2.y = center.y + a*(C2.center.y - center.y)/d + h*(C2.center.x - center.x)/d;

  if(P1==P2)
    return 1;
  return 2;
}

int Circle::contains( Circle& C2 )
{
  return dist(center.x,center.y,C2.center.x,C2.center.y) + C2.r < r+EPS;
}
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

bool compare( double a, double b, double eps )
{
  if(a>b)
    if(a-b < eps)
      return true; //equal enough
    else
      return false; //not equal
  else
    if(b-a < eps)
      return true; //equal enough
    else
      return false;
}

void getFiles( int argc, char* argv[], FILE*& inF, FILE*& outF )
{
  if(argc!=2)
  {
    fprintf(stderr,"usage: %s infile\n",argv[0]);
    exit(0);
  }
  if(fopen_s(&inF,argv[1],"rt") != 0)
  {
    fprintf(stderr,"Could not open %s\n",argv[1]);
    exit(0);
  }
  char outFileName[256] = {0};
  sprintf_s(outFileName,sizeof(outFileName),"%s.out.txt",argv[1]);
  if(fopen_s(&outF,outFileName,"wt") != 0)
  {
    fprintf(stderr,"Could not open %s\n",outFileName);
    exit(0);
  }
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
  setSEPS("\t\n");
}

void tokenizer::setSEPS(const char* SEPS)
{
  strcpy_s(MOD_SEPS,sizeof(MOD_SEPS),SEPS);
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
    retval = strtok_s(tokens,MOD_SEPS,&context);
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
