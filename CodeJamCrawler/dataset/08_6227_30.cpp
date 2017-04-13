#include <iostream>
#include <limits.h>

using namespace std;

struct result_t {
	int a;
	int b;
};

static const int all_minutes = 24 * 60;

result_t do_it()
{
	result_t retval;
	retval.a = 0;
	retval.b = 0;
	int ta = 0; //turn around time
	int na = 0;
	int nb = 0;
	cin >> ta;
	cin >> na;
	cin >> nb;
	
	int st_a [all_minutes]; // station A
	int st_b [all_minutes]; // station B

	memset (st_a, 0, sizeof(int)*all_minutes);
	memset (st_b, 0, sizeof(int)*all_minutes);

	int hh = 0;
	int mm = 0;
	int t_idx = 0;
	int sum = 0;
	int min = INT_MAX;

	for (int i = 0; i < na; i++) {
		scanf("%d:%d", &hh, &mm);
		t_idx = hh * 60 + mm;
		st_a[t_idx] --;
		//printf ("s: %2d:%2d \t", hh, mm);
		scanf("%d:%d", &hh, &mm);
		t_idx = hh * 60 + mm;
		st_b[t_idx + ta] ++;
		//printf ("e: %2d:%2d\n", hh, mm);
	}

	for (int i = 0; i < nb; i++) {
		scanf("%d:%d", &hh, &mm);
		t_idx = hh * 60 + mm;
		//printf ("s: %2d:%2d \t", hh, mm);
		st_b[t_idx] --;

		scanf("%d:%d", &hh, &mm);
		t_idx = hh * 60 + mm;
		st_a[t_idx + ta] ++;
		//printf ("e: %2d:%2d\n", hh, mm);
	}

	sum = 0;
	min = INT_MAX;
	for (int i = 0; i < all_minutes; i++) 
	{
		if (st_a[i] == 0) {
			continue;
		}
		sum += st_a[i];
		if (sum < min) {
			min = sum;
		}
	}
	if (min < 0) {
		retval.a = -min;
	}

	sum = 0;
	min = INT_MAX;
	for (int i = 0; i < all_minutes; i++) 
	{
		if (st_b[i] == 0) {
			continue;
		}
		sum += st_b[i];
		if (sum < min) {
			min = sum;
		}
	}
	if (min < 0) {
		retval.b = -min;
	}

	//printf ("ta: %d na: %d nb: %d\n", ta, na, nb);

	return retval;
}

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		result_t res = do_it();
		printf ("Case #%d: %d %d\n", i+1, res.a, res.b);
	}
}
