#include <stdio.h>

#define NMAX 110

int t;
int n, m;

int map[NMAX][NMAX];

int t1, t2;
int data[NMAX][NMAX][2];

int ans[NMAX][NMAX];

int plus1[4] = {-1, 0, 0, 1}, plus2[4] = {0, -1, 1, 0};

void proc(int x, int y)
{
	int i;
	int nx, ny;
	int flag;
	int min;

	min = 99999;
	flag = -1;

	for(i = 0; i < 4; i++)
	{
		nx = x + plus1[i];
		ny = y + plus2[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if(map[x][y] <= map[nx][ny])
			continue;
		if(map[nx][ny] < min)
		{
			min = map[nx][ny];
			flag = i;
		}
	}

	if(flag == -1)
	{
		data[t1][t2][0] = x;
		data[t1][t2][1] = y;
		return;
	}

	nx = x + plus1[flag];
	ny = y + plus2[flag];

	proc(nx, ny);
}

int find(int x, int y)
{
	int i, j;
	for(i = 0; i <= x; i ++)
	{
		for(j = 0; j < m; j ++)
		{
			if(i == x && j >= y)
				break;
			if(data[i][j][0] == data[x][y][0] && data[i][j][1] == data[x][y][1])
			{
				return ans[i][j];
			}
		}
	}
	return -1;
}

int main()
{
	int i, j, k, tt;
	int temp;
	int count;

	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in, "%d", &t);

	for(tt = 0; tt < t; tt ++)
	{
		count = 0;
		fscanf(in, "%d%d", &n, &m);
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				fscanf(in, "%d", &map[i][j]);
			}
		}

		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				t1 = i;
				t2 = j;
				proc(i, j);
			}
		}

		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				temp = find(i, j);
				if(temp == -1)
				{
					ans[i][j] = count;
					count ++;
				}
				else
				{
					ans[i][j] = temp;
				}
			}
		}
		fprintf(out, "Case #%d:\n", tt+1);
		for(i = 0; i < n ; i++)
		{
			for(j = 0; j < m; j ++)
			{
				fprintf(out, "%c ", ans[i][j] + 'a');
			}
			fprintf(out, "\n");
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
