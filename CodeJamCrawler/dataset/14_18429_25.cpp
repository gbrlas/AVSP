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

l T, t, n, N;
d C, F, X;


d getresult()
{
	if (X <= C) return X /2.0;
	d cookierate = 2.0;
	d time = X / 2.0;
	d timespent = 0;
	while (true)
	{		
		d newtime = timespent + C / cookierate + (X / (cookierate + F));
			
		time = min(time, newtime);
		timespent += C/cookierate;
		if (timespent > time) return time;
		cookierate += F;
		
	}
    return time;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");
    
    f >> T;
    for (t = 1; t <= T; t++)
    {
		f >> C >> F >> X;
       d result = getresult();
	   cout << std::fixed;
	   cout.precision(7);
       cout << "Case #" << t << ": " << result << endl;    
	   f2 << std::fixed;
	   f2.precision(7);
       f2 << "Case #" << t << ": " << result << endl;  
    }


    f.close();
    f2.close();
	return 0;
}

