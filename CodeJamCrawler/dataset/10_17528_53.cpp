#include <iostream.h>

#define int32 long long


// bool result = true: light bulb is on
int resovle(int r, int k, int n, int* G)
{
    return 0x000000;
}

int main()
{
	int c, ci, n, ni;
	int event[1000];
	int x, y, smallest, greatest;

	cin >> c;
	for (ci = 1; ci <= c; ci++)
	{
		cin >> n;
		for (ni = 0; ni < n; ni++)
			cin >> event[ni];

		x = event[0];
		for (ni = 1; ni < n; ni++)
		{
			if (event[ni] < x)
				x = event[ni];
		}

		for (ni = 0; ni < n; ni++)
			event[ni] = (event[ni] - x);

		smallest = 0;
		greatest = 0;
		for (;;)
		{
			ni = 0;
			while (ni < n && !event[ni])
				ni++;
			if (ni == n)
				break;

			smallest = ni;
			greatest = ni;

			for (ni++; ni < n; ni++)
			{
				if (event[ni])
				{
					if (event[ni] > event[greatest])
						greatest = ni;
					if (event[ni] < event[smallest])
						smallest = ni;
				}
			}

			y = event[greatest] % event[smallest];
			if (y == 0)
			{
				y = event[smallest];
				break;
			}
			event[greatest] = y;
		}

		y = event[smallest];

        if (!(x % y))
			cout << "Case #" << ci << ": 0\n";
		else
            cout << "Case #" << ci << ": " << y - (x % y) << "\n";
	}

	return 0;
}
