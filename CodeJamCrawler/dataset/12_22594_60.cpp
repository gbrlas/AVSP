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

int main(void){
    int test_case;
    s(test_case);
    int scores[100];
    for(int i=1; i<=test_case; i++){
	  int n,s,p;
	  scanf("%d %d %d",&n,&s,&p);
	  for(int j=0; j<n; j++)
		scanf("%d",&scores[j]);
	  int not_amazing = 0;
	  int amazing = 0;
	  for(int j=0; j<n; j++){
		int rem = scores[j]/3;
		if (rem >= p)
		    not_amazing++;
		else{
		    if (scores[j]%3 == 0 && p-rem == 1 && scores[j] != 0)
			  amazing++;
		    else if (scores[j]%3 == 1 && p-rem == 1)
			  not_amazing++;
		    else if (scores[j]%3 == 2){
			  if ((p-rem) == 1)
				not_amazing++;
			  else if ((p-rem) == 2)
				amazing++;
		    }
		}
	  }
	  int ans = not_amazing + min(amazing,s);
	  printf("Case #%d: %d\n",i,ans);
    }
}

