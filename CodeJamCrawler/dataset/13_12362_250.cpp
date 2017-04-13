#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>

using namespace std;

#define MAXNEED (1000)
#define PERDIGIT (10)
#define LOGDIGIT (1) // LOGDIGIT=log10(PERDIGIT)
#define MAXARRAY ((MAXNEED+LOGDIGIT-1)/LOGDIGIT)

// if need BigNum::BigNum(char*)
#define ISNUM(c) ((c)>='0' && (c)<='9')

class BigNum {
// Declare everything public
public:

// Data
	int nDigit;
	int digit[MAXARRAY];

// Constructors that may need
	BigNum();
	BigNum(const char* str);
	BigNum(const unsigned int num);
	BigNum(const BigNum& bn);

// Destructor does nothing
	~BigNum() {
	}
	;

// Arithmatic Operators
	friend BigNum operator+(const BigNum& first, const BigNum& second);
	friend BigNum operator-(const BigNum& first, const BigNum& second);
	friend BigNum operator*(const BigNum& first, const BigNum& second);
	friend BigNum operator/(const BigNum& first, const BigNum& second);
	friend BigNum operator%(const BigNum& first, const BigNum& second);
	BigNum sqrt(bool isUpper);
	BigNum pow(const int n);

	BigNum& operator=(const BigNum& second);

	BigNum& operator+=(const BigNum& second);
	BigNum& operator-=(const BigNum& second);
	BigNum& operator*=(const BigNum& second);
	BigNum& operator/=(const BigNum& second);
	BigNum& operator%=(const BigNum& second);

// Compare operators
	friend int operator==(const BigNum& first, const BigNum& second);
	friend int operator>(const BigNum& first, const BigNum& second);
	friend int operator<(const BigNum& first, const BigNum& second);

	friend int operator!=(const BigNum& first, const BigNum& second) {
		return !(operator==(first, second));
	}
	friend int operator>=(const BigNum& first, const BigNum& second) {
		return !(operator<(first, second));
	}
	friend int operator<=(const BigNum& first, const BigNum& second) {
		return !(operator>(first, second));
	}
// Output Stream
	friend ostream& operator<<(ostream& os, BigNum& bn);

// Useful Methods
	inline void clear() {
		int i;
		for (i = 0; i < MAXARRAY; i++)
			digit[i] = 0;
		nDigit = 0;
	}
	BigNum& div2() {
		int i;
		for (i = nDigit - 1; i >= 0; i--) {
			if (digit[i] % 2 && i)
				digit[i - 1] += PERDIGIT;
			digit[i] /= 2;
		}
		if (!digit[nDigit - 1])
			nDigit--;
		return (*this);
	}
};

// Compare Operators
int operator==(const BigNum& first, const BigNum& second) {
	if (first.nDigit != second.nDigit)
		return 0;
	int i;
	for (i = 0; i < first.nDigit; i++)
		if (first.digit[i] != second.digit[i])
			return 0;
	return 1;
}

int operator>(const BigNum& first, const BigNum& second) {
	if (first.nDigit > second.nDigit)
		return 1;
	if (first.nDigit < second.nDigit)
		return 0;
	int i;
	for (i = first.nDigit - 1; i >= 0; i--) {
		if (first.digit[i] > second.digit[i])
			return 1;
		if (first.digit[i] < second.digit[i])
			return 0;
	}
	return 0;
}

int operator<(const BigNum& first, const BigNum& second) {
	if (first.nDigit < second.nDigit)
		return 1;
	if (first.nDigit > second.nDigit)
		return 0;
	int i;
	for (i = first.nDigit - 1; i >= 0; i--) {
		if (first.digit[i] < second.digit[i])
			return 1;
		if (first.digit[i] > second.digit[i])
			return 0;
	}
	return 0;
}

// Arith Operators

BigNum operator+(const BigNum& first, const BigNum& second) {
// need BigNum::operator+=(BigNum&),BigNum::BigNum(BigNum&)
	BigNum temp(first);
	temp += second;
	return temp;
}

BigNum operator-(const BigNum& first, const BigNum& second) {
// need BigNum::operator-=(BigNum&),BigNum::BigNum(BigNum&)
	BigNum temp(first);
	temp -= second;
	return temp;
}

BigNum operator*(const BigNum& first, const BigNum& second) {
// need BigNum::operator*=(BigNum&),BigNum::BigNum(BigNum&)
	BigNum temp(first);
	temp *= second;
	return temp;
}

BigNum operator/(const BigNum& first, const BigNum& second) {
// need BigNum::operator/=(BigNum&),BigNum::BigNum(BigNum&)
	BigNum temp(first);
	temp /= second;
	return temp;
}

BigNum operator%(const BigNum& first, const BigNum& second) {
// need BigNum::operator%=(BigNum&),BigNum::BigNum(BigNum&)
	BigNum temp(first);
	temp %= second;
	return temp;
}

BigNum BigNum::sqrt(bool isUpper) {
// need BigNum::clear(),BigNum::operator-(BigNum&),
//      BigNum::operator>(BigNum&),BigNum::div2(),
//      BigNum::operator+(BigNum&),
//      BigNum::operator*(BigNum&),
//      BigNum::operator=(BigNum&),

	BigNum lower;
	BigNum higher;
	BigNum temp;
	BigNum mul;

	higher.clear();
	higher.nDigit = (nDigit + 3) / 2;
	higher.digit[higher.nDigit - 1] = 1;

	while (higher - lower > 1) {
		temp = (lower + higher).div2();
		mul = temp * temp;
		if (!(mul > (*this)))
			lower = temp;
		else
			higher = temp;
	}
	if (isUpper) {
		if (lower * lower != (*this))
			lower += BigNum(1);
	}
	return (lower);
}

BigNum BigNum::pow(const int n) {
// need BigNum::operator*(BigNum&),
//      BigNum::operator=(BigNum&)

	BigNum temp(1);
	BigNum mul(*this);
	int i;

	for (i = 1; i <= n; i <<= 1) {
		if (i & n)
			temp *= mul;
		mul *= mul;
	}
	return temp;
}

BigNum& BigNum::operator=(const BigNum& second) {

	for (nDigit = 0; nDigit < second.nDigit; nDigit++)
		digit[nDigit] = second.digit[nDigit];
	return (*this);
}

BigNum& BigNum::operator+=(const BigNum& second) {
	int i;
	digit[nDigit] = 0;
	for (i = 0; i < nDigit || i < second.nDigit; i++) {
		if (i < second.nDigit)
			digit[i] += second.digit[i];

		if (i < nDigit)
			digit[i + 1] += digit[i] / PERDIGIT;
		else
			digit[i + 1] = digit[i] / PERDIGIT;

		digit[i] %= PERDIGIT;
	}
	nDigit = (digit[i] ? (i + 1) : (i));
	return (*this);
}

BigNum& BigNum::operator-=(const BigNum& second) {
	int i, j;
	for (i = 0; i < second.nDigit; i++) {
		if (digit[i] < second.digit[i]) {
			digit[i] += PERDIGIT;

			for (j = i + 1; !(digit[j]); j++)
				digit[j] += (PERDIGIT - 1);

			digit[j]--;
		}
		digit[i] -= second.digit[i];
	}
	for (i = nDigit - 1; !(digit[i]); i--)
		;
	nDigit = i + 1;
	return (*this);
}

BigNum& BigNum::operator*=(const BigNum& second) {
// need BigNum::clear(),BigNum::operator=(BigNum&)
	int i, j;
	BigNum temp;
	temp.clear();
	for (i = 0; i < nDigit; i++) {
		for (j = 0; j < second.nDigit; j++) {
			temp.digit[i + j] += digit[i] * second.digit[j];
			temp.digit[i + j + 1] += (temp.digit[i + j] / PERDIGIT);
			temp.digit[i + j] %= PERDIGIT;
		}
	}
	temp.nDigit = i + j;
	while (temp.digit[temp.nDigit - 1] == 0)
		temp.nDigit--;
	(*this) = temp;
	return *this;
}

BigNum& BigNum::operator/=(const BigNum& second) {
// need BigNum::clear(),BigNum::operator-(BigNum&),
//      BigNum::operator>(BigNum&),BigNum::div2(),
//      BigNum::operator+(BigNum&),
//      BigNum::operator*(BigNum&),
//      BigNum::operator=(BigNum&),

	BigNum lower;
	BigNum higher;
	BigNum temp;
	BigNum mul;

	higher.clear();
	higher.nDigit = nDigit - second.nDigit + 2;
	higher.digit[higher.nDigit - 1] = 1;

	if (second == 2)
		return (*this).div2();
	while (higher - lower > 1) {
		temp = (lower + higher).div2();
		mul = temp * second;
		if (!(mul > (*this)))
			lower = temp;
		else
			higher = temp;
	}
	(*this) = lower;
	return (*this);
}

BigNum& BigNum::operator%=(const BigNum& second) {
// need BigNum::clear(),BigNum::operator-(BigNum&),
//      BigNum::operator>(BigNum&),BigNum::div2(),
//      BigNum::operator+(BigNum&),
//      BigNum::operator*(BigNum&),
//      BigNum::operator=(BigNum&),
//      BigNum::operator-=(BigNum&),

	BigNum lower;
	BigNum higher;
	BigNum temp;
	BigNum mul;

	higher.clear();
	higher.nDigit = nDigit - second.nDigit + 2;
	higher.digit[higher.nDigit - 1] = 1;

	if (second == 2)
		return ((*this) = digit[0] % 2);

	while (higher - lower > 1) {
		temp = (lower + higher).div2();
		mul = temp * second;
		if (!(mul > (*this)))
			lower = temp;
		else
			higher = temp;
	}
	(*this) -= (lower * second);
	return (*this);
}

// Output Stream
ostream& operator<<(ostream& os, BigNum& bn) {
	int i, j;

	os << bn.digit[bn.nDigit - 1];
	for (i = bn.nDigit - 2; i >= 0; i--) {
		for (j = PERDIGIT / 10; j >= 1; j /= 10) {
			if (j > bn.digit[i])
				os << '0';
			else
				break;
		}
		if (bn.digit[i])
			os << bn.digit[i];
	}
	return os;
}

// Constructors
BigNum::BigNum() {
	nDigit = 1;
	digit[0] = 0;
}

BigNum::BigNum(const char* str) {

	int i, j, pow10;
	for (i = strlen(str), j = LOGDIGIT,nDigit = 0; i >= 0; i--) {
		if (j == LOGDIGIT) {
			j = 0;
			nDigit++;

			digit[nDigit - 1] = 0;
			pow10 = 1;
		}
		if (ISNUM(str[i])) {
			j++;
			digit[nDigit - 1] += pow10 * (str[i] - '0');
			pow10 *= 10;
		}
	}
}

BigNum::BigNum(const unsigned int num) {
	int n = num;

	nDigit = 0;

	do {
		nDigit++;
		digit[nDigit - 1] = n % PERDIGIT;
		n /= PERDIGIT;
	} while (n);
}

BigNum::BigNum(const BigNum& bn) {
	for (nDigit = 0; nDigit < bn.nDigit; nDigit++)
		digit[nDigit] = bn.digit[nDigit];
}
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const llu inf64 = ((llu) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 310
#define LIBN 12
// and 0 inserted between them
//1, 2, 3, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 22, 121, 212, 11211

int lib[][4] = {
		{ 22, 2, 2, 0 },		//2, 3, 4, 5, ...
		{ 121, 3, 1, 2 },	//3, 5, 7, 9, ...
		{ 212, 3, 2, 1 },	//3, 5, 7, 9, ...
		{ 11211, 5, 1, 2},
		{ 11, 2, 1, 0 }, //2, 3, 4, 5, ...
		{ 111, 3, 1, 1 }, //3, 5, 7, 9, ...
		{ 1111, 4, 1, 0 }, //4, 5, 6, 7, ...
		{ 11111, 5, 1, 1 }, //5, 7, 9, 11, ...
		{ 111111, 6, 1, 0 }, //6, 7, 8, 9, ...
		{ 1111111, 7, 1, 1 }, //7, 9, 11, 13, ...
		{ 11111111, 8, 1, 0 }, //8, 9, 10, 11, ...
		{ 111111111, 9, 1, 1 } //9, 11, 13, 15, ...
};

BigNum A, AQ;
BigNum B, BQ;
llu cnt = 0;
int maxDigit;
int minDigit;

void count(int d) {
	if (d == 1)
		return;

	char tmp[MAXN];
	char rev[MAXN];
	char out[MAXN];
	seta(tmp, 0);

	forn(i, LIBN) {
		// more than d digits
		if (lib[i][1] > d)
			continue;

		// even digits
		if (lib[i][1] % 2 && d % 2 == 0)
			continue;

		// need 0s
		// need 1s
		int need0 = (d - lib[i][1]) / 2;
		int need1 = (lib[i][1] / 2 - 1);
		int all = need0 + need1;

		// create tmp
		for (int j = 0; j < need0; j++)
			tmp[j] = '0';
		for (int j = need0; j < all; j++)
			tmp[j] = '1';
		tmp[need0 + need1] = '\0';

		//printf("%d %d %d %d %s\n", d, need0, need1, lib[i][0], tmp);
		out[0] = ('0' + lib[i][2]);
		out[d - 1] = ('0' + lib[i][2]);
		out[d] = '\0';
		if (d % 2)
			out[d / 2] = ((d - lib[i][1]) % 2) ? '0' : ('0' + lib[i][3]);

		do {
			strcpy(rev, tmp);
			reverse(rev, rev + all);

			// 1 + [tmp] + mid + [tmp_rev] + 1
			strncpy(out + 1, tmp, all);
			strncpy(out + (d + 1) / 2, rev, all);

			if (AQ <= BigNum(out) && BigNum(out) <= BQ){
				cnt++;
				//printf("[%d: %d] %s %s %s\n", d, lib[i][0], out, tmp, rev);
			}



		} while (next_permutation(tmp, tmp + all));

	}
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		cnt = 0;
		char Ain[MAXN];
		char Bin[MAXN];

		scanf("%s%s", Ain, Bin);

		A = BigNum(Ain);
		B = BigNum(Bin);
		AQ = A.sqrt(true);
		BQ = B.sqrt(false);

		maxDigit = BQ.nDigit;
		minDigit = AQ.nDigit;
		for (int i = minDigit; i <= maxDigit; i++) {
			count(i);
		}
		//cout << AQ << " " << BQ << " " << endl;
		//cout << minDigit << " " << maxDigit << " " << endl;
		if (AQ <= BigNum(1) && BigNum(1) <= BQ)
			cnt++;
		if (AQ <= BigNum(2) && BigNum(2) <= BQ)
			cnt++;
		if (AQ <= BigNum(3) && BigNum(3) <= BQ)
			cnt++;
		printf("Case #%d: %llu\n", casenum++, cnt);
	}
	return 0;
}

