using System;

class Program
{
  static void Main(string[] args)
  {
    var sep = new char[]{' '};
    var caseNum = Byte.Parse(Console.ReadLine());

    for(Byte num = 1; num <= caseNum; num++)
    {
      var nm = Console.ReadLine().Split(sep);
      var N = Byte.Parse(nm[0]);
      var M = Byte.Parse(nm[1]);
      var a = new Byte[N, M];
      
      for (Byte i = 0; i < N; i++)
      {
        var nums = Console.ReadLine().Split(sep);
        for (Byte j = 0; j < M; j++)
        {
          a[i, j] = Byte.Parse(nums[j]);
        }
      }

      if ((N == 1) || (M == 1))
      {
        Console.WriteLine("Case #{0}: YES", num);
        continue;
      }

      CheckLawn(a, num);      
    }
  }

  static void CheckLawn(Byte[,] cells, Byte testNum)
  {
    var rows = cells.GetLength(0);
    var cols = cells.GetLength(1);
    for (Byte row = 0; row < rows; row++)
    {
      for (Byte col = 0; col < cols; col++)
      {
        if (CheckFail(cells, row, col, testNum))
        {
          return;
        }
      }
    }
    Console.WriteLine("Case #{0}: YES", testNum);
  }

  static bool CheckFail(Byte[,] cells, Byte row, int col, Byte testNum)
  {
    var cell = cells[row, col];
    var rows = cells.GetLength(0);
    var cols = cells.GetLength(1);
    bool leftFail = false;
    bool rightFail = false;
    bool upFail = false;
    bool downFail = false;
    bool rowFail = false;
    bool colFail = false;

    for (int j = col - 1; j >= 0; j--)
      if (cells[row, j] > cell)
        leftFail = true;
    for (int j = col + 1; j < cols; j++)
      if (cells[row, j] > cell)
        rightFail = true;
    for (int i = row - 1; i >= 0; i--)
      if (cells[i, col] > cell)
        upFail = true;
    for (int i = row + 1; i < rows; i++)
      if (cells[i, col] > cell)
        downFail = true;

    rowFail = leftFail || rightFail;
    colFail = upFail | downFail;

    if (rowFail && colFail)
    {
      Console.WriteLine("Case #{0}: NO", testNum);
      return true;
    }
    return false;
  }
}