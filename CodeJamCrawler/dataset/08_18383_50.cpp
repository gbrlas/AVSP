#include<stdio.h>
#include<set>
#include<string>
using namespace std;

int getit(void)
{
	set<string> s;
	char str[120];
	int ns, nq, res=0;

	scanf("%d\n", &ns);
	//printf("ns %d\n", ns);
	for (int i=0; i<ns; i++) {
		fgets(str, 120, stdin);
		//printf("s %s\n", str);
	}
	scanf("%d\n", &nq);
	//printf("nq %d\n", nq);
	for (int i=0; i<nq; i++) {
		fgets(str, 120, stdin);
		//printf("q %s\n", str);
		s.insert(string(str));
		if (s.size() == ns) {
			res++;
			s.clear();
			s.insert(string(str));
		}
	}
	return res;
}
int main(void)
{
	int ncase;

	scanf("%d\n", &ncase);
	for (int i=0; i<ncase; i++) {
		int res = getit();
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}
