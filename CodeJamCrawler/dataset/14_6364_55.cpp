#include <iostream>
// For strings			#include <string>
// For fstream 			#include <fstream>
#include <iomanip>
// For getchar() 		#include <cstdio>
// rand(),atoi			#include <cstdlib>
// For srand(time(NULL)) #include <time.h>
// For Built-in sort	#include <algorithm>
#include <cmath>
// For vectors 			#include <vector>
//For Binary Tree sets,multisets -  #include<set>
// For lists			#include<list>
//For queues  			#include<queue>
//For stacks  			#include<stack>
//For pairs				#include<utility>
//For maps 				#include<map>
using namespace std;


int main(){
	cout<<fixed;
	int tstCases;
	cin>>tstCases;
	//t = 1;	
	for(int tst = 0; tst < tstCases; tst++){
		double c,f,x,t = 0;
		cin>>c>>f>>x;
		double a = 2.0;
		while(true){
			if(x/a <= x/(a+f) + c/a){
				t += x/a;
				break;
			}
			else{
				t += c/a;
				a = a+f;
			}
		}
		cout<<"Case #"<<tst+1<<": ";
		cout<<setprecision(7)<<t<<endl;
			/*
		double n = ceil((x-c)/c - 2.0/f);
		n = max(0.0,n);
	*/
	//	cout<<setprecision(7)<<variable;
	}	
}
//speed up process: ios_base::sync_with_stdio(true/false);

/*
STRING
string s;
getline(cin,s); or cin>>s;(cin doesnt allow spaces)
s.substr(startpos, lenght);
s.find(char/string, startpos);
s.length();
*/

/*
FSTREAM
ofstream fo;
ifstream fi;
fi.open("input.in");
fo.open("output.in");

fo.close();
fi.close();
*/

/*
SETTING THE NUMBER OF DECIMALS TO BE PRINTED:

*/

/*
INPUTTING AN EMPTY VALUE
getchar();
*/

/*
BUILT IN SORT
	#include <algorithm>
	bool myCompare(type a, type b){
		return a<b; //correspondingly to the type the condition for a to be before b
	}
	//myCompare optional
	vector <type> v;
	sort(v.begin(), v.end(), <OPTIONAL : myCompare>);
	//or list.sort(OPTIONAL FUNCTION);
*/

/*
MERGESORT usage:- a = mergesort(a,size); // a is the array of "int" of length "size";

int* merge(int a[],int m, int b[],int n){
	int* c = new int [m+n];
	int i=0,j=0;
	while(i<=m&&j<=n){
		if(i==m&&j==n) return c;
		else if(i==m)	
			{
			for(int k=m+j;k<m+n;k++){
					c[k]=b[k-m];}
					j=n;}
		else if(j==n)
		{
			for(int k=n+i;k<m+n;k++){
					c[k]=a[k-n];}
					i=m;}
		else if(a[i]<b[j]){
			c[i+j] = a[i]; i++;}
		else {
			c[i+j] = b[j]; j++;}
	}
}

int* mergesort(int* a, int n){
	if(n!=1)
	{
	int m = n/2, p = n - m;
	int* b =  new int [m];
	int* c =  new int [p];
	for(int i=0;i<m;i++){
		b[i] = a[i];
	}
	for(int i=0;i<p;i++){
		c[i] = a[i+m];
	}
	return merge(mergesort(b,m),m,mergesort(c,p),p);
	}
	else return a;
}

*/

/*
A random list of integers limited by max

#include <ctime>
#include <cstdlib>
void randomList(int* a, int n, int max=1000){
		srand (time(NULL));
		for(int i=0;i<n;i++){
			a[i] = rand()%max;
		}
		return;
}

*/

/*
long long int nCr(long long int n, long long int r){
	long long int div,result = 1, denom = 1;
	for(int i=1;i<=n-r;i++){
		result *=r+i;
		denom *= i;
		div = gcd(result,denom);
		result /= div;
		denom /= div;
	}
	return result;
}
*/
/*
unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
	if(a==0) return b;
	else if(b==0) return a;
	else if(a==1) return 1;
	else if(b==1) return 1;
	else if(a==b) return a;
	else if(a>b) return gcd(b,a%b);
	else return gcd(a,b%a);
}
*/
/*
unsigned long long int factors(unsigned long long int n){
	unsigned long long int tc = 1, count =1,fac = 2;
	while(n!=1){
		if(n%fac==0){
			n /= fac;
			count++;
		}
		else{
			tc *= count;
			count = 1;
			fac++;
		}
	}
	tc *= count;
	return tc;
}*/
/*
INVERSE MODULO b

long long int inverse(long long int a, long long int b){
	long long int m = b;
	long long int x = 0, y = 1, lx = 1, ly = 0,X,Y,q,A,B,Lx,Ly;
	while(b!=0){
		q = a/b;	
		A = a;
		B = b;	
		a = B;
		b = A%B;	
		X = x;
		Lx = lx;
		Y = y;
		Ly = ly;	
		x = Lx - q*X;
		lx = X;	
		y = Ly - q*Y;
		ly = Y;
	}
	if(lx < 0) lx += m;
	return lx;	
}

*/

/* LOG TIME MODULAR EXPONENTIATION

long long int logexp(long long int  a,long long int n,long long int &mod){
	if(n==0)  return 1;
	else if(n==1) return a%mod;
	long long int x = logexp(a,n/2,mod);
	if(n%2==0) return ((x%mod)*(x%mod))%mod;
	else if(n%2==1) return (a*((x%mod)*(x%mod))%mod)%mod;
}

*/
/*
pair<double,double> solveQuad(long long int a, long long int b, long long int c){
	double d = sqrt(b*b - 4*a*c);
	return make_pair((-b + d)/(2*a),(-b - d)/(2*a));
}

bool isInt(double d){
	return d==floor(d);
}
*/
