#include "libfns.h"


int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());
	bool board[100][100];

	for(int i=1; i<=cases;++i)
	{
		for(int x=0;x<100;++x)
		{
			for(int y=0;y<100;++y)
			{
				board[x][y] = false;
			}
		}
		int rectangles = atoi(t.getToken());
		int x1,y1,x2,y2;
		bool found = false;
		for(int r = 0; r<rectangles; ++r)
		{
			x1 = atoi(t.getToken())-1;
			y1 = atoi(t.getToken())-1;
			x2 = atoi(t.getToken())-1;
			y2 = atoi(t.getToken())-1;
			for(int x=x1;x<=x2;++x)
			{
				for(int y=y1;y<=y2;++y)
				{
					board[x][y] = true;
					found=true;
				}
			}
		}

		int count=0;
		while(found)
		{
			found = false;
			++count;
			for(int y=99; y>=0; --y)
			{
				for(int x=99; x>=0; --x)
				{
					bool n,w;
					if(y>0)
						n = board[x][y-1];
					else
						n = false;
					
					if(x > 0)
						w = board[x-1][y];
					else
						w = false;

					if(!n && !w)
						board[x][y] = false;
					else if(n && w)
					{
						board[x][y] = true;
						found=true;
					}
					else
					{
						if(board[x][y] == true)
							found = true;
					}

				}
			}
		}


		fprintf(outF,"Case #%d: %d\n",i,count);
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

