#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <math.h>
#define PI 3.1415926
#define EPS .00001

double dist(double x1, double y1, double x2, double y2);
bool compare(double a, double b, double eps);

class Point{
public:
  double x,y;
  Point();
  ~Point();
  bool operator==(const Point& rhs);
  bool operator!=(const Point& rhs);
  Point& operator=(const Point& rhs);
};

class Circle{
public:
  Point center;
  double r;
  Circle();
  ~Circle();
  int findIntersection(Circle& C2, Point& P1, Point& P2);
  int contains(Circle& C2);
};

bool isDigit(char c);
bool isAlpha(char c);
void getFiles(int argc, char* argv[], FILE*& inF, FILE*& outF);

class tokenizer{
private:
  FILE* dataFile;
  char line[1024];
  char* retval;
  char MOD_SEPS[32];
  void setFile(FILE* fp);
public:
  tokenizer();
  tokenizer(FILE* fp);
  void setSEPS(const char*);
  char* getToken();
  ~tokenizer();
  char* context;
};


class Node {
  Node* left;
  Node* right;
public:
  Node();
  ~Node();
};

#define BASE 10000 //for ease of printing
#define BRANCHES 16
class bigNum{
private:
	unsigned int data[BRANCHES]; //4 digits per array item.  64 enough? too much?
	bool sign;
	char printable[BRANCHES*4 + 2]; //+2 for NULL and sign
	int topMismatch(const bigNum& rhs) const;
	void init();
public:
	bigNum();
	bigNum(const bigNum& rhs);
	bigNum(const int rhs);
	bigNum(const char* rhs);
	~bigNum();
	bigNum& operator=(const bigNum& rhs);
	bigNum& operator=(const int rhs);
	bigNum& operator=(const char* rhs);

	bigNum operator+(const bigNum& rhs) const;
	bigNum operator-(const bigNum& rhs) const;
	bigNum operator*(const bigNum& rhs) const;
	bigNum operator/(const bigNum& rhs) const;
	bigNum operator%(const bigNum& rhs) const;
	bigNum operator^(const int exp) const;
	bigNum& operator+=(const bigNum& rhs);
	bigNum& operator-=(const bigNum& rhs);
	bigNum& operator*=(const bigNum& rhs);
	bigNum& operator/=(const bigNum& rhs);
	bigNum& operator%=(const bigNum& rhs);
	
	bigNum operator-() const;
	bigNum abs(const bigNum& rhs) const;
	bool operator==(const bigNum& rhs) const;
	bool operator!=(const bigNum& rhs) const;
	bool operator<(const bigNum& rhs) const;
	bool operator>(const bigNum& rhs) const;
	bool operator<=(const bigNum& rhs) const;
	bool operator>=(const bigNum& rhs) const;
	char* getStr();
};

template<class T>
class fraction{
private:
	T numerator;
	T denominator;
	T gcd(T a, T b)
	{
		if(b==T(0))
			return a;
		else
			return gcd(b, a%b);
	}
	void reduce()
	{
		T g = gcd(numerator,denominator);
		numerator=numerator/g;
		denominator=denominator/g;
	}
public:
	fraction<T>()
	{
	}
	fraction<T>(const fraction<T>& rhs)
	{
		numerator = rhs.numerator;
		denominator=rhs.denominator;
		reduce();
	}
	fraction<T>(const T& rhs)
	{
		numerator = rhs;
		denominator=T(1);
		reduce();
	}

	~fraction<T>()
	{
	}

	fraction<T>& operator=(const fraction<T>& rhs)
	{
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		reduce();
		return *this;
	}
	fraction<T>& operator=(T rhs)
	{
		numerator = rhs;
		denominator = T(1);
		return *this;
	}
	fraction<T> operator+(const fraction<T>& rhs) const
	{
		fraction<T> retval = *this;
		retval+=rhs;
		return retval;
	}
	fraction<T>& operator+=(const fraction<T>& rhs)
	{
		fraction<T> r = rhs;
		T g = gcd(denominator,r.denominator);
		denominator/=g;
		r.denominator/=g;
		numerator = numerator*r.denominator+denominator*r.numerator;
		denominator = denominator*r.denominator;
		reduce();
		denominator*=g;
		reduce();
		return *this;
	}
	fraction<T> operator-(const fraction<T>& rhs) const
	{
		fraction retval = *this;
		retval-=rhs;
		return retval;
	}
	fraction<T>& operator-=(const fraction<T>& rhs)
	{
		fraction<T> r = rhs;
		T g = gcd(denominator,r.denominator);
		denominator/=g;
		r.denominator/=g;
		numerator = numerator*r.denominator-denominator*r.numerator;
		denominator = denominator*r.denominator;
		reduce();
		denominator*=g;
		reduce();
		return *this;
	}
	fraction<T> operator*(const fraction<T>& rhs) const
	{
		fraction<T> retval = *this;
		retval*=rhs;
		return retval;
	}
	fraction<T>& operator*=(const fraction<T>& rhs)
	{
		fraction<T> r = rhs;
		T g = gcd(numerator,r.denominator);
		numerator=numerator/g;
		r.denominator=r.denominator/g;
		g = gcd(r.numerator,denominator);
		r.numerator=r.numerator/g;
		denominator=denominator/g;

		numerator = numerator*r.numerator;
		denominator = denominator*r.denominator;
		reduce();
		return *this;
	}
	fraction<T> operator/(const fraction<T>& rhs) const
	{
		fraction<T> retval = *this;
		retval/=rhs;
		return retval;
	}
	fraction<T>& operator/=(const fraction<T>& rhs)
	{
		fraction<T> r = rhs;
		T g = gcd(numerator,r.numerator);
		numerator=numerator/g;
		r.numerator=r.numerator/g;
		g = gcd(denominator,r.denominator);
		r.denominator=r.denominator/g;
		denominator=denominator/g;

		numerator = numerator * r.denominator;
		denominator = denominator * r.numerator;
		reduce();
		return *this;
	}
	bool operator==(const fraction<T>& rhs) const
	{
		if(numerator == rhs.numerator)
			if(numerator == 0 || denominator==rhs.denominator)
				return true;
		return false;
	}
	bool operator!=(const fraction<T>& rhs) const
	{
		return !(*this == rhs);
	}
	bool operator<(const fraction<T>& rhs) const
	{
		// a/b < c/d  =>  ad < bc
		fraction<T> t = *this;
		t -= rhs;
		if(t.numerator<0 || t.denominator<0)  //should really check for both here.
			return true;
		return false;
	}
	bool operator>(const fraction<T>& rhs) const
	{
		fraction<T> t = *this;
		t -= rhs;
		if(t.numerator>0)
			return true;
		return false;
	}
	bool operator<=(const fraction<T>& rhs) const
	{
		if(*this<rhs)
			return true;
		if(*this==rhs)
			return true;
		return false;
	}
	bool operator>=(const fraction<T>& rhs) const
	{
		if(*this>rhs)
			return true;
		if(*this==rhs)
			return true;
		return false;
	}
	T getNum() const
	{
		return numerator;
	}
	T getDen() const
	{
		return denominator;
	}
	void setNum(T num)
	{
		numerator = num;
		reduce();
	}
	void setDen(T den)
	{
		denominator = den;
		reduce();
	}
	void setFrac(T num, T den)
	{
		numerator = num;
		denominator = den;
		reduce();
	}
};

template<class T>
std::ostream& operator<<(std::ostream& os, fraction<T>& f)
{
	os<<f.getNum()<<'/'<<f.getDen();
	return os;
}

// takes an augmented matrix and performs Gaussian elimination
template<class T>
class AugmentedMatrix{
private:
	int rows; //cols = rows + 1;
	T* data;
public:
	AugmentedMatrix<T>()
	{
		rows = 5;
		init();
	}
	AugmentedMatrix<T>(int numRows)
	{
		rows = numRows;
		init();
	}
	void init()
	{
		data = new T[rows*(rows+1)];
	}
	~AugmentedMatrix<T>()
	{
		delete[] data;
	}
	int getRows() const
	{
		return rows;
	}
	void setEntry(const int row, const int col, const T& rhs)
	{
		data[row*(rows+1)+col] = rhs;
	}
	T getEntry(int row, int col) const
	{
		return data[row*(rows+1)+col];
	}
	void reSize(int newRows)
	{
		delete[] data;
		rows = newRows;
		data = new T[rows*(rows+1)];
	}
	void solve()
	{
		T divider;
		for(int currRow=0; currRow<rows; ++currRow)
		{
			divider = data[currRow*(rows+1)+currRow];
			for(int col=0; col<(rows+1); ++col)
			{
				data[currRow*(rows+1)+col]/=divider;
			}

			// now clear all lower rows
			for(int clearRow = currRow+1; clearRow<rows; ++clearRow)
			{
				divider = data[clearRow*(rows+1)+currRow]/data[currRow*(rows+1)+currRow];
				for(int col=0; col<(rows+1); ++col)
				{
					data[clearRow*(rows+1)+col]-=(divider*data[currRow*(rows+1)+col]);
				}
			}
		}

		for(int currRow = rows-1; currRow>0; --currRow)
		{
			for(int clearRow = currRow-1; clearRow>=0; --clearRow)
			{
				divider = data[clearRow*(rows+1)+currRow];
				for(int col=0; col<(rows+1); ++col)
				{
					data[clearRow*(rows+1)+col]-=(divider*data[currRow*(rows+1)+col]);
				}
			}
		}
	}
};

template<class T>
std::ostream& operator<<(std::ostream& os, AugmentedMatrix<T>& a)
{
	for(int i=0; i<a.getRows();++i)
	{
		for(int j=0; j<=a.getRows();++j)
		{
			os<<a.getEntry(i,j)<<'\t';
		}
		os<<std::endl;
	}
	return os;
}

template<class T>
inline T gcd (T a, T b)
{
	T t;

	while (!(b == T(0)))
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}
