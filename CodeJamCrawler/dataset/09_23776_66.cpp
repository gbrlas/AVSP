#include <cstdio>
#include <cstdlib>
#include <cstring>

const int max_msize = 100;
int height, width;

const int dx[] = {0,-1,1,0};
const int dy[] = {-1,0,0,1};
const char way[] = {0x01, 0x02, 0x04, 0x08};

int map[max_msize][max_msize];
char flows[max_msize][max_msize];
char labels[max_msize][max_msize];

void expl(int h, int w, char label)
{
	labels[h][w] = label;
	for (int i=0;i<4;++i)
	{
		if ((flows[h][w] & way[i]) == 0)
			continue;
		int tx=w+dx[i];
		int ty=h+dy[i];
		if (tx>=0 && tx<width
			&& ty>=0 && ty<height
			&& labels[ty][tx] == 0)
			expl(ty, tx, label);
	}
}

void sim()
{
	memset(flows, 0, height*max_msize);
	for (int h=0;h<height;++h)
	{
		for (int w=0;w<width;++w)
		{
			int flow = -1;
			int minaltitudes = 10000;
			for (int i=0;i<4;++i)
			{
				int tx = w+dx[i];
				int ty = h+dy[i];
				if (tx>=0 && tx<width
					&& ty>=0 && ty<height
					&& map[ty][tx] < map[h][w]
					&& map[ty][tx] < minaltitudes)
				{
					flow = i;
					minaltitudes = map[ty][tx];
				}
			}
			if (flow==-1) continue;
			flows[h][w] |= way[flow];
			flows[h+dy[flow]][w+dx[flow]] |= way[3-flow];
		}
	}

/*
	// print flows
	printf("\n");
	for (int h=0;h<height;++h)
	{
		for (int w=0;w<width;++w)
		{
			printf("%d%d%d%d ", flows[h][w]&way[0], flows[h][w]&way[1], flows[h][w]&way[2], flows[h][w]&way[3]);
		}
		printf("\n");
	}
	printf("\n");
*/
	
	char label = 'a';
	memset(labels, 0, height*max_msize);
	for (int h=0;h<height;++h)
		for (int w=0;w<width;++w)
			if (labels[h][w] == 0)
				expl(h, w, label++);
}

void print_ans(int caseno)
{
	printf("Case #%d:\n", caseno);
	for (int h=0;h<height;++h)
	{
		for (int w=0;w<width-1;++w)
			printf("%c ", labels[h][w]);
		printf("%c\n", labels[h][width-1]);
	}
}

int main()
{
	int map_num;
	scanf("%d", &map_num);
	
	for (int caseno=1;caseno<=map_num;++caseno)
	{
		scanf("%d%d", &height, &width);
		for (int h=0;h<height;++h)
			for (int w=0;w<width;++w)
				scanf("%d", &map[h][w]);
		sim();
		print_ans(caseno);
	}
}
