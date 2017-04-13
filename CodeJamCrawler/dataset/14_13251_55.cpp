#include <cstdio>
#include <vector>
using namespace std;


int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 0; casenum < testcase; ++casenum) {

		vector<bool> p;

		p.resize(16, true);

		for(int t = 0; t < 2; ++t) {

			int row;

			scanf("%d", &row);
			row -= 1;

			for(int i = 0; i < 4; ++i) {
				for(int j = 0; j < 4; ++j) {

					int n;

					scanf("%d", &n);
					n -= 1;
					if(i != row)
						p[n] = false;
				}
			}
		}

		int ans = -1, count = 0;

		for(int i = 0; i < 16; ++i) {
			if(p[i]) {
				ans = i;
				count += 1;
			}
		}

		printf("Case #%d: ", casenum + 1);
		if(count == 1)
			printf("%d\n", ans + 1);
		else if(count == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}

	return 0;
}