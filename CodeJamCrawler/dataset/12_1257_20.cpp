#include "libfns.h"

double dist(double x1, double y1, double x2, double y2)
{
  double retval = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  retval = sqrt(retval);
  return retval;
}

double min(double a, double b)
{
	if(a<b)
		return a;
	return b;
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

double Point::dist(Point& P2)
{
	double retval = (x-P2.x)*(x-P2.x) + (y-P2.y)*(y-P2.y);
	retval = sqrt(retval);
	return retval;
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

double Circle::intersectionArea(Circle& C2)
{
	Point intPts[2];
	int numPts = findIntersection(C2,intPts[0],intPts[1]);
	double retval;
	if(numPts < 2)
	{
		retval=0.0;
	}
	else if(contains(C2))
	{
		//area of C2
		retval = PI * C2.r*C2.r;
	}
	else if(C2.contains(*this))
	{
		//this area
		retval = PI * r*r;
	}
	else
	{
		double d = dist(center.x,center.y,C2.center.x,C2.center.y);
		double d1 = (d*d - C2.r*C2.r + r*r) / (2.0*d);
		double d2 = (d*d + C2.r*C2.r - r*r) / (2.0*d);
		retval = lensArea(r,d1) + lensArea(C2.r,d2);
	}
	return retval;
}

double Circle::lensArea(double R, double d)
{
	double retval = R*R;
	double tmp = acos(d/R);
	retval *=tmp;

	tmp = R*R - d*d;
	tmp = sqrt(tmp);
	tmp = d*tmp;
	retval -=  tmp;
	return retval;
//	return R*R*acos(d/R) - d*sqrt(R*R - d*d);
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

bigNum::bigNum()
{
	init();
}

bigNum::bigNum( const bigNum& rhs )
{
	sign = rhs.sign;
	for(size_t i = 0; i < BRANCHES; ++i)
	{
		data[i] = rhs.data[i];
	}
}

bigNum::bigNum( const char* rhs )
{
	init();
	//NULL terminated rhs
	char* currPtr = (char*) rhs;
	if(*currPtr == '-')
	{
		sign = false;
		++currPtr;
	}
	char digits[5] = {'0','0','0','0','\0'};
	size_t first_branch_len = ((strlen(currPtr) - 1)%4 )+ 1;
	int curr_branch = (int)(strlen(currPtr)-1 )/ 4;
	//handle first
	for(size_t i = (4-first_branch_len); i < 4; ++i)
	{
		digits[i] = *currPtr;
		++currPtr;
	}
	data[curr_branch] = atoi(digits);
	--curr_branch;
	while(curr_branch >= 0)
	{
		strncpy_s(digits,5,currPtr,4);
		data[curr_branch] = atoi(digits);
		--curr_branch;
		currPtr+=4;
	}
}

bigNum::bigNum( const int rhs )
{
	init();
	int x;
	if(rhs < 0)
	{
		sign = false;
		x = -rhs;
	}
	else
	{
		x = rhs;
	}
	int idx = 0;
	while(x > 0)
	{
		data[idx] = x%BASE;
		++idx;
		x/=BASE;
	}
}

bigNum::~bigNum()
{
}

bigNum& bigNum::operator=( const bigNum& rhs )
{
	sign = rhs.sign;
	for(int i=0; i<BRANCHES; ++i)
	{
		data[i] = rhs.data[i];
	}
	return *this;
}

bigNum& bigNum::operator=( const int rhs )
{
	bigNum x(rhs);
	*this = x;
	return *this;
}

bigNum& bigNum::operator=( const char* rhs )
{
	bigNum x(rhs);
	*this = x;
	return *this;
}

bigNum bigNum::operator+( const bigNum& rhs ) const
{
	bigNum retval = *this;
	retval += rhs;
	return retval;
}

bigNum bigNum::operator-( const bigNum& rhs ) const
{
	bigNum retval = *this;
	retval -= rhs;
	return retval;
}

bigNum bigNum::operator*( const bigNum& rhs ) const
{
	bigNum retval = *this;
	retval *= rhs;
	return retval;
}

bigNum bigNum::operator/( const bigNum& rhs ) const
{
	bigNum retval = *this;
	retval /= rhs;
	return retval;
}

bigNum bigNum::operator%( const bigNum& rhs ) const
{
	bigNum retval = *this;
	retval %= rhs;
	return retval;
}

bigNum& bigNum::operator+=( const bigNum& rhs )
{
	if(sign == rhs.sign)
	{
		int carry = 0;
		int subtotal = 0;
		for(size_t i=0; i<BRANCHES; ++i)
		{
			subtotal = data[i] + rhs.data[i] + carry;
			data[i] = subtotal % BASE;
			carry = subtotal/BASE;
		}
	}
	else
	{
		*this -= -rhs;
	}
	return *this;
}

bigNum& bigNum::operator-=( const bigNum& rhs )
{
	if(sign!=rhs.sign)
	{
		*this += -rhs;
	}
	else
	{
		// signs are the same
		if(abs(rhs) > abs(*this))
			*this = -(rhs - *this);
		else
		{
			//the meat of it
			int carry = 0;
			for(int i=0; i<BRANCHES; ++i)
			{
				data[i] -= (rhs.data[i] + carry);
				if(data[i] > BASE) //stupid unsigned ints
				{
					data[i] += BASE;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
			}
		}

	}
	return *this;
}

bigNum& bigNum::operator*=( const bigNum& rhs )
{
	bigNum product;
	for(int i=0; i<BRANCHES;++i)
	{
		int carry=0;
		for(int j=0; i+j<BRANCHES-1;++j)
		{
			int partial = data[i] * rhs.data[j];
			product.data[i+j] += (partial + carry);
			carry = product.data[i+j] / BASE;
			product.data[i+j] %= BASE;
		}
		product.data[BRANCHES-1] += carry;
	}
	product.sign = (sign==rhs.sign);
	*this = product;
	return *this;
}

bigNum& bigNum::operator/=( const bigNum& rhs )
{
	return *this;
}

bigNum& bigNum::operator%=( const bigNum& rhs )
{
	*this -= ((*this/rhs)*rhs);
	return *this;
}

void bigNum::init()
{
	for(size_t i=0; i<BRANCHES; ++i)
	{
		data[i] = 0;
	}
	sign = true;
}

bigNum bigNum::operator-() const
{
	bigNum retval = *this;
	retval.sign = !retval.sign;
	return retval;
}

bigNum bigNum::abs( const bigNum& rhs ) const
{
	bigNum retval = rhs;
	retval.sign = true;
	return retval;
}

bool bigNum::operator==( const bigNum& rhs ) const
{
	for(int i=0; i<BRANCHES; ++i)
	{
		if(data[i] != rhs.data[i])
		{
			return false;
		}
	}
	if(sign!=rhs.sign)
	{
		return false;
	}
	return true;
}

bool bigNum::operator!=( const bigNum& rhs ) const
{
	return !(*this == rhs);
}

bool bigNum::operator<( const bigNum& rhs ) const
{
	if(sign)
	{
		if(!rhs.sign)
		{
			return false;
		}
		else
		{
			int branch = topMismatch(rhs);
			if(branch==-1)
			{
				return false;
			}
			else if(data[branch] < rhs.data[branch])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if(rhs.sign)
		{
			return true;
		}
		else
		{
			return (-(*this) > -rhs);
		}
	}
}

bool bigNum::operator>( const bigNum& rhs ) const
{
	if(sign)
	{
		if(!rhs.sign)
		{
			return true;
		}
		else
		{
			int branch = topMismatch(rhs);
			if(branch==-1)
			{
				return false;
			}
			else if(data[branch] > rhs.data[branch])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if(rhs.sign)
		{
			return false;
		}
		else
		{
			return (-(*this) > -rhs);
		}
	}

}

bool bigNum::operator<=( const bigNum& rhs ) const
{
	if(*this == rhs)
		return true;
	if(*this < rhs)
		return true;
	return false;
}

bool bigNum::operator>=( const bigNum& rhs ) const
{
	if(*this == rhs)
		return true;
	if(*this > rhs)
		return true;
	return false;
}

char* bigNum::getStr()
{
	char* currptr = printable;
	char buff[5];
	if(!sign)
	{
		*currptr = '-';
		++currptr;
	}
	*currptr = 0;
	int top_branch;
	for(top_branch = BRANCHES-1; top_branch > 0; --top_branch)
	{
		if(data[top_branch] != 0)
			break;
	}
	//hand first
	sprintf_s(buff,5,"%d",data[top_branch]);
	buff[4] = 0;
	strcat_s(printable,66,buff);
	--top_branch;

	while(top_branch >= 0)
	{
		sprintf_s(buff,5,"%04d",data[top_branch]);
		buff[4] = 0;
		strcat_s(printable,66,buff);
		--top_branch;
	}
	


	return printable;
}

int bigNum::topMismatch( const bigNum& rhs ) const
{
	int i;
	for(i=BRANCHES-1; i>=0; --i)
	{
		if(data[i] != rhs.data[i])
		{
			break;
		}
	}
	return i;
}

bigNum bigNum::operator^( const int exp ) const
{
	if(exp>0)
	{
		if(exp==2)
		{
			return ((*this)*(*this));
		}
		else if(exp%2 == 0)
		{
			return (((*this)^(exp/2))^2); 
		}
		else
		{
			return ((*this)*((*this)^(exp-1)));
		}
	}
	else if(exp == 0)
	{
		return bigNum(1);
	}
	else
	{
		// < 0.  Just return 0 for now
		return bigNum(0);
	}
}