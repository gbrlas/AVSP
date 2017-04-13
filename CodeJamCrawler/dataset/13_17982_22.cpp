#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <math.h>
#include <string>
#include <stack>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long l;typedef long double d;typedef char ch;typedef bool b;typedef string str;
#define InitContainers(T) typedef vector<T> T##v; typedef list<T> T##l; typedef set<T> T##s; typedef stack<T> T##st; typedef map<T,T> T##m; typedef pair<T,T> T##p;
#define InitIterators(T) typedef vector<T>::iterator T##vi; typedef list<T>::iterator T##li; typedef set<T>::iterator T##si; typedef map<T,T>::iterator T##mi;
InitContainers(l)InitContainers(d)InitContainers(ch)InitContainers(str)InitIterators(l)InitIterators(d)InitIterators(ch)InitIterators(str)
#define fi(i, n) for (int i = 0; i < n; i++)
#define fe(T, iter, container) for (T::iterator iter = container.begin(); iter != container.end(); iter++)
#define fsort(list) sort(list.begin(), list.end())
#define all(list) list.begin(), list.end()

int T, t, n, N;
l A;
lv m;

int getresult()
{
    l sum = 0;
    fsort(m);
    l counter = m.size();
    fe (lv, i, m)
    {
        if (*i < A)
        {
           A+=*i;
        }
        else
        {
            if (A*2-1 <= *i && A - 1 > 0)
            {
                l c2 = 0;
                l newsum = 0;
                while (A <= *i)
                {
                    A+= A-1;
                    newsum++;
                    c2++;
                }
                if (newsum > counter) newsum = counter;
                sum+=newsum;
                A+=*i;
            } else {
                if (A*2 -1 > *i)
                {
                    A+= A-1;
                    A+=*i;
                }
                sum++;
            }
        }
        counter--;
    }
    if (sum > m.size()) sum = m.size();
    return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");
    
    f >> T;
    for (t = 1; t <= T; t++)
    {
       m.clear();
       f >> A >> N;
       fi(i, N) {
         l a;
         f >> a;
         m.push_back(a);
       }
       int result = getresult();
       f2 << "Case #" << t << ": " << result << endl;              
    }
    


    f.close();
    f2.close();
	return 0;
}

