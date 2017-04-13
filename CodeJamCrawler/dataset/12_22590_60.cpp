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

string translation = "yhesocvxduiglbkrztnwjpfmaq";

int main(void){
    int t;
    s(t);
    getchar();
    for(int j=1; j<=t; j++){
	  string in,out;
	  getline(cin,in);
	  for(int i=0; i<in.length(); i++){
		if (isspace(in.at(i)))
		    out.push_back(in.at(i));
		else
		    out.push_back(translation.at((int) in.at(i)-97));
	  }
	  cout<<"Case #"<<j<<": "<<out<<endl;;
    }
    return 0;
}

