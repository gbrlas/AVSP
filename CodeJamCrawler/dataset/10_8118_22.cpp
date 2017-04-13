#pragma once
#include <iostream>
using namespace std;


struct TMyPair
{
	int A;
	int B;
};


int main()
{
	FILE *inp = NULL, *outp = NULL;
	if (fopen_s(&inp, "input.txt", "rb") || fopen_s(&outp, "output.txt", "wb"))
		return 1;

	int cases = -1;
	fscanf_s(inp, "%d\n", &cases);

	for (int i = 1; i <= cases; ++i)
	{
		int wiresCnt = -1;
		fscanf_s(inp, "%d\n", &wiresCnt);

		TMyPair *elems = new TMyPair[wiresCnt];
		for (int j = 0; j < wiresCnt; ++j)
			fscanf_s(inp, "%d %d\n", &elems[j].A, &elems[j].B);

		int res = 0;
		for (int j = 0; j < wiresCnt; ++j)
			for (int k = 0; k < wiresCnt; ++k)
			{
				if (k == j) continue;
				if (
					(elems[j].A > elems[k].A && elems[j].B < elems[k].B) ||
					(elems[j].A < elems[k].A && elems[j].B > elems[k].B)
				)
					++res;
			}
		
		fprintf(outp, "Case #%d: %d\r\n", i, int(res / 2));
	}

	fclose(inp);
	fclose(outp);
	return 0;
}