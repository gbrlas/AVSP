using System;

class TicTac
{
  const Byte size = 4;
    const char X = 'X';
    const char O = 'O';
    const char T = 'T';
    const char dot = '.';

  static void Main(string[] args)
  {
    int dotCount;
    UInt16 i;
    string result;
    bool winnerFound;
    int caseNum;

    UInt16 gameCount = UInt16.Parse(Console.ReadLine());

    for (i = 0; i < gameCount; i++)
    {
      var game = ReadGame();
      winnerFound = false;
      dotCount = 0;
      caseNum = i + 1;

      //проверка строк
      for (Byte row = 0; row < size; row++)
      {
        winnerFound = CheckCells(game[row].ToCharArray(), ref dotCount, caseNum);
        if(winnerFound) break;
      }
      if (winnerFound)
        continue;

      //проверка столбцов
      for (int col = 0; col < size; col++)
      {
        var column = new char[size];
        for (int row = 0; row < size; row++)
        {
          column[row] = game[row][col];
        }
        winnerFound = CheckCells(column, ref dotCount, caseNum);
        if (winnerFound)
          break;
      }
      if (winnerFound)
        continue;

      //проверка диагоналей
      var diag1 = new char[size] { game[0][0], game[1][1], game[2][2], game[3][3]};
      if (CheckCells(diag1, ref dotCount, caseNum))
        continue;
      var diag2 = new char[size] { game[0][3], game[1][2], game[2][1], game[3][0] };
      if (CheckCells(diag2, ref dotCount, caseNum))
        continue;
      
      if (dotCount > 0)
        result = "Game has not completed";
      else
        result = "Draw";
      Console.WriteLine("Case #{0}: {1}", caseNum, result);
    }
  }

  static string[] ReadGame()
  {
    var game = new string[size];
    for (Byte row = 0; row < size; row++)
    {
      game[row] = Console.ReadLine();
    }
    Console.ReadLine();
    return game;
  }

  static bool CheckCells(char[] cells, ref int dots, int gameNum)
  {
    Byte x = 0;
    Byte o = 0;
    bool t = false;
    char cell;
    for(int i=0; i < size; i++)
    {
      cell = cells[i];
      if(cell == X) x++;
      if(cell == O) o++;
      if(cell == T)  t = true;
      if (cell == dot) dots++;
    }
    if(t)
    {
      x++;
      o++;
    }
    if (x == size)
    {
      Console.WriteLine("Case #{0}: X won", gameNum);
      return true;
    }
    if (o == size)
    {
      Console.WriteLine("Case #{0}: O won", gameNum);
      return true;
    }
    return false;
  }
}