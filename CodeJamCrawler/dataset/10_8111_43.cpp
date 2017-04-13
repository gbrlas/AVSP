#pragma once
#include <math.h>
#include <iostream>
using namespace std;


int main()
{
	FILE *inp = NULL, *outp = NULL;
	if (
		fopen_s(&inp, "A-large.in", "rb") ||
		fopen_s(&outp, "A-large.out", "wb")
	)
		return 1;

	int cnt = -1;
	fscanf_s(inp, "%d\n", &cnt);

	for (int i = 1; i <= cnt; ++i)
	{
		int N = -1, K = -1;
		fscanf_s(inp, "%d %d\n", &N, &K);
		fprintf(
			outp, "Case #%d: %s\r\n",
			i, !((K + 1) % int(pow(2.0, N))) ? "ON" : "OFF");
	}

	fclose(inp);
	fclose(outp);
	return 0;
}