#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

double f;
double R;
double t;
double r;
double g;

double pro;

double arch(double len, double radius)
{
	double alpha = asin(len/2/radius);
	double area  = radius * radius * alpha;
	area = area - sqrt(radius * radius - len * len / 4) * len / 2;
	return area; 
}

double funcA(double Ra, double x, double y, double len)
{
	double px = sqrt (Ra * Ra - (y + len) * (y + len));
	double py = sqrt (Ra * Ra - (x + len) * (x + len));
	double area = len * len;

	double stringlen = sqrt( (px - x - len) * (px - x - len) + (py - y - len) * (py - y - len));
	area = area - (x + len - px) * (y + len - py) * 0.5 + arch(stringlen, Ra);
	return area;

}

double funcB(double Ra, double x, double y, double len)
{
	double py1 = sqrt (Ra * Ra - x * x);
	double py2 = sqrt (Ra * Ra - (x + len) * (x + len));
	double area = (py1 + py2 - y - y) / 2 * len;

	double stringlen = sqrt( (py1 - py2) * (py1 - py2) + len * len);
	area = area  + arch(stringlen, Ra);
	return area;
}

double funcC(double Ra, double x, double y, double len)
{
	double px1 = sqrt (Ra * Ra - y * y);
	double px2 = sqrt (Ra * Ra - (y + len) * (y + len));
	double area = (px1 + px2 - x - x) / 2 * len;

	double stringlen = sqrt( (px1 - px2) * (px1 - px2) + len * len);
	area = area  + arch(stringlen, Ra);
	return area;
}

double funcD(double Ra, double x, double y, double len)
{
	double px = sqrt (Ra * Ra - y * y);
	double py = sqrt (Ra * Ra - x * x);
	double area = (px - x) * (py - y) / 2;

	double stringlen = sqrt( (px - x) * (px - x) + (py - y) * (py - y));
	area = area + arch(stringlen, Ra);
	return area;
}

void compute()
{
	double area = 0.00;

	double innerR = R - t - f;
	double innerL = g - f - f;
	double step   = g + r + r;
	double offset = r + f;
	
	double sq = innerL * innerL;

	if ( innerL <= 0.00) {
		pro = 1.00;
		return;
	}

	for (double x = 0.00; x <= innerR; x+= step) {
		for (double y = 0.00; y * y + x * x <= innerR * innerR; y+= step) {
			if ( (x + offset + innerL) * (x + offset + innerL) + (y + offset + innerL) * (y + offset + innerL) < innerR * innerR ) {
				area += sq;
			} else if ( (x + offset) * (x + offset) + (y + offset) * (y + offset) > innerR * innerR) {
				;
			} else {
				if ( (x + offset) * (x + offset) + (y + offset + innerL) * (y + offset + innerL) < innerR * innerR) {
					if ((x + offset + innerL) * (x + offset + innerL) + (y + offset) * (y + offset) < innerR * innerR) {
						area += funcA(innerR, x + offset, y + offset, innerL);
					} else {
						area += funcC(innerR, x + offset, y + offset, innerL);
					}
				} else {
					if ((x + offset + innerL) * (x + offset + innerL) + (y + offset) * (y + offset) < innerR * innerR) {
						area += funcB(innerR, x + offset, y + offset, innerL);
					} else {
						area += funcD(innerR, x + offset, y + offset, innerL);
					}
				}
			}
		}
	}
	pro = 1.00 - area * 4 / R / R / 3.1415926;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>f>>R>>t>>r>>g;
		compute();
		cout<<"Case #"<<i<<": "<<pro<<endl;
	}
	return 0;
}