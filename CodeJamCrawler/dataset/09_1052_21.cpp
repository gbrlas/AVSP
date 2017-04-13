#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#define PI 3.1415926

bool isDigit(char c);
bool isAlpha(char c);

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
};


class Node {
  Node* left;
  Node* right;
public:
  Node();
  ~Node();
};