#include "libfns.h"

char evaluateboard(char board[], int N, int K);
bool findWinner(char board[], int N, int K, char target);

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());
	char* rowdata;

	for(int i=1; i<=cases;++i)
	{
		int N = atoi(t.getToken());
		int K = atoi(t.getToken());

		char* board = new char[N*N];

		for(int row=0; row<N; ++row)
		{
			rowdata = t.getToken();
			int col = N-1;
			int boardcol = N-1;
			while(col >= 0)
			{
				if(rowdata[col] != '.')
				{
					board[row*N + boardcol] = rowdata[col];
					--boardcol;
				}
				--col;
			}
			while(boardcol >= 0)
			{
				board[row*N + boardcol] = '.';
				--boardcol;
			}
		}
		char x = evaluateboard(board,N,K);
		switch(x)
		{
		case 'B':
			fprintf(outF,"Case #%d: %s\n",i,"Blue");
			break;
		case 'R':
			fprintf(outF,"Case #%d: %s\n",i,"Red");
			break;
		case 'P':
			fprintf(outF,"Case #%d: %s\n",i,"Both");
			break;
		case '\0':
			fprintf(outF,"Case #%d: %s\n",i,"Neither");
			break;
		default:
			fprintf(stderr,"Case #%d: %s\n",i,"Problem!");
			break;
		}
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

char evaluateboard(char board[], int N, int K)
{
	bool B = findWinner(board,N,K,'B');
	bool R = findWinner(board,N,K,'R');
	if(B && R)
		return 'P';
	if(B)
		return 'B';
	if(R)
		return 'R';
	return '\0';
}

bool findWinner( char board[], int N, int K, char target )
{
	// horizontal search
	for(int row = 0; row<N; ++row)
	{
		for(int col=0; col<=(N-K); ++col)
		{
			if(board[row*N + col] == target)
			{
				bool found = true;
				for(int looking = col+1; looking<col+K; ++looking)
				{
					if(board[row*N + looking] != target)
					{
						found = false;
					}
				}
				if(found)
					return true;
			}
		}
	}
	// vertical search
	for(int col = 0; col<N; ++col)
	{
		for(int row=0; row<=(N-K); ++row)
		{
			if(board[row*N + col] == target)
			{
				bool found = true;
				for(int looking = row+1; looking<row+K; ++looking)
				{
					if(board[looking*N + col] != target)
					{
						found = false;
					}
				}
				if(found)
					return true;
			}
		}
	}

	// diagonal search bot-left -top right
	for(int col = 0; col<=(N-K); ++col)
	{
		for(int row=N-1; row>=K-1; --row)
		{
			if(board[row*N + col] == target)
			{
				bool found = true;
				for(int looking = 1; looking<K; ++looking)
				{
					if(board[(row-looking)*N + (col+looking)] != target)
					{
						found = false;
					}
				}
				if(found)
					return true;
			}
		}
	}

	// bot-right top-left
	for(int col = 0; col<=(N-K); ++col)
	{
		for(int row=0; row<=(N-K); ++row)
		{
			if(board[row*N + col] == target)
			{
				bool found = true;
				for(int looking = 1; looking<K; ++looking)
				{
					if(board[(row+looking)*N + (col+looking)] != target)
					{
						found = false;
					}
				}
				if(found)
					return true;
			}
		}
	}

	return false;
}
