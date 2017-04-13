#include "libfns.h"

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int i=1; i<=cases;++i)
	{
    bool found = false;
    bool empties = false;
    char board[16];
    for(int j=0; j<4; ++j)
    {
      memcpy(&(board[j*4]),t.getToken(),4);
    }

    //check rows
    for(int row = 0; row < 4 && !found; ++row)
    {
      int xcount=0;
      int ocount=0;
      for(int col = 0; col < 4; ++col)
      {
        switch(board[row*4+col])
        {
        case 'X':
          ++xcount;
          break;
        case 'O':
          ++ocount;
          break;
        case 'T':
          ++xcount;
          ++ocount;
          break;
        case '.':
          empties = true;
        default:
          col = 4;
          break;
        }
      }
      if(xcount == 4)
      {
        fprintf(outF,"Case #%d: X won\n",i);
        row=4;
        found = true;
      }
      else if(ocount == 4)
      {
        fprintf(outF,"Case #%d: O won\n",i);
        row=4;
        found = true;
      }
    }

    //check cols
    for(int row = 0; row < 4 && !found; ++row)
    {
      int xcount=0;
      int ocount=0;
      for(int col = 0; col < 4; ++col)
      {
        switch(board[col*4+row])
        {
        case 'X':
          ++xcount;
          break;
        case 'O':
          ++ocount;
          break;
        case 'T':
          ++xcount;
          ++ocount;
          break;
        case '.':
          empties = true;
        default:
          col = 4;
          break;
        }
      }
      if(xcount == 4)
      {
        fprintf(outF,"Case #%d: X won\n",i);
        row=4;
        found = true;
      }
      else if(ocount == 4)
      {
        fprintf(outF,"Case #%d: O won\n",i);
        row=4;
        found = true;
      }
    }

    //check diag row=col
    if(!found)
    {
      int xcount=0;
      int ocount=0;
      for(int col = 0; col < 4; ++col)
      {
        switch(board[col*4+col])
        {
        case 'X':
          ++xcount;
          break;
        case 'O':
          ++ocount;
          break;
        case 'T':
          ++xcount;
          ++ocount;
          break;
        case '.':
          empties = true;
        default:
          col = 4;
          break;
        }
      }
      if(xcount == 4)
      {
        fprintf(outF,"Case #%d: X won\n",i);
        found = true;
      }
      else if(ocount == 4)
      {
        fprintf(outF,"Case #%d: O won\n",i);
        found = true;
      }
    }

    //check diag row!=col
    if(!found)
    {
      int xcount=0;
      int ocount=0;
      for(int col = 0; col < 4; ++col)
      {
        switch(board[col*4+(3-col)])
        {
        case 'X':
          ++xcount;
          break;
        case 'O':
          ++ocount;
          break;
        case 'T':
          ++xcount;
          ++ocount;
          break;
        case '.':
          empties = true;
        default:
          col = 4;
          break;
        }
      }
      if(xcount == 4)
      {
        fprintf(outF,"Case #%d: X won\n",i);
        found = true;
      }
      else if(ocount == 4)
      {
        fprintf(outF,"Case #%d: O won\n",i);
        found = true;
      }
    }

    if(!found)
    {
      if(!empties)
      {
        fprintf(outF,"Case #%d: Draw\n",i);
      }
      else
      {
        fprintf(outF,"Case #%d: Game has not completed\n",i);
      }
    }

	}
	fclose(outF);
	fclose(inF);
	return 0;
}

