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
l row1, row2;
lv set1(16), set2(16);


int getresult()
{
	if (row1 < 1 || row1 > 4 || row2 < 1 || row2 > 4) return -1;
	lvi first = set1.begin() + (row1-1)*4;
	lvi second = set2.begin() + (row2-1)*4;
	sort(first, first+4);
	sort(second, second+4);
	lv result(4);
	lvi res = set_intersection(first, first+4, second, second+4, result.begin());
	int size = res - result.begin();
	if (size > 1) return -2;
	if (size == 0) return -1;
    return result[0];
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream f("c:\\temp\\input.in");
    ofstream f2("c:\\temp\\output.txt");
    
    f >> T;	
    for (t = 1; t <= T; t++)
    {
	   f >> row1;
	   fi(i, 16) f >> set1[i];	   
	   f >> row2;
	   fi(i, 16) f >> set2[i];
       int result = getresult();
	   if (result > 0)
	   {
			cout << "Case #" << t << ": " << result << endl;
			f2 << "Case #" << t << ": " << result << endl;   
	   }
	   else if (result == -2)
	   {
		   cout << "Case #" << t << ": Bad magician!" << endl;
		   f2 << "Case #" << t << ": Bad magician!" << endl;
	   }
	   else
	   {
			cout << "Case #" << t << ": Volunteer cheated!" << endl;
			f2 << "Case #" << t << ": Volunteer cheated!" << endl; 
	   }
    }


    f.close();
    //f2.close();
	return 0;
}

