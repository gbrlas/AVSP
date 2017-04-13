/*   In The Name of Allah   */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std ;


typedef long long LL ;
#define ALL(a)              (a).begin(),(a).end()
#define SZ(v)               ((int)(v).size())
#define FOR(i,start,end)    for(int i = start ; i < end ; i++)
#define REP(i,start,end)    for(int i = start ; i >= end ; i--)
#define FOREACH(it,x)       for(it = (x.begin()) ; it != (x).end() ; it ++)

bool isLowerCase(char c){ return (c >= 'a' &&  c <= 'z') ; }
bool isUpperCase(char c){ return (c >= 'A' &&  c <= 'Z') ; }
char toLowerCase(char c){ return (isUpperCase(c) ? (c + 32) : c) ; }
char toUpperCase(char c){ return (isLowerCase(c) ? (c - 32) : c) ; }
bool isLetter ( char c ){ return (isUpperCase(c)) || (isLowerCase(c)) ; }
bool isDigit  ( char c ){ return (c >= '0' &&  c <= '9') ; }

template < class T > string toString(T x) {stringstream s ; s << x; return s.str() ; }
template < class T > long long toInt(T x) {istringstream is(x) ; long long num  ; is >> num ; return num ; }
template < class T > vector <T> Parse(T temp){ vector <T> ans ; ans.clear() ; T s ; istringstream is(temp) ; while(is >> s){ ans.push_back(s) ; } return ans ; }

bool sw[1001] ;
int main()// *(codejam 2012 - qualification)* -  A. Speaking in Tongues
{
    freopen ("input.in","r",stdin) ; freopen ("output.out","w",stdout) ;
    //ifstream cin("input.in") ; //ofstream cout("output.out") ;

	/*
	string str = "1234" ;
	cout << str.substr(0) + str.substr(0,0) << endl  ;
	*/
	int tCase ;
	cin >> tCase ;
	FOR(i , 0 , tCase){
		memset(sw , false , sizeof(sw)) ;
		int a , b ;
		cin >> a >> b ;
		int ans = 0 ;
		FOR(j , a , b + 1){
			if(j < 10 || sw[j]) continue ;// 0 - 9
			string str = toString(j) ;
			if(count(ALL(str) , str[0]) == SZ(str)) continue ;//Ex : 2222
			int cnt = 1 ;
			sw[j] = true ;
			//cout << "\n " << j ; 
			FOR(k , 0 , SZ(str) - 1){
				string tmp = str.substr(k + 1) + str.substr(0 , k + 1)  ;
				int num = toInt(tmp) ;
				if(SZ(toString(num)) == SZ(str) && num >= a && num <= b){
					sw[num] = true ;
					//cout << " " << num << " " ;
					cnt ++ ;
				}
			}
			ans += ((cnt * (cnt - 1)) / 2) ;
		}
		printf("Case #%d: %d\n" , i + 1 , ans) ;
	}
	
return 0 ;
}
/*
---------------------------------------------
Input:
---------

---------------------------------------------
Output:
---------

---------------------------------------------
*/