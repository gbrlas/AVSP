#include <stdio.h>
#include <string.h>

char map[20];

char map2[20];

int masks[16] =
{
	0x0001, 0x0002, 0x0004, 0x0008,
	0x0010, 0x0020, 0x0040, 0x0080,
	0x0100, 0x0200, 0x0400, 0x0800,
	0x1000, 0x2000, 0x4000, 0x8000
};

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int R, C;
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)
			scanf("%s", map + i*C);

		int max;

		if (R*C == 16)
			max = 65536;
		else if (R*C == 12)
			max = 4096;
		else
			max = 512;

		int res = 0;

		for (int u = 0; u != max; u++)
		{
			memset(map2, 0, 20);

			for (int y = 0; y < R; y++)
			{
				for (int x = 0; x < C; x++)
				{
					int x2 = x;
					int y2 = y;
					int ind = y*C + x;
					switch (map[ind])
					{
					case '-':
						if (u & masks[ind])
							x2 = (x + C + 1) % C;
						else
							x2 = (x + C - 1) % C;
						break;
					case '|':
						if (u & masks[ind])
							y2 = (y + R + 1) % R;
						else
							y2 = (y + R - 1) % R;
						break;
					case '/':
						if (u & masks[ind])
						{
							x2 = (x + C + 1) % C;
							y2 = (y + R - 1) % R;
						}
						else
						{
							x2 = (x + C - 1) % C;
							y2 = (y + R + 1) % R;
						}
						break;
					case '\\':
						if (u & masks[ind])
						{
							x2 = (x + C + 1) % C;
							y2 = (y + R + 1) % R;
						}
						else
						{
							x2 = (x + C - 1) % C;
							y2 = (y + R - 1) % R;
						}
						break;
					}

					map2[y2*C + x2]++;
				}
			}

			int ok = 1;
			for (int i = 0; i < R*C; i++)
			{				
				if (map2[i] >= 2)
					ok = 0;
			}
			res += ok;
		}
		printf("Case #%d: %d\n", tst, res);
	}

	return 0;
}
