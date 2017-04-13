#include <iostream>
#include <list>
#include <cmath>
using namespace std;

typedef struct {
	int a;
	int b;
} interval;

list<int> values;
int t;

int count(interval in){
	list<int>::iterator it = values.begin();
	bool flag = false;
	int s = 0;
	while(*it <= in.b && it != values.end()){
		if(*it >= in.a)
			s++;
		it ++;
	}
	return s;
}

int last(int n){
	if(n < 10) return n;
	return n / pow(10,(int)(log(n)/log(10)));
}

bool isFair(long long n){
	if(n < 10) return true;
	long p = pow(10,(int)(log(n)/log(10)));
	if( n / p != n % 10) return false;
	n = n % p;
	n = n / 10;
	return isFair(n);
}

int main(){
	long long a,b;
	float sq;
	interval in;
	list<interval> ints;
	int min, max;
	min = pow(10,7); 
	max = 0;
	int i,mod;
	cin >> t;
	for(i=1; i<=t; i++){
		cin >> a;
		cin >> b;
		sq = sqrt(a); if((int)sq == sq) in.a = sq; else in.a = 1 + sq;
		in.b = sqrt(b);
		ints.push_back(in);
		if(in.a < min) min = in.a;
		if(in.b > max) max = in.b;
	}

	while(min <= max){
		mod = min % 10;
		if(isFair(min) && isFair(min*min)){
			values.push_back(min);
			if(min < 10)
				min ++;
			else
				min += 11 - mod;
		}else{
			if(last(min) < mod)
				min += 11 - mod;
			else
				min ++;
		}
	}

	i = 1;
	while(i <= t){
		in = ints.front();
		ints.pop_front();
		cout << "Case #"<< i <<": "<< count(in) << endl;
		i++;
	}
	return 0;
}