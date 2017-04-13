// =====================================================
//   Online Qualifier 2, A : void.parallax
// =====================================================
// Parallax : a member of team Void at the ACM ICPC contest

// --- With thanks to 'rem'
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef char s8;
typedef unsigned char u8;
typedef long long ll;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<ll> vl;

#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

typedef enum 
{
    kOr,
    kAnd,
    kTrue,
    kFalse
} Type;

class Node
{
public:
    Node(Type nodeType, bool changable)
        : m_nodeType(nodeType), m_changable(changable){}


    Type m_nodeType;
    bool m_changable;
};

typedef std::vector<Node> TreeType;
TreeType Tree;

u32 M; // Num Nodes
bool V; // Goal

//if -1, not possible, otherwise, num changes req
int changes[20000][2];
u32 numInterior;

const int bigInt = 0xfffFFFF;

// --===========================================================--
void calcChanges(u32 nodeIdx)
{
    u32 leftChildIdx  =  (nodeIdx + 1) * 2 - 1;
    u32 rightChildIdx = ((nodeIdx + 1) * 2) ;
    
    int andFalseValue = std::min(bigInt, changes[leftChildIdx][0] + changes[rightChildIdx][0]);
    andFalseValue = std::min(andFalseValue, changes[leftChildIdx][0] + changes[rightChildIdx][1]);
    andFalseValue = std::min(andFalseValue, changes[leftChildIdx][1] + changes[rightChildIdx][0]);

    int andTrueValue = std::min(bigInt, changes[leftChildIdx][1] + changes[rightChildIdx][1]);

    int orTrueValue = std::min(bigInt, changes[leftChildIdx][1] + changes[rightChildIdx][1]);
    orTrueValue = std::min(orTrueValue, changes[leftChildIdx][0] + changes[rightChildIdx][1]);
    orTrueValue = std::min(orTrueValue, changes[leftChildIdx][1] + changes[rightChildIdx][0]);

    int orFalseValue = std::min(bigInt, changes[leftChildIdx][0] + changes[rightChildIdx][0]);

    switch(Tree[nodeIdx].m_nodeType)
    {
    case kOr:
       if (Tree[nodeIdx].m_changable)
       {
           changes[nodeIdx][0] = std::min(orFalseValue, andFalseValue + 1);
           changes[nodeIdx][1] = std::min(orTrueValue,  andTrueValue + 1);
       }
       else
       {
           changes[nodeIdx][0] = orFalseValue;
           changes[nodeIdx][1] = orTrueValue;
       }
       break;
    case kAnd:
       if (Tree[nodeIdx].m_changable)
       {
           changes[nodeIdx][0] = std::min(orFalseValue + 1, andFalseValue);
           changes[nodeIdx][1] = std::min(orTrueValue + 1,  andTrueValue);
       }
       else
       {
           changes[nodeIdx][0] = andFalseValue;
           changes[nodeIdx][1] = andTrueValue;
       }
       break;
    case kTrue:
    case kFalse:
        assert(false);
        break;
    }

    cerr << "Node : " << nodeIdx << ": ("<<Tree[nodeIdx].m_nodeType<<"," << Tree[nodeIdx].m_changable << ") " 
        << ": ("<<leftChildIdx<<"," << rightChildIdx << ") "<< changes[nodeIdx][0] << ", " <<  changes[nodeIdx][1] << endl;
}

// --===========================================================--

int main()
{
    //NOTE: To see correct output, redirect stdout to a file and 
    // ignore stderr

    u32 numProblems = 0;

    cin >> numProblems;
    For(probNum, 1, numProblems)
    {
        
        Tree.clear();
        cin >> M >> V;
        numInterior = (M-1)/2;
        bool nodeAnd, nodeChangable;
        For(node, 0, numInterior - 1)
        {
            cin >> nodeAnd >> nodeChangable;
            Tree.push_back(Node(nodeAnd ? kAnd : kOr, nodeChangable));
            changes[node][0] = bigInt;
            changes[node][1] = bigInt;
        }

        bool nodeVal;
        For(node, numInterior, M-1)
        {
            cin >> nodeVal;
            Tree.push_back(Node(nodeVal ? kTrue : kFalse , false));
            if (nodeVal == 0)
            {
                changes[node][0] = 0;
                changes[node][1] = bigInt;
            }
            else
            {
                changes[node][0] = bigInt;
                changes[node][1] = 0;
            }
        }

        Ford(node, numInterior - 1, 0)
        {
            calcChanges(node);
        }

        int result = changes[0][V];

        if (result < bigInt)
        {
          cout << "Case #" << probNum <<": " << result << endl;
          cerr << "Case #" << probNum <<": " << result << endl;
        } 
        else
        {
          cout << "Case #" << probNum <<": " << "IMPOSSIBLE" << endl;
          cerr << "Case #" << probNum <<": " << "IMPOSSIBLE" << endl;
        }
    }
}