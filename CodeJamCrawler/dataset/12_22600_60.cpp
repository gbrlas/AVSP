/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <list>

#define s(a) scanf("%d",&a)
#define ss(a,b) scanf("%d %d",&a,&b)
#define p(a) printf("%d\n",a)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>

using namespace std;
typedef long long int LL;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int possible_pair(int n, int limit){
    int num_digits = convertInt(n).length();
    int count = 0;
    set<int> pairs;
    for(int i=1; i< num_digits; i++){
	  int factor = pow(10,num_digits-i);
	  int rem = n%factor;
	  int quot = n/factor;
	  int pair = rem*pow(10,i)+quot;
	  if (pair>n && pair<=limit && pairs.find(pair) == pairs.end()){
		count++;
		pairs.insert(pair);
	  }
    }
    return count;
}

int main(void){
    int t;
    s(t);
    for(int i=1; i<=t; i++){
	  int a,b;
	  ss(a,b);
	  int count = 0;
	  for(int j=a; j<b; j++){
		count += possible_pair(j,b);
	  }
	  printf("Case #%d: %d\n",i,count);
    }
}

