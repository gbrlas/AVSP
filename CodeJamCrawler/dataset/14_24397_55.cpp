#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;
typedef long long int int64;
#define MOD 1000000007

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a, long long b, long long c){
	long long x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1){
			x = (x + y) % c;
		}
		y = (y * 2) % c;
		b /= 2;
	}
	return x%c;
}
/* This function calculates (a^sb)%c */
long long modulo(long long a, long long b, long long c){
	long long x = 1, y = a; // long long is taken to avoid overflow of intermediate results
	while (b > 0){
		if (b % 2 == 1){
			x = mulmod(x, y, c);
		}
		y = mulmod(y, y, c); // squaring the base
		b /= 2;
	}
	return x%c;
}
/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p, int iteration){
	if (p<2){
		return false;
	}
	if (p != 2 && p % 2 == 0){
		return false;
	}
	long long s = p - 1;
	while (s % 2 == 0){
		s /= 2;
	}
	for (int i = 0; i<iteration; i++){
		long long a = rand() % (p - 1) + 1, temp = s;
		long long mod = modulo(a, temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1){
			mod = mulmod(mod, mod, p);
			temp *= 2;
		}
		if (mod != p - 1 && temp % 2 == 0){
			return false;
		}
	}
	return true;
}
//int main(int argc, char* argv[])
int length;
int binsearch(int arr[], int key)
{
	int low = 0, mid,high = length - 1;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (arr[mid]>=key) high=mid-1;
		else low=mid+1;
	}
	if (arr[low] == key) return low;
	else return -1;
}

void reverse_string(char str[])
{
	char c;
	char *p, *q;

	p = str;
	if (!p)
		return;

	q = p + 1;
	if (*q == '\0')
		return;

	c = *p;
	reverse_string(q);

	while (*q != '\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = c;

	return;
}
int arr[16];
int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code here
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		double c, f, x,sum=0;
		cin >> c >> f >> x;
		int i = 0;
		while (c < f*x / (2 + f*(i + 1)))
		{
			sum += c / (2 + f*i);
			i++;
		}
		sum += x / (2 + f*i);
		printf("Case #%d: %.7lf\n",testcase,sum);
	}
	//debug
	//for (vector<i64>::iterator it = sqr.begin(); it != sqr.end(); ++it)
	//cout << ' ' << *it;
	//cout << '\n';
	//
	fclose(stdout);
	fclose(stdin);

	return 0;

}