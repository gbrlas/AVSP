#include <iostream>
#include <string>

#define SMALL
#ifdef SMALL
  #define FILE_IN "A-small-attempt0.in"
  #define FILE_OUT "A-small.out"
#else
  #define FILE_IN "A-large.in"
  #define FILE_OUT "A-large.out"
#endif

#define BOARD_SIZE 4

using namespace std;

class Game
{
  char board[BOARD_SIZE][BOARD_SIZE];
public:
  char winner;
  bool isEmptySquare;

  void Init()
  { 
	isEmptySquare = false;
    for (int i = 0; i < BOARD_SIZE; i++)
      for (int j = 0; j < BOARD_SIZE; j++)
	  {
        cin >> board[i][j];
		if (board[i][j] == '.')
		  isEmptySquare = true;
	  }
    winner = -1;
  };

  bool searchWinner( int x, int y, int dx, int dy )
  {
    char first;

	if (board[x][y] == '.')
	  return false;
	if (board[x][y] == 'T')
	  first = board[x + dx][y + dy];
	else 
	  first = board[x][y];
    for (int i = 1; i < BOARD_SIZE; i++)
	  if (first != board[x + i * dx][y + i * dy] && board[x + i * dx][y + i * dy] != 'T')
	    return false;
	winner = first;
    cout << first << " won" << endl;
	return true;
  };
}; 

void main()
{
  int T;
  Game game;

  freopen(FILE_IN, "r" , stdin);
  freopen(FILE_OUT , "w" , stdout);
  cin >> T;
  for (int caseNumber = 1; caseNumber <= T; caseNumber++)
  {
	  cout << "Case #" << caseNumber << ": ";
	game.Init();
	if (game.searchWinner(0, 0, 1, 1))
	  continue;
	if (game.searchWinner(0, 3, 1, -1))
	  continue;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
	  if (game.searchWinner(i, 0, 0, 1))
	    break;
	  if (game.searchWinner(0, i, 1, 0))
	    break;
	}
	if (game.winner != -1)
	  continue;
	if (game.isEmptySquare)
	  cout << "Game has not completed" << endl;
	else
	  cout << "Draw" << endl;
  }
}
