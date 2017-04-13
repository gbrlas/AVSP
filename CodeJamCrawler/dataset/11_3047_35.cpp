#include <stdio.h>
#include <math.h>

const double EPS = 0.0000001;

bool is_real (int n, int min, double t,
			  int _vend[100][2])
{
	int vend[100][2] = {{}};
	for (int i = 0; i < n; ++i)
	{
		vend[i][0] = _vend[i][0];
		vend[i][1] = _vend[i][1];
	}
	double cur_pos = static_cast<double> (vend[0][1]) - t;
	--vend[0][0];
	for (int i = 0; i < n; ++i)
		while (vend[i][0] > 0)
		{
			--vend[i][0];
			if (static_cast<double> (vend[i][1]) - t - cur_pos >= static_cast<double> (min))
				cur_pos = static_cast<double> (vend[i][1]) - t;
			else if (static_cast<double> (vend[i][1]) - cur_pos >= static_cast<double> (min) &&
				     static_cast<double> (vend[i][1]) - cur_pos - static_cast<double> (min) <= t)
				cur_pos += static_cast<double> (min);
			else
				return false;
		}

	return true;
}

double find_ans (int all_vendors, int min_dist,
				 int vend[100][2])
{
	double left = 0.00,
		   right = 1000000000.00;
	while (right - left >= EPS)
	{
		double now = (left + right) / 2;
		
		if (is_real (all_vendors, min_dist, now, vend))
			right = now;
		else
			left = now;
	}

	return left;
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	int all_query = 0;
	scanf ("%d", &all_query);
	for (int query = 0; query < all_query; ++query)
	{
		int all_vendors = 0,
			min_dist = 0;
		scanf ("%d %d", &all_vendors, &min_dist);
		int vendors[100][2] = {{}};
		for (int i = 0; i < all_vendors; ++i)
			scanf ("%d %d", &vendors[i][1], &vendors[i][0]);

		printf ("Case #%d: %lf\n", query + 1, find_ans (all_vendors, min_dist, vendors) / 2);
	}

	return 0;
}