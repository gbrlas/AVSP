#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define SZ(a) (int)(a).size()
#define For(i, a, b) for(int i=a, _b=b; i<_b; ++i)
#define ForD(i, b, a) for(int i=b-1, _a=a; i>=_a; --i)
#define Fill(a, b) memset(a, b, sizeof(a))
#define sqr(a) (a)*(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> matr;

typedef ll type;

ll  gcd(ll  a, ll  b) { return b ? gcd(b, a%b) : a; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

class Frac
{
public:
	type ch,  zn;
	Frac(type _ch, type _zn=1) {
		ch = _ch, zn = _zn;

		if (zn < 0) ch=-ch, zn=-zn;
		type g = gcd(ch, zn);
		if (g != 0) ch/=g, zn/=g;
	}
	bool operator < (const Frac f) {
		return ch*f.zn < zn*f.ch;
	}
	bool operator != (const Frac f) {
		return ch*f.zn != zn*f.ch;
	}
	bool operator == (const Frac f) {
		return ch*f.zn == zn*f.ch;
	}

	Frac operator + (const Frac& f) {
		return Frac(ch*f.zn+zn*f.ch, zn*f.zn);
	}
	Frac operator - (const Frac& f) {
		return Frac(ch*f.zn-zn*f.ch, zn*f.zn);
	}
	Frac operator - () {
		return Frac(-ch, zn);
	}
	Frac operator * (const Frac& f) {
		type g1 = gcd(ch, f.zn);
		type g2 = gcd(zn, f.ch);
		return Frac(ch/g1*f.ch/g2, zn/g2*f.zn/g1);
	}
	Frac operator / (const Frac& f) {
		type g1 = gcd(ch, f.ch);
		type g2 = gcd(zn, f.zn);
		return Frac(ch/g1*f.zn/g2, zn/g2*f.ch/g1);
	}

	Frac operator * (const type& l) {
		type g = gcd(l, zn);
		return Frac(l/g*ch, zn/g);
	}
	Frac operator / (const type& l) {
		type g = gcd(l, ch);
		return Frac(ch/g, l/g*zn);
	}
};

Frac abs(Frac f) { if (f.ch<0) f.ch=-f.ch; return f; }
double sqrt(Frac f) { return sqrt((double)f.ch/(double)f.zn); }
bool eq(Frac f1, Frac f2) {
	return f1==f2;
}
bool pos(Frac f1) {
	return f1.ch>0;
}
bool neg(Frac f1) {
	return f1.ch<0;
}

bool eq(ll t1, ll t2) {
	return t1==t2;
}
bool eq(int t1, int t2) {
	return t1==t2;
}
bool eq(double t1, double t2) {
	return fabs(t1-t2)<1e-9;
}

bool pos(ll t) {
	return t>0;
}
bool pos(int t) {
	return t>0;
}
bool pos(double t) {
	return t>1e-9;
}

bool neg(ll t) {
	return t<0;
}
bool neg(int t) {
	return t<0;
}
bool neg(double t) {
	return t<-1e-9;
}

template
<typename T>
int sign(T val) {
	if (eq(val, T(0))) return 0;
	if (pos(val)) return 1;
	return -1;
}

#endif