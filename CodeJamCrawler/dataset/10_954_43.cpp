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
