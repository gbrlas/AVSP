#include <cstdio>

struct stat
{
	int x;
	int o;
	int t;
};


void initStats(stat *st, int size)
{
	for(int i=0; i<size; i++)
	{
		st[i].x = st[i].o = st[i].t = 0;
	}
};

void changeStat(stat &st, char c)
{
	switch(c)
	{
	case 'X':
		st.x++;
		break;
	case 'O':
		st.o++;
		break;
	case 'T':
		st.t++;
		break;
	}
}

const int XWIN = 1;
const int OWIN = 2;
const int DRAW = 3;
const int NONE = 4;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	char ch;

	scanf("%d\n", &T);

	stat rows[4];
	stat cols[4];
	stat dgnl[2];

	for(int t = 1; t <= T; t++)
	{
		initStats(rows, 4);
		initStats(cols, 4);
		initStats(dgnl, 2);


		int emptyCells = 0;
		for(int r=0; r<4; r++)
		{
			for(int c = 0; c < 4; c++)
			{
				scanf("%c", &ch);

				if(ch == '.')
					emptyCells++;

				changeStat(rows[r], ch);
				changeStat(cols[c], ch);
				
				if(c == r)
					changeStat(dgnl[0], ch);
				else if(c + r == 3)
					changeStat(dgnl[1], ch);

				//printf("%c", ch);
			}
			scanf("\n");
			//printf("\n");
		}

		int ans = 0;
		for(int i=0; i<4; i++)
		{
			if(rows[i].x + rows[i].t == 4)
				ans = XWIN;
			else if(rows[i].o + rows[i].t == 4)
				ans = OWIN;
			else if(cols[i].x + cols[i].t == 4)
				ans = XWIN;
			else if (cols[i].o + cols[i].t == 4)
				ans = OWIN;

			if(ans)
				break;	
		}

		if(!ans)
		{
			for(int i=0; i<2; i++)
			{
				if(dgnl[i].x + dgnl[i].t == 4)
					ans = XWIN;
				else if(dgnl[i].o + dgnl[i].t == 4)
					ans = OWIN;
				if(ans)
					break;
			}
		}

		if(!ans && emptyCells == 0)
			ans = DRAW;

		switch(ans)
		{
		case XWIN:
			printf("Case #%d: X won\n", t);
			break;
		case OWIN:
			printf("Case #%d: O won\n", t);
			break;
		case DRAW:
			printf("Case #%d: Draw\n", t);
			break;
		default:
			printf("Case #%d: Game has not completed\n", t);
		}

		//printf("\n");
	}

	return 0;
}