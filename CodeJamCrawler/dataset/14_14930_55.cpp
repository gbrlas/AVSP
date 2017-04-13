#include <fstream>
#include <cstdio>

using namespace std;

FILE * output;
ifstream input;

double C, F, X;

void singleCase(int CaseNum)
{
	input >> C >> F >> X;
	double v = 2;
	double tot_T = 0;
	double t1 = X / v;
	double t2 = X / (v+F) + C / v;
	while (t2<t1)
	{
		tot_T += C/v;
		v += F;
		t1 = X / v;
		t2 = C / v + X / (v+F);
	}
	tot_T += t1;
	fprintf(output, "Case #%d: %.7lf\n", CaseNum, tot_T);
}

int main()
{
	input.open("b-small-attempt0.in");
	output = fopen("cookie.out","w");

	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i+1);

	fclose(output);
}