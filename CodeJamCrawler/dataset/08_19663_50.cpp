#include <iostream>
#include <string>
#include <vector>
using namespace std;

double tomin(string hh_mm)
{
//	cout << hh_mm << " : " << (hh_mm[0] - '0')*600 + (hh_mm[1] - '0')*60 + (hh_mm[3] - '0')*10 + (hh_mm[4] - '0') << endl;
	return (hh_mm[0] - '0')*600 + (hh_mm[1] - '0')*60 + (hh_mm[3] - '0')*10 + (hh_mm[4] - '0');
}
bool isArrival(double d)
{
	return (int)d == (int)(d+0.6);
}

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
	{
		int t, na, nb;
		cin >> t >> na >> nb;
		vector<double> a(na+nb), b(na+nb);
		for (int j=0; j<na; ++j)
		{
			string stra, strb;
			cin >> stra >> strb;
			a[j] = tomin(stra) + 0.5;
			b[j] = tomin(strb) + t;
		}
		for (int j=0; j<nb; ++j)
		{
			string strb, stra;
			cin >> strb >> stra;
			b[na+j] = tomin(strb) + 0.5;
			a[na+j] = tomin(stra) + t;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int cura=0, curb=0, maxa=0, maxb=0;
		for (int j=0; j<na+nb; ++j)
		{
//			cout << "a["<<j<<"]: " << a[j] << endl;
			if (isArrival(a[j])) cura++;
			else if (--cura < maxa) maxa = cura;
		}
		for (int j=0; j<na+nb; ++j)
		{
//			cout << "b["<<j<<"]: " << b[j] << endl;
			if (isArrival(b[j])) curb++;
			else if (--curb < maxb) maxb = curb;
		}
		cout << "Case #" << i+1 << ": " << maxa*-1 << " " << maxb*-1 << endl;
	}
}
