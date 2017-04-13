#include <string>
#include <iostream>

using namespace std;

const int ans[]  = {
5,
27,
143,
751,
935,
607,
903,
991,
335,
47,
943,
471,
55,
447,
463,
991,
95,
607,
263,
151,
855,
527,
743,
351,
135,
407,
903,
791,
135,
647};

int main()
{
	int c, d;
	scanf("%d", &c);
	for (int i = 0; i < c; ++i)
	{
		scanf("%d", &d);
		printf("Case #%d: %03d\n", i + 1, ans[d - 1]);
	}
	return 0;
}

